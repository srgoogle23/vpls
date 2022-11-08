#include <string>
#include <iostream>

using namespace std;

class Shape
{
	private:
		string color;

	public:
		Shape(string color): color(color) {}
		Shape() : color("") {}
		virtual double getArea() const = 0;
		virtual string toString() const { return "cor: " + color; }
};

class Rectangle: public Shape
{
	private:
		double width;
		double height;

	public:
		Rectangle(double width, double height, string color): Shape(color), width(width), height(height) {}
		virtual double getArea() const override { return width * height; }
		virtual string toString() const override { return Shape::toString() + " largura: " + to_string(width) + " altura: " + to_string(height); }
};

class Triangle: public Shape
{
	private:
		double base;
		double height;

	public:
		Triangle(double base, double height, string color): Shape(color), base(base), height(height) {}
		virtual double getArea() const override { return base * height / 2; }
		virtual string toString() const override { return Shape::toString() + " base: " + to_string(base) + " altura: " + to_string(height); }
};

int main()
{
	Rectangle r(10, 20, "vermelho");
	Triangle t(10, 20, "verde");
	cout << r.toString() << endl;
	cout << t.toString() << endl;
}