#pragma once
#include <string>
#include <iostream>
#include "Filme.h"
#include "AnoL.h"

using namespace std;

class Comedia : public Filme {
private:
    string estiloHumor;

public:
    Comedia(string estilo, string n, string a, string c, AnoL l)
        : Filme(n, a, c, l) {
        estiloHumor = estilo;
    }

    string getEstiloHumor() {
        return estiloHumor;
    }

    void setEstiloHumor(string estilo) {
        estiloHumor = estilo;
    }

    string getGenero() override{
    return "Comedia";
    }   

    void exibirInformacoes() override {
        Filme::exibirInformacoes();
        cout << "Estilo de humor: " << estiloHumor << endl;
    }
};