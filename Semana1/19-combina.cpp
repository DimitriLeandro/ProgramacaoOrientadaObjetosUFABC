#include <iostream>

using namespace std;

int* lerVetor(int tamanho){

	int *vetor = new int[tamanho];

	for (int i=0; i<tamanho; i++){
		cin >> vetor[i];
	}

	return vetor;
}

void printarVetor(int *vetor, int tamanho){
	for (int i=0; i<tamanho; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}

int* combina(int *vetorA, int *vetorB, int tamanhoA, int tamanhoB){

	int i, *vetorC = new int[tamanhoA+tamanhoB];

	for (i=0; i<tamanhoA; i++){
		vetorC[i] = vetorA[i];
	}

	for (i=0; i<tamanhoB; i++){
		vetorC[tamanhoA+i] = vetorB[tamanhoB-i-1];
	}

	return vetorC;
}

int main(){

	int n, m;

	cin >> n >> m;

	int *v = lerVetor(n);
	int *w = lerVetor(m);
	int *z = combina(v, w, n, m);

	printarVetor(z, n+m);

	delete &v, &w, &z;

	return 0;
}