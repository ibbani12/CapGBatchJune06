#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(){
              day = 1;
              month = 1;
              year = 2001;
              cout << "\tDefault constructor called " << endl;
          };
Date::Date(int d){
              day = d;
              cout << "\tParameterised constructor 1 called " << endl;
          };
Date::Date(int d, int m, int y){
              day = d;
              month = m;
              year = y;
              cout << "\tParameterised constructor 2 called " << endl;
          }
int Date::getYear() {
              return year;
          }
void Date::setDate(int day, int month, int year) {
              cout << day << ":" << month << ":" << year << endl;
              this->day = day;
              this->month = month;
              this->year = year;
          }

void Date::getDate(){
              cout << day << "/" << month << "/" << year << endl;
          }

// TODO: Write C++ code to return name of month
// For month = 1 function returns "January", if month = 2 function returns "February" and so on ... 

string Date::getMonthName() {
int month;
string Months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
  
   cout << "Enter the month? (1-12)"<<endl;
   cin >>month;
   cout << "The month name is" << Months[month-1]<< "\n\n"; // subtract 1 from input, since arrays start at 0
  // return 0;
//}
      return "January";
        }

// TODO: Write C++ code to return true if year is leap year else return false
// year is leap year if it is divisible by 400 or 
// (it is divisible for 4 but not by 100)


bool Date::checkLeapYear() {
int y;
   cout<<"Enter year: ";
   cin>>y;
   //Calling function
   bool flag = y;
   if(flag == true)  
      cout<<y<<" is a leap Year"; 
   else 
      cout<<y<<" is not a leap Year";
   return 0;
}
bool leapYear(int y){
   bool isLeapYear = false;
   if (y % 4 == 0) {
      if (y % 100 == 0) {
         if (y % 400 == 0) {
            isLeapYear = true;
         }
      } 
      else isLeapYear = true;
   }
   return isLeapYear;
}