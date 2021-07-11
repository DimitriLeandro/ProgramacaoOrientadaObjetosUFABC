#include <iostream>

using namespace std;

int** gravarMatriz(int n, int m){
	
	int **matriz = new int*[n];
	
	for (int i=0; i<n; i++){
		
		matriz[i] = new int[m];
		
		for (int j=0; j<m; j++){
			cin >> matriz[i][j];
		}
	}
	
	return matriz;
}

int** transporMatriz(int **matriz, int n, int m){

	int **transposta = new int*[m];

	for (int i=0; i<m; i++){

		transposta[i] = new int[n];

		for (int j=0; j<n; j++){
			transposta[i][j] = matriz[j][i];
		}
	}

	return transposta;

}

void printarMatriz(int **matriz, int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){

	int n, m;

	cin >> n >> m;

	int **matriz = gravarMatriz(n, m);
	int **transposta = transporMatriz(matriz, n, m); 

	printarMatriz(transposta, m, n);
}