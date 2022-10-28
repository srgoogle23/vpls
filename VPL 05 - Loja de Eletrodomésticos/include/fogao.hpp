#ifndef FOGAO_HPP
#define FOGAO_HPP

#include <iostream>

class Fogao {
    private:
        int numero_de_queimadores;
        int capacidade_forno;
    public:
        Fogao();
        Fogao(int numero_de_queimadores, int capacidade_forno);
        int get_numero_de_queimadores();
        int get_capacidade_forno();
};

#endif