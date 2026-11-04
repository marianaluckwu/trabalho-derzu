#pragma once
#include <iostream>
using namespace std;

class AnoL{ 
    private:
    int ano;

    public:
    AnoL(){
        ano = 0;
    }
    AnoL(int a){
        ano = a;
    }
    int getAno(){
        return ano;
    }
    void setAno(int a){
        ano = a;
    }

};