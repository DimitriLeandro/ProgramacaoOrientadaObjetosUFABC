#include <iostream>

using namespace std;

int main(){

	int tamanhoVetor, numeroBase, qtdMaiorIgualBase=0, i=0;

	cin >> tamanhoVetor;

	int *vetor = new int[tamanhoVetor];

	for (i=0; i<tamanhoVetor; i++){
		cin >> vetor[i];
	}

	cin >> numeroBase;

	for (i=0; i<tamanhoVetor; i++){
		if (vetor[i] >= numeroBase){
			qtdMaiorIgualBase++;
		}
	}

	cout << qtdMaiorIgualBase << endl;	

	return 0;
}