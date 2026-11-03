#pragma once

#include <string>
#include <iostream>
#include "Filme.h"

using namespace std;

class Comedia : public Filme {
private:
    string estiloHumor;

public:
    Comedia(string n, string a, string estilo)
        : Filme(n, a) {
        estiloHumor = estilo;
    }

    string getEstiloHumor() {
        return estiloHumor;
    }

    void setEstiloHumor(string estilo) {
        estiloHumor = estilo;
    }

    void exibirInformacoes() override {
        Filme::exibirInformacoes();
        cout << "Estilo de humor: " << estiloHumor << endl;
    }
};