#include <iostream>

using namespace std;

class DataJuliana{
    private:
        int diaJuliano;
    public:
        DataJuliana();
        DataJuliana(int);
        int getDiaJuliano();
        void setDiaJuliano(int);
};

DataJuliana::DataJuliana(){
    this->setDiaJuliano(1);
}

DataJuliana::DataJuliana(int diaJuliano){
    this->setDiaJuliano(diaJuliano);
}

int DataJuliana::getDiaJuliano(){
    return this->diaJuliano;
}

void DataJuliana::setDiaJuliano(int diaJuliano){
    this->diaJuliano = diaJuliano;
}

class DataGregoriana{
    private:
        int dia, mes, ano;
    public:
        DataGregoriana();
        DataGregoriana(int, int, int);
        DataGregoriana(DataJuliana);
        void setDia(int);
        void setMes(int);
        void setAno(int);
        int getDia();
        int getMes();
        int getAno();
        operator DataJuliana();
};

DataGregoriana::DataGregoriana(){
    this->setDia(1);
    this->setMes(1);
    this->setAno(1);
}

DataGregoriana::DataGregoriana(int dia, int mes, int ano){
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
}

int DataGregoriana::getDia(){
    return this->dia;
}

int DataGregoriana::getMes(){
    return this->mes;
}
                
int DataGregoriana::getAno(){
    return this->ano;
}

void DataGregoriana::setDia(int dia){
    this->dia = dia;
}

void DataGregoriana::setMes(int mes){
    this->mes = mes;
}

void DataGregoriana::setAno(int ano){
    this->ano = ano;
}

DataGregoriana::operator DataJuliana(){
    int a, b, c, d, e, diaJuliano;
    if(this->getMes() < 3) {
        this->setAno(this->getAno() - 1);
        this->setMes(this->getMes() + 12);
    }
    a = this->getAno() / 100;
    b = a / 4;
    c = 2 - a + b;
    d = 365.25 * (this->getAno() + 4716);
    e = 30.6001 * (this->getMes() + 1);
    diaJuliano = d + e + this->getDia() + 0.5 + c - 1524.5;
    return DataJuliana(diaJuliano);
}

DataGregoriana::DataGregoriana(DataJuliana dataJuliana){
    int jd, q, z, w, x, a, b, c, d, e, f;
    jd = dataJuliana.getDiaJuliano();
    q = jd + 0.5;
    z = q;
    w = (z - 1867216.25) / 36524.25;
    x = w / 4;
    a = z + 1 + w - x;
    b = a + 1524;
    c = (b - 122.1) / 365.25;
    d = 365.25 * c;
    e = (b - d) / 30.6001;
    f = 30.6001 * e;
    this->setDia(b- d - f + (q - z));
    this->setMes(e<14 ? e-1 : e-13);
    this->setAno(mes<3 ? c-4715 : c-4716);
}

int main(){
    DataGregoriana dataGregoriana;
    int dia, mes, ano;
    while(cin >> dia >> mes >> ano){
        dataGregoriana.setDia(dia);
        dataGregoriana.setMes(mes);
        dataGregoriana.setAno(ano);
        DataJuliana dataJuliana = dataGregoriana;
        cout << dataJuliana.getDiaJuliano() << endl;
    }
    return 0;
}
