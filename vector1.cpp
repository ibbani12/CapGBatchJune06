#include<iostream>

#include<vector>

using namespace std;

int main()
{
	vector <int> v;
	long int i;
	for(i=0;i<1025;i++)
		v.push_back(i);

	cout<<"\nSize of vector : "<<v.size()<<endl;
	cout<<"\nCap of vector : "<<v.capacity()<<endl;

	return 0;
}