#pragma once
#include "AnoL.h"
#include <string.h>
#include <iostream>
using namespace std;

class Filme {

      private:
      string nome;
      string avaliacao;
      string nacionalidade;
      AnoL lancamento;

      public:
      Filme(){
       nome = "";
       avaliacao = "";
       nacionalidade = "";
       }
       
      Filme(string n, string a, string c, AnoL l){
        nome = n;
        avaliacao = a;
        nacionalidade = c;
        lancamento = l;
      }
      
      string getNome(){
        return nome;}
           
      string getAvaliacao(){
        return avaliacao;
      }
      string getNacionalidade(){
        return nacionalidade;
      }
      AnoL getAno(){
        return lancamento;
      }
      void setNome(string n){
        nome = n;
      }
      void setAvaliacao(string a){
        avaliacao = a;
      }
      void setNacionalidade(string c){
        nacionalidade = c;
      }
      void setAno(AnoL l){
        lancamento = l;
    }
};