#include<bits/stdc++.h>
using namespace std;
int main()
{
         vector<int> sortedarray = {6, 15, 21, 27, 39, 42};
         cout<<"The element to be found in the array is 21\n" ;
         if(binary_search(sortedarray.begin(), sortedarray.end(), 21))
               cout<<"The element is found";
         else
               cout<<"The element is not found";


                cout<<"\nThe element to be found in the array is 5\n" ;
                 if(binary_search(sortedarray.begin(), sortedarray.end(), 5))
                       cout<<"The element is found";
                 else
                        cout<<"The element is not found";
}
