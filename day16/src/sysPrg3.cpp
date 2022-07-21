/*

ipcs - give all the ipc used/runing in the system

message queue -

create-> msgget()

flag - IPC_CREAT -> create a msg queue if not exists else ignored
IPC_EXCL -> forces an error when used along with IPC_CREAT when a queue
alread exists

struct ipc_perm
{
	ushort uid; // owners user id
	ushort git; // owners group id
	ushort cuid; // creators user id
	ushort cgid; // creators group id
	ushort mode; // access mode
	ushort seq; // slot usage seq number
	key_t key; //key 	
};



*/

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>



using namespace std;

int main()
{
	int msgid;
	msgid = msgget((key_t)123456, 0666 | IPC_CREAT | IPC_EXCL );
	if(msgid == -1)
	{
		perror("msgget() error");
		cout<<"Error No: "<<errno<<endl;
		if(errno == EACCES)
			cout<<"Access error"<<endl;
		else if (errno == EEXIST)
			cout<<"EXISTS"<<endl;
		else if (errno == ENOENT)
			cout<<"ENOENT"<<endl;
		else if (errno == ENOMEM )
			cout<<"ENOMEM"<<endl;
		else if (errno == ENOSPC )
			cout<<"ENOSPC "<<endl;


	}
	cout<<"\nMessage queue successfully created";
	cout<<" with key :"<<msgid<<endl;

	return (EXIT_SUCCESS);
}