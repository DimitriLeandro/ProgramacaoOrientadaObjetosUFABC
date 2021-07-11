#include <iostream>

using namespace std;

class Data{
    private:
        int dia, mes, ano;
    public:
        Data(int, int, int);
        Data* operator + (int);
        bool isBissexto();
        bool isValida();
        void diaSeguinte();
        void printarData();
        int getDia();
        int getMes();
        int getAno();
        void setDia(int);
        void setMes(int);
        void setAno(int);        
};

Data::Data(int d, int m, int a){
    this->setDia(d);
    this->setMes(m);
    this->setAno(a);
}

Data* Data::operator + (int qtdDias){
    Data *novaData = this;
    for(int i=0; i<qtdDias; i++){
        novaData->diaSeguinte();
    }
    return novaData;
}

bool Data::isBissexto(){
    if (this->getAno() % 400 == 0 or (this->getAno() % 4 == 0 and this->getAno() % 100 != 0)){
		return true;
	} else {
		return false;
	}
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

void Data::diaSeguinte(){
    Data *novaData = new Data(this->getDia()+1, this->getMes(), this->getAno());
    if(!novaData->isValida()){
        novaData->setDia(1);
        novaData->setMes(this->getMes()+1);
        novaData->setAno(this->getAno());
        if(!novaData->isValida()){
            novaData->setDia(1);
            novaData->setMes(1);
            novaData->setAno(this->getAno()+1);
        }
    }
    this->setDia(novaData->getDia());
    this->setMes(novaData->getMes());
    this->setAno(novaData->getAno());
}

void Data::printarData(){
	cout << this->getDia() << " " << this->getMes() << " " << this->getAno() << endl;
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
    this->dia = dia;
}
void Data::setMes(int mes){
    this->mes = mes;
}
void Data::setAno(int ano){
    this->ano = ano;
}

int main() {
    int dia, mes , ano, qtdDiasAMais;
    Data *objData;
    while(cin >> dia >> mes >> ano >> qtdDiasAMais){
    	objData = new Data(dia, mes, ano);
        objData = *objData + qtdDiasAMais;
        objData->printarData();
    }
    return 0;
}