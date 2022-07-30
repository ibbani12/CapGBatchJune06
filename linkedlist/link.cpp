#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
        char ch;
        string str;
        list<string> ll;
        list<string>::iterator itr=ll.begin();
        do
        {
                cout<<"\n Enter string"<<endl;
                getline(cin,str);
                ll.insert(itr,str);
                itr++;
                cout<<"\n Do you want to continue(y or n)"<<endl;
                cin>>ch;
                cin.get();
        }while(ch !='n');

        itr=ll.begin();
        cout<<"List contents are...\n";
        while(itr !=ll.end())
        {
                cout<<"\n"<<*itr++;
        }
}