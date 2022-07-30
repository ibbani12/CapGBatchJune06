#include "Emp.h"
#include<iostream>
#include<fstream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<cstring>
#include<string>
int main()
{
        int n;
        fstream a;
        cout<<"\nEnter how many employees:";
        cin>>n;
        Emp *E=new Emp[n];
        int pno;
        pno = fork();
        if(pno==0)
        {
                cout<<"child starts"<<endl;
                a.open("Emp.txt",ios::out);
                if(!a)
                {
                        cout<<"I can't open the file"<<endl;
                        exit(0);
                }
                for(int i=0;i<n;i++)
                {
E[i].getEmpDetails();
                        a.weite(reinterpret_cast<char *>(&E[i]),sizeof(Emp));
                }
                a.close();
                cout<<child terminates"<<endl;
        }
        else
        {
                wait((int *)0);
                cout<<"parent starts"<<endl;
                a.open("Emp.txt",ios::in);
                if(!a)
                {
                        cout<<"\n I can't open the file"<<endl;
                        exit(0);
                }
                cout<<"\n print employee Details"<<endl;
                for(int i=0;i<n;i++)
                {
                        a.read(reinterpret_cast<char*>(&E[i]),sizeof(Emp));

                        E[i].display();
                }
                a.close();
                cout<<"parent terminates"<<endl;
        }
        reurn 0;
}
