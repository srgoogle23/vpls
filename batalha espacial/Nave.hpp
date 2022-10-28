#ifndef _NAVE_HPP_
#define _NAVE_HPP_

#include "Ponto2D.hpp"

class Nave
{
	private:
		Ponto2D posicao;
		double forca, energia;
	public:
		Nave(Ponto2D, double);
		Nave();
		void mover(double, double);
		double calcular_distancia(Nave);
		int determinar_indice_nave_mais_proxima(Nave naves[], int n);
		void atacar(Nave naves[], int n);
		void imprimir_status();
};

#endif