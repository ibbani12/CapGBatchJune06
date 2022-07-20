#include <iostream>
#include<string>
#include <cstring>

using namespace std;

class Container
{
	char pName[5];
	char pType[4];
	long pNum;
public:
	void setData(char pn[5], char pt[4], long pno)
	{
		strcpy(pName, pn);
		strcpy(pType, pt);
		pNum = pno;
	}

	void disp(){
		cout<<pName<<endl;
		cout<<pType<<endl;
		cout<<pNum<<endl;
	}
};

int main()
{
	Container d[3];

	string pn,pt,pno;
	cin>>pn>>pt>>pno;
	d[0].setData((char*)pn.c_str(),(char*)pt.c_str(),stol(pno));
	d[0].disp();

	return 0;
}