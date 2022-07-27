#include <ourHeader.h>

int main()
{
	int semid, pid,val;
	struct sembuf sop;
	semid = semget(0x20,1,IPC_CREAT|0666);
	pid = fork();
	if(pid == 0)
	{
		sleep(2);
		cout<<"\nChild before semop"<<endl;
		sop.sem_num = 0;
		sop.sem_op = -3;
		sop.sem_flg = IPC_NOWAIT;
		semop(semid, &sop, 1);
		cout<<"Child terminates"<<endl;
	}
	else
	{
		cout<<"\nParent before 1st semctl operation"<<endl;
		semctl(semid, 0, SETVAL, 1);
		cout<<"Parent sleeping"<<endl;
		sleep(5);
		cout<<"Parent before 2nd semctl operation"<<endl;
		val = semctl(semid,0,GETVAL,0);
		cout<<"Semaphore value : "<<val<<endl;
		cout<<"Parent terminates"<<endl;

	}

	return 0;
}