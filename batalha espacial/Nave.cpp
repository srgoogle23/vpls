#include "Nave.hpp"
#include <iostream>

Nave::Nave(Ponto2D posicao, double forca)
{
	this->posicao = posicao;
	this->forca = forca;
	energia = 100;
}

Nave::Nave()
{
	posicao = Ponto2D();
	forca = 1;
	energia = 100;
}

void Nave::mover(double dx, double dy)
{
	posicao.x = posicao.x + dx;
	posicao.y = posicao.y + dy;
}

double Nave::calcular_distancia(Nave nave)
{
	return posicao.calcular_distancia(nave.posicao);
}

int Nave::determinar_indice_nave_mais_proxima(Nave naves[], int n)
{
	int indiceNave;
	// acha o indice da propria nave
	for (int i = 0; i < n; i++)
	{
		if (naves[i].posicao.x == posicao.x && naves[i].posicao.y == posicao.y)
		{
			indiceNave = i;
			break;
		}
	}

	int indiceNaveProxima;
	// acha o primeiro indice de naves que seja diferente do indice da propria nave
	for (int i = 0; i < n; i++)
	{
		if (i != indiceNave)
		{
			indiceNaveProxima = i;
			break;
		}
	}
	
	// acha o indice da nave mais proxima
	for (int i = 0; i < n; i++)
	{
		if (i != indiceNave)
		{
			if (calcular_distancia(naves[i]) < calcular_distancia(naves[indiceNaveProxima]))
			{
				indiceNaveProxima = i;
			}
		}
	}
	return indiceNaveProxima;
}

void Nave::atacar(Nave naves[], int n)
{
	// determina a nave mais proxima pro ataque
	int indiceNaveProxima = determinar_indice_nave_mais_proxima(naves, n);

	// ataca a nave mais proxima
	double dano = (this->forca * 100) / calcular_distancia(naves[indiceNaveProxima]);

	if (dano > 30)
		dano = 30;
	
	naves[indiceNaveProxima].energia = naves[indiceNaveProxima].energia - dano;

	// se a energia apos o ataque for menor ou igual a zero, a energia é zero
	if (naves[indiceNaveProxima].energia <= 0)
		naves[indiceNaveProxima].energia = 0;

	// Se após um ataque, a nave atacada tiver energia menor/igual a 50 deve ser impressa a mensagem "Energia baixa!".
	if (naves[indiceNaveProxima].energia <= 50)
		std::cout << "Energia baixa!" << std::endl;
}

void Nave::imprimir_status()
{
	// "x y energia".
	std::cout << posicao.x << " " << posicao.y << " " << energia << std::endl;
}