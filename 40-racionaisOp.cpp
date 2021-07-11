#include <iostream>

using namespace std;

class Racional{
	private:
		int numerador;
		int denominador;

	public:
		Racional(int, int);
		Racional* operator + (Racional);
        Racional* operator - (Racional);
        Racional* operator * (Racional);
        Racional* operator / (Racional);
		void soma(Racional*);
		void subtracao(Racional*);
		void produto(Racional*);
		void quociente(Racional*);
        void negativo();
		void simplifica();
		void setNumerador(int);
		void setDenominador(int);
		int getNumerador();
		int getDenominador(); 
};

Racional::Racional(int numerador, int denominador){
	this->setNumerador(numerador);
	this->setDenominador(denominador);
}

Racional* Racional::operator + (Racional racionalB){
	Racional *resultado = new Racional(this->getNumerador(), this->getDenominador());
	resultado->soma(&racionalB);
	return resultado;
}

Racional* Racional::operator - (Racional racionalB){
	Racional *resultado = new Racional(this->getNumerador(), this->getDenominador());
	resultado->subtracao(&racionalB);
	return resultado;
}

Racional* Racional::operator * (Racional racionalB){
	Racional *resultado = new Racional(this->getNumerador(), this->getDenominador());
	resultado->produto(&racionalB);
	return resultado;
}

Racional* Racional::operator / (Racional racionalB){
	Racional *resultado = new Racional(this->getNumerador(), this->getDenominador());
	resultado->quociente(&racionalB);
	return resultado;
}

void Racional::soma(Racional *racionalB){
	this->setNumerador(this->getNumerador()*racionalB->getDenominador() + racionalB->getNumerador()*this->getDenominador());
	this->setDenominador(this->getDenominador() * racionalB->getDenominador());
}

void Racional::subtracao(Racional *racionalB){
	racionalB->negativo();
	this->soma(racionalB);
}

void Racional::produto(Racional *racionalB){
	this->setNumerador(this->getNumerador() * racionalB->getNumerador());
	this->setDenominador(this->getDenominador() * racionalB->getDenominador());
}

void Racional::quociente(Racional *racionalB){
	int aux = racionalB->getNumerador();
	racionalB->setNumerador(racionalB->getDenominador());
	racionalB->setDenominador(aux);
	this->produto(racionalB);
}

void Racional::negativo(){
	this->setNumerador(-1 * this->getNumerador());
}

void Racional::simplifica(){
	int moduloDoDenominador = this->getDenominador();
	if (moduloDoDenominador < 0){
		moduloDoDenominador *= -1;
	}
	for (int i=2; i<=moduloDoDenominador; i++){
		if (this->getNumerador() % i == 0 and this->getDenominador() % i == 0){
			this->setNumerador(this->getNumerador()/i);
			this->setDenominador(this->getDenominador()/i);
			this->simplifica();
		}
	}
}

void Racional::setNumerador(int numerador){
	this->numerador = numerador;
}

void Racional::setDenominador(int denominador){
	this->denominador = denominador;
}

int Racional::getNumerador(){
	return this->numerador;
}

int Racional::getDenominador(){
	return this->denominador;
}

int main(){

	int numA, denA, numB, denB;
	char op;
	Racional *numeroRacionalA, *numeroRacionalB, *resultado;

	while (cin >> numA >> denA >> op >> numB >> denB){

		numeroRacionalA = new Racional(numA, denA);
		numeroRacionalB = new Racional(numB, denB);

		switch (op){
			case '+':
				resultado = *numeroRacionalA + *numeroRacionalB;
				break;
			case '-':
				resultado = *numeroRacionalA - *numeroRacionalB;
				break;
			case '*':
				resultado = *numeroRacionalA * *numeroRacionalB;
				break;
			case '/':
				resultado = *numeroRacionalA / *numeroRacionalB;
				break;
		}

		if (resultado->getDenominador() < 0){
			resultado->setNumerador(-1 * resultado->getNumerador());
			resultado->setDenominador(-1 * resultado->getDenominador());
		}

		resultado->simplifica();
		
		cout << resultado->getNumerador() << " " << resultado->getDenominador() << endl;
	}

	return 0;
}