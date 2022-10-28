#include "estrada.h"
#include "doctest.h"

TEST_CASE("Testa se os carros gerados foram inseridos com sucesso")
{
	Sapo sapo(0, 0);
	Estrada estrada(10, 10, 1, sapo);
	estrada.atualiza(NADA);
	std::set<Carro *> carros = estrada.get_carros();
	CHECK(carros.size() == 1);

	// testa uma estrada com 10 carros
	Estrada estrada2(10, 10, 10, sapo);
	while(estrada2.get_carros().size() < 10)
	{
		estrada2.atualiza(NADA);
	}
	std::set<Carro *> carros2 = estrada2.get_carros();
	CHECK(carros2.size() == 10);
}

TEST_CASE("Testa se os carros andam")
{
	Sapo sapo(0, 0);
	Estrada estrada(10, 10, 1, sapo);
	estrada.atualiza(NADA);
	std::set<Carro *> carros = estrada.get_carros();
	for(auto carro : carros)
	{
		int coluna = carro->get_coluna();
		int velocidade = carro->get_velocidade();
		bool moveu = carro->mover();

		velocidade *= -1;

		if(moveu)
		{
			CHECK(coluna == carro->get_coluna() + velocidade);
		}
		else
		{
			CHECK(coluna == carro->get_coluna());
		}
	}

	// testa com 10 carros
	Estrada estrada2(10, 10, 10, sapo);
	for(int i = 0; i < 100; i++)
	{
		estrada2.atualiza(NADA);
	}
	std::set<Carro *> carros2 = estrada2.get_carros();
	for(auto carro : carros2)
	{
		int coluna = carro->get_coluna();
		int velocidade = carro->get_velocidade();
		velocidade *= -1;
		bool moveu = carro->mover();
		if(moveu)
		{
			CHECK(coluna == carro->get_coluna() + velocidade);
		}
		else
		{
			CHECK(coluna == carro->get_coluna());
		}
	}
}

TEST_CASE("Testa se o sapo anda")
{
	Sapo sapo(0, 0);
	Estrada estrada(10, 10, 1, sapo);
	estrada.atualiza(NADA);
	int linha = sapo.get_linha();
	int coluna = sapo.get_coluna();

	// mover cima
	estrada.atualiza(CIMA);
	if (linha > 0)
    	linha--;
	CHECK(linha == sapo.get_linha());
	CHECK(coluna == sapo.get_coluna());

	// mover baixo
	estrada.atualiza(BAIXO);
	linha++;
	CHECK(linha == sapo.get_linha());
	CHECK(coluna == sapo.get_coluna());

	// mover esquerda
	estrada.atualiza(ESQUERDA);
	if (coluna > 0)
    	coluna--;
	CHECK(linha == sapo.get_linha());
	CHECK(coluna == sapo.get_coluna());

	// mover direita
	estrada.atualiza(DIREITA);
	coluna++;
	CHECK(linha == sapo.get_linha());
	CHECK(coluna == sapo.get_coluna());
}

TEST_CASE("Testa se o sapo morre")
{
	// testa se o sapo morre ao sair da tela
	Sapo sapo(2, 2);
	Estrada estrada(10, 10, 1, sapo);
	estrada.atualiza(NADA);
	CHECK(estrada.atualiza(CIMA) == false);
	CHECK(estrada.atualiza(BAIXO) == false);
	CHECK(estrada.atualiza(ESQUERDA) == false);
	CHECK(estrada.atualiza(DIREITA) == false);
	estrada.atualiza(CIMA);
	CHECK(estrada.atualiza(CIMA) == true);
}