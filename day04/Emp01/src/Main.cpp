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
	int N;
	fstream fs;
	cout<<"\nEnter How many Employees: ";
	cin>>N;
	Employee *E = new Employee[N];
	
	fs.open("Emp.dat", ios::in|ios::out|ios::app);
	if(!fs)
	{
		cout<<"Unable to open the file"<<endl;
		exit(0);
	}
	for(int i=0;i<N;i++){
		E[i].getEmpDetails();
		fs.write(reinterpret_cast<char *>(&E[i]), sizeof(Employee));
	}

	fs.close();


	cout<<"\nPrint Employee Details"<<endl;
	
	for(int i=0;i<N;i++){
		E[i].display();
	}


	return 0;

}
