#include <iostream>
#include<thread>

using namespace std;

int main()
{
	int x=10;
	std::thread t1([x]{
		for(int i=1;i<=x;i++)
		cout<<3*i<<endl;
	});

	cout<<"\nExecuting main thread"<<endl;
	for(int i=0;i<1000;i++)
		cout<<"in main i = "<<i<<endl;
	cout<<"\nExecuting the thread"<<endl;
	t1.join();
	cout<<"Bye"<<endl;

	return 0;
}