#ifndef PESSOA_HPP
#define PESSOA_HPP

class Pessoa{
	protected:
		double x;
		double y;
	public:
		Pessoa(double x, double y);
		double getX();
		double getY();
		void mover(double dx, double dy);
};

#endif