#include <iostream>

using namespace std;

void func1(int l)
{
	cout<<"l: "<<l<<endl;
}

int main()
{
	int a=10;
	int b=20;
	int c;

	// c = a++ + ++b;

	c=a++;
	++b;


	 cout<<"a: "<<a<<endl;
	 cout<<"b: "<<b<<endl;
	 c = sizeof(++a + ++b);
	 //func1(++a + ++b);
	 cout<<"a: "<<a<<endl;
	 cout<<"b: "<<b<<endl;
	 cout<<"c: "<<c<<endl;

	//cout<<sizeof(double)<<endl;
	return 0;
}