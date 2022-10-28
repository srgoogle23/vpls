#ifndef GELADEIRA_HPP
#define GELADEIRA_HPP

#include <iostream>

class Geladeira {
    private:
        int capacidade_em_litros;
        int numero_de_portas;
    public:
        Geladeira(int capacidade_em_litros, int numero_de_portas);
        Geladeira();
        int get_capacidade_em_litros();
        int get_numero_de_portas();
};

#endif