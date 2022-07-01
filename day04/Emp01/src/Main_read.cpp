#include <Employee.h>
#include <vector>
#include <fstream>

using namespace std;

// void dispE_Sid(vector <Employee*> v, string key)
// {

// 	for(auto it: v){
// 		if(it->getSid() == key)
// 			it->display();
// 	}
// }

int main()
{
	int N=0;
	fstream fs;
	
	
	fs.open("Emp.dat", ios::in|ios::out|ios::app);
	if(!fs)
	{
		cout<<"Unable to open the file"<<endl;
		exit(0);
	}
	char EName[20];
	int USal;
	cout<<"\nEnter the name of the Employee to be updated: ";
	cin>>EName>>USal;

	Employee E;
	while(fs.read(reinterpret_cast<char *>(&E), sizeof(Employee))){
		cout<<"\nPrint Employee Details"<<endl;
		E.display();
		if(strcmp(E.getName(), EName)==0)
		{
			cout<<"\nFound"<<endl;
		}
		N++;
				
	}

	fs.close();


	

	return 0;

}
