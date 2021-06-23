#include <iostream>

using namespace std;

class Item {
    private:
        int chave;
        Item *proximo;
    public:
        Item(int);
        int getChave();
        Item* getProximo();
        void setChave(int);
        void setProximo(Item*);
};

Item::Item(int chave){
    this->setChave(chave);
    this->setProximo(NULL);
}

int Item::getChave() {
    return this->chave;
}

Item * Item::getProximo() {
    return this->proximo;
}

void Item::setChave(int chave) {
    this->chave = chave;
}

void Item::setProximo(Item *proximo) {
    this->proximo = proximo;
}

class Fila {
    private:
        Item *primeiro;
        Item *ultimo;
    public:
        Fila();
        void setPrimeiro(Item*);
        void setUltimo(Item*);
        Item * getPrimeiro();
        Item * getUltimo();
        bool verificarFilaVazia();
        void printarFila();
        void enfileirar(int);
        int desenfileirar();
};

Fila::Fila(){
    this->setPrimeiro(NULL);
    this->setUltimo(NULL);
}

bool Fila::verificarFilaVazia(){
    if (getPrimeiro() == NULL) {
        return true;
    } else {
        return false;
    }
}

void Fila::printarFila(){
    if(!this->verificarFilaVazia()){
        Item *atual = this->getPrimeiro();
        while(atual->getProximo() != NULL){
            cout << atual->getChave() << " ";
            atual = atual->getProximo();
        }
        cout << atual->getChave() << endl;
    }
}

void Fila::enfileirar(int chave) {
    Item *novo = new Item(chave);
    Item *ultimo = NULL;
    novo->setProximo(NULL);
    if(this->verificarFilaVazia()){
        this->setPrimeiro(novo);
        this->setUltimo(novo);
    } else {
        ultimo = this->getUltimo();
        ultimo->setProximo(novo);
        this->setUltimo(novo);
    }
}

int Fila::desenfileirar() {
    Item *itemRemover = this->getPrimeiro();
    int chave = itemRemover->getChave();
    this->setPrimeiro(itemRemover->getProximo());
    delete itemRemover;
    return chave;
}

void Fila::setPrimeiro(Item *primeiro){
    this->primeiro = primeiro;
}
void Fila::setUltimo(Item *ultimo){
    this->ultimo = ultimo;
}
Item* Fila::getPrimeiro(){
    return this->primeiro;
}
Item* Fila::getUltimo(){
    return this->ultimo;
}

int main() {
    char operador;
    int chave;
    Fila *fila = new Fila();
    while (std::cin >> operador) {
        switch (operador) {
            case 'E': 
                cin >> chave;
                fila->enfileirar(chave);
                break;
            case 'D':
                if (!fila->verificarFilaVazia()) {
                    chave = fila->desenfileirar();
                    cout << "<" << chave << ">" << endl;
                }
                break;
            case 'M':
                fila->printarFila();
                break;
        }
    }
    delete fila;
    return 0;
} 