#include <iostream>
#include <stdexcept>

using namespace std;

class Matriz {
    float data[2][2];
public: 
    Matriz() {
        data[0][0] = 0.0f; data[0][1] = 0.0f;
        data[1][0] = 0.0f; data[1][1] = 0.0f;
    }

    Matriz(float a, float b, float c, float d) {
       data[0][0] = a; data[0][1] = b;
       data[1][0] = c; data[1][1] = d; 
    }

    float determinante() const {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    Matriz operator+(const Matriz& other) const {
        return Matriz {
            data[0][0] + other.data[0][0], data[0][1] + other.data[0][1],
            data[1][0] + other.data[1][0], data[1][1] + other.data[1][1]
        };
    }

    Matriz operator-(const Matriz& other) const {
        return Matriz {
            data[0][0] - other.data[0][0], data[0][1] - other.data[0][1],
            data[1][0] - other.data[1][0], data[1][1] - other.data[1][1]
        };
    }

    Matriz operator*(const Matriz& other) const {
        return Matriz {
            data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0],
            data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1],
            data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0],
            data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1],
        };
    }

    Matriz inversa() const {
        float det = determinante();
        if (det == 0) {
            throw runtime_error("Matriz não é inversa");
        }
        return Matriz(
            data[1][1] / det, -data[0][1] / det,
            -data[1][0] / det, data[0][0] / det
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Matriz& matriz) {
        os << "[" << matriz.data[0][0] << ", " << matriz.data[0][1] << "]\n";
        os << "[" << matriz.data[1][0] << ", " << matriz.data[1][1] << "]\n";
        return os;
    }

};

int main()
{
    Matriz m1(1, 2, 3, 4);
    Matriz m2(2, 0, 1, 2);

    cout << "Matriz 1: \n" << m1;
    cout << "Matriz 2: \n" << m2;

    Matriz soma = m1 + m2;

    cout << "Soma das Matrizes: \n" << soma;

    Matriz produto = m1 * m2;

    cout << "Produto das Matrizes: \n" << produto;

    cout << "Determinante da Matriz 1: " << m1.determinante() << "\n";

    try {
        Matriz inversa = m1.inversa();
        cout << "Inversa da Matriz 1:\n" << inversa;
    } catch (const std::runtime_error& e) {
        cout << e.what() << "\n";
    }

    return 0;
}