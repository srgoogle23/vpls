#include "jogo_da_vida.h"
#include <iostream>
using namespace std;

JogoDaVida::JogoDaVida(int l, int c): vivas_(l, std::vector<bool>(c, false)) {}

bool JogoDaVida::viva(int i, int j)
{
	if((0 <= i && i < linhas()) && (0 <= j && j < colunas()))
		return vivas_[i][j];
	else
	    return false;
}

void JogoDaVida::Matar(int i, int j)
{
    if((0 <= i && i < linhas()) && (0 <= j && j < colunas()))
		vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j)
{
	if((0 <= i && i < linhas()) && (0 <= j && j < colunas()))
		vivas_[i][j] = true;
}


void JogoDaVida::ExecutarProximaIteracao()
{
	// cria uma cópia do estado atual
	JogoDaVida copia(linhas(), colunas());
	for (int i = 0; i < linhas(); i++)
	{
		for (int j = 0; j < colunas(); j++)
		{
			copia.vivas_[i][j] = vivas_[i][j];
		}
	}

	// Nascimentos e mortes são instantâneos e ocorrem simultaneamente no início de cada iteração.
	// Uma célula que morre por qualquer razão pode ajudar a provocar o nascimento, mas uma célula recém-nascida não pode ressuscitar uma célula que está morrendo
	// nem a morte de uma célula impede a morte de outra, digamos, por meio da redução da população local.
	for (int i = 0; i < linhas(); i++)
	{
		for (int j = 0; j < colunas(); j++)
		{
			int vizinhas_copia = copia.NumeroDeVizinhasVivas(i, j);

			if (copia.viva(i, j))
			{
				if (vizinhas_copia < 2 || vizinhas_copia > 3)
					Matar(i, j);
			}
			else
			{
				if (vizinhas_copia == 3)
				    Reviver(i, j);
			}
		}
	}
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y)
{
	int vizinhas_vivas = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i == x && j == y)
				continue;
			if (i < 0 || i >= linhas() || j < 0 || j >= colunas())
				continue;
			if (vivas_[i][j] == true)
				vizinhas_vivas++;
		}
	}
	return vizinhas_vivas;
}