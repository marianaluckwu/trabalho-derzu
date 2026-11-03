#pragma once
#include <string>
#include <iostream>
#include "Filme.h"

using namespace std;

class Acao : public Filme {
private:
    bool violento;

public:
    Acao(string n, string a, bool v)
        : Filme(n, a) {
        violento = v;
    }

    bool getViolento() {
        return violento;
    }

    void setViolento(bool v) {
        violento = v;
    }

    void exibirInformacoes() override {
    Filme::exibirInformacoes();

    if (violento) {
        cout << "Violento: Sim" << endl;
    } else {
        cout << "Violento: Nao" << endl;
    }
}
};