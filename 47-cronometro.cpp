#include <iostream>

using namespace std;

class Cronometro{
    private:
        int horas, minutos, segundos;
    public:
        Cronometro();
        void printar();
        void incrementar();
        int getHoras();
        int getMinutos();
        int getSegundos();
        void setHoras(int);
        void setMinutos(int);
        void setSegundos(int);
};

Cronometro::Cronometro(){
    this->setHoras(0);
    this->setMinutos(0);
    this->setSegundos(0);
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

int main() {
    string tic;
    Cronometro *objCronometro = new Cronometro();
    while(cin >> tic){
        objCronometro->incrementar(); 
    }
    objCronometro->printar();
    return 0;
}