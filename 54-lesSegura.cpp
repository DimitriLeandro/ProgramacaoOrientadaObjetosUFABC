#include <iostream>

using namespace std;

class IncluirException: public runtime_error{
	public:
		IncluirException();
};

IncluirException::IncluirException():
	runtime_error("Logic Error: Chave existente na lista."){}

class ExcluirException: public runtime_error{
	public:
		ExcluirException();
};

ExcluirException::ExcluirException():
	runtime_error("Logic Error: Chave inexistente na lista."){}

class PosicaoInvalidaException: public runtime_error{
	public:
		PosicaoInvalidaException();
};

PosicaoInvalidaException::PosicaoInvalidaException():
	runtime_error("Runtime Error: Posicao da lista inexistente."){}

class ListaCheiaException: public runtime_error{
	public:
		ListaCheiaException();
};

ListaCheiaException::ListaCheiaException():
	runtime_error("Runtime Error: Lista cheia."){}

class ListaVaziaException: public runtime_error{
	public:
		ListaVaziaException();
};

ListaVaziaException::ListaVaziaException():
	runtime_error("Runtime Error: Lista Vazia."){}

class ListaEstaticaSequencial{
	private:
		int *lista;
		int tamanho;
		int quantidade;
		int obterPosicaoNovoItem(int);
		void moverElementosParaDireita(int);
		void moverElementosParaEsquerda(int);
	public:
		ListaEstaticaSequencial(int);
		~ListaEstaticaSequencial();
		int buscarPosicao(int);
		int verificarSeItemExiste(int);
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

int ListaEstaticaSequencial::verificarSeItemExiste(int valor){
	try{
		if (this->getQuantidade()==0){
			throw ListaVaziaException();
		}
		for (int i=0; i<this->getQuantidade(); i++){
			if (this->getItens(i) == valor){
				return 1;
			}
		}
		return 0;
	} catch (ListaVaziaException exception){
		cout << exception.what() << endl;
		return -1;
	}
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
	try{    	
		if (this->getQuantidade() > 0){
			if (this->getQuantidade() == this->getTamanho()){
				throw ListaCheiaException();
			}
			if (this->verificarSeItemExiste(valor) == 1){
				throw IncluirException();
			}
		}		
		int posicaoOndeAdicionar = this->obterPosicaoNovoItem(valor);
		this->moverElementosParaDireita(posicaoOndeAdicionar);
		this->setItens(posicaoOndeAdicionar, valor);
		this->setQuantidade(this->getQuantidade() + 1);
	} catch (ListaCheiaException exception){
		cout << exception.what() << endl;
	} catch (IncluirException exception){
		cout << exception.what() << endl;
	}
}

void ListaEstaticaSequencial::excluirItem(int valor){	
	try{
		if (this->getQuantidade()==0){
			throw ListaVaziaException();
		}
		if (this->verificarSeItemExiste(valor) != 1){
			throw ExcluirException();
		}
		for (int i=0; i<this->getQuantidade(); i++){
			if (this->getItens(i) == valor){
				this->moverElementosParaEsquerda(i);
				this->setQuantidade(this->getQuantidade() - 1);
				break;
			}
		}
	} catch (ListaVaziaException exception){
		cout << exception.what() << endl;
	} catch (ExcluirException exception){
		cout << exception.what() << endl;
	}
}

void ListaEstaticaSequencial::printarLista(){
	try{
		if (this->getQuantidade()==0){
			throw ListaVaziaException();
		}
		for (int i=0; i<this->getQuantidade(); i++) {
			cout << this->getItens(i) << " ";
		}
		cout << endl;
	} catch (ListaVaziaException exception){
		cout << exception.what() << endl;
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
	try{
		if(i >= this->getQuantidade() or i < 0){
			throw PosicaoInvalidaException();
		}
		return this->lista[i];
	} catch (PosicaoInvalidaException exception){
        cout << exception.what() << endl;
        return -1;
    }
}

int main(){
	int i, valor, tamanho;
	char operacao;
	ListaEstaticaSequencial *objLista;
	cin >> tamanho;
	objLista = new ListaEstaticaSequencial(tamanho);
	while (cin >> operacao){
		switch (operacao){
			case 'I':
				cin >> valor;
				objLista->adicionarItem(valor);
				break;
			case 'E':
				cin >> valor;
				objLista->excluirItem(valor);
				break;
			case 'B':
				cin >> valor;
				valor = objLista->verificarSeItemExiste(valor);
				if (valor == 0){
					cout << "NAO" << endl;
				}
				if (valor == 1){
					cout << "SIM" << endl;
				}
				break;
			case 'C':{
                cin >> valor;
                int posicao = objLista->getItens(valor);
                if(posicao != -1){
                    cout << "<" << posicao << ">" << endl;
                }
                break;
            }
			case 'M':
				objLista->printarLista();
				break;			
		}
	}
	return 0;
}