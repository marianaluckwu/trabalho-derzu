#include "Crud.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    int opcao;
    string n, a;
    
    cout << "Escolha as seguintes opções: 1.Inserir /n 2.Listar todos/n 3.Exibir um filme /n 4.Alterar/n 5.Remover um filme/n 6.Exibir Relatório /n 7.Sair"
    while(1){
        cin >> opcao;
        switch(opcao){
            case 1:
            cout << "Insira o nome do filme e sua avaliação" << endl;
            getline(cin, n);
            getline(cin, a);
            Inserir(n, a);
            break;

            case 2:
                ListarTodos();
                break;

            case 3:
                cout << "Digite o nome do filme: ";
                getline(cin, n);

                Exibir(n);
                break;

            case 4:
                cout << "Digite o nome do filme que deseja alterar: ";
                getline(cin, n);

                cout << "Digite a nova avaliacao: ";
                getline(cin, a);

                Alterar(n, a);
                break;

            case 5:
                cout << "Digite o nome do filme que deseja remover: ";
                getline(cin, n);

                Remover(n);
                break;

            case 6:
                Relatorio();
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