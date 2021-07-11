#include <iostream>

using namespace std;

int** alocarMemoriaParaMatriz(int dimensionalidade){
	
	int **matriz = new int*[dimensionalidade];

	for (int i=0; i<dimensionalidade; i++){
		matriz[i] = new int[dimensionalidade];
	}

	return matriz;
}

int** somarMatrizes(int **matrizA, int **matrizB, int dimensionalidade){

	int **matrizSoma = new int*[dimensionalidade];

	for (int i=0; i<dimensionalidade; i++){

		matrizSoma[i] = new int[dimensionalidade];

		for (int j=0; j<dimensionalidade; j++){
			matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
		}
	}

	return matrizSoma;

}

void gravarMatriz(int **matriz, int dimensionalidade){
	for (int i=0; i<dimensionalidade; i++){
		for (int j=0; j<dimensionalidade; j++){
			cin >> matriz[i][j];
		}
	}
}

void printarMatriz(int **matriz, int dimensionalidade){
	for (int i=0; i<dimensionalidade; i++){
		for (int j=0; j<dimensionalidade; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){

	// OBTENDO A DIMENSIONALIDADE
	int dimensionalidade, i, j;
	cin >> dimensionalidade;

	// ALOCANDO MEMORIA PARA AS MATRIZES A E B
	int **matrizA = alocarMemoriaParaMatriz(dimensionalidade);
	int **matrizB = alocarMemoriaParaMatriz(dimensionalidade);
	
	// GRAVANDO OS VALORES DE A E B
	gravarMatriz(matrizA, dimensionalidade);
	gravarMatriz(matrizB, dimensionalidade);

	// SOMANDO A E B 
	int **matrizSoma = somarMatrizes(matrizA, matrizB, dimensionalidade);

	// PRINTANDO O RESULTADO
	printarMatriz(matrizSoma, dimensionalidade);

	return 0;
}