#include <sys/wait.h>
#include <iostream>
#include <csignal>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <cstring>
#include <errno.h> /* for definition of errno */
#include <stdarg.h> /* ISO C variable aruments */

#define DEF_PAGER "/bin/more" /* default pager program */
#define MAXLINE 1024

void err_sys(const char *, ...) __attribute__((noreturn));
void err_quit(const char *, ...) __attribute__((noreturn));
static void err_doit(int, int, const char *, va_list);

int main(int argc, char *argv[])
{
	int n;
	int fd[2];
	pid_t pid;
	char *pager, *argv0;
	char line[MAXLINE];
	FILE *fp;
	if (argc != 2)
		err_quit("usage: a.out <pathname>");
	if ((fp = fopen(argv[1], "r")) == NULL)
		err_sys("can’t open %s", argv[1]);
	if (pipe(fd) < 0)
		err_sys("pipe error");
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} 
	else if (pid > 0) 
	{ /* parent */
		close(fd[0]); /* close read end */
		/* parent copies argv[1] to pipe */
		while (fgets(line, MAXLINE, fp) != NULL) {
			n = strlen(line);
			if (write(fd[1], line, n) != n)
				err_sys("write error to pipe");
		}
		if (ferror(fp))
			err_sys("fgets error");
		close(fd[1]); /* close write end of pipe for reader */
		if (waitpid(pid, NULL, 0) < 0)
			err_sys("waitpid error");
		exit(0);
	} 

	else { /* child */
		close(fd[1]); /* close write end */
		if (fd[0] != STDIN_FILENO) {
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
			err_sys("dup2 error to stdin");
			close(fd[0]); /* don’t need this after dup2 */
		}
		/* get arguments for execl() */
		if ((pager = getenv("PAGER")) == NULL)
			pager = DEF_PAGER;
		if ((argv0 = strrchr(pager, '/')) != NULL)
			argv0++; /* step past rightmost slash */
		else
			argv0 = pager; /* no slash in pager */
		if (execl(pager, argv0, (char *)0) < 0)
			err_sys("execl error for %s", pager);
	}
	exit(0);
}


/*
* Fatal error related to a system call.
* Print a message and terminate.
*/
void
err_sys(const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
err_doit(1, errno, fmt, ap);
va_end(ap);
exit(1);
}

/*
* Fatal error unrelated to a system call.
* Print a message and terminate.
*/
void
err_quit(const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
err_doit(0, 0, fmt, ap);
va_end(ap);
exit(1);
}
/*
* Print a message and return to caller.
* Caller specifies "errnoflag".
*/
static void
err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
char buf[MAXLINE];
vsnprintf(buf, MAXLINE-1, fmt, ap);
if (errnoflag)
snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s",
strerror(error));
strcat(buf, "\n");
fflush(stdout); /* in case stdout and stderr are the same */
fputs(buf, stderr);
fflush(NULL); /* flushes all stdio output streams */
}