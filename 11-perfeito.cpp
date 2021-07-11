#include <iostream>

using namespace std;

int main(){

	int numero=0, somaDivisores=0, i=0;
	string saida="NAO";

	cin >> numero;

	for (i=1; i<numero; i++){
		if (numero % i == 0){
			somaDivisores += i;
		}
	}

	if (somaDivisores==numero){
		saida = "SIM";
	}

	cout << saida << endl;

	return 0;
}