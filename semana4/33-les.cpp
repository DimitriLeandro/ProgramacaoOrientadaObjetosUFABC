#include <iostream>
using namespace std;

class ListaEstaticaSequencial{
	private:
		int *lista;
		int tamanho;
		int quantidade;
		bool verificarSeItemExiste(int);
		int obterPosicaoNovoItem(int);
		void moverElementosParaDireita(int);
		void moverElementosParaEsquerda(int);
	public:
		ListaEstaticaSequencial(int);
		~ListaEstaticaSequencial();
		void adicionarItem(int);
		void excluirItem(int);
		void printarLista();
		void setTamanho(int);
		void setQuantidade(int);
		void setItens(int , int);
		int getTamanho();
		int getQuantidade();
		int getItens(int);
};

ListaEstaticaSequencial::ListaEstaticaSequencial(int tamanho){
    this->setTamanho(tamanho);
    this->setQuantidade(0);
    this->lista = new int[tamanho];
}

ListaEstaticaSequencial::~ListaEstaticaSequencial(){
    delete[] this->lista;
}

bool ListaEstaticaSequencial::verificarSeItemExiste(int valor){
	for (int i=0; i<this->getQuantidade(); i++){
		if (this->getItens(i) == valor){
			return true;
		}
	}
	return false;
}

int ListaEstaticaSequencial::obterPosicaoNovoItem(int valor){
	int i;
	for (i=this->getQuantidade()-1; i>=0; i--){
		if (this->getItens(i) < valor){
			break;
		}
	}
	return i + 1;
}

void ListaEstaticaSequencial::moverElementosParaDireita(int posicaoOndeParar){
	for (int i=this->getQuantidade(); i>posicaoOndeParar; i--){
		this->setItens(i, this->getItens(i-1));
	}
}

void ListaEstaticaSequencial::moverElementosParaEsquerda(int posicaoInicial){
	for (int i=posicaoInicial; i<this->getQuantidade()-1; i++){
		this->setItens(i, this->getItens(i+1));
	}
}

void ListaEstaticaSequencial::adicionarItem(int valor){
	if (not this->verificarSeItemExiste(valor)){
		int posicaoOndeAdicionar = this->obterPosicaoNovoItem(valor);
		this->moverElementosParaDireita(posicaoOndeAdicionar);
		this->setItens(posicaoOndeAdicionar, valor);
		this->setQuantidade(this->getQuantidade() + 1);
	}
}

void ListaEstaticaSequencial::excluirItem(int valor){
	for (int i=0; i<this->getQuantidade(); i++){
		if (this->getItens(i) == valor){
			this->moverElementosParaEsquerda(i);
			this->setQuantidade(this->getQuantidade() - 1);
			break;
		}
	}
}

void ListaEstaticaSequencial::printarLista(){
    for (int i=0; i<this->getQuantidade(); i++) {
        cout << this->getItens(i) << endl;
    }
}

void ListaEstaticaSequencial::setTamanho(int tamanho){
    this->tamanho = tamanho;
}
void ListaEstaticaSequencial::setQuantidade(int quantidade){
    this->quantidade = quantidade;
}
void ListaEstaticaSequencial::setItens(int i, int valor){
    this->lista[i] = valor;
}
int ListaEstaticaSequencial::getTamanho(){
    return this->tamanho;
}
int ListaEstaticaSequencial::getQuantidade(){
    return this->quantidade;
}
int ListaEstaticaSequencial::getItens(int i){
    return this->lista[i];
}

int main(){

    int qtdOperacoes, i, valor, tamanho;
    char operacao;
    ListaEstaticaSequencial *objLista;

    cin >> qtdOperacoes;
    
    tamanho = qtdOperacoes;
    objLista = new ListaEstaticaSequencial(tamanho);

    for (i=0; i<qtdOperacoes; i++){
        cin >> operacao >> valor;
        
        switch (operacao){
            case 'I':
                objLista->adicionarItem(valor);
                break;
            case 'E':
                objLista->excluirItem(valor);
                break;
        }
    }

    objLista->printarLista();

    return 0;
}