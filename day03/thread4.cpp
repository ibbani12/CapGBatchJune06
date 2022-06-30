#include <iostream>
#include<thread>

using namespace std;

int main()
{
	std::thread t1([]{
		for(int i=1;i<=10;i++)
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