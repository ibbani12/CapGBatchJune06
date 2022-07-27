#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/ipc.h>

using namespace std;

int main(int argc, char *argv[])
{

	int semid, val=0;
	//val = atoi(argv[1]);
	semid = semget((key_t)0x20,1,IPC_CREAT|0666);
	cout<<"Semid: "<<semid<<endl;
	cout<<"Value in Sem: "<<semctl(semid, 0,GETVAL,0)<<endl;
	semctl(semid, 0,IPC_RMID,0);

	return 0;
}