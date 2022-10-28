#ifndef LISTA_PROCESSOS_HPP
#define LISTA_PROCESSOS_HPP

#include "Processo.hpp"
#include <map>

class ListaProcessos
{
    public:
		std::map<int, std::map<int, Processo, std::less<int>>, std::greater<int>> lista;
		ListaProcessos();
		void adicionar_processo(Processo proc);
		Processo remover_processo_maior_prioridade();
		Processo remover_processo_menor_prioridade();
		Processo remover_processo_por_id(int id);
		void imprimir_lista();
};

#endif