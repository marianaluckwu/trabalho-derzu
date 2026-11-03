#pragma once
#include <string>
#include <iostream>
#include "filme.h"

using namespace std;

class Acao : public Filme {
private:
    string nivelAcao;

public:
    Acao(string n, string a, string nivel)
        : Filme(n, a) {
        nivelAcao = nivel;
    }

    string getNivelAcao() {
        return nivelAcao;
    }

    void setNivelAcao(string nivel) {
        nivelAcao = nivel;
    }

    void exibirInformacoes() override {
        Filme::exibirInformacoes();
        cout << "Nivel de acao: " << nivelAcao << endl;
    }
};