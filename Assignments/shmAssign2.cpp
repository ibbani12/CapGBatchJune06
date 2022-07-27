#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <cstring>
#define SIZE 3
#define PERMS 0666

using namespace std;

typedef struct org
{
	char *name;
	unsigned int empcount;
}ORG;

int main()
{
	
	key_t key = ftok("shmAssign1",101);
	int shmid = shmget(key, sizeof(ORG), PERMS | IPC_CREAT);
	if(shmid < 0)
	{
		perror("shmget() error");
		exit(EXIT_FAILURE);
	}

	ORG *o1 = NULL;
	string n;
	o1 = (ORG *)shmat(shmid,(void*)0,0);
	// for(int i=0;i<SIZE;i++){
	// 	cin>>n;
		
	// 	o1[i].name = new char[n.length()+1];
		
	// 	strcpy(o1[i].name,(char *)n.c_str());
	// 	o1[i].empcount = (i+1);
	// 	cout<<"SIZEof: "<<sizeof(o1[i])<<endl;
	// }
	for(int i=0;i<3;i++)
		cout<<o1[i].empcount<<" "<<o1[i].name<<endl;

	shmdt(o1);

	return 0;
}