#include <iostream>

using namespace std;

struct tComplexo{
	int real, imaginario;
};

struct tComplexo complexo(int real, int imaginario){
	struct tComplexo numeroComplexo;
	numeroComplexo.real       = real;
	numeroComplexo.imaginario = imaginario;
	return numeroComplexo;
}

struct tComplexo soma(struct tComplexo a, struct tComplexo b){
	struct tComplexo soma;
	soma.real       = a.real + b.real;
	soma.imaginario = a.imaginario + b.imaginario;
	return soma;
}

struct tComplexo sub(struct tComplexo a, struct tComplexo b){
	struct tComplexo sub;
	sub.real       = a.real - b.real;
	sub.imaginario = a.imaginario - b.imaginario;
	return sub;
}

struct tComplexo mult(struct tComplexo a, struct tComplexo b){
	struct tComplexo mult;
	mult.real       = a.real*b.real - a.imaginario*b.imaginario;
	mult.imaginario = a.real*b.imaginario + a.imaginario*b.real;
	return mult;
}

struct tComplexo div(struct tComplexo a, struct tComplexo b){
	struct tComplexo numerador, denominador, div, conjugadoB=b;
	conjugadoB.imaginario *= -1;
	numerador              = mult(a, conjugadoB);
    denominador            = mult(b, conjugadoB);
    div.real               = numerador.real / denominador.real;
    div.imaginario         = numerador.imaginario / denominador.real;
	return div;
}

void printarComplexo(struct tComplexo numeroComplexo){
	cout << numeroComplexo.real << " " << numeroComplexo.imaginario << "i" << endl;
}

int main(){

	int realA, imaginarioA, realB, imaginarioB;
	char op, i;
	struct tComplexo numeroComplexoA, numeroComplexoB, numeroComplexoResposta;


	while (cin >> realA >> imaginarioA >> i >> op >> realB >> imaginarioB >> i){

		numeroComplexoA = complexo(realA, imaginarioA);
		numeroComplexoB = complexo(realB, imaginarioB);

		switch (op){
			case '+':
				numeroComplexoResposta = soma(numeroComplexoA, numeroComplexoB);
				break;
			case '-':
				numeroComplexoResposta = sub(numeroComplexoA, numeroComplexoB);
				break;
			case '*':
				numeroComplexoResposta = mult(numeroComplexoA, numeroComplexoB);
				break;
			case '/':
				numeroComplexoResposta = div(numeroComplexoA, numeroComplexoB);
				break;
		}

		printarComplexo(numeroComplexoResposta);
	}

	return 0;
}