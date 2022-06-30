#include <iostream>
#include<vector>
#include <string>
#include <thread>

using namespace std;

class Bank
{
    int m;
public:
    Bank() :m(0){}
    int getMoney() { return m; }
    void addMoney(int x)
    {
       for(int i = 0; i < x; ++i)
       {
          m++;
       }
    }
};

int testMultithreadedBank()
{
   Bank BankObj;
   std::vector<std::thread> threads;
   for(int i = 0; i < 7; ++i){

        threads.push_back(std::thread(&Bank::addMoney, &BankObj, 1000));
   }
   
   for(int i = 0; i < threads.size() ; i++)
   {
       threads.at(i).join();
   }
   
   return BankObj.getMoney();
}


int main()
{
  int val = 0;
  for(int k = 0; k < 10000; k++)
  {
     if((val = testMultithreadedBank()) != 7000)
     {
       std::cout << "Error at count = "<<k<<" Money in Bank = "<<val << std::endl;
     }
  }
  return 0;
}