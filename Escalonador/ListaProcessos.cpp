#include "ListaProcessos.hpp"
#include <iostream>

ListaProcessos::ListaProcessos()
{

}

void ListaProcessos::adicionar_processo(Processo proc)
{
	lista[proc.prioridade][proc.id] = proc;
}

Processo ListaProcessos::remover_processo_maior_prioridade()
{
	Processo proc = lista.begin()->second.begin()->second;
	// recupera o id do mesmo
	int id = proc.id;
	// recupera a prioridade
	int prioridade = proc.prioridade;
	// remove o processo
	lista[prioridade].erase(id);
	// se não houver mais processos com a prioridade, remove a prioridade
	if (lista[prioridade].empty())
		lista.erase(prioridade);
	return proc;
}

Processo ListaProcessos::remover_processo_menor_prioridade()
{
	Processo proc = lista.rbegin()->second.rbegin()->second;
	// recupera o id do mesmo
	int id = proc.id;
	// recupera a prioridade
	int prioridade = proc.prioridade;
	// remove o processo
	lista[prioridade].erase(id);
	// se não houver mais processos com a prioridade, remove a prioridade
	if (lista[prioridade].empty())
		lista.erase(prioridade);
	return proc;
}

Processo ListaProcessos::remover_processo_por_id(int id)
{
	int prioridade = -1;
	// descobre em qual prioridade está o processo
	for (auto it = lista.begin(); it != lista.end(); it++)
		if (it->second.find(id) != it->second.end())
			prioridade = it->first;

	// se não encontrou, retorna um processo com id -1
	if (prioridade == -1)
		return Processo(-1, "", -1);

	// recupera o processo
	Processo proc = lista[prioridade][id];
	
	// recria a lista sem o processo do id
	lista[prioridade].erase(id);
	// se não houver mais processos com a prioridade, remove a prioridade
	if (lista[prioridade].empty())
		lista.erase(prioridade);
	
	return proc;
}

void ListaProcessos::imprimir_lista()
{
	for (auto it = lista.begin(); it != lista.end(); it++)
	{
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			it2->second.imprimir_dados();
		}
	}
}