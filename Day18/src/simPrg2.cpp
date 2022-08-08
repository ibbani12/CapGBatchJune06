#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>

using namespace std;

int main()
{
	int semid, retVal;
	semid = semget(0x20, 1, 0666|IPC_CREAT);
	retVal = semctl(semid, 0, GETVAL, 0);
	cout<<"RetVal = "<<retVal<<endl;
	return (EXIT_SUCCESS);
}