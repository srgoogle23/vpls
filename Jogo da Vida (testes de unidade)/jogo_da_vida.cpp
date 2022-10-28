#include "jogo_da_vida.h"
#include <iostream>
using namespace std;

JogoDaVida::JogoDaVida(int l, int c): vivas_(l, std::vector<bool>(c, false)) {}

bool JogoDaVida::viva(int i, int j)
{
	if((0 <= i && i < linhas()) && (0 <= j && j < colunas()))
		return vivas_[i][j];
	else
	    throw ExcecaoCelulaInvalida{i, j};

}

void JogoDaVida::Matar(int i, int j)
{
    if((0 <= i && i < linhas()) && (0 <= j && j < colunas()))
		vivas_[i][j] = false;
	else
		throw ExcecaoCelulaInvalida{i, j};
}

void JogoDaVida::Reviver(int i, int j)
{
	if((0 <= i && i < linhas()) && (0 <= j && j < colunas()))
		vivas_[i][j] = true;
	else
		throw ExcecaoCelulaInvalida{i, j};
}


void JogoDaVida::ExecutarProximaIteracao()
{
	for (int i = 0; i < linhas(); i++)
	{
		for (int j = 0; j < colunas(); j++)
		{
			int vizinhas = NumeroDeVizinhasVivas(i, j);
			if (viva(i, j))
			{
				if (vizinhas < 2 || vizinhas > 3)
				    Matar(i, j);
			}
			else
			{
				if (vizinhas == 3)
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