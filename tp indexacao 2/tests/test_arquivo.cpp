#include "doctest"
#include "arquivo.hpp"
#include "utils.hpp"
#include <fstream>

TEST_CASE("Teste construtor e getters") {
    std::ofstream outfile("teste.txt");
    outfile.close();

    Arquivo arquivo("teste.txt");
    CHECK(arquivo.getNome() == "teste.txt");
    CHECK(arquivo.getWords().empty());

    std::remove("teste.txt");
}

TEST_CASE("Teste setNome e getNome") {
    Arquivo arquivo;
    arquivo.setNome("teste.txt");
    CHECK(arquivo.getNome() == "teste.txt");
}

TEST_CASE("Teste lePalavras") {
    std::ofstream outfile("teste.txt");
    outfile << "uma frase de teste";
    outfile.close();

    Arquivo arquivo("teste.txt");
    arquivo.lePalavras();
    std::vector<std::string> palavrasEsperadas = {"uma", "frase", "de", "teste"};
    CHECK(arquivo.getWords().empty());
    arquivo.substituiCaracteres();
    CHECK(arquivo.getWords().empty());
    arquivo.lerArquivo();
    std::map<std::string, std::set<std::string>> wordsEsperadas = {
        {"uma", {"teste.txt"}},
        {"frase", {"teste.txt"}},
        {"de", {"teste.txt"}},
        {"teste", {"teste.txt"}}
    };
    CHECK(arquivo.getWords() == wordsEsperadas);

    std::remove("teste.txt");
}

TEST_CASE("Teste mesclarWords") {
    Arquivo arquivo("teste.txt");
    arquivo.setWords({{"uma", {"arquivo1.txt"}}, {"frase", {"arquivo1.txt"}}});
    std::map<std::string, std::set<std::string>> words = {
        {"frase", {"arquivo2.txt"}},
        {"teste", {"arquivo2.txt"}}
    };
    arquivo.mesclarWords(words, "arquivo2.txt");
    std::map<std::string, std::set<std::string>> wordsEsperadas = {
        {"uma", {"arquivo1.txt"}},
        {"frase", {"arquivo1.txt", "arquivo2.txt"}},
        {"teste", {"arquivo2.txt"}}
    };
    CHECK(arquivo.getWords() == wordsEsperadas);
}

