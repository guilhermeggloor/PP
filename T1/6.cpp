#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Personagem {
    string nome;
    int vida, mana, ataque, defesa;
    float x, y;

public:
    Personagem(string nome, int vida, int mana, int ataque, int defesa, float x, float y):
        nome(nome), vida(vida), mana(mana), ataque(ataque), defesa(defesa), x(x), y(y)
    {};

    string getNome() {return nome;}

    void setNome(string nome) {
        this->nome = nome;
    }

    int getVida() {return vida;}

    void setVida(int vida) {
        this->vida = vida;
    }

    int getMana() {return mana;}

    void setMana(int mana) {
        this->mana = mana;
    }

    int getAtaque() {return ataque;}

    void setAtaque(int ataque) {
        this->ataque = ataque;
    }

    int getDefesa() {return defesa;}

    void setDefesa(int defesa) {
        this->defesa = defesa;
    }

    float getX() { return x; }

    void setX(float x) { 
        this->x = x;
    }

    float getY() { return y; }

    void setY(float y) { 
        this->y = y;
    }


    void atacar(Personagem &alvo) {
    int dano = ataque - alvo.getDefesa();
    if (dano > 0) {
        alvo.setVida(alvo.getVida() - dano);
        if (alvo.getVida() < 0) alvo.setVida(0);
        }
    }

    bool estaVivo() {
        return vida > 0;
    }

};

class Inimigos {
    string nome;
    int vida, mana, ataque, defesa;
    float x, y;

public:
    Inimigos(string nome, int vida, int mana, int ataque, int defesa, float x, float y):
        nome(nome), vida(vida), mana(mana), ataque(ataque), defesa(defesa), x(x), y(y)
    {};

    string getNome() {return nome;}

    void setNome(string nome) {
        this->nome = nome;
    }

    int getVida() {return vida;}

    void setVida(int vida) {
        this->vida = vida;
    }

    int getMana() {return mana;}

    void setMana(int mana) {
        this->mana = mana;
    }

    int getAtaque() {return ataque;}

    void setAtaque(int ataque) {
        this->ataque = ataque;
    }

    int getDefesa() {return defesa;}

    void setDefesa(int defesa) {
        this->defesa = defesa;
    }

    float getX() { return x; }

    void setX(float x) { 
        this->x = x;
    }

    float getY() { return y; }

    void setY(float y) { 
        this->y = y;
    }

};

class Arena {
    Personagem heroi;
    vector<Personagem> inimigos;
    float limitex, limitey;

public:
    Arena(float limitex, float limitey): 
        heroi("Arthur",  69, 100, 200, 50, 2, 6), limitex(limitex), limitey(limitey) {
            inimigos.push_back(Personagem(" goblin 1", 30, 50, 100, 20, 5, 5));
            inimigos.push_back(Personagem(" goblin 2", 40, 60, 90, 15, 6, 6));
        }

    void combate() {
        srand(time(0));

        while(heroi.estaVivo() && !inimigos.empty()) {
            for(auto &inimigos : inimigos) {
                if (inimigos.estaVivo()) {
                    heroi.atacar(inimigos);
                    cout << heroi.getNome() << " ataca" << inimigos.getNome() << " causando dano!" << endl;
                    if(!heroi.estaVivo()) {
                        cout << heroi.getNome() << " foi derrotado!" << endl;
                        break;
                    }
                }
            }
        }

        if(heroi.estaVivo()) {
            cout << "Todos os inimigos foram derrotados. " << heroi.getNome() << " é o vencedor!" << endl;
        }else {
            cout << heroi.getNome() << "foi derrotado. Os inimigos venceram !" << endl;
        }
    }

    void showHeroInfo() {
        cout << "Hero: " << heroi.getNome() << endl;
        cout << "Vida: " << heroi.getVida() << endl;
        cout << "Mana: " << heroi.getMana() << endl;
        cout << "Ataque: " << heroi.getAtaque() << endl;
        cout << "Defesa: " << heroi.getDefesa() << endl;
        cout << "Posição: (" << heroi.getX() << ", " << heroi.getY() << ")" << endl;
    }

    void showInimigosInfo() {
        for (auto &inimigo : inimigos) {
            cout << "Inimigo: " << inimigo.getNome() << endl;
            cout << "Vida: " << inimigo.getVida() << endl;
            cout << "Mana: " << inimigo.getMana() << endl;
            cout << "Ataque: " << inimigo.getAtaque() << endl;
            cout << "Defesa: " << inimigo.getDefesa() << endl;
            cout << "Posição: (" << inimigo.getX() << ", " << inimigo.getY() << ")" << endl;
            cout << "--------------------" << endl;
        }
    }
};


int main()
{
    Arena arena(10, 10); // Limites do mapa de 10x10
    arena.showHeroInfo();
    arena.showInimigosInfo();

    cout << "Iniciando combate..." << endl;
    arena.combate();

    return 0;
}