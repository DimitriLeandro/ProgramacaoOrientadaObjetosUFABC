#include <iostream>

using namespace std;

class Fila{
	private:
		int *itens, tamanho, inicio, fim;
		void resetarFila();
	public:
		Fila (int);
        ~Fila ();
        bool verificarFilaVazia();
        bool verificarFilaCheia();
        void printarFila();
        void enfileirarItem(int);
        int desenfileirarItem();
        void setItens(int, int);
        void setTamanho(int);
        void setInicio(int);
        void setFim(int);
        int getItens(int);
        int getTamanho();
        int getInicio();
        int getFim();
};

Fila::Fila(int tamanho){
    this->setTamanho(tamanho);
    this->resetarFila();
    this->itens = new int [tamanho];
}

Fila::~Fila(){
    delete[] this->itens;
}

void Fila::resetarFila(){
	this->setInicio(-1);
    this->setFim(-1);
}

bool Fila::verificarFilaVazia(){
    if (this->getFim() == -1){
    	return true;
    } else {
    	return false;
    }
}

bool Fila::verificarFilaCheia(){
    if (this->getFim() == this->tamanho - 1){
    	return true;
    } else {
    	return false;
    }
}

void Fila::enfileirarItem(int valor){
	if (this->verificarFilaVazia()){
        this->setItens(0, valor);
        this->setInicio(0);
        this->setFim(0);
    } else {
    	this->setItens(this->getFim() + 1, valor);
        this->setFim(this->getFim() + 1);
    }
}

int Fila::desenfileirarItem() {
    int valor = this->getItens(this->getInicio());
    if(this->getInicio() != this->getTamanho() - 1){
        this->setInicio(this->getInicio() + 1);
    } else{
        this->resetarFila();
    }
    return valor;
}

int Fila::getItens(int indice){
    return this->itens[indice];
}
int Fila::getTamanho(){
    return this->tamanho;
}
int Fila::getInicio(){
    return this->inicio;
}
int Fila::getFim(){
    return this->fim;
}
void Fila::setItens(int indice, int valor){
    this->itens[indice] = valor;
}
void Fila::setTamanho(int tamanho){
    this->tamanho = tamanho;
}
void Fila::setInicio(int indice){
    this->inicio = indice;
}
void Fila::setFim(int indice){
    this->fim = indice;
}

int main(){
	int tamanho, valor;
	char operacao;
	Fila *objFila;
    cin >> tamanho;
    objFila = new Fila(tamanho);    
    while (cin >> operacao){
        switch (operacao){
            case 'E': 
                cin >> valor;
                if (not objFila->verificarFilaCheia()){
                	objFila->enfileirarItem(valor);
                }
                break;
            case 'D':
            	if (not objFila->verificarFilaVazia()){
	                valor = objFila->desenfileirarItem();
	                cout << valor << endl;
	            }
            break;
        }
    }
	return 0;
}