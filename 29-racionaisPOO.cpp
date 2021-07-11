#include <iostream>

using namespace std;

class Racional{
	private:
		int numerador;
		int denominador;

	public:
		Racional(int, int);
		void negativo();
		void soma(Racional*);
		void subtracao(Racional*);
		void produto(Racional*);
		void quociente(Racional*);
		void simplifica();
		void setNumerador(int);
		void setDenominador(int);
		int getNumerador();
		int getDenominador(); 
};

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

void Racional::negativo(){
	this->setNumerador(-1 * this->getNumerador());
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

Racional::Racional(int numerador, int denominador){
	this->setNumerador(numerador);
	this->setDenominador(denominador);
}

int main(){

	int numA, denA, numB, denB;
	char op;
	Racional *numeroRacionalA, *numeroRacionalB;

	while (cin >> numA >> denA >> op >> numB >> denB){

		numeroRacionalA = new Racional(numA, denA);
		numeroRacionalB = new Racional(numB, denB);

		switch (op){
			case '+':
				numeroRacionalA->soma(numeroRacionalB);
				break;
			case '-':
				numeroRacionalA->subtracao(numeroRacionalB);
				break;
			case '*':
				numeroRacionalA->produto(numeroRacionalB);
				break;
			case '/':
				numeroRacionalA->quociente(numeroRacionalB);
				break;
		}

		if (numeroRacionalA->getDenominador() < 0){
			numeroRacionalA->setNumerador(-1 *numeroRacionalA->getNumerador());
			numeroRacionalA->setDenominador(-1 *numeroRacionalA->getDenominador());
		}

		numeroRacionalA->simplifica();
		
		cout << numeroRacionalA->getNumerador() << " " << numeroRacionalA->getDenominador() << endl;
	}

	return 0;
}