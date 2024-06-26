#include <iostream>
#include <cmath>

using namespace std;

class SegundoGrau {
    float a, b, c;

    float delta() {
        return (pow(b, 2) - (4*a*c));
    }

public:
    SegundoGrau(float x1=0, float x2=0, float n=0): a(x1), b(x2), c(n)
    {}

    float Bask() {
        if(delta() < 0)
        {
            return -1;
        }
        return ((-b) + sqrt(delta() / (2*a)));
    }

    float getA() {
        return a;
    }

    void setA(float x1) {
        this->a = x1;
    }

    float getB() {
        return b;
    }

     void setB(float x2){
        this->b = x2;
    }


    float getC(){
        return c;
    }

    void setC(float n){
        this->c = n;
    }

    float xv(){
        return ((-b) / (2*a));
    }

    float yv() {
        return ((-delta()) / (4*a));
    }

};
    

int main()
{
    SegundoGrau x(1, -5, 4);

    cout << x.Bask() << endl;
    cout << x.xv() << endl;
    cout << x.yv() << endl;

    return 0;
}