#include <iostream>

using namespace std;

int main(){

	int qtdNumeros, numero, i, soma=0;

	cin >> qtdNumeros;

	for (i=0; i<qtdNumeros; i++){
		cin >> numero;
		soma += numero;
	}

	cout << soma << endl;

	return 0;
}