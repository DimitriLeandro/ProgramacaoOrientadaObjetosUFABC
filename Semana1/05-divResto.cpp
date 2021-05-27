#include <iostream>

using namespace std;

int main(){

	long a, b, divisao, resto;
	
	cout << "Insira dois numeros separados por um espaco para fazer a divisao: ";
	cin >> a >> b;
	
	divisao = a/b;
	resto   = a%b;
	cout << divisao << " " << resto << "\n";

	return 0;
}