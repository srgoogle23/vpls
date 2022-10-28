#include "Ponto2D.hpp"
#include <cmath>

Ponto2D::Ponto2D()
{
	x = 0;
	y = 0;
}

Ponto2D::Ponto2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Ponto2D::calcular_distancia(Ponto2D ponto)
{
	double dx = x - ponto.x;
	double dy = y - ponto.y;
	return sqrt(dx*dx + dy*dy);
}