#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#define MSGSIZE 4
using namespace std;


int main()
{
	char *msg1 = "Hello, world #1";
	char *msg2 = "Hello, world #2";
	char *msg3 = "Hello, world #3";

	char inbuf[MSGSIZE];
	int p[2];

	pipe(p);

	write(p[1],msg1,strlen(msg1));
	write(p[1],msg2,strlen(msg2));
	write(p[1],msg3,strlen(msg3));

	// for(int i=0;i<3;i++)
	// {
	// 	read(p[0], inbuf, 1);
	// 	cout<<"i="<<i<<" "<<inbuf<<endl;
	// }

	int n=0;
	n=read(p[0], inbuf,MSGSIZE);
	cout<<inbuf<<endl;
	cout<<"n="<<n<<endl;
	// while(n > 0){
		
	// 	cout<<inbuf<<endl;
	// 	//strcpy(inbuf,NULL);

	// 	memset(inbuf, 0, MSGSIZE);
	// 	n=read(p[0], inbuf,MSGSIZE);
	// 	cout<<"n="<<n<<endl;
	// }

	exit(0);

}