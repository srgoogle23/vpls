#ifndef FILA_PROCESSOS_HPP
#define FILA_PROCESSOS_HPP

#include "Processo.hpp"
#include <map>

class FilaProcessos
{
	protected:
		int ids;
	public:
		std::map<int, std::map<int, Processo, std::less<int>>, std::greater<int>> lista;
		FilaProcessos();
		void adicionar_processo(std::string nome, int prioridade);
		Processo* remover_processo_maior_prioridade();
		Processo* remover_processo_menor_prioridade();
		Processo* remover_processo_por_id(int id);
		void imprimir_fila();
		void estimativa_tempo_para_execucao(int id);
};

#endif