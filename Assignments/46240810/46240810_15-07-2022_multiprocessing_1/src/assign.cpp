#include "assign.h"


int main(int argc,char* argv[])


{     
	fstream f;
	argc= 2;
	
	string line1,line2;
	
	int p;
	p=fork();

        if(p==0)
	{    cout<<"this is the child process with PID: "<<getpid()<<endl;
		f.open(argv[1] ,ios::out);
				if(!f)
				
				{	
	                        	cout<<"unable to open the file"<<endl;
					exit(0);

				}

				else

				{

					cout<<"enter the content to be entered"<<endl;
					cout<<"Enter the data:"<<endl;
                                          cin>>line1;
					  cin>>line2;
					  f<<line1;
					  f<<line2;
					  f.close();
				}			
	
				cout<<"child prcocess ends"<<endl;
	}
	else
	{
		
		wait(0);
		
		cout<<"this is the parent process with PID"<<getpid()<<endl;

		f.open(argv[1] , ios::in);

		if(!f)

		{

			cout<<"unable to open the file"<<endl;
	        }
		 while (!f.eof())

		 {
			 char buf[500];

			 f.read(buf,500);

			 cout<<buf<<endl;

		 }
	

        	f.close();

		cout<<"parent process ends"<<endl;
	
	} 	
	return 0;
	}

