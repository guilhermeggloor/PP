#include <iostream>

using namespace std;

template <typename T>
class ListaSimplesEncadeada {
    struct Node {
        T dado;
        Node* proximo;

        Node(const T& valor): dado(valor), proximo(nullptr) {}
    };

    Node* cabeca;
    Node* cauda;
    size_t tamanho;
public:
    ListaSimplesEncadeada(): cabeca(nullptr), cauda(nullptr), tamanho(0) {}

    ~ListaSimplesEncadeada() {
        while (cabeca != nullptr) {
            Node* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
        }
    }

    void inserirNoInicio(const T& valor) {
        Node* novoNo = new Node(valor);
        if (cabeca == nullptr) {
            cabeca = cauda = novoNo;
        } else {
            novoNo->proximo = cabeca;
            cabeca = novoNo;
        }
        ++tamanho;
    }

    void inserirNoFinal(const T& valor) {
        Node* novoNo = new Node(valor);
        if(cauda == nullptr) {
            cabeca = cauda = novoNo;
        } else {
            novoNo->proximo = novoNo;
            cabeca = novoNo;
        }
        ++tamanho;
    }

    void removerInicio() {
        if (cabeca == nullptr) {
            cout << "A lista está vazia!\n";
            return;
        }
        Node* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
        if (cabeca == nullptr) {
            cauda = nullptr;
        }
        --tamanho;
    }

    void removerFinal() {
        if (cauda == nullptr) {
            cout << "A lista está vazia!\n";
            return;
        }
        if(cabeca == cauda) {
            delete cabeca;
            cabeca = cauda = nullptr;
        } else {
            Node* atual = cabeca;
            while (atual->proximo != cauda) {
                atual = atual->proximo;
            }
            delete cauda;
            cauda = atual;
            cauda->proximo = nullptr;
        }
        --tamanho;
    }

    void exibir() const [
        Node* atual = cabeca;
        while (atual != nullptr) {
            cout << atual->dado << " ";
            atual = atual->proximo;
        }
        cout << "\n";
    ]

    size_t obterTamanho() const {
        return tamanho;
    }

    bool vazia() const {
        return tamanho == 0;
    }
};

int main()
{
    ListaSimplesEncadeada<int> lista;
    lista.inserirNoInicio(10);
    lista.inserirNoInicio(20);
    lista.inserirNoFinal(30);
    lista.inserirNoFinal(40);

    std::cout << "Lista após inserções: ";
    lista.exibir();

    lista.removerInicio();
    std::cout << "Lista após remover do início: ";
    lista.exibir();

    lista.removerFinal();
    std::cout << "Lista após remover do final: ";
    lista.exibir();

    return 0;
}
