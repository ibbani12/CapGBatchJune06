#include <test.h>

using namespace std;

int main()
{
	int *a = new int[10];
	a[0] = 10;
	cout<<"Hey Mates!"<<endl;
	delete []a;
	return true;

}