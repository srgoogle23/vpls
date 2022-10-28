#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include "QuadroAlocacao.hpp"

int QuadroAlocacao :: calculaCodigo(std :: string codigo)
{
    int codId;
    for(unsigned int i = 0; i < codigo.length(); i++)
    {
        codId += codigo[i] * pow(10, 2*(5 - i));
    }
    return codId;
}
void QuadroAlocacao :: inserir_alocacao(std :: string codigo, std :: string nome, std :: string dia, std :: string horario, std :: string sala)
{
    int codId;
    codId = calculaCodigo(codigo);
    if(quadroAlocacao.find(codId) == quadroAlocacao.end())
    {   
        Disciplina disciplinaNova(codigo, nome);
        disciplinaNova.inserir_alocacao(dia, horario, sala);
        quadroAlocacao[codId] = disciplinaNova;
    }
    else
    {
        quadroAlocacao[codId].inserir_alocacao(dia, horario, sala);
    }
    
}
void QuadroAlocacao :: remover_alocacao_disciplina(std :: string codigo, std :: string horario)
{
    int codId;
    codId = calculaCodigo(codigo);
    quadroAlocacao[codId].remover_alocacao(horario);

}

std :: vector<Disciplina> QuadroAlocacao :: recuperar_disciplinas_mais_ofertadas()
{   
    unsigned int maisOfertas = 0;
    std :: vector <Disciplina> disciplinaMaisOfertada;
    //define o maior numero de ofertas
    for(auto it = quadroAlocacao.begin(); it != quadroAlocacao.end(); it++) 
    {
        if(it->second.alocacao.size() > maisOfertas)
        {
            maisOfertas = it->second.alocacao.size();
        }
    }
    //recupera as disciplinas mais ofertadas
    for(auto it = quadroAlocacao.begin(); it != quadroAlocacao.end(); it++) 
    {
        if(it->second.alocacao.size() == maisOfertas)
        {
            disciplinaMaisOfertada.push_back(it->second);
        }
    }
    
    return disciplinaMaisOfertada;
}

void QuadroAlocacao :: imprimir_alocacao_completa()
{
    for (auto it = quadroAlocacao.begin(); it != quadroAlocacao.end(); it++) 
    {
        it -> second.imprimir_alocacao();
    }
}