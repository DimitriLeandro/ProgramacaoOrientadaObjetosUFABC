#include <iostream>

using namespace std;

int main(){

	int tamanhoVetor, i, n;
	string saida;

	cin >> tamanhoVetor;

	int *vetor = new int[tamanhoVetor];

	for (i=0; i<tamanhoVetor; i++){
		cin >> vetor[i];
	}

	while (cin >> n){

		saida = "CHAVE NAO ENCONTRADA";

		for (i=0; i<tamanhoVetor; i++){
			if (vetor[i]==n){
				saida = "SIM";
				break;
			}
		}

		cout << saida << endl;
	}

	return 0;
}