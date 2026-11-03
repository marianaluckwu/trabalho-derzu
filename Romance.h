#pragma once
#include <string>
#include <iostream>
#include "Filme.h"
#include "AnoL.h"
using namespace std;

class Romance : public Filme {
private:
    bool finalFeliz;

public:
    Romance( bool final, string n, string a, string c, AnoL l)
        : Filme(n, a, c, l) {
         finalfeliz = final;
    }

    bool getFinalFeliz() {
        return finalFeliz;
    }
    string getGenero() override{
    return "Romance";
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