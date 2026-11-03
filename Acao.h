#pragma once
#include <string>
#include <iostream>
#include "Filme.h"
#include "AnoL.h"
using namespace std;

class Acao : public Filme {
private:
    string nivelAcao;

public:
    Acao(string nivel, string n, string a, string c, AnoL l )
        : Filme(n, a, c, l) {
        nivelAcao = nivel;
    }

    string getNivelAcao() {
        return nivelAcao;
    }
    string getGenero() override{
    return "Acao";
    }
    void setNivelAcao(string nivel) {
        nivelAcao = nivel;
    }

    void exibirInformacoes() override {
        Filme::exibirInformacoes();
        cout << "Nivel de acao: " << nivelAcao << endl;
    }
};