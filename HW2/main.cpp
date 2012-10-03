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

	KSArray<int> ia6 = KSArray<int>();

	/*cout<< "the size of array ia5 is "<<ia5.size() << endl;

	cout<< "the first element of ia5 is " << *ia5.begin() <<endl;

	cout<< "the location of one past the end of ia5 is " << ia5.end() << endl;*/

	//cout << "the second element in ia5 is " << ia5[1] << endl;
	/*cout << "size of ia " << ia.size() << endl;
	cout << "size of ia6 " << ia6.size()<< endl;
	cout << "size of ia4 " << ia4.size()<<endl;*/
	if (ia6==ia2)
	{
		cout << "they are equal" << endl;
	}

	else 
	{
		cout << "not equal" << endl;
	}

	return 0;
}