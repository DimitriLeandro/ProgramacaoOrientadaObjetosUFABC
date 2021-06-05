#include <iostream>

using namespace std;

struct tInteiro{
	int algarismos[101];
	int tamanho;
};

struct tInteiro inteiro(string stringNumero){
	int i = 0;
	struct tInteiro tInteiroNumero;
	while (stringNumero[i] != '\0'){
		tInteiroNumero.algarismos[i] = stringNumero[i] - '0';
		i++;
	}
	tInteiroNumero.tamanho = i;
	return tInteiroNumero;
}

void printarInteiro(struct tInteiro* inteiro){
	for (int i=0; i<inteiro->tamanho; i++){
		cout << inteiro->algarismos[i];
	}
	cout << endl;
}

void trocarInteirosDePosicao(struct tInteiro* enderecoInteiroA, struct tInteiro* enderecoInteiroB){
	struct tInteiro enderecoInteiroAux;
	enderecoInteiroAux = *enderecoInteiroA;
	*enderecoInteiroA = *enderecoInteiroB;
	*enderecoInteiroB = enderecoInteiroAux;
}

void colocarEmOrdemMaiorMenor(struct tInteiro* enderecoInteiroA, struct tInteiro* enderecoInteiroB){
	if (enderecoInteiroA->tamanho < enderecoInteiroB->tamanho){
		trocarInteirosDePosicao(enderecoInteiroA, enderecoInteiroB);
	} else {
		if (enderecoInteiroA->tamanho == enderecoInteiroB->tamanho){
			for (int i=0; i<enderecoInteiroA->tamanho; i++){
				if (enderecoInteiroA->algarismos[i] < enderecoInteiroB->algarismos[i]){
					trocarInteirosDePosicao(enderecoInteiroA, enderecoInteiroB);
					break;
				} else {
					if (enderecoInteiroA->algarismos[i] > enderecoInteiroB->algarismos[i]){
						break;
					}
				}
			}
		}
	}
}

void preencherZerosAEsquerdaDoMenor(struct tInteiro* menor, int tamanhoDoMaior){
	int i, qtdNecessariaZeros = tamanhoDoMaior - menor->tamanho;
	int* novosAlgarismos = new int[tamanhoDoMaior];
	for (i=0; i<tamanhoDoMaior; i++){
		if (i < qtdNecessariaZeros){
			novosAlgarismos[i] = 0;
		} else {
			novosAlgarismos[i] = menor->algarismos[i-qtdNecessariaZeros];
		}
	}
	for (i=0; i<tamanhoDoMaior; i++){
		menor->algarismos[i] = novosAlgarismos[i];
	}
	menor->tamanho = tamanhoDoMaior;
}

void removerZeroAEsquerdaDoResultado(struct tInteiro* resultado){
	if (resultado->algarismos[0] == 0 and resultado->tamanho > 1){
		for (int i=0; i<resultado->tamanho; i++){
			resultado->algarismos[i] = resultado->algarismos[i+1];
		}
		resultado->tamanho--;
		removerZeroAEsquerdaDoResultado(resultado);
	}
}

struct tInteiro soma(struct tInteiro tInteiroA, struct tInteiro tInteiroB){
	int resultado=0, carry=0;
	struct tInteiro tInteiroResultado;
	for (int i=tInteiroA.tamanho; i>0; i--){
		resultado = tInteiroA.algarismos[i-1] + tInteiroB.algarismos[i-1] + carry;
		if (resultado >= 10){
			resultado -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		tInteiroResultado.algarismos[i] = resultado;
	}
	tInteiroResultado.algarismos[0] = carry;
	tInteiroResultado.tamanho = tInteiroA.tamanho + 1;
	return tInteiroResultado;
}

struct tInteiro sub(struct tInteiro tInteiroA, struct tInteiro tInteiroB){
	struct tInteiro tInteiroResultado;
	for (int i=tInteiroA.tamanho-1; i>=0; i--){
		if (tInteiroA.algarismos[i] < tInteiroB.algarismos[i]){
			tInteiroA.algarismos[i] += 10;
			tInteiroA.algarismos[i-1]--;
		} 
		tInteiroResultado.algarismos[i] = tInteiroA.algarismos[i] - tInteiroB.algarismos[i];		
	}
	tInteiroResultado.tamanho = tInteiroA.tamanho;
	return tInteiroResultado;
}

struct tInteiro mult(struct tInteiro tInteiroA, struct tInteiro tInteiroB){
	int i=0, j=0, quociente=0, resto=0;
	struct tInteiro tInteiroResultado;

	tInteiroResultado.tamanho = tInteiroA.tamanho + tInteiroB.tamanho;
	for (i=0; i<tInteiroResultado.tamanho; i++){
		tInteiroResultado.algarismos[i] = 0;
	}
	for (int i=tInteiroB.tamanho; i>0; i--){
		for (int j=tInteiroA.tamanho; j>0; j--){
			tInteiroResultado.algarismos[tInteiroResultado.tamanho-(tInteiroB.tamanho-i)-(tInteiroA.tamanho-j)-1] += tInteiroB.algarismos[i-1] * tInteiroA.algarismos[j-1];
		}
	}
	for (int i=tInteiroResultado.tamanho-1; i>=0; i--){
		if (tInteiroResultado.algarismos[i] >= 10){
			quociente = tInteiroResultado.algarismos[i] / 10;
            tInteiroResultado.algarismos[i] -= 10 * quociente;
            tInteiroResultado.algarismos[i-1] += quociente;
		}
	}
	return tInteiroResultado;
}

int main(){

	string stringNumeroA, stringNumeroB;
	char operacao;
	struct tInteiro tInteiroA, tInteiroB, tInteiroResultado;

	while(cin >> stringNumeroA >> operacao >> stringNumeroB){

        tInteiroA = inteiro(stringNumeroA);
        tInteiroB = inteiro(stringNumeroB);

        colocarEmOrdemMaiorMenor(&tInteiroA, &tInteiroB);
        preencherZerosAEsquerdaDoMenor(&tInteiroB, tInteiroA.tamanho);

        switch(operacao){
            case '+':
                tInteiroResultado = soma(tInteiroA, tInteiroB);
                break;
            case '-':
                tInteiroResultado = sub(tInteiroA, tInteiroB);
                break;
            case '*':
                tInteiroResultado = mult(tInteiroA, tInteiroB);
                break;
        }

        removerZeroAEsquerdaDoResultado(&tInteiroResultado);
        printarInteiro(&tInteiroResultado);
    }

	return 0;
}