#include <iostream>
using namespace std;

//#include "ksarray2.h"

#include "ksarray.h"

int main() {
	
	cout << "HELL OWORD\n";

	const int theSize=1000;
	const double val = -3.2;

    KSArray<double> tad(theSize, val);
	
	//KSArray<int> ia = KSArray<int>(); 

	//KSArray<int> ia2 = KSArray<int>(2); 

	/*KSArray<char> ia3 = KSArray<char>('a'); 

	KSArray<double> ia4 = KSArray<double>(5.6, 4);
	KSArray<double> ia7 = KSArray<double>(5.2, 4);

	KSArray<char> ia5 = KSArray<char>('l', 4);

	KSArray<int> ia6 = KSArray<int>();

	KSArray<char> ia8 = KSArray<char>('a', 4);
	KSArray<char> ia9 = KSArray<char>('b', 5);

	 KSArray<int> ia(10);          // array of 10 ints
  KSArray<int> iax;             // another array of 10 ints
  KSArray<double> da(40, 3.2);  // array of 40 doubles, each of which is set to 3.2
  //KSArray x(10);                // WILL NOT COMPILE; no template parameter
  
  // Set all items (counter loop)
  for (int c = 0; c < ia.size(); ++c)
  {
      ia[c] = c * c;
  }
  
  // Print all items (iterator loop)
  const int * iter;
  for (iter = ia.begin(); iter != ia.end(); ++iter)
  {
      cout << "Item :" << *iter << endl;
  }
  
  const KSArray<int> ia2(ia);   // Copy constructor
  if (ia2 == ia)                // Condition should be true
      cout << "Equal!" << endl;
  
  KSArray<double> da2;
  da2 = da;                     // Copy assignment
  //da2 = ia;                     // WILL NOT COMPILE; different types
  
  //if (da == ia)                 // WILL NOT COMPILE; different types
     // cout << "ZZZ" << endl; */


	/*cout << "ia8 " << ia8.size() << " " << *ia8.begin() << endl;
	cout << "ia9 " << ia9.size() << " " << *ia9.begin() << endl;
	ia8= ia9;

	cout << "ia8 has been set to ia 9 \n";
	cout << "ia8 " << ia8.size() << " " << *ia8.begin() << endl;
	cout << "ia9 " << ia9.size() << " " << *ia9.begin() << endl;*/

	/*int x=4;
	int y=5;
	cout << "x= " << x << endl;
	cout << "y= " << y << endl;

	x=y;
	cout << "x= " << x << endl;
	cout << "y= " << y << endl;*/

	/*KSArray<char> ia9 = KSArray<char>('b', 5);
	KSArray<char> ia10 = KSArray<char>('b', 5);

	cout << "ia9 " << ia9.size() << " "<< *ia9.begin()<< endl;
	cout << "ia10 " << ia10.size() << " " << *ia10.begin() << endl;

	if (ia10 == ia9)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fuuuuck" << endl;
	}*/

	KSArray<int> tai1(theSize);
    for (int i = 0; i < theSize; ++i)
        tai1[i] = 15 - i * i;
    const KSArray<int> & tai1Ref = tai1;
    KSArray<int> tai1Copy(tai1Ref);

    if (tai1==tai1Copy)
    	cout << "they are equal" << endl;
    else
    	cout << "not working\n";

     if (!(tai1!=tai1Copy))
    	cout << "they are equal" << endl;
    else
    	cout << "not working\n";

	/*cout<< "the size of array ia5 is "<<ia5.size() << endl;

	cout<< "the first element of ia5 is " << *ia5.begin() <<endl;

	cout<< "the location of one past the end of ia5 is " << ia5.end() << endl;*/

	//cout << "the second element in ia5 is " << ia5[1] << endl;
	/*cout << "size of ia " << ia.size() << endl;
	cout << "size of ia6 " << ia6.size()<< endl;
	cout << "size of ia4 " << ia4.size()<<endl;*/
	/*if (ia9>=ia8)
	{
		cout << "ia9 >= ia8" << endl;
	}

	else 
	{
		cout << "ia9 !>= ia8" << endl;
	}*/

	return 0;
}