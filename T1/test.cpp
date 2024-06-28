#include <iostream>

template <typename T>
class ListaSimplesmenteEncadeada {
private:
    // Estrutura de nó
    struct Nodo {
        T dado;
        Nodo* proximo;

        Nodo(const T& valor) : dado(valor), proximo(nullptr) {}
    };

    Nodo* cabeca; // Ponteiro para o primeiro nó
    Nodo* cauda;  // Ponteiro para o último nó
    size_t tamanho;

public:
    // Construtor
    ListaSimplesmenteEncadeada() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

    // Destrutor
    ~ListaSimplesmenteEncadeada() {
        while (cabeca != nullptr) {
            Nodo* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
        }
    }

    // Método para inserir no início da lista
    void inserirNoInicio(const T& valor) {
        Nodo* novoNodo = new Nodo(valor);
        if (cabeca == nullptr) {
            cabeca = cauda = novoNodo;
        } else {
            novoNodo->proximo = cabeca;
            cabeca = novoNodo;
        }
        ++tamanho;
    }

    // Método para inserir no final da lista
    void inserirNoFinal(const T& valor) {
        Nodo* novoNodo = new Nodo(valor);
        if (cauda == nullptr) {
            cabeca = cauda = novoNodo;
        } else {
            cauda->proximo = novoNodo;
            cauda = novoNodo;
        }
        ++tamanho;
    }

    // Método para remover do início da lista
    void removerDoInicio() {
        if (cabeca == nullptr) {
            std::cout << "A lista está vazia.\n";
            return;
        }
        Nodo* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
        if (cabeca == nullptr) {
            cauda = nullptr;
        }
        --tamanho;
    }

    // Método para remover do final da lista
    void removerDoFinal() {
        if (cauda == nullptr) {
            std::cout << "A lista está vazia.\n";
            return;
        }
        if (cabeca == cauda) {
            delete cabeca;
            cabeca = cauda = nullptr;
        } else {
            Nodo* atual = cabeca;
            while (atual->proximo != cauda) {
                atual = atual->proximo;
            }
            delete cauda;
            cauda = atual;
            cauda->proximo = nullptr;
        }
        --tamanho;
    }

    // Método para exibir a lista
    void exibir() const {
        Nodo* atual = cabeca;
        while (atual != nullptr) {
            std::cout << atual->dado << " ";
            atual = atual->proximo;
        }
        std::cout << "\n";
    }

    // Método para obter o tamanho da lista
    size_t obterTamanho() const {
        return tamanho;
    }

    // Método para verificar se a lista está vazia
    bool vazia() const {
        return tamanho == 0;
    }
};

int main() {
    ListaSimplesmenteEncadeada<int> lista;
    lista.inserirNoInicio(10);
    lista.inserirNoInicio(20);
    lista.inserirNoFinal(30);
    lista.inserirNoFinal(40);

    std::cout << "Lista após inserções: ";
    lista.exibir();

    lista.removerDoInicio();
    std::cout << "Lista após remover do início: ";
    lista.exibir();

    lista.removerDoFinal();
    std::cout << "Lista após remover do final: ";
    lista.exibir();

    return 0;
}
