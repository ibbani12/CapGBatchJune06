#include <myheader.h>

void func1()
{
	cout<<"Killed PID:"<<getpid()<<endl;
	
	kill(getpid(),SIGUSR1);
}

static void process_display_exit_code(int exitstatus)
{
	cout<<"Interrupt signal ("<<exitstatus<<") received"<<endl;
}

static void signalHandler(int ID)
{
	cout<<"ID : "<<ID<<endl;
}



int main(int argc, char *argv[])
{
	int pid, status;
	time_t t;
	if(argc != 2)
	{
		cout<<"Useage: ./app input.txt"<<endl;
		exit(EXIT_FAILURE);
	}
	
	char *fName = argv[1];

	
	
	
					// signal(SIGINT, process_display_exit_code);
					// signal(SIGILL, process_display_exit_code);
					// signal(SIGFPE, process_display_exit_code);
					// signal(SIGSEGV, process_display_exit_code);
					// signal(SIGTERM, process_display_exit_code);
					// signal(SIGABRT, process_display_exit_code);
					// signal(SIGCHLD, process_display_exit_code);
	pid = fork();
	if(pid<0){
		perror("fork() error");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		atexit(func1);
		cout<<"Child pid: "<<getpid()<<endl;
		cout<<"Child's Parent pid: "<<getppid()<<endl;
		cout<<"\nEnter two lines for the input:"<<endl;
		Write2File(fName);
		sleep(3);
		exit(EXIT_FAILURE);
		

	}
	else
	{
		atexit(func1);
		do{
			if((pid = waitpid(pid,&status,WNOHANG)) == -1)
			{
				signal(SIGCHLD, signalHandler);
				perror("wait() error");
			}
			else if(pid == 0){
				time(&t);
				cout<<"\nChild is still running at "<<ctime(&t)<<endl;
				sleep(1);
			}
			else
			{
				signal(SIGCHLD, process_display_exit_code);
				if(WIFEXITED(status)){
					
					cout<<"child exited with the status : "<<WEXITSTATUS(status)<<endl;
				}
				else if(WIFSIGNALED(status)){
					signal(SIGCHLD, process_display_exit_code);
					cout<<"Signaled: "<<status<<endl;
				}
				else
					cout<<"Child did not exit successfully"<<endl;
				cout<<"Parent pid: "<<getpid()<<endl;
				cout<<"Parent's Parent pid: "<<getppid()<<endl;
				cout<<"\nRead the contents from input file"<<endl;
				ReadFromFile(fName);
			}
			
		}while(pid == 0);

	}

	return 0;

}
