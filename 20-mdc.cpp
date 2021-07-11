#include <iostream>

using namespace std;

int main(){

	int numA, numB, i, mdc;

	cin >> numA >> numB;

	for (i=numA; i>=1; i--){
		if (numA%i == 0){
			if (numB%i == 0){
				mdc = i;
				break;
			}
		}
	}

	cout << mdc << endl;

	return 0;
}