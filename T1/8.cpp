#include <iostream>
#include <cstring>

using namespace std;

class String {
    char* str;
    size_t len;
public:
    String(): str(nullptr), len(0) {}

    String(const char* s) {
        if(s) {
            len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);
        }else {
            str = nullptr;
            len = 0;
        }
    }

    String(const String& other) {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }

    String operator=(const String& other) {
        if (this == &other) {
            return *this;
        }
    }

    ~String() {
        delete[] str;
    }

    size_t length() const {
        return len;
    }

    bool empty() const {
        return len == 0;
    }

    char& operator[](size_t index) {
        if (index >= len) {
            throw out_of_range("Index fora do alcance");
        }
        return str[index];
    }

    String operator+(const String& other) const {
        String resultado;
        resultado.len = len + other.len;
        resultado.str = new char[resultado.len + 1];
        strcpy(resultado.str, str);
        strcat(resultado.str, other.str);
        return resultado;
    }

    bool operator==(const String& other) const {
        if(len != other.len) {
            return false;
        }
        return strcmp(str, other.str) == 0;
    }

    void print() const {
        if (str) {
            cout << str;
        }
    }
};


int main()
{
    String s1("Hello");
    String s2("World");

    String s3 = s1 + s2;

    cout << "s1: ";
    s1.print();
    cout << "\ns2: ";
    s2.print();
    cout << "\ns3: ";
    s3.print();
    cout << "\n";

    cout << "tamanho de s3: " << s3.length() << "\n";
    cout << "s3 é vazio ? " << (s3.empty() ? "Yes" : "No") << "\n";

    s3[0] = 'h';
    cout << "s3 modificado: ";
    s3.print();
    cout << "\n";

    String s4 = s3;
    cout << "Copia s4: ";
    s4.print();
    cout << "\n";

    cout << "s3 e s4 são iguais ? " << (s3 == s4 ? "yes" : "No") << "\n";

    return 0;
}