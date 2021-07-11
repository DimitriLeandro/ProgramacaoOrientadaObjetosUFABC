#include <iostream>

using namespace std;

int main(){

	int anoAtual, anoNascimento, idade;
	string nome;
	cin >> anoAtual >> nome >> anoNascimento;
	idade = anoAtual - anoNascimento;
	cout << nome << ", voce completa " << idade << " anos de idade neste ano." << "\n";

	return 0;
}