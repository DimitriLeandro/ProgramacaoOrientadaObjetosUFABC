#include <iostream>

using namespace std;

class ChaveExistenteException : public runtime_error{
    public:
        ChaveExistenteException();
};

ChaveExistenteException::ChaveExistenteException():
    runtime_error("Logic Error: Chave ja existe na Lista."){}

class ChaveInexistenteException : public runtime_error{
    public:
        ChaveInexistenteException();
};

ChaveInexistenteException::ChaveInexistenteException():
    runtime_error("Logic Error: Chave inexistente na Lista."){}

class ListaVaziaException : public runtime_error{
    public:
        ListaVaziaException();
};

ListaVaziaException::ListaVaziaException():
    runtime_error("Underflow Error: Lista Vazia."){}

class Item {
    private:
        int chave;
        Item *proximo;
    public:
        Item(int);
        int getChave();
        void setProximo(Item *);
        void setChave(int);
        Item* getProximo();
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

class Lista {
    private:
        Item *primeiro;
        int quantidade;
        void incrementarQuantidade();
        void decrementarQuantidade();
    public:
        Lista();
        ~Lista();
        bool verificarListaVazia();
        void printarLista();
        void inserir(int);
        Item* buscar(int);
        Item* remover(int);
        Item* getPrimeiro();
        int getQuantidade();
        void setPrimeiro(Item *);
        void setQuantidade(int);
};

Lista::Lista() {
    this->setPrimeiro(NULL);
    this->setQuantidade(0);
}

Lista::~Lista() {
    Item *atual = this->getPrimeiro (),
    *anterior = NULL;
    while (atual != NULL) {
        anterior = atual;
        atual = atual->getProximo ();
        delete anterior;
    }
}

bool Lista::verificarListaVazia() {
    if (this->getQuantidade() == 0){
        return true;
    } else {
        return false;
    }
}

void Lista::printarLista() {
    Item *atual;
    int n;
    try{
        if (this->verificarListaVazia()){
            throw ListaVaziaException();
        }
        atual = this->getPrimeiro();
        n = this->getQuantidade();
        for (int i=0; i<n-1; i++) {
            cout << atual->getChave() << " ";
            atual = atual->getProximo();
        }
        if (n > 0) {
            cout << atual->getChave() << endl;
        }
    } catch (ListaVaziaException exception){
        cout << exception.what() << endl;
    }
}

void Lista::incrementarQuantidade() {
    this->setQuantidade(this->getQuantidade() + 1);
}

void Lista::decrementarQuantidade() {
    this->setQuantidade(this->getQuantidade() - 1);
}

void Lista::inserir(int chave) {
    Item *novo;
    Item *anterior;
    Item *atual;
    try{
        novo = new Item(chave);
        anterior = NULL;
        atual = this->getPrimeiro();
        if (this->verificarListaVazia()) {
            this->setPrimeiro(novo);  
        } else {
            while(atual != NULL and atual->getChave() < novo->getChave()) {
                anterior = atual;
                atual = atual->getProximo();
            }
            if (atual == NULL) {
                anterior->setProximo(novo);
            } else {
                if (atual->getChave() == novo->getChave()) {
                    throw ChaveExistenteException();
                } else {
                    novo->setProximo(atual);
                    if (atual == this->getPrimeiro()) {
                        this->setPrimeiro(novo);
                    } else {
                        anterior->setProximo(novo);
                    }
                }
            }
        }
        this->incrementarQuantidade();
    } catch (ChaveExistenteException exception){
        cout << exception.what() << endl;
    }
}

Item* Lista::buscar(int chave) {
    Item *atual;
    try{
        if (this->verificarListaVazia()){
            throw ListaVaziaException();
        }
        atual = this->getPrimeiro();
        while(atual != NULL and atual->getChave() != chave){
            atual = atual->getProximo();
        }
        if (atual == NULL){
            throw ChaveInexistenteException();
        }
        return atual;
    } catch (ListaVaziaException exception){
        cout << exception.what() << endl;
        return NULL;
    } catch (ChaveInexistenteException exception) {
        cout << exception.what() << endl;
        return NULL;
    }
}

Item* Lista::remover(int chave) {
    Item *atual;
    Item *anterior;
    try{
        if (this->verificarListaVazia()){
            throw ListaVaziaException();
        }
        atual = this->getPrimeiro();
        anterior = NULL;
        while(atual != NULL && atual->getChave() < chave){
            anterior = atual;
            atual = atual->getProximo();
        }
        if(atual != NULL && atual->getChave() == chave){
            if(anterior == NULL){
                this->setPrimeiro(atual->getProximo());
            }
            else{
                anterior->setProximo(atual->getProximo());
            }
            this->decrementarQuantidade();
            return atual;
        } else {
            throw ChaveInexistenteException();
        }
    } catch (ListaVaziaException exception){
        cout << exception.what() << endl;
        return NULL;
    } catch (ChaveInexistenteException exception){
        cout << exception.what() << endl;
        return NULL;
    }
}

Item* Lista::getPrimeiro() {
    return this->primeiro;
}

int Lista::getQuantidade() {
    return this->quantidade;
}

void Lista::setPrimeiro(Item *primeiro) {
    this->primeiro = primeiro;
}

void Lista::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

int main() {
    char operacao;
    int chave;
    Lista *lista = new Lista();
    Item *itemRemover = NULL;
    while (cin >> operacao) {
        switch (operacao) {
            case 'I':
                cin >> chave;
                lista->inserir(chave);
                break;
            case 'R':
                cin >> chave;
                itemRemover = lista->remover(chave);
                if (itemRemover != NULL) {
                    cout << "REMOVIDO: " << itemRemover->getChave() << endl;
                    delete itemRemover;
                }
                break;
            case 'B':
                cin >> chave;
                if (lista->buscar(chave)) {
                    cout << "SIM" << endl;
                }
                break;
            case 'M':
                lista->printarLista();
                break;
        }
    }
    delete lista;
    return 0;
}