#include <random>

#include "estrada.h"


Estrada::Estrada(
  unsigned int num_linhas,
  unsigned int num_colunas,
  unsigned int taxa_carros,
  Sapo &sapo
): _sapo(sapo) {
  _num_linhas = num_linhas;
  _num_colunas = num_colunas;
  _taxa_carros = taxa_carros;
  _turno = 0;
  _gera_rand.seed(30091985);
}

bool Estrada::atualiza(MovimentoSapo movimento) {
  
  // [AVISO] as linhas abaixo geram carros aleatórios
  
  std::uniform_int_distribution<int> ldist(0, _num_linhas);
  std::uniform_int_distribution<int> cdist(0, 1);
  std::uniform_int_distribution<int> vdist(0, _num_colunas / 5);

  if (_turno % _taxa_carros == 0) {
    unsigned int linha_carro = ldist(_gera_rand);
    unsigned int col_carro = cdist(_gera_rand);
    unsigned int velocidade = vdist(_gera_rand);
    if (col_carro == 1) {
      col_carro = _num_colunas - 1;
    }

    // cria um um carro e adiciona no set de carros
    Carro *carro = new Carro(linha_carro, col_carro, velocidade);
    _carros.insert(carro);
  }

  // anda o sapo
  switch (movimento) {
    case CIMA:
      _sapo.mover_cima();
      break;
    case BAIXO:
      _sapo.mover_baixo();
      break;
    case ESQUERDA:
      _sapo.mover_esq();
      break;
    case DIREITA:
      _sapo.mover_direita();
      break;
    case NADA:
      break;
    }

  // Garanta que carros que saiem da tela são desalocados.
  for (auto it = _carros.begin(); it != _carros.end();) {
    Carro *carro = *it;
    bool moveu = carro->mover();
    if (moveu) {
      it = _carros.erase(it);
      delete carro;
    } else {
      ++it;
    }
  }

  // se o sapo andou até 0 fim da estrada, ele morreu
  if (_sapo.get_linha() == 0 || _sapo.get_linha() == _num_linhas - 1) {
    return true;
  }
  else
  {
    _turno++;
    return false;
  }
}

std::set<Carro *> Estrada::get_carros() {
  return _carros;
}

unsigned int Estrada::get_num_colunas() {
  return _num_colunas;
}

unsigned int Estrada::get_num_linhas() {
  return _num_linhas;
}