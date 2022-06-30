#include <iostream>
#include <thread>

#include <chrono>
#include<algorithm>


using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

struct arg_struct {
    ull start;
    ull end;
};

ull OddSum =0;
ull EvenSum=0;

void *findEven(void *arguments)
{
	struct arg_struct *args =  (struct arg_struct *)arguments;
	cout<<"Entered Even Function"<<endl;
	for(ull i=args->start; i<=args->end;++i)
		{
			if((i&1)==0){
				EvenSum += i;
			}
		}
	cout<<"Exited Even Function"<<endl;
	return NULL;
}

void *findOdd(void *arguments)
{
	struct arg_struct *args =  (struct arg_struct *)arguments;
	cout<<"Entered Odd Function"<<endl;
	for(ull i=args->start; i<=args->end;++i)
		{
			if((i&1)==0){
				OddSum += i;
			}
		}
	cout<<"Exited Odd Function"<<endl;
	return NULL;
}


int main()
{

	ull start =0, end=1900000000;
	//pthread_t t1,t2;
	
	
	struct arg_struct args;

	// std::thread t1(findEven, (void *)&args);
	// std::thread t2(findOdd, (void *)&args);
    args.start = 0;
    args.end = 1900000000;

	// int err = pthread_create(&t1, NULL, &findEven, (void *)&args);
 //    // Check if thread is created sucessfuly
 //    if (err)
 //    {
 //        std::cout << "Thread creation failed : " << endl;
 //        return err;
 //    }
 //    else
 //        std::cout << "Thread Created with ID : " << t1 << std::endl;

 //    err = pthread_create(&t2, NULL, &findOdd, (void *)&args);
 //    // Check if thread is created sucessfuly
 //    if (err)
 //    {
 //        std::cout << "Thread creation failed : " << endl;
 //        return err;
 //    }
 //    else
 //        std::cout << "Thread Created with ID : " << t2 << std::endl;

	//pthread_create(&t1,NULL,&findOdd,start,end);
	auto startTime = high_resolution_clock::now();
	findOdd((void *)&args);
	findEven((void *)&args);
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
	// t1.join();
	// t2.join();

	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime - startTime);
	cout<<"Odd Sum: "<<OddSum<<endl;
	cout<<"Even Sum: "<<EvenSum<<endl;
	cout<<"Seconds: "<<duration.count()/1000000<<endl;

	// t1.detach();
	// t2.detach();

	return 0;
}