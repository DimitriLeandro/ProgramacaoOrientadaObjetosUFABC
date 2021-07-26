#include <iostream>

using namespace std;

class PilhaCheiaException: public runtime_error{
	public:
		PilhaCheiaException();
};

PilhaCheiaException::PilhaCheiaException():
	runtime_error("Runtime Error: Pilha Cheia."){}

class PilhaVaziaException: public runtime_error{
	public:
		PilhaVaziaException();
};

PilhaVaziaException::PilhaVaziaException():
	runtime_error("Runtime Error: Pilha Vazia."){}

class PilhaEstatica{
	private:
		int *pilha;
		int tamanho;
		int quantidade;

	public:
		PilhaEstatica(int);
		void printarTopoParaBase();
		void printarBaseParaTopo();
		void empilhar(int);
		void desempilhar();
		void setTamanho(int);
		void setQuantidade(int);
		void setItens(int, int);
		int getTamanho();
		int getQuantidade();
		int getItens(int);
};

PilhaEstatica::PilhaEstatica(int tamanho){
	this->setTamanho(tamanho);
	this->setQuantidade(0);
	this->pilha = new int[tamanho];
}

void PilhaEstatica::printarTopoParaBase(){
	try{
		if (this->getQuantidade()==0){
			throw PilhaVaziaException();
		}
		for (int i=this->getQuantidade()-1; i>=0; i--) {
			cout << this->getItens(i) << endl;
		}
	} catch (PilhaVaziaException exception){
		cout << exception.what() << endl;
	}
}

void PilhaEstatica::printarBaseParaTopo(){
	try{
		if (this->getQuantidade()==0){
			throw PilhaVaziaException();
		}
		for (int i=0; i<this->getQuantidade(); i++) {
			cout << this->getItens(i) << endl;
		}
	} catch (PilhaVaziaException exception){
		cout << exception.what() << endl;
	}
}

void PilhaEstatica::empilhar(int valor){
	try{
		if (this->getQuantidade() == this->getTamanho()){
			throw PilhaCheiaException();
		}
		this->setQuantidade(this->getQuantidade() + 1);
		this->setItens(this->getQuantidade() - 1, valor);
	} catch (PilhaCheiaException exception){
		cout << exception.what() << endl;
	}
}

void PilhaEstatica::desempilhar(){
	try{
		if (this->getQuantidade()==0){
			throw PilhaVaziaException();
		}
		this->setQuantidade(this->getQuantidade() - 1);
	} catch (PilhaVaziaException exception){
		cout << exception.what() << endl;
	}
}

void PilhaEstatica::setTamanho(int tamanho){
	this->tamanho = tamanho;
}
void PilhaEstatica::setQuantidade(int quantidade){
	this->quantidade = quantidade;
}
void PilhaEstatica::setItens(int i, int valor){
	this->pilha[i] = valor;
}
int PilhaEstatica::getTamanho(){
	return this->tamanho;
}
int PilhaEstatica::getQuantidade(){
	return this->quantidade;
}
int PilhaEstatica::getItens(int i){
	return this->pilha[i];
}

int main(){

	int tamanho, valor;
	char operacao;
	PilhaEstatica *objPilha;

	cin >> tamanho;

	objPilha = new PilhaEstatica(tamanho);

	while (cin >> operacao){
		switch (operacao){
			case 'E':
				cin >> valor;
				objPilha->empilhar(valor);
				break;
			case 'D':
				objPilha->desempilhar();
				break;
			case 'T':
				objPilha->printarTopoParaBase();
				break;
			case 'B':
				objPilha->printarBaseParaTopo();
				break;
		}
	}

	return 0;
}