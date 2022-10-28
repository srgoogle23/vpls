#include "carro.h"
#include "doctest.h"

TEST_CASE("Testa Carro Construtor") {
  Carro carro = Carro(5, 3, -2);
  CHECK_EQ(5, carro.get_linha());
  CHECK_EQ(3, carro.get_coluna());
  CHECK_EQ(-2, carro.get_velocidade());
}

TEST_CASE("Testa Carro Esquerda") {
  Carro carro = Carro(5, 3, -2);
  carro.mover();
  CHECK_EQ(5, carro.get_linha());
  CHECK_EQ(1, carro.get_coluna());
  CHECK_EQ(-2, carro.get_velocidade());

  carro.mover();
  CHECK_EQ(5, carro.get_linha());
  CHECK_EQ(1, carro.get_coluna());
  CHECK_EQ(-2, carro.get_velocidade());
}

TEST_CASE("Testa Carro Direita") {
  Carro carro = Carro(5, 3, 3);
  carro.mover();
  CHECK_EQ(5, carro.get_linha());
  CHECK_EQ(6, carro.get_coluna());
  CHECK_EQ(3, carro.get_velocidade());
}

TEST_CASE("Testa o carro em todas as direções")
{
  Carro carro = Carro(5, 3, 3);
  carro.mover();
  CHECK_EQ(5, carro.get_linha());
  CHECK_EQ(6, carro.get_coluna());
  CHECK_EQ(3, carro.get_velocidade());

  carro.mover();
  CHECK_EQ(5, carro.get_linha());
  CHECK_EQ(9, carro.get_coluna());
  CHECK_EQ(3, carro.get_velocidade());

  carro.mover();
  CHECK_EQ(5, carro.get_linha());
  CHECK_EQ(12, carro.get_coluna());
  CHECK_EQ(3, carro.get_velocidade());
}