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
	ushort val1[] = {1,3,5,7};
	ushort val2[] = {2,4,6,8};
	ushort val3[8];
	semid = semget(0x38, 10, 0666|IPC_CREAT);
	 semctl(semid, 0, SETALL, val1);
	 semctl(semid, 1, SETALL, val2);

	semctl(semid, 0, GETALL, val3);
	
	for(int i=0;i<8;i++)
		cout<<" "<<val3[i];
	cout<<endl;
	
	return (EXIT_SUCCESS);
}