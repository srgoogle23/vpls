#include "carro.h"
#include <iostream>

Carro::Carro(
  unsigned int linha, unsigned int coluna,
  int velocidade
) {
  _linha = linha;
  _coluna = coluna;
  _velocidade = velocidade;
}

bool Carro::mover()
{
  int dy = _velocidade + _coluna;
  if(dy > 0)
  {
    _coluna = dy;
    return true;
  }
  else
  {
    return false;
  }
}

unsigned int Carro::get_coluna() {
  return _coluna;
}

unsigned int Carro::get_linha() {
  return _linha;
}

int Carro::get_velocidade() {
  return _velocidade;
}