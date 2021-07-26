#include <iostream>

using namespace std;

class IndiceException: public runtime_error{
    public:
        IndiceException();
};

IndiceException::IndiceException(): 
    runtime_error("runtime error: indice fora dos limites do vetor."){}

class Vetor{
    private:
        int *vetor;
        int tamanhoVetor;
    public:
        Vetor(int);
        void printarIndice(int);
        void setValorIndice(int, int);
};

Vetor::Vetor(int tamanhoVetor){
    this->tamanhoVetor=tamanhoVetor;
    this->vetor = new int[tamanhoVetor];
}

void Vetor::printarIndice(int indice){
    if (indice < 0 || indice >= this->tamanhoVetor){
        throw IndiceException();
    }
    cout << this->vetor[indice] << endl;
}

void Vetor::setValorIndice(int valor, int indice){
    this->vetor[indice] = valor;
}

int main() {
    int tamanhoVetor, indice, valor;
    cin >> tamanhoVetor;
    Vetor *vetor = new Vetor(tamanhoVetor);
    for (indice=0; indice<tamanhoVetor; indice++){
        cin >> valor;
        vetor->setValorIndice(valor, indice);
    }
    while(cin >> indice){
        try{
            vetor->printarIndice(indice);
        }
        catch(IndiceException exception){
            cout << exception.what() << endl;
        }
    }
    return 0;
}