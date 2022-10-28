#ifndef _PONTO_HPP_
#define _PONTO_HPP_

class Ponto2D
{
	public:
		double x, y;
		Ponto2D();
		Ponto2D(double, double);
		double calcular_distancia(Ponto2D ponto);
};

#endif