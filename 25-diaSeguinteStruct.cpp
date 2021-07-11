#include <iostream>

using namespace std;

struct tData{
	int dia, mes, ano;
};

struct tData proximoAno(struct tData data){
	data.dia  = 1;
	data.mes  = 1;
	data.ano += 1;
	return data;
}

struct tData proximoMes(struct tData data){
	if (data.mes < 12){
		data.dia  = 1;
		data.mes += 1;
		return data;
	} else {
		return proximoAno(data);
	}
}

struct tData proximoDia(struct tData data){
	if (data.mes == 1 or data.mes == 3 or data.mes == 5 or data.mes == 7 or data.mes == 8 or data.mes == 10 or data.mes == 12){
		if (data.dia < 31){
			data.dia += 1;
			return data;
		} else {
			return proximoMes(data);
		}
	}
	if (data.mes == 4 or data.mes == 6 or data.mes == 9 or data.mes == 11){
		if (data.dia < 30){
			data.dia += 1;
			return data;
		} else {
			return proximoMes(data);
		}
	}
	if (data.mes == 2){
		if (data.dia < 28 or (data.dia == 28 and (data.ano % 400 == 0 or (data.ano % 4 == 0 and data.ano % 100 != 0)))){
			data.dia += 1;
			return data;
		} else {
			return proximoMes(data);
		}
	}
	return data;
}

void printarData(struct tData data){
	cout << data.dia << " " << data.mes << " " << data.ano << endl;
}

int main(){
	struct tData data;
	cin >> data.dia >> data.mes >> data.ano;
	data = proximoDia(data);
	printarData(data);
	return 0;
}