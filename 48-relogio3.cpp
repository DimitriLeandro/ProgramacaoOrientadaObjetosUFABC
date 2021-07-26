#include <iostream>

using namespace std;

class Cronometro{
    private:
        int horas, minutos, segundos;
    public:
        Cronometro();
        Cronometro(int, int, int);
        void printar();
        void incrementar(char);
        void ajustar();
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

Cronometro::Cronometro(int segundos, int minutos, int horas){
    this->setSegundos(segundos);
    this->setMinutos(minutos);
    this->setHoras(horas);
}

void Cronometro::printar(){
    cout << this->getHoras() << ":" << this->getMinutos() << ":" << this->getSegundos() << endl;
}

void Cronometro::incrementar(char charOperacao){
    switch (charOperacao){
        case 'i':
            this->setSegundos(this->getSegundos() + 1);
            break;
        case 'a':
            this->setMinutos(this->getMinutos() + 1);
            break;
        case 'o':
            this->setHoras(this->getHoras() + 1);
            break;
    }
    this->ajustar();
}

void Cronometro::ajustar(){
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
    int horas, minutos, segundos;
    cin >> horas >> minutos >> segundos;
    string strOperacao;
    Cronometro *objCronometro = new Cronometro(segundos, minutos, horas);
    while(cin >> strOperacao){
        objCronometro->incrementar(strOperacao[1]); 
    }
    objCronometro->printar();
    return 0;
}