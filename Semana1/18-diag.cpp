#include <iostream>
#include <iomanip>

using namespace std;

int** gravarMatriz(int dimensionalidade){

	int **matriz = new int*[dimensionalidade];

	for (int i=0; i<dimensionalidade; i++){
		
		matriz[i] = new int[dimensionalidade];

		for (int j=0; j<dimensionalidade; j++){
			cin >> matriz[i][j];
		}
	}

	return matriz;
}

float metricaAbaixoDiagonal(int **matriz, int dimensionalidade, char operacao){

	float soma=0, qtd=0, metrica=0;

	for (int i=1; i<dimensionalidade; i++){
		for (int j=0; j<i; j++){
			qtd++;
			soma += matriz[i][j];
		}
	}

	if (operacao == 'S'){
		metrica = soma;
	} else {
		metrica = soma/qtd;
	}

	return metrica;
}

int main(){

	char operacao;
	int dimensionalidade;
	float metrica;

	cin >> operacao;
	cin >> dimensionalidade;

	int **matriz = gravarMatriz(dimensionalidade);

	metrica = metricaAbaixoDiagonal(matriz, dimensionalidade, operacao);

	cout << fixed << setprecision(1) << metrica << endl;

	return 0;
}