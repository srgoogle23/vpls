#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "Alocacao.hpp"

Alocacao :: Alocacao(std :: string dia, std :: string horario, std :: string sala){

    _dia = dia;
    _horario = horario;
    _sala = sala;

}

void Alocacao :: imprimir_dados(){

    std :: cout << _dia << " " << _horario << " " << _sala << std :: endl;
    
}