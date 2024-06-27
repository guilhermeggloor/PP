#include <iostream>
#include <cmath>

using namespace std;

class Pontos {
    float x, y;

    float getX() { return x; }
    void setX(float x) { this->x = x;}

    float getY() { return y; }
    void setY(float y) { this->y = y;}
public: 
    //constructor
    Pontos(float x, float y): x(x), y(y)
    {};

    Pontos(): x(0.0f), y(0.0f) {};

    float translate(float x, float y) {
        return (x + y);

        setX(x);
        setY(y);
    }

    float distance(Pontos &other) {
        return sqrt(pow(other.x-x, 2) + pow(other.y-y, 2));
    }

};


class Triangulo {
    Pontos p1, p2, p3;

    float calcularAngulo(float a, float b, float c) const {
        return acos((b*b + c*c - a*a) / (2 * b * c)) * (180.0 / M_PI);
    }
public:
    Triangulo(Pontos p1, Pontos p2, Pontos p3):p1(p1), p2(p2), p3(p3)
    {};

    float area()  {
        float a = p1.distance(p2);
        float b = p2.distance(p3);
        float c = p3.distance(p1);
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    float anguloEmP1() {
        float a = p2.distance(p3);
        float b = p1.distance(p3);
        float c = p1.distance(p2);
        return calcularAngulo(a, b, c);
    }

    float anguloEmP2()  {
        float a = p1.distance(p3);
        float b = p1.distance(p2);
        float c = p2.distance(p3);
        return calcularAngulo(a, b, c);
    }

    float anguloEmP3() {
        float a = p1.distance(p2);
        float b = p2.distance(p3);
        float c = p1.distance(p3);
        return calcularAngulo(a, b, c);
    }

    bool isRetangulo() {
        const float tolerance = 1e-5;
        float anguloP1 = anguloEmP1();
        float anguloP2 = anguloEmP2();
        float anguloP3 = anguloEmP3();
        return fabs(anguloP1 - 90) < tolerance || fabs(anguloP2 - 90) < tolerance || fabs(anguloP3 - 90) < tolerance;
    }


};

int main()
{

    Pontos p1(0, 0);
    Pontos p2(3, 0);
    Pontos p3(0, 4);

    Triangulo t(p1, p2, p3);
    cout << "Área do Triângulo: " << t.area() << endl;

    cout << "Ângulo em P1: " << t.anguloEmP1() << " graus" << endl;
    cout << "Ângulo em P2: " << t.anguloEmP2() << " graus" << endl;
    cout << "Ângulo em P3: " << t.anguloEmP3() << " graus" << endl;

    if (t.isRetangulo()) {
        cout << "O triângulo é retângulo." << endl;
    } else {
        cout << "O triângulo não é retângulo." << endl;
    }

    return 0;
}