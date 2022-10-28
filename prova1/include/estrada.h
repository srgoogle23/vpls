#ifndef PDS2_ESTRADA_H
#define PDS2_ESTRADA_H

#include <random>
#include <set>

#include "carro.h"
#include "sapo.h"

enum MovimentoSapo {
  CIMA, BAIXO, ESQUERDA, DIREITA, NADA
};

class Estrada {
  private:
    unsigned int _num_linhas;
    unsigned int _num_colunas;
    unsigned int _taxa_carros;
    unsigned int _turno;
    Sapo &_sapo;
    std::set<Carro *> _carros;
    std::mt19937 _gera_rand;
  public:
    Estrada(
      unsigned int num_linhas,
      unsigned int num_colunas,
      unsigned int taxa_carros,
      Sapo &sapo
    );

    // Retorna true se o jogo acabou!
    bool atualiza(MovimentoSapo movimento);
    
    unsigned int get_num_linhas();
    unsigned int get_num_colunas();
    std::set<Carro *> get_carros();
};

#endif