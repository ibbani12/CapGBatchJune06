#include <iostream>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define PERMS 0666


using namespace std;

int main()
{
	int msgid, i;
	key_t key=100;
	// for(i=0;i<50;i++){
	// 	msgid = msgget(key, PERMS | IPC_CREAT );
	// 	if(msgid < 0)
	// 	{
	// 		cout<<"Unbale to create the msg"<<endl;
	// 		perror("msgget() error");
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	cout<<"Msg created succesfully with id: "<<msgid<<endl;


	
	// }


	for(i=50;i<100;i++){
		if(msgctl(i, IPC_RMID, 0) <0)
		{
			perror("msgctl() error");
			//exit(EXIT_FAILURE);
		}
		cout<<"Msg removed succesfully with id: "<<i<<endl;

	}






	
	
	return (EXIT_SUCCESS);
}