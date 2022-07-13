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

void Write2File(vector<Student>&vs)
{
	fstream fs;
	fs.open("Student.dat",ios::in | ios::out | ios::binary);
	if(!fs)
	{
		cout<<"Unable to open the Student's DB"<<endl;
		exit(0);
	}

	size_t size = vs.size();
    fs.write(reinterpret_cast<const char*>(&vs[0]), size*sizeof(Student));
    
	fs.close();
}

void ReadFromFile(vector<Student>&vs)
{
	fstream fs;
	fs.open("Student.dat",ios::in | ios::out | ios::binary);
	if(!fs)
	{
		cout<<"Unable to open the Student's DB"<<endl;
		exit(0);
	}

	size_t size = vs.size();
	fs.read(reinterpret_cast<char*>(&vs[0]), size*sizeof(Student));
    
    fs.close();
}

bool findNUpdate(vector<Student>&vs, int key, char *nName)
{

	return false;
}