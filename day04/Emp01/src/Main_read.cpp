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
	long pos=0;
	
	fs.open("Emp.dat", ios::in|ios::out);
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

	pos = fs.tellp();
	cout<<"\nFile position is: "<<pos<<" @ Record: "<<N<<endl;
	while(fs.read(reinterpret_cast<char *>(&E), sizeof(Employee))){
		pos = fs.tellp();
		N++;
		cout<<"\nFile position is: "<<pos<<" @ Record: "<<N<<endl;
	
		cout<<"\nPrint Employee Details"<<endl;
		E.display();
		if(strcmp(E.getName(), EName)==0)
		{
			cout<<"\nFound"<<endl;
			E.setSal(USal);
			fs.seekp(pos-(sizeof(Employee)));
			cout<<"\nUpdated in memory"<<endl;
			cout<<"\nFile position is: "<<pos<<" @ Record: "<<N-1<<endl;
	
			E.display();
			fs.write(reinterpret_cast<char *>(&E), sizeof(Employee));
			break;

		}
		
				
	}

	fs.close();


	

	return 0;

}
