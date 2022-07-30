#ifndef DATE_H
#define DATE_H

#include <string.h>
using namespace std;

class Date {
    private: 
          int day, month, year;    // instance variable
    public:
          Date();
          Date(int d);
          Date(int d, int m, int y);
          int getYear();
          void setDate(int day, int month, int year);
          void getDate();
          string getMonthName();
          bool checkLeapYear();
};

#endif
Footer
© 2022 GitHub, Inc.