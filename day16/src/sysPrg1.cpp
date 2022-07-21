
#include <iostream>
#include <signal.h>
#include <cstring>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <string>
#include <time.h>

#define MAXBUFF 1024

using namespace std;


static void func1(int signum)
{
	cout<<"Sig Number: "<<signum<<endl;
	if(signum == SIGSEGV)
	{
		cout<<"Seg fault error occured"<<endl;
		exit(EXIT_FAILURE);
	}
}


void mystrcat(char *str1, char *str2)
{
	int i;
	signal(SIGSEGV,func1);
	str1 = new char[strlen(str2)];
	for(i=0;i<strlen(str2);i++)
		str1[i] = str2[i];
	str1[i] = '\0';
}

int main()
{
	sighandler_t ret = signal(SIGINT,func1);

	if(ret == SIG_ERR)
	{
		perror("signal() error");
		exit(EXIT_FAILURE);
	}

	// while(1)
	// {
	// 	sleep(2);
	// 	cout<<"SIgnal demo"<<endl;
	// }
	char *str1, str2[20];
	cin>>str2;
	char *str3 = NULL;
	
	mystrcat(str1, str3);

	cout<<"Str1: "<<str1<<endl;
	cout<<"Str2: "<<str2<<endl;

	return EXIT_SUCCESS;

}