
#pragma once
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include "Filme.h"
#include "AnoL.h"
#include "Comedia.h"
#include "Acao.h"
#include "Romance.h"

using namespace std;

class Crud {
private:
    Filme **filmes;
    int qtd;

public:
    Crud() {
        filmes = nullptr;
        qtd = 0;
    }

    string paraMinusculo(string texto) {
        for (int i = 0; i < texto.length(); i++) {
            texto[i] = tolower((unsigned char)texto[i]);
        }
        return texto;
    }

    void InserirComedia(string n, string a, string c, AnoL l, string estilo) {
        Filme **novo = new Filme*[qtd + 1];

        for (int i = 0; i < qtd; i++) {
            novo[i] = filmes[i];
        }

        novo[qtd] = new Comedia(estilo, n, a, c, l);

        delete[] filmes;
        filmes = novo;
        qtd++;
    }

    void InserirAcao(string n, string a, string c, AnoL l, string nivel) {
        Filme **novo = new Filme*[qtd + 1];

        for (int i = 0; i < qtd; i++) {
            novo[i] = filmes[i];
        }

        novo[qtd] = new Acao(nivel, n, a, c, l);

        delete[] filmes;
        filmes = novo;
        qtd++;
    }

    void InserirRomance(string n, string a, string c, AnoL l, bool final) {
        Filme **novo = new Filme*[qtd + 1];

        for (int i = 0; i < qtd; i++) {
            novo[i] = filmes[i];
        }

        novo[qtd] = new Romance(final, n, a, c, l);

        delete[] filmes;
        filmes = novo;
        qtd++;
    }

    void ListarTodos() {
        if (qtd == 0) {
            cout << "Nenhum filme cadastrado" << endl;
            return;
        }

        for (int i = 0; i < qtd; i++) {
            cout << "Índice: " << i << endl;
            cout << "Nome: " << filmes[i]->getNome() << endl;
            cout << endl;
        }
    }

    int Pesquisar(string nome) {
        int count = 0;
        int ind = -1;

        string nomePesquisa = paraMinusculo(nome);

        for (int i = 0; i < qtd; i++) {
            string nomeFilme = paraMinusculo(filmes[i]->getNome());

            if (nomeFilme.find(nomePesquisa) == 0) {
                cout << "Índice: " << i << endl;
                filmes[i]->exibirInformacoes();
                cout << "Gênero: " << filmes[i]->getGenero() << endl;
                cout << endl;

                count++;
                ind = i;
            }
        }

        if (count == 0) {
            return -1;
        }

        if (count == 1) {
            return ind;
        }

        cout << "Digite o índice do filme desejado: " << endl;
        cin >> ind;
        cin.ignore();

        for (int i = 0; i < qtd; i++) {
            string nomeFilme = paraMinusculo(filmes[i]->getNome());

            if (i == ind && nomeFilme.find(nomePesquisa) == 0) {
                return ind;
            }
        }

        return -1;
    }

    void ExibirUm(string nome) {
        int i = Pesquisar(nome);

        if (i != -1) {
            filmes[i]->exibirInformacoes();
            cout << "Genero: " << filmes[i]->getGenero() << endl;
        }
        else {
            cout << "Filme não encontrado" << endl;
        }
    }

    void Alterar(string nome) {
        int i = Pesquisar(nome);

        if (i == -1) {
            cout << "Filme não encontrado" << endl;
            return;
        }

        string novoNome;
        string novaAvaliacao;
        string novaNacio;
        int novoAno;

        cout << "\nDigite o novo nome: ";
        getline(cin, novoNome);

        cout << "Digite a nova avaliacao: ";
        getline(cin, novaAvaliacao);

        cout << "Digite a nova nacionalidade: ";
        getline(cin, novaNacio);

        cout << "Digite o novo ano de lancamento: ";
        cin >> novoAno;
        cin.ignore();

        AnoL anoAlterado(novoAno);

        filmes[i]->setNome(novoNome);
        filmes[i]->setAvaliacao(novaAvaliacao);
        filmes[i]->setNacionalidade(novaNacio);
        filmes[i]->setAno(anoAlterado);

        Comedia* c = dynamic_cast<Comedia*>(filmes[i]);

        if (c != nullptr) {
            string novoEstilo;
            cout << "Digite o novo estilo de humor: ";
            getline(cin, novoEstilo);
            c->setEstiloHumor(novoEstilo);
        }

        Acao* a = dynamic_cast<Acao*>(filmes[i]);

        if (a != nullptr) {
            string novoNivel;
            cout << "Digite o novo nivel de acao: ";
            getline(cin, novoNivel);
            a->setNivelAcao(novoNivel);
        }

        Romance* r = dynamic_cast<Romance*>(filmes[i]);

        if (r != nullptr) {
            int novoFinal;
            cout << "O filme tem final feliz? (1-Sim / 0-Nao): ";
            cin >> novoFinal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            r->setFinalFeliz(novoFinal);
        }

        cout << "\nFilme alterado com sucesso!" << endl;
    }

