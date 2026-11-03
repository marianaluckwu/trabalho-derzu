#include "Crud.h"
#include "Dlancamento.h"
#include "Filme.h"
#include "Acao.h"
#include "Comedia.h"
#include "Romance.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    int opcao;
    string n, a, novoNome, novaAvaliacao;
    Crud c;

    cout << "Escolha as seguintes opções: 1.Inserir \n 2.Listar todos \n 3.Exibir um filme \n 4.Alterar \n 5.Remover um filme \n 6.Exibir Relatório \n 7.Sair" << endl;
    while(1){
        cin >> opcao;
        switch(opcao){
            case 1:
            cout << "Insira o nome do filme e sua avaliação" << endl;
            getline(cin, n);
            getline(cin, a);
            c.Inserir(n, a);
            break;

            case 2:
                c.ListarTodos();
                break;

            case 3:
                cout << "Digite o nome do filme: " << endl;
                getline(cin, n);
                c.ExibirUm(n);
                break;

            case 4:
                cout << "Digite o nome do filme que deseja alterar: " << endl;
                getline(cin, n);
                cout << "Digite o novo filme: " << endl;
                getline(cin, novoNome);
                cout << "Digite a nova avaliacao: " << endl;
                getline(cin, novaAvaliacao);
                c.Alterar(n, novoNome, novaAvaliacao);
                break;

            case 5:
                cout << "Digite o nome do filme que deseja remover: " << endl;
                getline(cin, n);
                c.Remover(n);
                break;

            case 6:
                cout << "Relatório:" << endl;
                get
                c.ExibirRelatorio(n);
                break;

            case 7:
                cout << "Sair do programa." << endl;
                return 0;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }
    }

    return 0;
}