#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include<algorithm>


using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;




class Money
{
private:
	int m;
public:
	Money() : m(0){}
	void addMoney(int amt){
		for(int i=0;i<amt;i++)
			m=m+i;
	}

	int getMoney() { return m; }

};


int thFunc(){
	Money M;

	std::vector<std::thread> t;
	for(int i=0;i<3;i++)
	{
		t.push_back(std::thread(&Money::addMoney, &M, 2000));
	}

	for(int i=0;i<t.size();i++)
	{
		t.at(i).join();
	}

	return M.getMoney();
}


int main()
{
	//int Amt=0;

	for(int i=0;i<1000;i++)
	{
		auto startTime = high_resolution_clock::now();
	
		cout<<"Amount of "<<i<<" = "<<thFunc()<<endl;
		auto stopTime = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stopTime - startTime);
		cout<<"Seconds: "<<duration.count()/1000000<<endl;
		cout<<"microSeconds: "<<duration.count()<<endl;
	}

	return 0;
}