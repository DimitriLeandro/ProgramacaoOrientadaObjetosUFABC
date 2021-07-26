#include <iostream>

using namespace std;

class PilhaVaziaException: public runtime_error{
    public:
        PilhaVaziaException();
};

PilhaVaziaException::PilhaVaziaException():
    runtime_error("Underflow Error: Pilha Vazia."){}

class Item {
    private:
        int chave;
        Item *proximo;
    public:
        Item (int);
        int getChave();
        Item* getProximo();
        void setChave(int);
        void setProximo(Item*);
};

Item::Item(int chave) {
    this->setChave(chave);
    this->setProximo(NULL);
}

int Item::getChave() {
    return this->chave;
}

Item* Item::getProximo() {
    return this->proximo;
}

void Item::setChave(int chave) {
    this->chave = chave;
}

void Item::setProximo(Item *proximo) {
    this->proximo = proximo;
}

class Pilha {
    private:
        Item *topo;
        int quantidade;
        void incrementarQuantidade();
        void decrementarQuantidade();
    public:
        Pilha ();
        bool verificarListaVazia();
        void printarLista();
        void empilhar(int);
        int desempilhar();
        Item *getTopo();
        int getQuantidade();
        void setTopo(Item*);
        void setQuantidade(int);
};

Pilha::Pilha() {
    this->setTopo(NULL);
    this->setQuantidade(0);
}

bool Pilha::verificarListaVazia(){
    if (this->getTopo() == NULL) {
        return true;
    } else {
        return false;
    }
}

void Pilha::printarLista(){
    Item *atual;
    try{
        if (this->verificarListaVazia()){
            throw PilhaVaziaException();
        }
        atual = this->getTopo();
        int n = this->getQuantidade();
        for(int i=0; i<n; i++){
            cout << atual->getChave() << " ";
            atual = atual->getProximo();
        }
        if (n > 0) {
            cout << endl;
        }
    } catch(PilhaVaziaException exception){
        cout << exception.what() << endl;
    }
}

void Pilha::incrementarQuantidade() {
    this->setQuantidade(this->getQuantidade() + 1);
}

void Pilha::decrementarQuantidade() {
    this->setQuantidade(this->getQuantidade() - 1);
}

void Pilha::empilhar(int chave) {
    Item *novo = new Item(chave);
    novo->setProximo(this->getTopo());
    this->setTopo(novo);
    this->incrementarQuantidade();
}

int Pilha::desempilhar() {
    try{
        if (this->verificarListaVazia()) {
            throw PilhaVaziaException();
        }
        Item *itemRemover = this->getTopo();
        int chave = itemRemover->getChave();
        this->setTopo(itemRemover->getProximo());
        this->decrementarQuantidade();
        delete itemRemover;
        return chave;
    } catch(PilhaVaziaException exception){
        cout << exception.what() << endl;
        return -1;
    }
}

Item* Pilha::getTopo(){
    return this->topo;
}

int Pilha::getQuantidade(){
    return this->quantidade;
}

void Pilha::setTopo(Item *item){
    this->topo = item;
}

void Pilha::setQuantidade(int quantidade){
    this->quantidade = quantidade;
}

int main() {
    char operacao;
    int chave;
    Pilha *pilha = new Pilha();
    while (cin >> operacao) {
        switch (operacao) {
            case 'E': 
                cin >> chave;
                pilha->empilhar(chave);
                break;
            case 'D':
                chave = pilha->desempilhar();
                if (chave != -1){
                    cout << "[" << chave << "]\n";
                }
                break;
            case 'M':
                pilha->printarLista();
                break;
        }
    }
    delete pilha;
    return 0;
}