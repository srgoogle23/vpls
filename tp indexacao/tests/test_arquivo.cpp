#include "doctest"
#include "arquivo.hpp"

// test two of constructors
TEST_CASE("Teste do construtor padrão")
{
	Arquivo arquivo;
	CHECK(arquivo.getNome() == "");
}

TEST_CASE("Teste do construtor com parâmetro")
{
	Arquivo arquivo("teste.txt");
	CHECK(arquivo.getNome() == "teste.txt");
}

// test get and set functions
TEST_CASE("Teste do setNome")
{
	Arquivo arquivo;
	arquivo.setNome("teste.txt");
	CHECK(arquivo.getNome() == "teste.txt");
}

TEST_CASE("Teste do getNome")
{
	Arquivo arquivo("teste.txt");
	CHECK(arquivo.getNome() == "teste.txt");
}

TEST_CASE("Teste do lePalavras")
{
	Arquivo arquivo("d1.txt");
	arquivo.lePalavras();
	CHECK_NOTHROW(arquivo.lePalavras());
}

// test the lerArquivo
TEST_CASE("Teste do lerArquivo")
{
	Arquivo arquivo("d1.txt");
	arquivo.lerArquivo();
	CHECK_NOTHROW(arquivo.lerArquivo());

	// check if the getWords returns size equal or greater than 1
	CHECK(arquivo.getWords().size() >= 1);
}


// test mesclarWords with d1.txt and d2.txt
TEST_CASE("Teste do mesclarWords")
{
	Arquivo arquivo1("d1.txt");
	Arquivo arquivo2("d2.txt");
	arquivo1.lerArquivo();
	arquivo2.lerArquivo();
	arquivo1.mesclarWords(arquivo2.getWords(), arquivo2.getNome());
	CHECK_NOTHROW(arquivo1.mesclarWords(arquivo2.getWords(), arquivo2.getNome()));

	// try to find "entrar" word in the map, that is in arquivo2 and need to be in arquivo1 after mesclarWords
	auto it = arquivo1.getWords().find("entrar");
	CHECK(it != arquivo1.getWords().end());
}

// test the substituiCaracteres d1.txt and see if porem is in the map
TEST_CASE("Teste do substituiCaracteres")
{
	Arquivo arquivo("d1.txt");
	arquivo.lerArquivo();
	CHECK_NOTHROW(arquivo.substituiCaracteres());

	// try to find "porem" word in the map, that is in arquivo1 and need to be in arquivo1 after substituiCaracteres
	auto it = arquivo.getWords().find("porem");
	CHECK(it != arquivo.getWords().end());
}