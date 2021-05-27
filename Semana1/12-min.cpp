#include <iostream>

using namespace std;

int main(){

	long numero, minimo;

	cin >> numero;
	minimo = numero;

	while (numero >= 0){
		if (numero < minimo){
			minimo = numero;
		}
		cin >> numero;
	}

	if (minimo >= 0){
		cout << minimo << endl;
	} else {
		cout << "nenhum numero informado" << endl;
	}

	return 0;
}