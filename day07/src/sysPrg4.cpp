#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	cout<<"Run ps -el command"<<endl;
	sleep(50);
	cout<<"Run ps -el command once again"<<endl;
	for(;;);
		
	return 0;
}