#include <iostream>
#include <vector>

using namespace std;

struct aluno {
    string nome;
    float nota1;
    float nota2;
    float media;
};

float lerOpcao(int min, int max, const string &mensagemAviso, const string mensagemErro = "Opcao invalida");
void cadastrarAluno(vector<aluno> &lista);
void calcularMedia(vector<aluno> &lista, int indice);
void listarAluno(const vector<aluno> &lista, int indice);
void listarTodosAluno(const vector<aluno> &lista);

int main() {
    vector<aluno> lista;
    int opcao1;
    int opcao2;
    bool executar = true;

    while (executar) {
        cout << "Seja bem vindo\n";
        cout << "1 - Cadastrar aluno\n";
        cout << "2 - Listar todos os alunos\n";
        cout << "3 - Sair do programa\n";

        opcao1 = lerOpcao(1, 3, "Digite uma das opcoes");

        if (opcao1 == 2 && lista.empty()) {
            cout << "Nenhum aluno cadastrado\n";
            continue;
        }

        switch (opcao1) {
            case 1:
                cadastrarAluno(lista);
                break;
            case 2:
                listarTodosAluno(lista);
                break;
            case 3:
                cout << "Tem a certeza que deseja sair? (1 - sim, 2 - nao)\n";
                opcao2 = lerOpcao(1, 2, "Tem a certeza que deseja sair? (1 - sim, 2 - nao)");
                if (opcao2 == 1) {
                    executar = false;
                    cout << "Encerrando o programa...\n";
                }
                break;
        }
    }

    return 0;
}

float lerOpcao(int min, int max, const string &mensagemAviso, const string mensagemErro) {
    float opcao;
    while (!(cin >> opcao) || opcao < min || opcao > max) {
        cin.clear();
        cin.ignore(1000, '\n');
        cerr << mensagemErro << endl << mensagemAviso << endl;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return opcao;
}

void cadastrarAluno(vector<aluno> &lista) {
    int quanty;
    string nome;
    float nota1;
    float nota2;

    cout << "Quantos alunos deseja cadastrar? (Max 10)\n";
    quanty = lerOpcao(1, 10, "Quantos alunos deseja cadastrar? (Min 1 Max 10)");

    for (int i = 0; i < quanty; i++) {
        if (lista.size() >= 10) {
            cout << "Maximo de alunos alcancado\n";
            return;
        }

        cout << "Numero do aluno: " << lista.size() + 1 << endl;
        cout << "Digite o nome do aluno:\n";
        cin.ignore();
        getline(cin, nome);

        cout << "Digite a primeira nota:\n";
        nota1 = lerOpcao(0, 10, "A nota nao pode ser menor que 0 e maior que 10");

        cout << "Digite a segunda nota:\n";
        nota2 = lerOpcao(0, 10, "A nota nao pode ser menor que 0 e maior que 10");

        lista.push_back(aluno{nome, nota1, nota2});
        calcularMedia(lista, lista.size() - 1);
    }
}

void calcularMedia(vector<aluno> &lista, int indice) {
    lista[indice].media = (lista[indice].nota1 + lista[indice].nota2) / 2;
}

void listarAluno(const vector<aluno> &lista, int indice) {
    cout << "Numero do aluno: " << indice + 1 << endl;
    cout << "Nome: " << lista[indice].nome << endl;
    cout << "Primeira nota: " << lista[indice].nota1 << endl;
    cout << "Segunda nota: " << lista[indice].nota2 << endl;
    cout << "Media: " << lista[indice].media << endl;
}

void listarTodosAluno(const vector<aluno> &lista) {
    for (int i = 0; i < lista.size(); i++) {
        listarAluno(lista, i);
        cout << "----------------------\n";
    }
}