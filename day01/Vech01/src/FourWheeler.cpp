#include <FourWheeler.h>
#include <iostream>
using namespace std;

int FourWheeler::getWeight() { return weight; }
string FourWheeler::getTypeFW() { return typeFW; }
void FourWheeler::display()
{
	cout<<"\nFour Wheeler Type: "<<typeFW;
	cout<<"\nNo of Wheels: "<<getWheels()<<endl;
}
