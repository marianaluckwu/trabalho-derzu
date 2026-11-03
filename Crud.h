#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "Filme.h"
#include "AnoL.h"
#include "Comedia.h"
#include "Acao.h"
#include "Romance.h"

using namespace std;

class Crud{
    private:
    Filme **filmes;
    int qtd;

    public:
    Crud(){
        filmes = nullptr;
        qtd = 0;
    }

    void InserirComedia(string n, string a, string c, AnoL l, string estilo){
        Filme **novo = new Filme*[qtd + 1];

        for(int i=0; i<qtd; i++){
            novo[i] = filmes[i];
        }

        novo[qtd] = new Comedia(estilo, n, a, c, l);

        delete[] filmes;
        filmes = novo;
        qtd++;
    }

    void InserirAcao(string n, string a, string c, AnoL l, string nivel){
        Filme **novo = new Filme*[qtd + 1];

        for(int i=0; i<qtd; i++){
            novo[i] = filmes[i];
        }

        novo[qtd] = new Acao(nivel, n, a, c, l);

        delete[] filmes;
        filmes = novo;
        qtd++;
    }

    void InserirRomance(string n, string a, string c, AnoL l, bool final){
        Filme **novo = new Filme*[qtd + 1];

        for(int i=0; i<qtd; i++){
            novo[i] = filmes[i];
        }

        novo[qtd] = new Romance(final, n, a, c, l);

        delete[] filmes;
        filmes = novo;
        qtd++;
    }

   void ListarTodos(){
    if(qtd == 0){
        cout << "Nenhum filme cadastrado" << endl;
        return;
    }

    for(int i=0; i<qtd; i++){
        cout << "Índice: " << i << endl;
        cout << "Nome: " << filmes[i]->getNome() << endl;
        cout << endl;
    }
}

    int Pesquisar(string nome){
        int count = 0;
        int ind = -1;

        for(int i=0; i<qtd; i++){
            if(filmes[i]->getNome().find(nome) == 0){
                cout << "Índice: " << i << endl;
                filmes[i]->exibirInformacoes();
                cout << "Gênero: " << filmes[i]->getGenero() << endl;
                cout << endl;

                count++;
                ind = i;
            }
        }

        if(count == 0){
            return -1;
        }

        if(count == 1){
            return ind;
        }

        cout << "Digite o índice do filme desejado: " << endl;
        cin >> ind;
        cin.ignore();

        for(int i=0; i<qtd; i++){
            if(i == ind && filmes[i]->getNome().find(nome) == 0){
                return ind;
            }
        }

        return -1;
    }

    void ExibirUm(string nome){
        int i = Pesquisar(nome);

        if(i != -1){
            filmes[i]->exibirInformacoes();
            cout << "Gênero: " << filmes[i]->getGenero() << endl;
        }
        else{
            cout << "Filme não encontrado" << endl;
        }
    }

    void Alterar(string nome, string novoNome, string novaNacio,
                 string novaAvaliacao, AnoL novoAno){
        int i = Pesquisar(nome);

        if(i != -1){
            filmes[i]->setNome(novoNome);
            filmes[i]->setNacionalidade(novaNacio);
            filmes[i]->setAvaliacao(novaAvaliacao);
            filmes[i]->setAno(novoAno);
        }
        else{
            cout << "Filme não encontrado" << endl;
        }
    }

    void Remover(string nome){
        int ind = Pesquisar(nome);

        if(ind != -1){
            delete filmes[ind];

            Filme **novo = nullptr;

            if(qtd > 1){
                novo = new Filme*[qtd - 1];

                for(int i=0, j=0; i<qtd; i++){
                    if(i != ind){
                        novo[j] = filmes[i];
                        j++;
                    }
                }
            }

            delete[] filmes;
            filmes = novo;
            qtd--;
        }
        else{
            cout << "Filme não encontrado" << endl;
        }
    }

    void ExibirRelatorio(){
    int comedia = 0;
    int romance = 0;
    int acao = 0;

    for(int i=0; i<qtd; i++){
        cout << "Relatorio do filme" << endl;
        cout << "Nome: " << filmes[i]->getNome() << endl;
        cout << "Avaliacao: " << filmes[i]->getAvaliacao() << endl;
        cout << "Nacionalidade: " << filmes[i]->getNacionalidade() << endl;
        cout << "Ano de lancamento: " << filmes[i]->getAno().getAno() << endl;
        cout << "Genero: " << filmes[i]->getGenero() << endl;
        cout << endl;

        if(filmes[i]->getGenero() == "Comedia"){
            comedia++;
        }
        else if(filmes[i]->getGenero() == "Romance"){
            romance++;
        }
        else if(filmes[i]->getGenero() == "Acao"){
            acao++;
        }
    }

    cout << "Resumo do relatorio" << endl;
    cout << "Total de filmes cadastrados: " << qtd << endl;
    cout << "Total de filmes de comedia: " << comedia << endl;
    cout << "Total de filmes de romance: " << romance << endl;
    cout << "Total de filmes de acao: " << acao << endl;
   } 

    ~Crud(){
        for(int i=0; i<qtd; i++){
            delete filmes[i];
        }

        delete[] filmes;
    }
};