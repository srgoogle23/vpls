#ifndef CARRO_HPP
#define CARRO_HPP

#include "Pessoa.hpp"

#include <cmath>
#include <iostream>

class Carro{
	protected:
		double x;
		double y;
		double th;
	public:
		Carro(double x, double y, double th);
		double getX();
		double getY();
		double getTH();
		void setX(double x);
		void setY(double y);
		void setTH(double th);
		void girar(double w, double t);
		void mover(double v, double t);
		double calcular_angulo_pessoa(Pessoa *pessoa);
		double calcular_distancia_pessoa(Pessoa *pessoa);
		bool movimentacao_permitida(Pessoa **pessoas, int n);
		void navegar(Pessoa **pessoas, int n, double w, double v, double t);
};

#endif