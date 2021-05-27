#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double altura, peso, imc;

	cin >> altura >> peso;

	imc = peso/pow(altura, 2);

	if (imc < 16.0){
		cout << "Magreza grave" << endl;
	}
	else if (imc >= 16.0 && imc < 17.0){
		cout << "Magreza moderada" << endl;
	}
	else if (imc >= 17.0 && imc < 18.5){
		cout << "Magreza leve" << endl;
	}
	else if (imc >= 18.5 && imc < 25.0){
		cout << "Saudavel" << endl;
	}
	else if (imc >= 25.0 && imc < 30.0){
		cout << "Sobrepeso" << endl;
	}
	else if (imc >= 30.0 && imc < 35.0){
		cout << "Obesidade Grau I" << endl;
	}
	else if (imc >= 35.0 && imc < 40.0){
		cout << "Obesidade Grau II (severa)" << endl;
	}
	else{
		cout << "Obesidade Grau III (morbida)" << endl;
	}

	return 0;
}