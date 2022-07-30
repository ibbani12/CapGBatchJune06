#include<iostream>
#include<sys/types.h>
#include<wait.h>
#include<unistd.h>


using namespace std;

int main(int argc, char* argv[])
{
	int n;
	n = fork();
	if(n == 0)
	{
	if(argc[i]%2 ==0){
	for(int i=0;i<argc;i++)
	    cout<<argv[i]<<" "<<endl;
	    cout<<"parent process\n";
	    cout<<"odd numbers is"<<argc<<endl;}
	 }
	else
	{
	wait(0);
	{
	if(argv[i]%2!=0)
	{
                   for(int i=0;i<argc;i++)
		   cout<<"argv[i+1]"<<" "<<endl;
		   cout<<n<<"even numbers are:"<<argv<<endl;
	}
	}
	return 0;
	}
}