#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Student
{
private:
	char sName[20];
	int sRollNo;
public:
	Student(){ strcpy(sName,"defaultName"); sRollNo=0; }
	Student(const char *n, int r){ strcpy(sName, n); sRollNo= r; }
	char *getSName();
	int getSRollNo();
	void setSName(const char *);
	void setSRollNo(int );
	void setValues(const char *, int );
	void dispStudent();

};


bool searchStd(vector <Student>&, string);

void Write2File(vector<Student>&);
void ReadFromFile(vector<Student>&);
bool findNUpdate(vector<Student>&);
