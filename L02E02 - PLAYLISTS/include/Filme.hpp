#ifndef FILME_HPP
#define FILME_HPP

#include <string>
#include <iostream>

using namespace std;

class Filme
{
    public:
        string _nome;
		string _genero;
		int _duracao;
		Filme();
		Filme(string nome, string genero, int duracao);
		void imprimir_dados();
};

#endif