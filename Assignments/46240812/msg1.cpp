#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string>
#include <cstring>

#define PERMS 0666
#define MAXBUF 10

using namespace std;
class Email
{
    private:
    string Name;
    string domain;
    char specialcharacter;
    public:
    Email(){}
    Email(string n,string dname,char s){Name=n;domain=dname;specialcharacter=s;}
    
    string getName(){return Name;}
    string getdomain(){return domain;}
    char getspecialcharacter(){return specialcharacter;}
    void Display(){
    cout<<"Name"<<Name<<endl;
    cout<<"Symbol"<<specialcharacter<<endl;
    cout<<"Domain"<<domain<<endl;
    }
};
   
      //  Email E("user 1",'@',"abc.com");
       // E.Display();

    

    
    struct msg_buf
    {
        long mesg_type;
        char mesg_txt[100];
    }message;
    
    typedef struct msg_buf MSG;
    
    int main()
    {
        MSG m;
        key_t key;
        int msgid;
        key=ftok("file", 65);
        msgid = msgget(key, 0666 | IPC_CREAT);
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        cout<<"valid Emailid is"<<E.Display();
        msgctl(msgid, IPC_RMID, NULL);
        return 0;
    }
