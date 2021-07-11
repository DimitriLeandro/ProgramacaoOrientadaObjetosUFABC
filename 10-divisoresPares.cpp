#include <iostream>

using namespace std;

int main(){

	int numero=0, qtdDivisores=0, i=0;

	cin >> numero;

	for (i=2; i<=numero; i+=2){
		if (numero % i == 0){
			qtdDivisores += 1;
		}
	}

	cout << qtdDivisores << endl;

	return 0;
}