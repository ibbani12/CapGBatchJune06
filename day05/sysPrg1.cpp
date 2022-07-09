/*
	program to show backgroung process
	run your output program in the following way
	./a.out &
*/

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	for(int i=0;i<=400;++i){
		cout<<i<<endl;
		sleep(1);
	}

	return 0;
}