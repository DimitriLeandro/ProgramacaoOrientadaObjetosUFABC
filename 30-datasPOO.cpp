#include <iostream>

using namespace std;

class Data{
	private:
		int dia, mes, ano;
	public:
		Data(int, int, int);
		bool isValida();
		bool isBissexto();
		int getDia();
		int getMes();
		int getAno();
		void setDia(int);
		void setMes(int);
		void setAno(int);
};

Data::Data(int dia, int mes, int ano){
	this->setDia(dia);
	this->setMes(mes);
	this->setAno(ano);	
}

bool Data::isValida(){
	if (this->getDia() >= 1 and this->getDia() <= 31 and (this->getMes() == 1 or this->getMes() == 3 or this->getMes() == 5 or this->getMes() == 7 or this->getMes() == 8 or this->getMes() == 10 or this->getMes() == 12)){
		return true;
	}
	if (this->getDia() >= 1 and this->getDia() <= 30 and (this->getMes() == 4 or this->getMes() == 6 or this->getMes() == 9 or this->getMes() == 11)){
		return true;
	}
	if (this->getDia() >= 1 and this->getDia() <= 29 and this->getMes() == 2){
		if (this->getDia() <= 28){
			return true;
		} else {
			if (this->isBissexto()){
				return true;
			}
		}		
	}
	return false;
}

bool Data::isBissexto(){
	if (this->getAno() % 400 == 0 or (this->getAno() % 4 == 0 and this->getAno() % 100 != 0)){
		return true;
	} else {
		return false;
	}
}

int Data::getDia(){
	return this->dia;
}

int Data::getMes(){
	return this->mes;
}

int Data::getAno(){
	return this->ano;
}

void Data::setDia(int dia){
	this->dia= dia;
}

void Data::setMes(int mes){
	this->mes= mes;
}

void Data::setAno(int ano){
	this->ano= ano;
}

int main(){

	int n, i, dia, mes, ano;
	Data *objData;

	cin >> n;

	for (i=0; i<n; i++){
		cin >> dia >> mes >> ano;
		objData = new Data(dia, mes, ano);
		if (objData->isValida()){
			cout << "DATA VALIDA" << endl;
		} else {
			cout << "DATA INVALIDA" << endl;
		}
	}

	return 0;
}