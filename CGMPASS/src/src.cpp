#include<header.h>

int main(int argc, char* argv[])
{
	fstream fs;
	int pid;
	string buff=argv[1];
	string fpath = PATH;
	fpath +=buff;
	pid =fork();
	if(pid ==0){
		cout<<"child process ID :"<<getpid()<<endl;
		cout<<"enter the lines into the file"<<endl;
		vector<string>lines;
		string line;
		for(int i=0;i<2;i++){
			getline(cin,line);
			lines.push_back(line);
		}
		fstream fs;
		fs.open(fpath,ios::in | ios::out |ios::binary);
		if(!fs)
		{
			cout<<"unable to open the file"<<endl;
			exit(0);
		}
		size_t size = line.size();
		fs.write(reinterpret_cast<const char*>(&lines), size*sizeof(string));

                fs.close();
	}
	else if(WIFEXITED(status)){

		wait(int *);
		cout<<"parent process ID"<<getpid()<<endl;
		string thline;
		fstream f;
		f.open(fpath,ios::in |ios::out|ios::binary);
		if(!f)
		{
			cout<<"unable to open this file"<<endl;
			exit(0);
		}
		size_t sizes = line.size;
		f.read(reinterpret_cast<char*>(&line),sizes*sizeof(string));

		f.close();
	}
	else
		return 0;
}