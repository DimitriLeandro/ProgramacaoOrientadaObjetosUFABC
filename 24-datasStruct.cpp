#include <iostream>

using namespace std;

struct tData{
	int dia, mes, ano;
};

bool verificarData(struct tData data){
	
	bool valida = false;

	if (data.dia >= 1 and data.dia <= 31 and (data.mes == 1 or data.mes == 3 or data.mes == 5 or data.mes == 7 or data.mes == 8 or data.mes == 10 or data.mes == 12)){
		valida = true;
	}
	if (data.dia >= 1 and data.dia <= 30 and (data.mes == 4 or data.mes == 6 or data.mes == 9 or data.mes == 11)){
		valida = true;
	}
	if (data.dia >= 1 and data.dia <= 29 and data.mes == 2){
		if (data.dia <= 28){
			valida = true;
		} else {
			if (data.ano % 400 == 0 or (data.ano % 4 == 0 and data.ano % 100 != 0)){
				valida = true;
			}
		}		
	}

	return valida;
}

int main(){

	int n;

	cin >> n;

	struct tData *vetorDatas = new tData[n];

	for (int i=0; i<n; i++){
		cin >> vetorDatas[i].dia >> vetorDatas[i].mes >> vetorDatas[i].ano;
	}

	for (int i=0; i<n; i++){
		if (verificarData(vetorDatas[i])){
			cout << "DATA VALIDA" << endl;
		} else {
			cout << "DATA INVALIDA" << endl;
		}
	}

	return 0;
}