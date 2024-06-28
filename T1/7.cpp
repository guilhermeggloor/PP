#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Usuario {
    string nome, nome_usuario, senha, dados_basicos;
public:
    Usuario(string nome, string nome_usuario, string senha, string dados_basicos):
        nome(nome), nome_usuario(nome_usuario), senha(senha), dados_basicos(dados_basicos)
    {};

    string getNomeUsuario() { return nome_usuario; }
    string getSenha() { return senha; }
    string getNome() { return nome; }
    string getDadosBasicos() { return dados_basicos; } 
};

class Aluno : public Usuario {
    unordered_map<string, float> notas;
    vector<string> materias;

public:
    Aluno(string nome, string nome_usuario, string senha, string dados_basicos): 
        Usuario(nome, nome_usuario, senha, dados_basicos) 
    {};

    void adicionarMateria(string materia) {
        materias.push_back(materia);
        notas[materia] = 0.0f; // Inicializa a nota como 0
    }

    void setNota(string materia, float nota) {
        if (notas.find(materia) != notas.end()) {
            notas[materia] = nota;
        }
    }

    float getNota(string materia) {
        if (notas.find(materia) != notas.end()) {
            return notas[materia];
        }
        return -1.0f; // Indica que a matéria não foi encontrada
    }

    vector<string> getMaterias() { return materias; }
    void listarNotas() {
        for (auto& materia : materias) {
            cout << "Matéria: " << materia << " - Nota: " << notas[materia] << endl;
        }
    }
};

class Professor : public Usuario {
    vector<string> materias;

public:
    Professor(string nome, string nome_usuario, string senha, string dados_basicos)
        : Usuario(nome, nome_usuario, senha, dados_basicos) {}

    void adicionarMateria(string materia) {
        materias.push_back(materia);
    }

    vector<string> getMaterias() { return materias; }


    void listarAlunosPorMateria(string materia, vector<Aluno>& alunos) {
        cout << "Alunos que cursam " << materia << ":" << endl;
        for (auto& aluno : alunos) {
            if (find(aluno.getMaterias().begin(), aluno.getMaterias().end(), materia) != aluno.getMaterias().end()) {
                cout << aluno.getNome() << endl;
            }
        }
    }

     void modificarNotaAluno(string materia, Aluno& aluno, float nota) {
        aluno.setNota(materia, nota);
    }

    

};

class SAU {
    vector<Aluno> alunos;
    vector<Professor> professores;
public:
    void adicionarAluno(Aluno aluno) {
        alunos.push_back(aluno);
    }

    void adicionarProfessor(Professor professor) {
        professores.push_back(professor);
    }

    Aluno* loginAluno(string nome_usuario, string senha) {
        for (auto& aluno : alunos) {
            if (aluno.getNomeUsuario() == nome_usuario && aluno.getSenha() == senha) {
                return &aluno;
            }
        }
        return nullptr;
    }

    Professor* loginProfessor(string nome_usuario, string senha) {
        for (auto& professor : professores) {
            if (professor.getNomeUsuario() == nome_usuario && professor.getSenha() == senha) {
                return &professor;
            }
        }
        return nullptr;
    }

    void interfaceAluno(Aluno* aluno) {
        if (aluno) {
            cout << "Bem-vindo, " << aluno->getNome() << endl;
            aluno->listarNotas();
        } else {
            cout << "Login de aluno falhou." << endl;
        }
    }

    void interfaceProfessor(Professor* professor) {
        if (professor) {
            cout << "Bem-vindo, " << professor->getNome() << endl;
            for (auto& materia : professor->getMaterias()) {
                professor->listarAlunosPorMateria(materia, alunos);
            }
        } else {
            cout << "Login de professor falhou." << endl;
        }
    }
};

int main()
{
    SAU sistema;

    // Adicionar alguns alunos
    Aluno aluno1("Alice", "alice_u", "1234", "Dados básicos Alice");
    aluno1.adicionarMateria("Matematica");
    aluno1.adicionarMateria("Historia");

    Aluno aluno2("Bob", "bob_u", "1234", "Dados básicos Bob");
    aluno2.adicionarMateria("Matematica");
    aluno2.adicionarMateria("Geografia");

    sistema.adicionarAluno(aluno1);
    sistema.adicionarAluno(aluno2);

    // Adicionar um professor
    Professor professor("Dr. Smith", "smith_p", "abcd", "Dados básicos Dr. Smith");
    professor.adicionarMateria("Matematica");
    professor.adicionarMateria("Geografia");

    sistema.adicionarProfessor(professor);

    // Interface de login para aluno
    Aluno* alunoLogado = sistema.loginAluno("alice_u", "1234");
    sistema.interfaceAluno(alunoLogado);

    // Interface de login para professor
    Professor* professorLogado = sistema.loginProfessor("smith_p", "abcd");
    sistema.interfaceProfessor(professorLogado);

    // Professor modificando a nota de um aluno
    if (professorLogado && alunoLogado) {
        professorLogado->modificarNotaAluno("Matematica", *alunoLogado, 95.0f);
    }

    // Interface de login para aluno para verificar a nota modificada
    alunoLogado = sistema.loginAluno("alice_u", "1234");
    sistema.interfaceAluno(alunoLogado);


    return 0;
}