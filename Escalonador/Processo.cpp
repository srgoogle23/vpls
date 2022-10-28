#include "Processo.hpp"
#include <iostream>

Processo::Processo()
{
    
}

Processo::Processo(int id, std::string nome, int prioridade)
{
    this->id = id;
    this->nome = nome;
    this->prioridade = prioridade;
}

void Processo::imprimir_dados() 
{
    std::cout << " " << this->id << " " << this->nome << " " << this->prioridade << std::endl;
}