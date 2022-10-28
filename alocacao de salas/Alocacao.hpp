#ifndef ALOCACAO_H
#define ALOCACAO_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

struct Alocacao {
    
    //Atributos
    std :: string _dia, _horario, _sala; 

    //Funçoes

    Alocacao(std :: string dia, std :: string horario, std :: string sala);
    void imprimir_dados();
    
};

#endif