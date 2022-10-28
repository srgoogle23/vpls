#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <string>

class Processo
{
    public:
		int id;
        std::string nome;
        int prioridade;
        Processo();
        Processo(int id, std::string nome, int prioridade);
        void imprimir_dados();

};

#endif