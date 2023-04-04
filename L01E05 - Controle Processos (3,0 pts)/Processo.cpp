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

// Método que faz a impressão dos atributos do processo no seguinte formato: "id nome prioridade", com uma quebra de linha ao final. Atenção, nesse caso utilize tab (\t) para separar os elementos. Além disso, substitua o código da prioridade por: BAIXA, MEDIA ou ALTA.
void Processo::imprimir_dados() 
{
	std::string p;
	if (this->prioridade == 0)
	{
		p = "BAIXA";
	}
	else if (this->prioridade == 1)
	{
		p = "MEDIA";
	}
	else if (this->prioridade == 2)
	{
		p = "ALTA";
	}
	else
	{
		p = "ERRO";
	}
	std::cout << this->id << " " << this->nome << " " << p << std::endl;
}

// Método que retorna o tempo reservado para execução do processo de acordo com a prioridade. Prioridade: BAIXA (0.5), MÉDIA (1.5), ALTA (3.0).
double Processo::tempo_reservado_processo()
{
	if (this->prioridade == 0)
	{
		return 0.5;
	}
	else if (this->prioridade == 1)
	{
		return 1.5;
	}
	else if (this->prioridade == 2)
	{
		return 3.0;
	}
	else
	{
		return 0.0;
	}
}	