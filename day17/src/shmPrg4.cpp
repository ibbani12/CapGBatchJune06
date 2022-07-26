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
	int i=1;
	for(;;){
		if(counter >= SIZE)
			break;
		if(i%2 == 0)
			arr[counter++] = i;
	i++;
	}

	cout<<"\nThe array content are\n";

	for(int i=0;i<counter;i++)
		cout<<" "<<arr[i];
	shmdt(arr);

	return 0;
}