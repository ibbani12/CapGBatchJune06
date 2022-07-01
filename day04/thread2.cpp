//introduction to mutex - lock_guard

#include <iostream>
#include<vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class Bank
{
    int m;
    std::mutex mu;
public:
    Bank() :m(0){}
    int getMoney() { return m; }
    void addMoney(int x)
    {
      
      std::lock_guard<std::mutex> LG_01(mu);
      
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
   
   for(int i = 0; i < 10; ++i){
         
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
      
     if((val = testMultithreadedBank()) != 10000)
     {
       std::cout << "Error at count = "<<k<<" Money in Bank = "<<val << std::endl;
     }
   
  }
  return 0;
}