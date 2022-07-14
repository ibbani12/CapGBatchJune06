#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void sigChld(int arg){
	int pid ;
	printf("SIGCHLD caught\n") ;
	pid = wait(NULL) ;
	printf("signal's wait() caught pid %d\n", pid) ;
	signal(SIGCHLD, sigChld) ;
}

int main(){
	signal(SIGCHLD, sigChld) ;
	int pid ;
	pid = fork() ;
	if (pid == 0){
		int status = getpid() ;
		printf("child pid is %d\n", status) ;
		for (int i = 0, j = 0 ; i < 1000000 ; i++, j++) ;
		printf("child is gonna return %d\n", status) ;
		exit(0) ;
	}else{
		printf("Waiting for pid %d\n", pid) ;
		int ret ;
		int x = waitpid(pid, &ret, 0) ;
		printf("wait pid returns %d\n" , x) ;
	}
			
}