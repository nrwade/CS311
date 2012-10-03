#include <iostream>
using namespace std;

//#include "ksarray2.h"

#include "KSArray3.h"

int main() {
	
	cout << "HELL OWORD\n";
	
	KSArray<int> ia = KSArray<int>(); 

	KSArray<int> ia2 = KSArray<int>(2); 

	KSArray<char> ia3 = KSArray<char>('a'); 

	KSArray<double> ia4 = KSArray<double>(5.6, 4);

	KSArray<char> ia5 = KSArray<char>('l', 4);

	cout<< "the size of array ia5 is "<<ia5.size() << endl;

	cout<< "the first element of ia5 is " << *ia5.begin() <<endl;

	


	return 0;
}