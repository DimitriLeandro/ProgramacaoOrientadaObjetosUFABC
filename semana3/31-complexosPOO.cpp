#include <iostream>

using namespace std;

class Complexo{
	private:
		int real, imaginario;
	public:
		Complexo(int, int);
		void printar();
		void soma(Complexo*);
		void sub(Complexo*);
		void mult(Complexo*);
		void div(Complexo*);
		void setReal(int);
		void setImaginario(int);
		int getReal();
		int getImaginario();		
};

Complexo::Complexo(int real, int imaginario){
	this->setReal(real);
	this->setImaginario(imaginario);
}

void Complexo::printar(){
	cout << this->getReal() << " " << this->getImaginario() << "i" << endl;
}

void Complexo::soma(Complexo *complexoB){
	this->setReal(this->getReal() + complexoB->getReal());
	this->setImaginario(this->getImaginario() + complexoB->getImaginario());
}

void Complexo::sub(Complexo *complexoB){
	this->setReal(this->getReal() - complexoB->getReal());
	this->setImaginario(this->getImaginario() - complexoB->getImaginario());
}

void Complexo::mult(Complexo *complexoB){
	Complexo *anterior = new Complexo(this->getReal(), this->getImaginario());
	this->setReal(anterior->getReal()*complexoB->getReal() - anterior->getImaginario()*complexoB->getImaginario());
	this->setImaginario(anterior->getReal()*complexoB->getImaginario() + anterior->getImaginario()*complexoB->getReal());
}

void Complexo::div(Complexo *complexoB){
	Complexo *numerador = new Complexo(this->getReal(), this->getImaginario());
	Complexo *denominador = new Complexo(complexoB->getReal(), complexoB->getImaginario());
	complexoB->setImaginario(-1 * complexoB->getImaginario());
	numerador->mult(complexoB);
    denominador->mult(complexoB);
    this->setReal(numerador->getReal() / denominador->getReal());
    this->setImaginario(numerador->getImaginario() / denominador->getReal());
}

void Complexo::setReal(int real){
	this->real = real;
}

void Complexo::setImaginario(int imaginario){
	this->imaginario = imaginario;
}

int Complexo::getReal(){
	return this->real;
}

int Complexo::getImaginario(){
	return this->imaginario;
}

int main(){

	int realA, imaginarioA, realB, imaginarioB;
	char op, i;
	Complexo *numeroComplexoA, *numeroComplexoB;

	while (cin >> realA >> imaginarioA >> i >> op >> realB >> imaginarioB >> i){

		numeroComplexoA = new Complexo(realA, imaginarioA);
		numeroComplexoB = new Complexo(realB, imaginarioB);

		switch (op){
			case '+':
				numeroComplexoA->soma(numeroComplexoB);
				break;
			case '-':
				numeroComplexoA->sub(numeroComplexoB);
				break;
			case '*':
				numeroComplexoA->mult(numeroComplexoB);
				break;
			case '/':
				numeroComplexoA->div(numeroComplexoB);
				break;
		}

		numeroComplexoA->printar();
	}

	return 0;
}