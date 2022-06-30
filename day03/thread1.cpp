#include <iostream>
#include <thread>

using namespace std;

void func1()
{
	for(int i=1;i<=10;i++)
		cout<<3*i<<endl;
}

int main()
{
	thread t1(func1); // threads created by function ptrs
	for(int i=0;i<1000;i++)
		cout<<"in main i = "<<i<<endl;
	//t1.join();
	// t1.join();
	// t1.detach();
	//t1.detach();

	if(t1.joinable())
	{
		cout<<"\nJoiing to main"<<endl;
		//t1.detach();
		t1.join();
	}

	cout<<"Bye"<<endl;
	return 0;

}