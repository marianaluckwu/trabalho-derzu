#pragma once
#include <iostream>
#include <string>
#include "Filme.h"
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

    void Inserir(string n, string a){
        Filme *novo = new Filme[qtd + 1];

        for(int i=0; i<qtd; i++){
            novo[i] = filmes[i];
        }

        novo[qtd] = Filme(n, a);

        delete[] filmes;

        filmes = novo;
        qtd++;
    }

    void ListarTodos(){
        for(int i=0; i<qtd; i++){
            cout << "Nome: " << filmes[i].getNome() << endl;
            cout << "Avaliacao: " << filmes[i].getAvaliacao() << endl;
        }
    }

    int Buscar(string nome){
        for(int i=0; i<qtd; i++){
            if(filmes[i].getNome() == nome){
                return i;
            }
        }

        return -1;
    }

    void ExibirUm(string nome){
        int i = Buscar(nome);

        if(i != -1){
            cout << filmes[i].getNome() << endl;
            cout << filmes[i].getAvaliacao() << endl;
        }
        else{
            cout << "Filme nao encontrado." << endl;
        }
    }

    void Alterar(string nome, string novoNome, string novaAvaliacao){
        int i = Buscar(nome);

        if(i != -1){
            filmes[i].setNome(novoNome);
            filmes[i].setAvaliacao(novaAvaliacao);
        }
        else{
            cout << "Filme nao encontrado." << endl;
        }
    }

    void Remover(string nome){
        int i = Buscar(nome);

        if(i != -1){
            Filme *novo = new Filme[qtd - 1];

            for(int i=0, j=0; i<qtd; i++){
                if(i != i){
                    novo[j] = filmes[i];
                    j++;
                }
            }

            delete[] filmes;

            filmes = novo;
            qtd--;
        }
        else{
            cout << "Filme nao encontrado." << endl;
        }
    }

    void ExibirRelatorio(string nome){
        int i = Buscar(nome);

        if(i != -1){
            cout << "Relatorio do filme" << endl;
            cout << "Nome: " << filmes[i].getNome() << endl;
            cout << "Avaliacao: " << filmes[i].getAvaliacao() << endl;
        }
        else{
            cout << "Filme nao encontrado." << endl;
        }
    }

    ~Crud(){
        delete[] filmes;
    }
};




