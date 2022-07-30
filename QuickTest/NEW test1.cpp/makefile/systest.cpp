#include <iostream>
#include <unistd.h>
using namespace std;
 
int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sumOdd = 0, sumEven = 0, n, i;
    n = fork();
 
   
    if (n > 0) {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 == 0)
                sumEven = sumEven + a[i];
        }
        cout << "Parent process \n";
        cout << "Sum of even no. is " << sumEven << endl;
    }
 
    
    else {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 != 0)
                sumOdd = sumOdd + a[i];
        }
        cout << "Child process \n";
        cout << "\nSum of odd no. is " << sumOdd << endl;
    }
    return 0;
}
