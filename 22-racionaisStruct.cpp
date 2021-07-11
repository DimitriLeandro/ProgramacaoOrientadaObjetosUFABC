#include <iostream>

using namespace std;

struct tRacional{
	long numerador, denominador;
};

struct tRacional racional(long numerador, long denominador){
	struct tRacional numeroRacional;
	numeroRacional.numerador   = numerador;
	numeroRacional.denominador = denominador;
	return numeroRacional;
}

struct tRacional negativo(struct tRacional numeroRacional){
	if (numeroRacional.numerador < 0 && numeroRacional.denominador < 0){
		numeroRacional.denominador *= -1;
	}
	else if (numeroRacional.numerador < 0 && numeroRacional.denominador >= 0){
		numeroRacional.numerador *= -1;
	}
	else if (numeroRacional.numerador >= 0 && numeroRacional.denominador < 0){
		numeroRacional.denominador *= -1;
	}
	else {
		numeroRacional.numerador *= -1;
	}
	return numeroRacional;
}

struct tRacional soma(struct tRacional a, struct tRacional b){
	struct tRacional soma;
	soma.numerador   = a.numerador*b.denominador + b.numerador*a.denominador;
	soma.denominador = a.denominador * b.denominador;
	return soma;
}

struct tRacional mult(struct tRacional a, struct tRacional b){
	struct tRacional mult;
	mult.numerador   = a.numerador * b.numerador;
	mult.denominador = a.denominador * b.denominador;
	return mult;
}

struct tRacional div(struct tRacional a, struct tRacional b){
	struct tRacional inversoB;
	long aux = inversoB.numerador;
	inversoB.numerador = inversoB.denominador;
	inversoB.denominador = aux;
	return mult(a, inversoB);
}

struct tRacional reduz(struct tRacional numeroRacional){
	for (long i=2; i<=numeroRacional.denominador; i++){
		if (numeroRacional.numerador % i == 0 and numeroRacional.denominador % i == 0){
			numeroRacional.numerador   /= i;
			numeroRacional.denominador /= i;
			return reduz(numeroRacional);
		}
	}
	return numeroRacional;
}

void printarRacional(struct tRacional numeroRacional){
	cout << numeroRacional.numerador << " " << numeroRacional.denominador << endl;
}

int main(){

	long numA, denA, numB, denB;
	char op;
	struct tRacional numeroRacionalA, numeroRacionalB, numeroRacionalRespostaInicial, numeroRacionalRespostaReduzida;


	while (cin >> numA >> denA >> op >> numB >> denB){

		numeroRacionalA = racional(numA, denA);
		numeroRacionalB = racional(numB, denB);

		switch (op){
			case '+':
				numeroRacionalRespostaInicial = soma(numeroRacionalA, numeroRacionalB);
				break;
			case '-':
				numeroRacionalB = negativo(numeroRacionalB);
				numeroRacionalRespostaInicial = soma(numeroRacionalA, numeroRacionalB);
				break;
			case '*':
				numeroRacionalRespostaInicial = mult(numeroRacionalA, numeroRacionalB);
				break;
			case '/':
				numeroRacionalRespostaInicial = div(numeroRacionalA, numeroRacionalB);
				break;
		}

		if (numeroRacionalRespostaInicial.denominador < 0){
			numeroRacionalRespostaInicial.numerador   *= -1;
			numeroRacionalRespostaInicial.denominador *= -1;
		}

		numeroRacionalRespostaReduzida = reduz(numeroRacionalRespostaInicial);
		printarRacional(numeroRacionalRespostaReduzida);
	}

	return 0;
}