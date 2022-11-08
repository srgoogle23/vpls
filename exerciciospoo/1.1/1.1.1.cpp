#include <iostream>
using namespace std;

class Lampada
{
		int watts;
		float preco;
	public:
		Lampada();
		Lampada(int watts, float preco);
		Lampada(int watts);
		float operator+(Lampada const &lp);
};

Lampada::Lampada()
{
	watts = 0;
	preco = 0;
}

Lampada::Lampada(int watts, float preco)
{
	this->watts = watts;
	this->preco = preco;
}

Lampada::Lampada(int watts)
{
	this->watts = watts;
	this->preco = 0;
}

float Lampada::operator+(Lampada const &lp)
{
	return this->preco + lp.preco;
}

int main()
{
	Lampada l1(1, 1.0);
	Lampada l2(1, 2.0);
	cout << "Soma: " << l1 + l2 << endl;
	return 0;
}