    void Remover(string nome) {
        int ind = Pesquisar(nome);

        if (ind != -1) {
            delete filmes[ind];

            Filme **novo = nullptr;

            if (qtd > 1) {
                novo = new Filme*[qtd - 1];

                for (int i = 0, j = 0; i < qtd; i++) {
                    if (i != ind) {
                        novo[j] = filmes[i];
                        j++;
                    }
                }
            }

            delete[] filmes;
            filmes = novo;
            qtd--;
        }
        else {
            cout << "Filme não encontrado" << endl;
        }
    }

    void ExibirRelatorio() {
        int comedia = 0;
        int romance = 0;
        int acao = 0;

        for (int i = 0; i < qtd; i++) {
            cout << "Relatorio do filme" << endl;
            cout << "Nome: " << filmes[i]->getNome() << endl;
            cout << "Avaliacao: " << filmes[i]->getAvaliacao() << endl;
            cout << "Nacionalidade: " << filmes[i]->getNacionalidade() << endl;
            cout << "Ano de lancamento: " << filmes[i]->getAno().getAno() << endl;
            cout << "Genero: " << filmes[i]->getGenero() << endl;
            cout << endl;

            if (filmes[i]->getGenero() == "Comedia") {
                comedia++;
            }
            else if (filmes[i]->getGenero() == "Romance") {
                romance++;
            }
            else if (filmes[i]->getGenero() == "Acao") {
                acao++;
            }
        }

        cout << "Resumo do relatorio" << endl;
        cout << "Total de filmes cadastrados: " << qtd << endl;
        cout << "Total de filmes de comedia: " << comedia << endl;
        cout << "Total de filmes de romance: " << romance << endl;
        cout << "Total de filmes de acao: " << acao << endl;
    }

    void SalvarArquivo() {
        ofstream arquivo("dados_filmes.txt");

        if (!arquivo.is_open()) {
            cout << "Erro ao abrir o arquivo para salvar" << endl;
            return;
        }

        for (int i = 0; i < qtd; i++) {
            if (dynamic_cast<Comedia*>(filmes[i]) != nullptr) {
                Comedia* c = dynamic_cast<Comedia*>(filmes[i]);

                arquivo << "COMEDIA "
                        << quoted(filmes[i]->getNome()) << " "
                        << quoted(filmes[i]->getAvaliacao()) << " "
                        << quoted(filmes[i]->getNacionalidade()) << " "
                        << filmes[i]->getAno().getAno() << " "
                        << quoted(c->getEstiloHumor())
                        << endl;
            }
            else if (dynamic_cast<Acao*>(filmes[i]) != nullptr) {
                Acao* a = dynamic_cast<Acao*>(filmes[i]);

                arquivo << "ACAO "
                        << quoted(filmes[i]->getNome()) << " "
                        << quoted(filmes[i]->getAvaliacao()) << " "
                        << quoted(filmes[i]->getNacionalidade()) << " "
                        << filmes[i]->getAno().getAno() << " "
                        << quoted(a->getNivelAcao())
                        << endl;
            }
            else if (dynamic_cast<Romance*>(filmes[i]) != nullptr) {
                Romance* r = dynamic_cast<Romance*>(filmes[i]);

                arquivo << "ROMANCE "
                        << quoted(filmes[i]->getNome()) << " "
                        << quoted(filmes[i]->getAvaliacao()) << " "
                        << quoted(filmes[i]->getNacionalidade()) << " "
                        << filmes[i]->getAno().getAno() << " "
                        << r->getFinalFeliz()
                        << endl;
            }
        }

        arquivo.close();
        cout << "Os dados foram salvos" << endl;
    }

    void CarregarArquivo() {
        ifstream arquivo("dados_filmes.txt");

        if (!arquivo.is_open()) {
            return;
        }

        string tipo;
        string nome;
        string avaliacao;
        string nacionalidade;
        int ano;

        while (arquivo >> tipo) {
            arquivo >> quoted(nome) >> quoted(avaliacao) >> quoted(nacionalidade) >> ano;

            if (!arquivo) {
                cout << "Erro ao ler os dados do arquivo" << endl;
                break;
            }

            AnoL lancamento(ano);

            if (tipo == "COMEDIA") {
                string estilo;
                arquivo >> quoted(estilo);

                if (!arquivo) {
                    break;
                }

                InserirComedia(nome, avaliacao, nacionalidade, lancamento, estilo);
            }
            else if (tipo == "ACAO") {
                string nivel;
                arquivo >> quoted(nivel);

                if (!arquivo) {
                    break;
                }

                InserirAcao(nome, avaliacao, nacionalidade, lancamento, nivel);
            }
            else if (tipo == "ROMANCE") {
                bool finalFeliz;
                arquivo >> finalFeliz;

                if (!arquivo) {
                    break;
                }

                InserirRomance(nome, avaliacao, nacionalidade, lancamento, finalFeliz);
            }
            else {
                cout << "Gênero não encontrado " << tipo << endl;
                break;
            }
        }

        arquivo.close();
        cout << "Dados carregados: " << qtd << " filmes" << endl;
    }

    ~Crud() {
        for (int i = 0; i < qtd; i++) {
            delete filmes[i];
        }

        delete[] filmes;
    }
};
