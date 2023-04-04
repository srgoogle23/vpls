	#include "FilaProcessos.hpp"
	#include <iostream>
	#include <iomanip>

	FilaProcessos::FilaProcessos()
	{
		ids = 1;
	}

	void FilaProcessos::adicionar_processo(std::string nome, int prioridade)
	{
		// cria o processo
		Processo proc = Processo(ids, nome, prioridade);
		// incrementa o id
		ids++;
		// adiciona o processo na lista
		lista[proc.prioridade][proc.id] = proc;
	}

	Processo* FilaProcessos::remover_processo_maior_prioridade()
	{
		Processo* proc = &lista.begin()->second.begin()->second;
		// recupera o id do mesmo
		int id = proc->id;
		// recupera a prioridade
		int prioridade = proc->prioridade;
		// remove o processo
		lista[prioridade].erase(id);
		// se não houver mais processos com a prioridade, remove a prioridade
		if (lista[prioridade].empty())
			lista.erase(prioridade);
		return proc;
	}

	Processo* FilaProcessos::remover_processo_menor_prioridade()
	{
		// cria um ponteiro para o processo
		Processo* proc = &lista.begin()->second.begin()->second;
		// recupera o id do mesmo
		int id = proc->id;
		// recupera a prioridade
		int prioridade = proc->prioridade;
		// remove o processo
		lista[prioridade].erase(id);
		// se não houver mais processos com a prioridade, remove a prioridade
		if (lista[prioridade].empty())
			lista.erase(prioridade);
		return proc;
	}

	Processo* FilaProcessos::remover_processo_por_id(int id)
	{
		int prioridade = -1;
		// descobre em qual prioridade está o processo
		for (auto it = lista.begin(); it != lista.end(); it++)
			if (it->second.find(id) != it->second.end())
				prioridade = it->first;

		// se não encontrou, retorna um processo com id -1
		if (prioridade == -1)
			return new Processo(-1, "", -1);

		// recupera o processo
		Processo* proc = &lista[prioridade][id];
		
		// recria a lista sem o processo do id
		lista[prioridade].erase(id);
		// se não houver mais processos com a prioridade, remove a prioridade
		if (lista[prioridade].empty())
			lista.erase(prioridade);
		
		return proc;
	}

	void FilaProcessos::imprimir_fila()
	{
		for (auto it = lista.begin(); it != lista.end(); it++)
		{
			for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
			{
				it2->second.imprimir_dados();
			}
		}
	}

	void FilaProcessos::estimativa_tempo_para_execucao(int id)
	{
		// faz o somatório dos tempos reservados de acordo com a prioridade dos processos à sua na frente da fila
		double tempo = 0;
		// descobre em qual prioridade está o processo
		for (auto it = lista.begin(); it != lista.end(); it++)
		{
			if (it->second.find(id) != it->second.end())
			{
				// recupera o processo
				Processo* proc = &it->second[id];
				// recupera a prioridade
				int prioridade = proc->prioridade;
				// faz o somatório dos tempos reservados de acordo com a prioridade dos processos à sua na frente da fila
				// considera por exemplo, que um processo de prioridade 2 está na frente de um processo de prioridade 1, e que o processo de prioridade 1 está na frente de um processo de prioridade 0
				// o processo de prioridade 2 so vai somar com o tempo de prioridade 2
				// o processo de prioridade 1 vai somar com o tempo de prioridade 1 e 2
				// o processo de prioridade 0 vai somar com o tempo de prioridade 0, 1 e 2
				for (auto it2: lista)
				{
					if (it2.first >= prioridade)
					{
						for (auto it3: it2.second)
						{
							// nao conta ele msm
							if (it3.second.id >= id && it2.first == prioridade)
								break;

							tempo += it3.second.tempo_reservado_processo();
						}
					}
				}
				
				// imprime o tempo estimado
				// Tempo estimado para execução do processo NOMEPROCESSO (id=ID) eh X.X segundos. Mostrando o tempo em decimais com 1 casa.
				std::cout << "Tempo estimado para execução do processo ";
				std::cout << proc->nome;
				std::cout << " (id=";
				std::cout << proc->id;
				std::cout << ") eh ";
				std::cout << std::fixed << std::setprecision(1) << tempo;
				std::cout << " segundos." << std::endl;
				return;
			}
		}
	}