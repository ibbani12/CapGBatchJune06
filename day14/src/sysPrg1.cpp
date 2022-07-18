/*

signal,
sigaction - int sigaction(int signo, const struct sigaction *act,
 struct sigaction *oact);

 return 0 ->  success
 -1 error

 struct sigaction
 {
	void (*sa_handler)();  //address of signal handler, or SIG_IGN, or SIG_DFL
	sigset_t sa_mask; // additional signals to the block
	int sa_flags; // signal option
 };

sigfillset(&sa_mask)
sigemptyset()

*/


#include <sysPrg.h>

volatile sig_atomic_t unprocessedSig = 0;

void sigHandler(int sigNum)
{
	if (sigNum == SIGINT)
		unprocessedSig = 1;
}


int main()
{
	cout<<"\nPID : "<<getpid()<<endl;

	struct sigaction act;

	act.sa_handler = &sigHandler;

	sigfillset(&act.sa_mask);
	act.sa_flags = SA_RESTART;

	if(sigaction(SIGINT, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	//cout<<"\nKill the process using kill -9 pid"<<endl;
	cout<<"\nKill the process using killall -9 sigaction"<<endl;

	while(1)
	{
		if(unprocessedSig)
		{
			unprocessedSig = 0;
			cout<<"\nSIGINT has occured"<<endl;
		}
	}

	return 0;

}
