#include <Employee.h>
#include <vector>

void dispE_Sid(vector <Employee*> v, string key)
{

	for(auto it: v){
		if(it->getSid() == key)
			it->display();
	}
}

int main()
{
	//int N=3;
	//for(int i=0;i<3;i++){
		vector <Employee*> v;
		// cout<<"\n0"<<endl;
		// cout<<"\nSize of vector : "<<v.size()<<endl;
		// cout<<"\nCap of vector : "<<v.capacity()<<endl;

		Employee *E = new Employee(30, "James1", 'M', "CG_001",30000,"SE","1001");
		v.push_back(E);
		// cout<<"\n1"<<endl;
		// cout<<"\nSize of vector : "<<v.size()<<endl;
		// cout<<"\nCap of vector : "<<v.capacity()<<endl;

		E = new Employee(30, "James2", 'M', "CG_002",30000,"SE","1002");
		v.push_back(E);
		// cout<<"\n2"<<endl;
		// cout<<"\nSize of vector : "<<v.size()<<endl;
		// cout<<"\nCap of vector : "<<v.capacity()<<endl;

		E = new Employee(30, "James3", 'M', "CG_003",30000,"SE","1001");
		v.push_back(E);
		
		// cout<<"\n3"<<endl;
		// cout<<"\nSize of vector : "<<v.size()<<endl;
		// cout<<"\nCap of vector : "<<v.capacity()<<endl;


		E = new Employee(30, "James4", 'M', "CG_004",30000,"SE","1002");
		v.push_back(E);
		
		// cout<<"\n4"<<endl;
		// cout<<"\nSize of vector : "<<v.size()<<endl;
		// cout<<"\nCap of vector : "<<v.capacity()<<endl;

		E = new Employee(30, "James5", 'M', "CG_005",30000,"SE","1002");
		v.push_back(E);
		
		// cout<<"\n5"<<endl;
		// cout<<"\nSize of vector : "<<v.size()<<endl;
		// cout<<"\nCap of vector : "<<v.capacity()<<endl;

		E = new Employee(30, "James6", 'M', "CG_006");
		v.push_back(E);

		//E->display();
		
	//}

	for(auto it: v)
		cout<<it->getSid()<<endl;

	// cout<<"\nSize of vector : "<<v.size()<<endl;
	// cout<<"\nCap of vector : "<<v.capacity()<<endl;

	

	dispE_Sid(v,"1001");

	return 0;

}
