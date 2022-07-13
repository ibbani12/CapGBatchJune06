#include <Student.h>

char *Student::getSName(){ return sName; }
int Student::getSRollNo(){ return sRollNo; }
void Student::setSName(const char *n){ strcpy(sName, n); }
void Student::setSRollNo(int r) { sRollNo = r; }

void Student::setValues(const char *n, int r){ strcpy(sName, n); sRollNo= r; }


void Student::dispStudent(){
	cout<<"\n=======Student Details========"<<endl;
	cout<<"Student Name: "<<sName<<endl;
	cout<<"Student Roll No: "<<sRollNo<<endl;
	cout<<"\n=============================="<<endl;
}

bool searchStd(vector <Student>& vs, string key)
{
	vector <Student> :: iterator it;
	for(it=vs.begin(); it!=vs.end(); it++)
		if(strcmp(it->getSName(), key.c_str()) == 0)
			return true;
	
	return false;
}