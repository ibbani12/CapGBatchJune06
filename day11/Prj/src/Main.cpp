#include <Student.h>
#include <iostream>

using namespace std;

extern int SIZE;

int main()
{
	int N=SIZE;
	string n;
	int r;
	Student *s = new Student[N];
	vector <Student> vs;
	vector<Student> :: iterator it;

	for(int i=0;i<N;i++,it++)
	{
		cout<<"\nEnter the value for Student ["<<i<<"]"<<endl;
		cout<<"\nName: ";
		cin>>n;
		cout<<"\nRoll No: ";
		cin>>r;
		s[i].setValues(n.c_str(),r);
		vs.push_back(s[i]);
	}

	// for(int i=0;i<N;i++)
	// 	s[i].dispStudent();

	//vector<Student> :: iterator it;
	for(it=vs.begin(); it!=vs.end();it++)
		it->dispStudent();

	// for(auto it: vs)
	// 	it.dispStudent();

	cout<<searchStd(vs,"d")<<endl;

	delete []s;
	return 0;
}