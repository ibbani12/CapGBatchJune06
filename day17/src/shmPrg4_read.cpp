#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#define PERMS 0666
#define SIZE 10

using namespace std;


int main()
{
	key_t key = ftok("myfile",104);
	int shmid = shmget(key, sizeof(int)*SIZE, PERMS | IPC_CREAT);

	if(shmid < 0)
	{
		perror("shmget() error");
		exit(EXIT_FAILURE);
	}

	int* arr = NULL;// = new int[20];
	int counter=0;
	cout<<"Size: "<<sizeof(arr)<<endl;
	//arr = new int[20];
	arr = (int *)shmat(shmid, (void *)0, 0);

	cout<<"\nThe array content are \n";

	struct shmid_ds buf;
	shmctl(shmid, IPC_STAT, &buf);
	int len = (int)buf.shm_segsz / sizeof(int);
	cout<<"length: "<<len<<endl;
	for(int i=0;i<len;i++)
		cout<<" "<<arr[i];
	shmdt(arr);
	cout<<endl;
	return 0;
}