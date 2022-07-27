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

ORG *createOrg(ORG *e, int id, const char a[])
{
   //e = (ORG *)malloc( sizeof(*e) + (sizeof(char) * strlen(a))+1); //memory allocation
   e = new ORG[sizeof(*e) + (sizeof(char) * strlen(a))+1];
   e->empcount = id;
   
   cout<<sizeof(*e)<<endl;
   e->name = new char[strlen(a)+1];
   strcpy(e->name, a);
   return e;
}


void disp(ORG *e)
{
	cout<<e->name<<" "<<e->empcount<<endl;
}

int main(int argc, char*argv[])
{
	key_t key = ftok("shmAssign1",101);
   ORG *e1 = NULL
   ORG *temp =NULL;
   for(int i=0;i<3;i++){
   	string n;
   	cin>>n;
   	if(temp == NULL){
   		e1 = createOrg(e1, 23,(char*)n.c_str());
		temp = e1;
	}
	else
		{
			e1 = createOrg(e1, 23,(char*)n.c_str());
		}
	disp(e1);

	}

	
	// int shmid = shmget(key, (sizeof(*e1) + (sizeof(char) * n.length())+1), PERMS | IPC_CREAT);
	// if(shmid < 0)
	// {
	// 	perror("shmget() error");
	// 	exit(EXIT_FAILURE);
	// }

	// ORG *o1 = NULL;
	
	// o1 = (ORG *)shmat(shmid,(void*)0,0);
	// o1 = e1;
	// }
   
   return 0;
}























// int main()
// {
	
// 	key_t key = ftok("shmAssign1",101);
	
// 	ORG *o1 = NULL;
// 	string n;
	
// 	// for(int i=0;i<SIZE;i++){
// 	 	cin>>n;
// 		int shmid = shmget(key,  (sizeof(*o1) + sizeof(char [n.length()+1])), PERMS | IPC_CREAT);
// 		if(shmid < 0)
// 		{
// 			perror("shmget() error");
// 			exit(EXIT_FAILURE);
// 		}
// 		o1 = (ORG *)shmat(shmid,(void*)0,0);


// 	 	o1[0].name = new char[n.length()+1];
		
// 	 	strcpy(o1[0].name,(char *)n.c_str());
// 	 	o1[0].empcount = 1;
// 	// 	cout<<"SIZEof: "<<sizeof(o1[i])<<endl;
// 	// }
// 	// for(int i=0;i<3;i++)
// 	// 	cout<<o1[i].empcount<<" "<<o1[i].name<<endl;

// 	shmdt(o1);

// 	return 0;
// }