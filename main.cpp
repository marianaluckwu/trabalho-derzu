#include "Crud.h"
#include "AnoL.h"
#include "Filme.h"
#include "Acao.h"
#include "Comedia.h"
#include "Romance.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int main(){
    int opcao;
    int genero;
    int ano;
    int final;
    string n, a, c;
    string novoNome, novaAvaliacao, novaNacio;
    string estilo, nivel;
    string nome;

    Crud crud;

    while(1){
        cout << "\nEscolha as seguintes opcoes:" << endl;
        cout << "1. Inserir" << endl;
        cout << "2. Listar todos" << endl;
        cout << "3. Exibir um filme" << endl;
        cout << "4. Alterar" << endl;
        cout << "5. Remover um filme" << endl;
        cout << "6. Exibir relatorio" << endl;
        cout << "7. Sair" << endl;

        cin >> opcao;
        cin.ignore();

        switch(opcao){

            case 1:{
                cout << "Nome do filme: ";
                getline(cin, n);

                cout << "Avaliação: ";
                getline(cin, a);

                cout << "Nacionalidade: ";
                getline(cin, c);

                cout << "Ano de lançamento: ";
                cin >> ano;
                cin.ignore();

                AnoL lancamento(ano);

                cout << "Escolha o gênero:" << endl;
                cout << "1. Comédia" << endl;
                cout << "2. Ação" << endl;
                cout << "3. Romance" << endl;

                cin >> genero;
                cin.ignore();

                switch(genero){

                    case 1:
                        cout << "Estilo de humor: ";
                        getline(cin, estilo);

                        crud.InserirComedia(n, a, c, lancamento, estilo);
                        break;

                    case 2:
                        cout << "Nível de ação: ";
                        getline(cin, nivel);

                        crud.InserirAcao(n, a, c, lancamento, nivel);
                        break;

                    case 3:
                        cout << "O filme tem final feliz? (1-Sim / 0-Nao): ";
                        cin >> final;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        crud.InserirRomance(n, a, c, lancamento, final);
                        break;

                    default:
                        cout << "Gênero inválido." << endl;
                        break;
                }

                break;
            }

            case 2:
                crud.ListarTodos();
                break;

            case 3:
                cout << "Digite o nome do filme: ";
                getline(cin, nome);

                crud.ExibirUm(nome);
                break;

            case 4:{
                int novoAno;

                cout << "Digite o nome do filme que deseja alterar: ";
                getline(cin, nome);

                cout << "Digite o novo nome: ";
                getline(cin, novoNome);

                cout << "Digite a nova nacionalidade: ";
                getline(cin, novaNacio);

                cout << "Digite a nova avaliaçãoo: ";
                getline(cin, novaAvaliacao);

                cout << "Digite o novo ano de lancamento: ";
                cin >> novoAno;
                cin.ignore();

                AnoL anoAlterado(novoAno);

                crud.Alterar(nome, novoNome, novaNacio,
                             novaAvaliacao, anoAlterado);
                break;
            }

            case 5:
                cout << "Digite o nome do filme que deseja remover: ";
                getline(cin, nome);

                crud.Remover(nome);
                break;

            case 6:
                crud.ExibirRelatorio();
                break;

            case 7:
                cout << "Saindo do programa." << endl;
                return 0;

            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }

    return 0;
}