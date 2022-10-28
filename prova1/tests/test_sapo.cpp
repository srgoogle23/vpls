#include "doctest.h"

#include "sapo.h"

TEST_CASE("Testa o Sapo") {
  Sapo sapo = Sapo(0, 0);
  CHECK_EQ(0, sapo.get_linha());
  CHECK_EQ(0, sapo.get_coluna());

  // Testa cima com erro
  sapo.mover_cima();
  CHECK_EQ(0, sapo.get_linha());
  CHECK_EQ(0, sapo.get_coluna());

  // Testa esq com erro
  sapo.mover_esq();
  CHECK_EQ(0, sapo.get_linha());
  CHECK_EQ(0, sapo.get_coluna());

  // Testa ok
  sapo.mover_direita();
  CHECK_EQ(0, sapo.get_linha());
  CHECK_EQ(1, sapo.get_coluna());

  // Testa ok
  sapo.mover_baixo();
  CHECK_EQ(1, sapo.get_linha());
  CHECK_EQ(1, sapo.get_coluna());

  // Testa ok
  sapo.mover_cima();
  CHECK_EQ(0, sapo.get_linha());
  CHECK_EQ(1, sapo.get_coluna());

  // Testa ok
  sapo.mover_esq();
  CHECK_EQ(0, sapo.get_linha());
  CHECK_EQ(0, sapo.get_coluna());
}