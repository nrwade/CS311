// testing main

#include "birthday.h"

#include <iostream>
using namespace std; 

int main()
{
	Birthday dflt;

	Birthday mine("nicole wade", 9, 4);

	cout<< "default values in toString " << dflt.toString()<< endl;
	cout << "my values in toString " << mine.toString() << endl;



	return 0;
}