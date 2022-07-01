#include <Employee.h>
#include <vector>
#include <fstream>

using namespace std;


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
	
	cout<<"\nPrint Employee Details"<<endl;
	Employee E;
	while(fs.read(reinterpret_cast<char *>(&E), sizeof(Employee))){
		
		E.display();

		N++;
				
	}

	fs.close();


	

	return 0;

}
