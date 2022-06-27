#pragma once
#include <Vechicle.h>
#include <string>

using namespace std;

class FourWheeler : public Vech
{
protected:
	string typeFW;
	int weight;
public:
	FourWheeler(){}
	FourWheeler(int w, string f, string e, string tFW, int wt) : Vech(w,f,e) {
		typeFW = tFW;
		weight = wt;
	 }

	 int getWeight();
	 string getTypeFW();

	 void display();
};


