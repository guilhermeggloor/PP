#include <iostream>
#include <cmath>

using namespace std;

class numInt {
    int numero;

public:
    numInt(const int numero=0):numero(numero)
    {}

    void setNumero(const int numero){
        this->numero = numero;
    }

    int getNumero(){
        return numero;
    }

    int raizQ(){
        return sqrt(this->numero);
    }

    int Potencia2(){
        return pow(this->numero, 2);
    }

    int soma(int numero2) {
        return this->numero = numero + numero2;
    }
    
};

int main()
{
    numInt x(5);

    cout << "Raiz: " << x.raizQ() << endl;
    cout << "Potencia: " << x.Potencia2() << endl;
    cout << "Soma: " << x.soma(3) << endl;

    return 0;
}