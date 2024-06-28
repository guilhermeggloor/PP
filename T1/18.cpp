#include <iostream>
#include <cmath>

const double METROS_POR_MILHA = 1609.34;

class Milha; // Declaração antecipada para permitir a conversão entre objetos

class Metro {
private:
    double metros;

public:
    // Construtores
    Metro(double m = 0.0) : metros(m) {}
    Metro(const Milha& milha); // Construtor para conversão de Milha para Metro

    // Métodos de acesso
    double getMetros() const { return metros; }
    void setMetros(double m) { metros = m; }

    // Operadores de conversão
    operator Milha() const;

    // Sobrecarga dos operadores aritméticos
    Metro operator+(const Metro& other) const { return Metro(metros + other.metros); }
    Metro operator-(const Metro& other) const { return Metro(metros - other.metros); }

    // Sobrecarga dos operadores de incremento
    Metro& operator++() { ++metros; return *this; } // Prefixado
    Metro operator++(int) { Metro temp = *this; ++metros; return temp; } // Pós-fixado

    // Sobrecarga dos operadores de comparação
    bool operator==(const Metro& other) const { return metros == other.metros; }
    bool operator!=(const Metro& other) const { return metros != other.metros; }
    bool operator<(const Metro& other) const { return metros < other.metros; }
    bool operator<=(const Metro& other) const { return metros <= other.metros; }
    bool operator>(const Metro& other) const { return metros > other.metros; }
    bool operator>=(const Metro& other) const { return metros >= other.metros; }

    // Método de exibição
    void exibir() const { std::cout << metros << " metros\n"; }
};

class Milha {
private:
    double milhas;

public:
    // Construtores
    Milha(double m = 0.0) : milhas(m) {}
    Milha(const Metro& metro) : milhas(metro.getMetros() / METROS_POR_MILHA) {}

    // Métodos de acesso
    double getMilhas() const { return milhas; }
    void setMilhas(double m) { milhas = m; }

    // Operadores de conversão
    operator Metro() const { return Metro(milhas * METROS_POR_MILHA); }

    // Método de exibição
    void exibir() const { std::cout << milhas << " milhas\n"; }
};

// Implementação do construtor de conversão de Milha para Metro
Metro::Metro(const Milha& milha) : metros(milha.getMilhas() * METROS_POR_MILHA) {}

// Implementação do operador de conversão de Metro para Milha
Metro::operator Milha() const { return Milha(metros / METROS_POR_MILHA); }

int main() {
    // Criação de objetos
    Metro m1(500);
    Milha mi1(1);

    // Exibição inicial
    m1.exibir();
    mi1.exibir();

    // Conversão entre tipos
    Metro m2 = mi1;
    Milha mi2 = m1;

    // Exibição após conversão
    m2.exibir();
    mi2.exibir();

    // Operações aritméticas
    Metro m3 = m1 + m2;
    m3.exibir();

    Metro m4 = m1 - m2;
    m4.exibir();

    // Operações de incremento
    ++m1;
    m1.exibir();

    m2++;
    m2.exibir();

    // Comparações
    std::cout << (m1 == m2) << "\n";
    std::cout << (m1 != m2) << "\n";
    std::cout << (m1 < m2) << "\n";
    std::cout << (m1 <= m2) << "\n";
    std::cout << (m1 > m2) << "\n";
    std::cout << (m1 >= m2) << "\n";

    return 0;
}
