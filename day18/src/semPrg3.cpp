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
	semid = semget(0x21, 1, 0666|IPC_CREAT);
	cout<<"getpid(): "<<getpid()<<endl;
	semctl(semid,0,SETVAL,1001);
	retVal = semctl(semid, 0, GETVAL, 0);
	cout<<"RetVal (getval) = "<<retVal<<endl;
	retVal = semctl(semid, 0, GETPID, 0);
	cout<<"RetVal (getpid)= "<<retVal<<endl;
	return (EXIT_SUCCESS);
}