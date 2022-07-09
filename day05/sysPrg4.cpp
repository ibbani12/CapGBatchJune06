#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{

	fork();
	fork();
	fork();
	cout<<"Hello WOrld!"<<endl;

	return 0;
}