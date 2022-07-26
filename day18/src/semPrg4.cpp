#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <unistd.h>

using namespace std;

int main()
{
	int semid, retVal;
	ushort val[6];
	semid = semget(0x25, 5, 0666|IPC_CREAT);
	semctl(semid, 0, SETVAL, 1);
	semctl(semid, 1, SETVAL, 2);
	semctl(semid, 2, SETVAL, 3);
	semctl(semid, 3, SETVAL, 4);
	semctl(semid, 4, SETVAL, 5);
	if(semctl(semid, 5, SETVAL, 6)<0)
		perror("semctl() error");

	semctl(semid, 0, GETALL, val);
	for(int i=0;i<6;i++)
		cout<<" "<<val[i];
	cout<<endl;
	
	return (EXIT_SUCCESS);
}