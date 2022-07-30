#include <iostream>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define PERMS 0666
#define MAXBUF 10

using namespace std;

struct msg_buf{
	long msg_type;
	char msg_txt[100];
};

typedef struct msg_buf MSG;

int main()
{
	MSG m;

	key_t key;
	int msgid;

	// to gen unique key
	key = ftok("myfile", 100);

	msgid = msgget(key, PERMS | IPC_CREAT);
	if(msgid<0)
	{
		perror("msgget() error");
		exit(EXIT_FAILURE);
	}

	while(msgrcv(msgid, &m, sizeof(m),1,0)){

		cout<<"\nReceived data : "<<m.msg_txt<<endl;
	}
	msgctl(msgid, IPC_RMID, NULL);

	return (EXIT_SUCCESS);
}