#pragma once
#include <string>
#include <iostream>
#include "Filme.h"

using namespace std;

class Romance : public Filme {
private:
    bool finalFeliz;

public:
    Romance(string n, string a, bool final)
        : Filme(n, a) {
        finalFeliz = final;
    }

    bool getFinalFeliz() {
        return finalFeliz;
    }

    void setFinalFeliz(bool final) {
        finalFeliz = final;
    }

    void exibirInformacoes() override {
        Filme::exibirInformacoes();

        if (finalFeliz) {
            cout << "Final feliz: Sim" << endl;
        } else {
            cout << "Final feliz: Nao" << endl;
        }
    }
};