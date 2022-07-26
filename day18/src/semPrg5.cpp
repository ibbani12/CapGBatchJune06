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
	ushort val[6] = {1,2,3,4,5,6};
	ushort val2[6];
	semid = semget(0x26, 6, 0666|IPC_CREAT);
	semctl(semid, 0, SETALL, val);
	
	semctl(semid, 0, GETALL, val2);
	for(int i=0;i<6;i++)
		cout<<" "<<val2[i];
	cout<<endl;
	
	return (EXIT_SUCCESS);
}