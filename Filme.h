#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Filme {

      private:
      string nome;
      string avaliacao;

      public:
       
      Filme(string n, string a){
        nome = n;
        avaliacao = a;
      }
      string getNome(){
        return nome;
      }
      string getAvaliacao(){
        return avaliacao;
      }
      void setNome(string n){
        nome = n;
      }
      void setAvaliacao(string a){
        avaliacao = a;
      }



};