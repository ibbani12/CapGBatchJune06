#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/ipc.h>

using namespace std;

int main()
{

	int semid, retval=0;
	struct sembuf sop;
	sop.sem_num = 0;
	sop.sem_op = 0;
	sop.sem_flg = 0;
	semid = semget((key_t)0x20,1,IPC_CREAT|0600);

	cout<<"Before semop: ";
	retval = semop(semid,&sop,1);
	cout<<"semop returned : "<<retval<<endl;

	return 0;
}