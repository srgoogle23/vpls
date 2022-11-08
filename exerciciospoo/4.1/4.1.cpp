#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Circle
{
	private:
		double raio;
	public:
		Circle(double raio): raio(raio) {}
		double getRaio() const { return raio; }
		virtual double area() const { return 3.14159 * raio * raio; }
		virtual string toString() const { ostringstream os; os << "Circulo de raio " << raio; return os.str(); }
};

class Cylinder: public Circle
{
	private:
		double altura;
	public:
		Cylinder(double raio, double altura): Circle(raio), altura(altura) {}
		virtual double area() const override { return 2 * Circle::area() + 2 * 3.14159 * Circle::getRaio() * altura; }
		double getVolume() const { return Circle::area() * altura; }
		virtual string toString() const override { ostringstream os; os << "Cilindro de raio " << Circle::getRaio() << " e altura " << altura; return os.str(); }
};

void imprime(Circle *c)
{
	cout << c->toString() << endl;
}

int main()
{
	Circle c(10);
	Cylinder cl(10, 20);
	imprime(&c);
	imprime(&cl);
}