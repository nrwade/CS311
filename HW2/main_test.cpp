#include <iostream>
using namespace std;


int main() {
	
	cout << "IN Main\n";

	int a[5];

	for (int i=0; i<6; i++) {
		if (a[i] == NULL) {
			cout << "AI is null\n";
		}
		cout << a[i] << "\n";
	}


	return 0;
}