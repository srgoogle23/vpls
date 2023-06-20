#include "doctest"
#include "arquivo.hpp"
#include "pesquisa.hpp"
#include "utils.hpp"
#include <fstream>

TEST_SUITE("Arquivo") {
    TEST_CASE("Teste construtor e getters") {
        std::ofstream outfile("teste.txt");
        outfile.close();

        Arquivo arquivo("teste.txt");
        CHECK(arquivo.pegarNome() == "teste.txt");
        CHECK(arquivo.pegarPalavrasFormatadas().empty());

        std::remove("teste.txt");
    }

    TEST_CASE("Teste configurarNome e pegarNome") {
        Arquivo arquivo;
        arquivo.configurarNome("teste.txt");
        CHECK(arquivo.pegarNome() == "teste.txt");
    }

    TEST_CASE("Teste pegarPalavras") {
        std::ofstream outfile("teste.txt");
        outfile << "uma frase de teste";
        outfile.close();

        Arquivo arquivo("teste.txt");
        arquivo.pegarPalavras();
        std::vector<std::string> palavrasEsperadas = {"uma", "frase", "de", "teste"};
        CHECK(arquivo.pegarPalavrasFormatadas().empty());
        arquivo.mudarLetras();
        CHECK(arquivo.pegarPalavrasFormatadas().empty());
        arquivo.pegarArquivo();
        std::map<std::string, std::set<std::string>> wordsEsperadas = {
            {"uma", {"teste.txt"}},
            {"frase", {"teste.txt"}},
            {"de", {"teste.txt"}},
            {"teste", {"teste.txt"}}
        };
        CHECK(arquivo.pegarPalavrasFormatadas() == wordsEsperadas);

        std::remove("teste.txt");
    }

    TEST_CASE("Teste misturarPalavrasFormatadas") {
        Arquivo arquivo("teste.txt");
        arquivo.configurarPalavrasFormatadas({{"uma", {"arquivo1.txt"}}, {"frase", {"arquivo1.txt"}}});
        std::map<std::string, std::set<std::string>> words = {
            {"frase", {"arquivo2.txt"}},
            {"teste", {"arquivo2.txt"}}
        };
        arquivo.misturarPalavrasFormatadas(words, "arquivo2.txt");
        std::map<std::string, std::set<std::string>> wordsEsperadas = {
            {"uma", {"arquivo1.txt"}},
            {"frase", {"arquivo1.txt", "arquivo2.txt"}},
            {"teste", {"arquivo2.txt"}}
        };
        CHECK(arquivo.pegarPalavrasFormatadas() == wordsEsperadas);
    }
}

TEST_SUITE("Pesquisa") {
    TEST_CASE("Teste nomesDosArquivos") {
        Arquivo arquivo("teste.txt");
        arquivo.configurarPalavrasFormatadas({
            {"uma", {"arquivo1.txt"}},
            {"frase", {"arquivo1.txt", "arquivo2.txt"}},
            {"teste", {"arquivo2.txt"}}
        });
        Pesquisa pesquisa(arquivo);
        std::set<std::string> nomesEsperados = {"arquivo1.txt", "arquivo2.txt"};
        CHECK(pesquisa.nomesDosArquivos(arquivo.pegarPalavrasFormatadas()) == nomesEsperados);
    }

    TEST_CASE("Teste seraQueEhRelevante") {
        Arquivo arquivo("teste.txt");
        arquivo.configurarPalavrasFormatadas({
            {"uma", {"arquivo1.txt"}},
            {"frase", {"arquivo1.txt", "arquivo2.txt"}},
            {"teste", {"arquivo2.txt"}}
        });
        Pesquisa pesquisa(arquivo);
        std::map<std::string, std::set<std::string>> words = {
            {"uma", {"arquivo1.txt"}},
            {"frase", {"arquivo2.txt"}},
            {"teste", {"arquivo2.txt"}}
        };
        std::set<std::string> palavras = {"frase", "teste"};
		Arquivo arquivo2("arquivo2.txt");
        CHECK(pesquisa.seraQueEhRelevante(words, palavras, arquivo2.pegarNome()) == true);

        palavras = {"uma", "teste"};
        CHECK(pesquisa.seraQueEhRelevante(words, palavras, arquivo2.pegarNome()) == false);
    }

    TEST_CASE("Teste ajustarPesquisaFrase") {
        Arquivo arquivo("teste.txt");
        Pesquisa pesquisa(arquivo);
        std::set<std::string> palavrasEsperadas = {"uma", "frase"};
        CHECK(pesquisa.ajustarPesquisaFrase("   uma  Frase  ") == palavrasEsperadas);
    }
}
