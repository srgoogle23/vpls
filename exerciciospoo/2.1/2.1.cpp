#include <string>
#include <iostream>

using namespace std;

class Data{
	private:
		int dia;
		int mes;
		int ano;
	public:
		Data(int d, int m, int a);
		string imprime();
};

Data::Data(int d, int m, int a){
	dia = d;
	mes = m;
	ano = a;
}

string Data::imprime(){
	string s = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
	return s;
}

class Hora{
	private:
		int hora;
		int min;
		int seg;
	public:
		Hora(int h, int m, int s);
		string imprime();
};

Hora::Hora(int h, int m, int s){
	hora = h;
	min = m;
	seg = s;
}

string Hora::imprime(){
	string s = to_string(hora) + "/" + to_string(min) + "/" + to_string(seg);
	return s;
}

class Calendario
{
	private:
		Data data;
		Hora hora;
	public:
		Calendario(int d, int m, int a, int h, int min, int s);
		string imprime();
};

Calendario::Calendario(int d, int m, int a, int h, int min, int s) : data(d, m, a), hora(h, min, s) {}

string Calendario::imprime(){
	return data.imprime() + " " + hora.imprime();
}

int main(){
	Calendario c(4, 11, 2022, 18, 12, 0);
	cout << c.imprime() << endl;
	return 0;
}