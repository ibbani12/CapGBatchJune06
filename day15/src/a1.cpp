#include <myheader.h>

int main(int argc, char *argv[])
{
	int pid, status;
	time_t t;
	if(argc != 2)
	{
		cout<<"Useage: ./app input.txt"<<endl;
		exit(EXIT_FAILURE);
	}
	
	//char *fName = argv[1];

	
	
	
	pid = fork();
	if(pid<0){
		perror("fork() error");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		cout<<"Child pid: "<<getpid()<<endl;
		cout<<"Child's Parent pid: "<<getppid()<<endl;
		cout<<"\nEnter two lines for the input:"<<endl;
		sleep(20);
		exit(EXIT_FAILURE);
		//Write2File(fName);

	}
	else
	{
		do{
			if((pid = waitpid(pid,&status,WNOHANG)) == -1)
				perror("wait() error");
			else if(pid == 0){
				time(&t);
				cout<<"\nChild is still running at "<<ctime(&t)<<endl;
				sleep(1);
			}
			else
			{
				if(WIFEXITED(status))
					cout<<"child exited with the status : "<<WEXITSTATUS(status)<<endl;
				else
					cout<<"Child did not exit successfully"<<endl;
				cout<<"Parent pid: "<<getpid()<<endl;
				cout<<"Parent's Parent pid: "<<getppid()<<endl;
				cout<<"\nRead the contents from input file"<<endl;
			}
			//ReadFromFile(fName);
		}while(pid == 0);

	}

	return 0;

}
