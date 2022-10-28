#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Alocacao.hpp"

struct Disciplina {
    
    //Atributos
    std :: string _codigo, _nome;
    std:: vector <Alocacao> alocacao;

    //Funçoes

    Disciplina(std :: string codigo, std :: string nome);
    Disciplina();
    void inserir_alocacao(std :: string dia, std :: string horario, std :: string sala);
    void remover_alocacao(std :: string horario);
    void imprimir_alocacao();
    
};

#endif
