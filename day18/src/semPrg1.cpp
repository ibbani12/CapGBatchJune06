#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>

using namespace std;

int main()
{

	int semid, key, nsem;
	int flag = IPC_CREAT | 0666;
	
	key = (key_t)0x21;
	nsem = 25;
	semid = semget(key, nsem,flag);

	if(semid < 0)
	{
		perror("semget() error");
		exit(EXIT_FAILURE);
	}

	cout<<"1st Semaphore created"<<endl;

	key = (key_t)0x22;
	nsem = 25;
	semid = semget(key, nsem,flag);

	if(semid < 0)
	{
		perror("semget() error");
		exit(EXIT_FAILURE);
	}
	
	cout<<"2nd Semaphore created"<<endl;

	
	key = (key_t)0x23;
	nsem = 10;
	semid = semget(key, nsem,flag);

	if(semid < 0)
	{
		perror("semget() error");
		exit(EXIT_FAILURE);
	}
	
	cout<<"3rd Semaphore created"<<endl;


	key = (key_t)0x24;
	nsem = 1;
	semid = semget(key, nsem,flag);

	if(semid < 0)
	{
		perror("semget() error");
		exit(EXIT_FAILURE);
	}
	cout<<"4th Semaphore created"<<endl;



	//semctl(semid, 0, IPC_RMID,0);

	return 0;

}