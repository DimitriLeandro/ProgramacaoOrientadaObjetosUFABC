#include <iostream>

using namespace std;

struct tAno{
	int ano;
};

bool verificarBissexto(struct tAno ano){
	if (ano.ano % 400 == 0 or (ano.ano % 4 == 0 and ano.ano % 100 != 0)){
		return true;
	}
	return false;
}

int main(){

	int anoEntrada;
	struct tAno ano;

	cin >> anoEntrada;

	ano.ano = anoEntrada;

	if (verificarBissexto(ano)){
		cout << "ANO BISSEXTO" << endl;
	} else {
		cout << "ANO NAO BISSEXTO" << endl;
	}

	return 0;
}