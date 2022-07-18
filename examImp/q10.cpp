#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class PLists
{
private:
	string port_type;
	string port_name;
	int port_num;
	char valid_portNum;
	char valid_portType;
	int vCount;
public:
	PLists(){ valid_portType = 'V'; valid_portNum = 'V'; vCount=0; }
	void setValues(int pno, string pt, string pn, char vpno, char vpt)
	{
		port_num = pno;
		port_type = pt;
		port_name = pn;
		valid_portNum = vpno;
		valid_portType = vpt;
	}
	void setValues(int pno, string pt, string pn)
	{
		port_num = pno;
		port_type = pt;
		port_name = pn;
		
	}

	char getVpno(){ return valid_portNum; }
	char getVpt() { return valid_portType; }
	int getPno() { return port_num; }
	string getPType() { return port_type; }
	string getPName() { return port_name; }
	void setVpno(char x) { valid_portNum = x; }
	void setVpt(char x) { valid_portType = x; }

	void disp()
	{
		cout<<"\n=========List=========\n";
		cout<<port_num<<endl;
		cout<<"port_type : "<<port_type<<endl;
		cout<<port_name<<endl;
		cout<<"Port Number: "<<valid_portNum<<endl;
		cout<<"Port Type: "<<valid_portType<<endl;
		cout<<"\n=========List End=========\n";
	}

};



string trimfnc(string str) {
const char* typeOfWhitespaces = " \t\n\r\f\v";
str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
str.erase(0,str.find_first_not_of(typeOfWhitespaces));
cout<<str<<endl;
return str;
}


// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}


void sepWords(char *line, vector<string>&vs)
{
		vector<string>vtemp;
		string bs=" ";
		
		char *tokens = strtok(line,",");
		
		while(tokens != NULL)
		{
			
			
			string t = tokens;
			
			trim(t);

			vs.push_back(t);
			
			tokens = strtok(NULL,",");
			
		}
		
}

int validateAll(vector<PLists>&vpl)
{
	int count=0;
	int flag=0;
	vector <PLists> :: iterator it = vpl.begin();
	string s1("tcp");
	string s2("TCP");
	string s3("udp");
	string s4("UDP");
	while(it!= vpl.end())
	{
		//invalid port type code
		
		if((s1.compare(it->getPType()) == 0) || (s2.compare(it->getPType()) == 0) || (s3.compare(it->getPType()) == 0) || (s4.compare(it->getPType()) == 0))
		{
				
				it->setVpt('V');
				flag++;
				
		}
		else
		{
				
				it->setVpt('I');
				flag--;
				it++;
				continue;
				
		}
		//invalid port number code
		if(it->getPno() < 0 || it->getPno() > 65535)
		{
			it->setVpno('I');
			flag--;
			it++;
			continue;
		}
		else
			{
				flag++;
			}
		
		if(flag > 0)
			count++;
		it++;
	}

	
	return count;
}

void dispInErrData(vector<PLists>&vpl)
{
	string s1 = "Input error in line ";
	string s2 = " Invalid port number ";
	string s3 = " Invalid port type ";
	vector <PLists> :: iterator it = vpl.begin();
	while(it!= vpl.end())
	{
		if(it->getVpt() == 'I')
		{
			cout<<s1<<"\""<<it->getPName()<<","<<it->getPType()<<","<<it->getPno()<<"\"";
			cout<<s3<<"\""<<it->getPType()<<"\""<<endl;
			it++;
		}
		else if((it->getVpno() == 'I'))
		{
			cout<<s1<<"\""<<it->getPName()<<","<<it->getPType()<<","<<it->getPno()<<"\"";
			cout<<s2<<"\""<<it->getPno()<<"\""<<endl;
			it++;
		}
		
		else
			it++;
	}
}


void dispValidData(vector<PLists>&vpl)
{
	string s1 = "Protocol: ";
	string s2 = "Port: ";
	string s3 = " Well known ports";
	string s4 =" Registered Ports";
	string s5 = " Dynamic Ports";
	vector <PLists> :: iterator it = vpl.begin();
	
	while(it!= vpl.end())
	{
		if((it->getVpt() != 'I') || (it->getVpno() == 'I'))
		{
			if((it->getPno() > 0) && (it->getPno() < 1023))
			{
				//well known ports
				cout<<s1<<it->getPName()<<"\t"<<s2<<it->getPType()<<"\t";
				cout<<s2<<it->getPno()<<" "<<s3<<endl;
			}
			else if((it->getPno() > 1024) && (it->getPno() < 49151))
			{
				//Registered Ports

				cout<<s1<<it->getPName()<<"\t"<<s2<<it->getPType()<<"\t";
				cout<<s2<<it->getPno()<<" "<<s4<<endl;
			}
			else if((it->getPno() > 49152) && (it->getPno() < 65535))
			{
				//Dynamic Ports
				cout<<s1<<it->getPName()<<"\t"<<s2<<it->getPType()<<"\t";
				cout<<s2<<it->getPno()<<" "<<s5<<endl;
			}
			else
			{
				//nothing

			}

			
		}
		it++;
	}
}


int main()
{
	fstream fs;
	string lines;
	PLists pl;
	vector <PLists> vpl;
	vector <PLists> vvpl;
	vector <string> vs;
	int pno;
	string pt, pn;
	char vpno, vpt;
	
	fs.open("input.txt",ios::in);
	if(!fs)
	{
		cout<<"Unable to open the input file"<<endl;
		exit(0);
	}

	while(getline(fs,lines))
	{
		//cout<<lines<<endl;
		vs.clear();
		sepWords((char *)lines.c_str(), vs);
		
		vector <string> :: iterator it = vs.begin();
		int icount=0;
		while(it != vs.end()){
			if(icount == 0)
				pn = *it;
			else if(icount == 1)
				pt = *it;
			else
				pno = stoi(*it);

			it++;
			icount++;
		}
		pl.setValues(pno,pt,pn);
		vpl.push_back(pl);
		
	}
	fs.close();

	
	int count=validateAll(vpl);
	dispInErrData(vpl);
	cout<<"Total valid entries: "<<count<<endl;
	dispValidData(vpl);
	cout<<"UDP protocol entries:"<<endl;
	vector <PLists> :: iterator it1 = vpl.begin();
	string s1("udp");
	string s2("UDP");
	
	while(it1!= vpl.end())
	{
		if((s1.compare(it1->getPType()) == 0) || (s2.compare(it1->getPType()) == 0)) 
		{
			//cout<<it1->getVpt()<<"\t"<<it1->getVpno()<<"\t"<<endl;
			if((it1->getVpt() != 'I') && (it1->getVpno() != 'I')){
				cout<<it1->getVpt()<<"\t"<<it1->getVpt()<<"\t";
				cout<<it1->getPName()<<endl;

			}
		}
		it1++;
	}
	return 0;
}