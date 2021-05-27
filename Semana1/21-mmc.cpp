#include <iostream>

using namespace std;

int main(){

	int numA, numB, i, mmc;

	cin >> numA >> numB;

	for (i=numA; i<=numA*numB; i+=numA){
		if (i%numB == 0){
			mmc = i;
			break;
		}
	}

	cout << mmc << endl;

	return 0;
}