#include "sapo.h"

Sapo::Sapo(
  unsigned int linha, unsigned int coluna
) {
  _linha = linha;
  _coluna = coluna;
}

unsigned int Sapo::get_linha() {
  return _linha;
}

unsigned int Sapo::get_coluna() {
  return _coluna;
}

void Sapo::mover_cima() {
  if (_linha > 0)
    _linha--;
}

void Sapo::mover_direita() {
  _coluna++;
}

void Sapo::mover_esq() {
  if (_coluna > 0)
    _coluna--;
}

void Sapo::mover_baixo() {
  _linha++;
}