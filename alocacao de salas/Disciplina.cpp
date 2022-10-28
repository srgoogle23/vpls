#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "Alocacao.hpp"
#include "Disciplina.hpp"

Disciplina :: Disciplina(std :: string codigo, std :: string nome){

    _codigo = codigo;
    _nome = nome;

}

Disciplina :: Disciplina(){

}

void Disciplina :: inserir_alocacao(std :: string dia, std :: string horario, std :: string sala)
{

    Alocacao novaAlocacao(dia, horario, sala);
    alocacao.push_back(novaAlocacao);
    
}

void Disciplina :: remover_alocacao(std :: string horario)
{
    int i = 0;
    for (auto it = alocacao.begin(); it != alocacao.end(); it++) 
    {
        if (alocacao[i]._horario == horario) 
        {
            alocacao.erase(it);
            break;
        } 
        i++;
    }
}

void Disciplina :: imprimir_alocacao()
{
    int i = 0;
    for(int x = (alocacao.size() - 2); x >= 0; x--){
        if(alocacao[x]._horario.compare(alocacao[x + 1]._horario) == 0)
        {
            continue;
        }
        else if(alocacao[x]._horario.compare(alocacao[x + 1]._horario) < 0)
        {
            continue;
        }
        else
        {
            Alocacao intermediario = alocacao[x];
            alocacao[x] = alocacao[x + 1];
            alocacao[x + 1] = intermediario;
        }
    }
    for (auto it = alocacao.begin(); it != alocacao.end(); it++) 
    {
        std :: cout << _codigo << " " << _nome << " ";
        alocacao[i].imprimir_dados();
        i++;  
    }

}