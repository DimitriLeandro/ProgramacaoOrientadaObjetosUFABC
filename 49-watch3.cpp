#include <iostream>

using namespace std;

class Cronometro{
    private:
        int horas, minutos, segundos;
        char PM;
    public:
        Cronometro(int, int, int, char);
        void printar();
        void incrementar(char);
        void ajustar(int);
        int getHoras();
        int getMinutos();
        int getSegundos();
        char getPM();
        void setHoras(int);
        void setMinutos(int);
        void setSegundos(int);
        void setPM(char);
};

Cronometro::Cronometro(int segundos, int minutos, int horas, char PM){
    this->setSegundos(segundos);
    this->setMinutos(minutos);
    this->setHoras(horas);
    this->setPM(PM);
}

void Cronometro::printar(){
    cout << this->getHoras() << ":" << this->getMinutos() << ":" << this->getSegundos() << " " << this->getPM() << "M" << endl;
}

void Cronometro::incrementar(char charOperacao){
    int horaAnterior = this->getHoras();
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
    this->ajustar(horaAnterior);
}

void Cronometro::ajustar(int horaAnterior){
    if(this->getSegundos() == 60){
        this->setSegundos(0);
        this->setMinutos(this->getMinutos() + 1);
    }
    if(this->getMinutos() == 60){
        this->setMinutos(0);
        this->setHoras(this->getHoras() + 1);
    }
    if(this->getHoras() == 12 and horaAnterior == 11){
        if (this->getPM() == 'A'){
            this->setPM('P');
        } else {
            this->setPM('A');
        }
    }
    if(this->getHoras() == 13){
        this->setHoras(1);
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

char Cronometro::getPM(){
    return this->PM;
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

void Cronometro::setPM(char PM){
    this->PM = PM;
}

int main() {
    int horas, minutos, segundos;
    string strOperacao, PM;
    cin >> horas >> minutos >> segundos >> PM;
    Cronometro *objCronometro = new Cronometro(segundos, minutos, horas, PM[0]);
    while(cin >> strOperacao){
        objCronometro->incrementar(strOperacao[1]); 
    }
    objCronometro->printar();
    return 0;
}