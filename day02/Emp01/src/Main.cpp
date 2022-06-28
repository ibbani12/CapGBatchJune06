#include <Employee.h>
#include <vector>

int main()
{
	int N=3;
	//for(int i=0;i<3;i++){
		vector <Employee*> v;
		Employee *E = new Employee(30, "James1", 'M', "CG_001",30000,"SE","1001");
		v.push_back(E);
		E = new Employee(30, "James2", 'M', "CG_002",30000,"SE","1002");
		v.push_back(E);
		E = new Employee(30, "James3", 'M', "CG_003",30000,"SE","1001");
		v.push_back(E);
		E = new Employee(30, "James4", 'M', "CG_004",30000,"SE","1002");
		v.push_back(E);
		
		//E->display();
		
	//}

	for(auto it: v)
		cout<<it->getSid()<<endl;;

	return 0;

}
