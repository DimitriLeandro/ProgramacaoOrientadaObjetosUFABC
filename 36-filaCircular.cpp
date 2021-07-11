#include <iostream>

using namespace std;

class FilaCircular{
	private:
		int *itens, tamanho, inicio, fim;
	public:
		FilaCircular(int);
        ~FilaCircular();
        bool verificarFilaCircularVazia();
        bool verificarFilaCircularCheia();
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

FilaCircular::FilaCircular(int tamanho){
    this->setTamanho(tamanho);
    this->setInicio(0);
    this->setFim(0);
    this->itens = new int[tamanho];
}

FilaCircular::~FilaCircular(){
    delete[] this->itens;
}

bool FilaCircular::verificarFilaCircularVazia(){
    if (this->getInicio() == this->getFim()){
    	return true;
    } else {
    	return false;
    }
}

bool FilaCircular::verificarFilaCircularCheia(){
    if (((this->getFim() + 1) % this->getTamanho()) == this->getInicio()){
    	return true;
    } else {
    	return false;
    }
}

void FilaCircular::enfileirarItem(int valor){
    int index;
    if (this->verificarFilaCircularVazia()){
        index = this->getInicio();
        this->setFim((this->getFim() + 1) % this->getTamanho());
    } else {
        this->setFim((this->getFim() + 1) % this->getTamanho());
        if (this->getFim() == 0){
            index = this->getTamanho() - 1;
        } else {
            index = this->getFim() - 1;
        }
    }
    this->setItens(index, valor);
}

int FilaCircular::desenfileirarItem() {
    int valor = this->getItens(this->getInicio());
    this->setInicio((this->getInicio() + 1) % this->getTamanho());
    return valor;
}

int FilaCircular::getItens(int indice){
    return this->itens[indice];
}
int FilaCircular::getTamanho(){
    return this->tamanho;
}
int FilaCircular::getInicio(){
    return this->inicio;
}
int FilaCircular::getFim(){
    return this->fim;
}
void FilaCircular::setItens(int indice, int valor){
    this->itens[indice] = valor;
}
void FilaCircular::setTamanho(int tamanho){
    this->tamanho = tamanho;
}
void FilaCircular::setInicio(int indice){
    this->inicio = indice;
}
void FilaCircular::setFim(int indice){
    this->fim = indice;
}

int main(){
	int tamanho, valor;
	char operacao;
	FilaCircular *objFilaCircular;
    cin >> tamanho;
    objFilaCircular = new FilaCircular(tamanho);    
    while (cin >> operacao){
        switch (operacao){
            case 'E': 
                cin >> valor;
                if (not objFilaCircular->verificarFilaCircularCheia()){
                	objFilaCircular->enfileirarItem(valor);
                }
                break;
            case 'D':
            	if (not objFilaCircular->verificarFilaCircularVazia()){
	                valor = objFilaCircular->desenfileirarItem();
	                cout << valor << endl;
	            }
            break;
        }
    }
	return 0;
}