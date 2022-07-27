#include <ourHeader.h>

int main()
{
	key_t key;
	int semid;
	union semun arg;
	struct sembuf sb = {0,-1,0};  // set to allocate resource

	if((key = ftok("semdemo.c",'3')) == -1)
	{
		perror("ftok() Error");
		exit(1);
	}

	//create a sem with 1 sub-sem
	if((semid = semget(key, 1,0666|IPC_CREAT)) == -1)
	{
		perror("semget() error");
		exit(1);
	}

	//remove the ipc/sem created

	if(semctl(semid, 0, IPC_RMID,arg) == -1)
	{
		perror("semctl() error");
		exit(1);
	}

	return 0;
}