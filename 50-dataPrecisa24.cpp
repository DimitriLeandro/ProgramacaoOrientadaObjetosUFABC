#include <iostream>

using namespace std;

class Cronometro{
    private:
        int horas, minutos, segundos;
    public:
        Cronometro(int, int, int);
        void printar();
        void incrementar();
        int getHoras();
        int getMinutos();
        int getSegundos();
        void setHoras(int);
        void setMinutos(int);
        void setSegundos(int);
};

Cronometro::Cronometro(int segundos, int minutos, int horas){
    this->setSegundos(segundos);
    this->setMinutos(minutos);
    this->setHoras(horas);
}

void Cronometro::printar(){
    cout << this->getHoras() << ":" << this->getMinutos() << ":" << this->getSegundos() << endl;
}

void Cronometro::incrementar(){
    this->setSegundos(this->getSegundos() + 1);
    if(this->getSegundos() == 60){
        this->setSegundos(0);
        this->setMinutos(this->getMinutos() + 1);
    }
    if(this->getMinutos() == 60){
        this->setMinutos(0);
        this->setHoras(this->getHoras() + 1);
    }
    if(this->getHoras() == 24){
        this->setHoras(0);
    }
}

int Cronometro::getHoras(){
    return this->horas;
}

int Cronometro::getMinutos(){
    return this->minutos;
}

int Cronometro::getSegundos(){
    return this->segundos;
}

void Cronometro::setHoras(int horas){
    this->horas = horas;
}

void Cronometro::setMinutos(int minutos){
    this->minutos = minutos;
}

void Cronometro::setSegundos(int segundos){
    this->segundos = segundos;
}

class Data{
    private:
        int dia, mes, ano;
    public:
        Data(int, int, int);
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

Data::Data(int dia, int mes, int ano){
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
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

class DataPrecisa: Data, Cronometro{
    public:
        DataPrecisa(int, int, int, int, int, int);
        void printar();
        void incrementar();
};

DataPrecisa::DataPrecisa(int dia, int mes, int ano, int segundos, int minutos, int horas): Data(dia, mes, ano), Cronometro(segundos, minutos, horas){}

void DataPrecisa::printar(){
    cout << this->getDia() << "/" << this->getMes() << "/" << this->getAno() << " " << this->getHoras() << ":" << this->getMinutos() << ":" << this->getSegundos() << endl;
}

void DataPrecisa::incrementar(){
    int horaAnterior = this->getHoras();
    this->Cronometro::incrementar();
    if(horaAnterior == 23 and this->getHoras() == 0){
        this->Data::diaSeguinte();
    }
}

int main() {
    int dia, mes, ano, horas, minutos, segundos;
    char operacao;
    cin >> dia >> mes >> ano >> horas >> minutos >> segundos;
    DataPrecisa *objDataPrecisa = new DataPrecisa(dia, mes, ano, segundos, minutos, horas);
    while(cin >> operacao){
        objDataPrecisa->incrementar();
    }
    objDataPrecisa->printar();
    return 0;
}