#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template <typename T>
class Lista {
private:
    std::vector<T> elementos;

public:
    // Método para inserir um elemento
    void inserir(const T& elemento) {
        elementos.push_back(elemento);
    }

    // Método para remover um elemento
    void remover(const T& elemento) {
        auto it = std::find(elementos.begin(), elementos.end(), elemento);
        if (it != elementos.end()) {
            elementos.erase(it);
        } else {
            std::cout << "Elemento não encontrado.\n";
        }
    }

    // Método para ordenar usando Bubble Sort
    void ordenar() {
        bool trocado;
        for (size_t i = 0; i < elementos.size() - 1; ++i) {
            trocado = false;
            for (size_t j = 0; j < elementos.size() - i - 1; ++j) {
                if (elementos[j] > elementos[j + 1]) {
                    std::swap(elementos[j], elementos[j + 1]);
                    trocado = true;
                }
            }
            if (!trocado) {
                break;
            }
        }
    }

    // Método para embaralhar aleatoriamente
    void embaralhar() {
        std::srand(unsigned(std::time(0)));
        std::random_shuffle(elementos.begin(), elementos.end());
    }

    // Método para busca linear
    int buscaLinear(const T& elemento) const {
        for (size_t i = 0; i < elementos.size(); ++i) {
            if (elementos[i] == elemento) {
                return i;
            }
        }
        return -1; // Retorna -1 se o elemento não for encontrado
    }

    // Método para busca binária (assume que o vetor está ordenado)
    int buscaBinaria(const T& elemento) const {
        size_t esquerda = 0;
        size_t direita = elementos.size() - 1;

        while (esquerda <= direita) {
            size_t meio = esquerda + (direita - esquerda) / 2;

            if (elemento == elementos[meio]) {
                return meio;
            }

            if (elemento > elementos[meio]) {
                esquerda = meio + 1;
            } else {
                direita = meio - 1;
            }
        }
        return -1; // Retorna -1 se o elemento não for encontrado
    }

    // Método para exibir a lista
    void exibir() const {
        for (const auto& elemento : elementos) {
            std::cout << elemento << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Lista<int> lista;
    lista.inserir(10);
    lista.inserir(5);
    lista.inserir(8);
    lista.inserir(1);
    lista.inserir(7);

    std::cout << "Lista original: ";
    lista.exibir();

    lista.ordenar();
    std::cout << "Lista ordenada: ";
    lista.exibir();

    lista.embaralhar();
    std::cout << "Lista embaralhada: ";
    lista.exibir();

    int elementoBusca = 8;

    clock_t inicio = clock();
    int indiceLinear = lista.buscaLinear(elementoBusca);
    clock_t fim = clock();
    double tempoBuscaLinear = double(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Busca Linear - Elemento " << elementoBusca << " encontrado no índice " << indiceLinear << " em " << tempoBuscaLinear << " segundos.\n";

    lista.ordenar(); // Necessário para busca binária
    inicio = clock();
    int indiceBinario = lista.buscaBinaria(elementoBusca);
    fim = clock();
    double tempoBuscaBinaria = double(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Busca Binária - Elemento " << elementoBusca << " encontrado no índice " << indiceBinario << " em " << tempoBuscaBinaria << " segundos.\n";

    return 0;
}
