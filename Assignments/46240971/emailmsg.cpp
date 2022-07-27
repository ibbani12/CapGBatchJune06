#include<iostream>    
#include<sys/msg.h> 
#include<sys/ipc.h> 
#include<sys/types.h> 
#define PERMS 0666
#define MAXBUF 1024                                                                                                                                                                              
using namespace std;
struct msg_buf{
	long msg_type;
	char ans;
};
typedef struct msg_buf msg; 
bool isChar(char c)  
{        
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));   
}    
bool isDigit(const char c)  

{       
	return (c >= '0' && c <= '9');  
}
bool is_valid(string email)  
{ 
	if (!isChar(email[0]))  
	{
		cout<<"invalid email is"<<endl;   
		return 0; 
	}   
	int At = -1, Dot = -1;   
	for (int i = 0;i < email.length(); i++)     
	{                          
		if (email[i] == '@')   
		{        
			At = i; 
		}              
		else if (email[i] == '.') 
		{       
			Dot = i;  
		}   
	}      
	
//If At or Dot is not present 
if (At == -1 || Dot == -1)                    
return 0;
//If Dot is present  before At 
if(At>Dot)

return 0;
//If Dot is present at the the end
return !(Dot >= (email.length() - 1)); 
}
int main() 
{
	msg m;  
	key_t key;
	int msgid;    
	key =ftok("myfile",101);      
	msgid=msgget(key,PERMS|IPC_CREAT);

		if(msgid<0) 
	{
		perror("msgget() error");
		exit(EXIT_FAILURE);
	}
        
	string email ="ramanir061@gmail.com";  
	bool ans = is_valid(email);    
	if (ans) 
	{

	  cout << email << " : "<< "valid:"<<"ramanir061@gmail.com"<< endl;

	}

	else
       	{ 

	cout<<email<<" :"<<"inavalid"<<endl; 
	
	}	
       msgrcv(msgid,&m,sizeof(m),1,0);      
       cout<<"\n Received data:"<<m.ans<<endl; 

     
	return 0;
}




