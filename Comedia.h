#pragma once
#include <string>
#include <iostream>
#include "Filme.h"

using namespace std;

class Comedia : public Filme {
private:
    string tipoHumor;

public:
    Comedia(string n, string a, string tipo)
        : Filme(n, a) {
        tipoHumor = tipo;
    }

    string getTipoHumor() {
        return tipoHumor;
    }

    void setTipoHumor(string tipo) {
        tipoHumor = tipo;
    }

    void exibirInformacoes() override {
        Filme::exibirInformacoes();
        cout << "Tipo de humor: " << tipoHumor << endl;
    }
};