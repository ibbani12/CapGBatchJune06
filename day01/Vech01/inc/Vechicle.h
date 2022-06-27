#pragma once

#include <string>
using namespace std;
class Vech
{
protected:
	int wheels;
	string fuel;
	string engType;
public:
	Vech(){}
	Vech(int w, string f, string e){ wheels = w; fuel =f; engType = e; }
	int getWheels();
	string getFuelType();
	string getEngType();
};

