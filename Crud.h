#pragma once
#include <iostream>
#include <string>
#include "Filme.h"
#include "AnoL.h"
#include "Comedia.h"
#include "Acao.h"
#include "Romance.h"

using namespace std;

class Crud{
    private:
    Filme *filmes;
    int qtd;

    public:
    Crud(){
        filmes = nullptr;
        qtd = 0;
    }

    void Inserir(string n, string a, string c, AnoL l){
        Filme *novo = new Filme[qtd + 1];
        for(int i=0; i<qtd; i++){
            novo[i] = filmes[i];
        }
        novo[qtd] = Filme(n, a, c, l);
        delete[] filmes;
        filmes = novo;
        qtd++;
    }

    void ListarTodos(){
        if(qtd == 0){
        cout << "Nenhum filme cadastrado." << endl;
        }
        for(int i=0; i<qtd; i++){
            cout << "Índice: " << i << endl;
            cout << "Nome: " << filmes[i].getNome() << endl;
            cout << "Nacionalidade: " << filmes[i].getNacionalidade() << endl;
            cout << "Avaliação: " << filmes[i].getAvaliacao() << endl;
            cout << "Avaliação: " << filmes[i].getAvaliacao() << endl;
            cout << endl;
        }
    }

    int Pesquisar(string nome){
        int i;
        int count = 0;
        int ind = -1;

        for(i=0; i<qtd; i++){
            if(filmes[i].getNome().find(nome) == 0){
                cout << "Índice: " << i << endl;
                cout << "Nome: " << filmes[i].getNome() << endl;
                cout << "Avaliação: " << filmes[i].getAvaliacao() << endl;
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
        cout << "Digite o índice do filme desejado: ";
        cin >> ind;
        for(i=0; i<qtd; i++){
            if(i == ind && filmes[i].getNome().find(nome) == 0){
                return ind;
            }
        }

        return -1;
    }

    void ExibirUm(string nome){
        int i = Pesquisar(nome);

        if(i != -1){
            cout << filmes[i].getNome() << endl;
            cout << filmes[i].getNacionalidade() << endl;
            cout << filmes[i].getAvaliacao() << endl;
            cout << filmes[i].getAno() << endl;
         }
        else{
            cout << "Filme não encontrado" << endl;
        }
    }

    void Alterar(string nome, string novoNome, string novaNacio, string novaAvaliacao){
        int i = Pesquisar(nome);

        if(i != -1){
            filmes[i].setNome(novoNome);
            filmes[i].setNome(novaNacio);
            filmes[i].setAvaliacao(novaAvaliacao);
        }
        else{
            cout << "Filme não encontrado" << endl;
        }
    }

    void Remover(string nome){
        int ind = Pesquisar(nome);

        if(ind != -1){
            Filme *novo = new Filme[qtd - 1];

            for(int i=0, j=0; i<qtd; i++){
                if(i != ind){
                    novo[j] = filmes[i];
                    j++;
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

    void ExibirRelatorio(string nome){
        int i = Pesquisar(nome);

        if(i != -1){
            cout << "Relatório do filme" << endl;
            cout << "Nome: " << filmes[i].getNome() << endl;
            cout << "Avaliação: " << filmes[i].getAvaliacao() << endl;
            cout << "Quantidade de filmes cadastrados: " << qtd << endl;
        }
        else{
            cout << "Filme não encontrado" << endl;
        }
    }

    ~Crud(){
        delete[] filmes;
    }
};
