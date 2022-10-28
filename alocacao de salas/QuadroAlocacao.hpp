#ifndef QUADROALOCACAO_H
#define QUADROALOCACAO_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Alocacao.hpp"
#include "Disciplina.hpp"

struct QuadroAlocacao {
    
    //Atributos
    std :: map <int, Disciplina> quadroAlocacao;

    //Funçoes
    int calculaCodigo(std :: string codigo);
    void inserir_alocacao(std :: string codigo, std :: string nome, std :: string dia, std :: string horario, std :: string sala);
    void remover_alocacao_disciplina(std :: string codigo, std :: string horario);
    std :: vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
    void imprimir_alocacao_completa();
    
};

#endif