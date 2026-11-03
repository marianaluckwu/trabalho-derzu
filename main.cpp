#include "Romance.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    int opcao;
    string n, a;
    
    cout << "Escolha as seguintes opções: 1.Inserir /n 2.Listar todos/n3.Exibir um filme /n 4.Alterar/n 5.Remover um filme/n 6.Exibir Relatório /n 7.Sair"
    while(1){
        cin >> opcao;
        switch(opcao){
            case 1:
            cout << "Insira o nome do filme e sua avaliação" << endl;
            getline(cin, n);
            getline(cin, a);
            Inserir(n, a);
            case 2:
            
        }

    }
}