#include "doctest"
#include "utils.hpp"

// test the constructor
TEST_CASE("testando o construtor")
{
	// test not throws
	CHECK_NOTHROW(Utils());
}

// test the function removerAcentos
TEST_CASE("testando a funcao removerAcentos")
{
	// test not throws
	CHECK_NOTHROW(Utils::removerAcentos("teste"));
	// test the return
	CHECK(Utils::removerAcentos("teste") == "teste");
	CHECK(Utils::removerAcentos("áéíóú") == "aeiou");
	CHECK(Utils::removerAcentos("ÁÉÍÓÚ") == "aeiou");
	CHECK(Utils::removerAcentos("âêîôû") == "aeiou");
	CHECK(Utils::removerAcentos("ÂÊÎÔÛ") == "aeiou");
	CHECK(Utils::removerAcentos("ãõ") == "ao");
	CHECK(Utils::removerAcentos("ÃÕ") == "ao");
	CHECK(Utils::removerAcentos("ç") == "c");
	CHECK(Utils::removerAcentos("Ç") == "c");
}