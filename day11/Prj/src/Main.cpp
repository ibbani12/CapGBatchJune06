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

	//cout<<searchStd(vs,"bhima")<<endl;
	//cout<<"Sizeof Vector: "<<vs.size()<<endl;
	size_t sizeVs = vs.size();
	Write2File(vs);
	
	cout<<"\nafter reading from the file student details are\n";

	vector <Student> vs1;
	vs1.resize(sizeVs);
	cout<<"Sizeof Vector: "<<vs1.size()<<endl;
	ReadFromFile(vs1);

	for(it=vs1.begin(); it!=vs1.end();it++)
	 	it->dispStudent();

	delete []s;
	return 0;
}