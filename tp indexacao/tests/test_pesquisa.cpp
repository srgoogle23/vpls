#include "doctest"
#include "pesquisa.hpp"

// test constructors
TEST_CASE("Testando construtores")
{
	Pesquisa p;
	// check not throws
	CHECK_NOTHROW(Pesquisa p);

	Arquivo a;
	Pesquisa p2(a);
	// check not throws
	CHECK_NOTHROW(Pesquisa p2(a));
}

// test relavante function
TEST_CASE("Testando relavante")
{
	// create an map<string, set<string>> words that include the word "foo" to file "bar.txt"
	map<string, set<string>> words;
	words["foo"].insert("bar.txt");
	set<string> palavras;
	palavras.insert("foo");
	Pesquisa p;
	// check if the function return true
	CHECK(p.relavante(words, palavras, "bar.txt"));
}

// test normalizaPesquisa
TEST_CASE("Testando normalizaPesquisa")
{
	Pesquisa p;
	// check if the function return a set with the word "foo"
	CHECK(p.normalizaPesquisa("foo") == set<string>{"foo"});
}

// test procuraNomeArquivos
TEST_CASE("Testando procuraNomeArquivos")
{
	// create an map<string, set<string>> words that include the word "foo" to file "bar.txt"
	map<string, set<string>> words;
	words["foo"].insert("bar.txt");
	Pesquisa p;
	// check if the function return a set with the file "bar.txt"
	CHECK(p.procuraNomeArquivos(words) == set<string>{"bar.txt"});
}

// test pesquisaRelavancia
TEST_CASE("Testando pesquisaRelavancia")
{
	// create an map<string, set<string>> words that include the word "foo" to file "bar.txt"
	map<string, set<string>> words;
	words["foo"].insert("bar.txt");
	Arquivo a;
	a.setWords(words);
	Pesquisa p(a);
	
	// check if the function return a map with the file "bar.txt" and the value 1
	CHECK(p.pesquisaRelavancia("foo") == map<string, int, less<string>>{{"bar.txt", 1}});
}