#include <ourHeader.h>

int main()
{
	key_t key;
	int semid;
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

	cout<<"\nPress return key to lock"<<endl;
	getchar();
	cout<<"Trying to lock....."<<endl;

	if(semop(semid,&sb,1)==-1)
	{
		perror("semop() error");
		exit(1);
	}

	cout<<"Locked..."<<endl;
	cout<<"Press return key to unlock it: "<<endl;
	getchar();
	sb.sem_op = 1; //free the resource
	if(semop(semid,&sb,1)==-1)
	{
		perror("semop() error");
		exit(1);
	}

	cout<<"Unlocked"<<endl;

	return 0;	

}