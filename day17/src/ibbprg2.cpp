#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#define PERMS 0666

using namespace std;


int main()
{
	key_t key = ftok("myfile",101);
	int shmid = shmget(key, 1024, PERMS | IPC_CREAT);

	if(shmid < 0)
	{
		perror("shmget() error");
		exit(EXIT_FAILURE);
	}

	char *str = (char *)shmat(shmid, (void *)0, 0);
	cout<<"Read the data from shared Mem"<<endl;
	cout<<"Contents in str\n"<<str<<endl;
	cout<<"Shared mem ID: "<<shmid<<endl;
	shmdt(str);

	

	return 0;
}