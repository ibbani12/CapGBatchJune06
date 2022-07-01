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
	int i=0;
	fstream fs;
	// cout<<"\nEnter How many Employees: ";
	// cin>>N;
	
	
	fs.open("Emp.dat", ios::in|ios::out|ios::app);
	if(!fs)
	{
		cout<<"Unable to open the file"<<endl;
		exit(0);
	}
	Employee E;
	while(fs.read(reinterpret_cast<char *>(&E), sizeof(Employee))){
		cout<<"\nPrint Employee Details"<<endl;
		E.display();

				
	}

	fs.close();


	

	return 0;

}
