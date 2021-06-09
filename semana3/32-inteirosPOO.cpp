#include <iostream>

using namespace std;

class Inteiro{
	public:
		int algarismos[400];
		int tamanho;
		Inteiro(string);
		void soma(Inteiro*);
		void sub(Inteiro*);
		void mult(Inteiro*);
		void preencherZerosAEsquerda(int);
		void removerZerosAEsquerda();
		void printar();
};

Inteiro::Inteiro(string stringNumero){
	this->tamanho = 0;
	while (stringNumero[this->tamanho] != '\0'){
		this->algarismos[this->tamanho] = stringNumero[this->tamanho] - '0';
		this->tamanho++;
	}
}

void Inteiro::soma(Inteiro *inteiroB){
	int resultado=0, carry=0;
	inteiroB->preencherZerosAEsquerda(this->tamanho);
	for (int i=this->tamanho; i>0; i--){
		resultado = this->algarismos[i-1] + inteiroB->algarismos[i-1] + carry;
		if (resultado >= 10){
			resultado -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		this->algarismos[i] = resultado;
	}
	this->algarismos[0] = carry;
	this->tamanho = this->tamanho + 1;
	this->removerZerosAEsquerda();
}

void Inteiro::sub(Inteiro *inteiroB){
	inteiroB->preencherZerosAEsquerda(this->tamanho);
	for (int i=this->tamanho-1; i>=0; i--){
		if (this->algarismos[i] < inteiroB->algarismos[i]){
			this->algarismos[i] += 10;
			this->algarismos[i-1]--;
		} 
		this->algarismos[i] = this->algarismos[i] - inteiroB->algarismos[i];		
	}
	this->removerZerosAEsquerda();
}

void Inteiro::mult(Inteiro *inteiroB){
	int i=0, j=0, quociente=0, resto=0;
	int arrayResultado[400];
	inteiroB->preencherZerosAEsquerda(this->tamanho);
	for (i=0; i<400; i++){
		arrayResultado[i] = 0;
	}
	for (int i=this->tamanho; i>0; i--){
		for (int j=this->tamanho; j>0; j--){
			arrayResultado[399-(this->tamanho-i)-(this->tamanho-j)] += inteiroB->algarismos[i-1] * this->algarismos[j-1];
		}
	}
	for (int i=399; i>=0; i--){
		if (arrayResultado[i] >= 10){
			quociente = arrayResultado[i] / 10;
            arrayResultado[i] -= 10 * quociente;
            arrayResultado[i-1] += quociente;
		}
		this->algarismos[i] = arrayResultado[i];
	}
	this->tamanho = 400;
	this->removerZerosAEsquerda();
}

void Inteiro::preencherZerosAEsquerda(int tamanhoTotal){
	int i, qtdNecessariaZeros = tamanhoTotal - this->tamanho;
	int* novosAlgarismos = new int[tamanhoTotal];
	for (i=0; i<tamanhoTotal; i++){
		if (i < qtdNecessariaZeros){
			novosAlgarismos[i] = 0;
		} else {
			novosAlgarismos[i] = this->algarismos[i-qtdNecessariaZeros];
		}
	}
	for (i=0; i<tamanhoTotal; i++){
		this->algarismos[i] = novosAlgarismos[i];
	}
	this->tamanho = tamanhoTotal;
}

void Inteiro::removerZerosAEsquerda(){
	if (this->algarismos[0] == 0 and this->tamanho > 1){
		for (int i=0; i<this->tamanho; i++){
			this->algarismos[i] = this->algarismos[i+1];
		}
		this->tamanho--;
		this->removerZerosAEsquerda();
	}
}

void Inteiro::printar(){
	for (int i=0; i<this->tamanho; i++){
		cout << this->algarismos[i];
	}
	cout << endl;
}

int main(){

	string stringNumeroA, stringNumeroB;
	char operacao;
	Inteiro *inteiroA, *inteiroB;

	while(cin >> stringNumeroA >> operacao >> stringNumeroB){

        inteiroA = new Inteiro(stringNumeroA);
        inteiroB = new Inteiro(stringNumeroB);

        switch(operacao){
            case '+':
                inteiroA->soma(inteiroB);
                break;
            case '-':
                inteiroA->sub(inteiroB);
                break;
            case '*':
                inteiroA->mult(inteiroB);
                break;
        }

        inteiroA->printar();
    }

	return 0;
}