#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

using namespace std;


union semun{
	int val;              // used for SETVAL only
	struct semid_ds *buf; // used for IPC_STAT and IPC_SET
	ushort *array;        // used for GETALL and SETALL
};