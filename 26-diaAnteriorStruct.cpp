#include <iostream>

using namespace std;

struct tData{
	int dia, mes, ano;
};

int ultimoDiaDoMes(int mes, int ano){
	int ultimoDiaDoMes = 31;
	if (mes == 4 or mes == 6 or mes == 9 or mes == 11){
		ultimoDiaDoMes -= 1;
	}
	if (mes == 2){
		ultimoDiaDoMes -= 2;
		if (not (ano % 400 == 0 or (ano % 4 == 0 and ano % 100 != 0))){
			ultimoDiaDoMes -= 1;
		}
	}
	return ultimoDiaDoMes;
}

struct tData anoAnterior(struct tData data){
	data.dia  = 31;
	data.mes  = 12;
	data.ano -= 1;
	return data;
}

struct tData mesAnterior(struct tData data){
	if (data.mes > 1){
		data.mes -= 1;
		data.dia  = ultimoDiaDoMes(data.mes, data.ano);
		return data;
	} else {
		return anoAnterior(data);
	}
}

struct tData diaAnterior(struct tData data){
	if (data.dia > 1){
		data.dia -= 1;
		return data;
	} else {
		return mesAnterior(data);
	}
}

void printarData(struct tData data){
	cout << data.dia << " " << data.mes << " " << data.ano << endl;
}

int main(){
	struct tData data;
	cin >> data.dia >> data.mes >> data.ano;
	data = diaAnterior(data);
	printarData(data);
	return 0;
}