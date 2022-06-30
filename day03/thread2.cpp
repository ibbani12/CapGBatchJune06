#include <iostream>
#include <thread>

using namespace std;

class Emp
{
public:
	void operator()(){
		for(int i=1;i<=10;i++)
			cout<<3*i<<endl;
	}
};

int main()
{
	thread t1((Emp())); // thread created using function object
	cout<<"\nExecuting main thread"<<endl;
	for(int i=0;i<1000;i++)
		cout<<"in main i = "<<i<<endl;
	cout<<"\nExecuting the thread"<<endl;
	t1.join();
	cout<<"Bye"<<endl;


	return 0;
}