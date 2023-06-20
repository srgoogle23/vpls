#include "doctest"
#include "utils.hpp"

TEST_CASE("Teste pegarArquivosPasta") {
    std::vector<std::string> arquivos = Utils::pegarArquivosPasta("./documentos/");
    REQUIRE(arquivos.size() == 3);
    CHECK(std::find(arquivos.begin(), arquivos.end(), "d1.txt") != arquivos.end());
    CHECK(std::find(arquivos.begin(), arquivos.end(), "d2.txt") != arquivos.end());
    CHECK(std::find(arquivos.begin(), arquivos.end(), "d3.txt") != arquivos.end());
}

TEST_CASE("Teste removerDetalhesPalavras") {
    std::string str = "Olá, mundo!";
    std::string resultado = Utils::removerDetalhesPalavras(str);
    CHECK(resultado == "ola mundo");

    str = "Ação e Reação";
    resultado = Utils::removerDetalhesPalavras(str);
    CHECK(resultado == "acao e reacao");

    str = "Palavra-com-hifen";
    resultado = Utils::removerDetalhesPalavras(str);
    CHECK(resultado == "palavracomhifen");

    str = "Texto_com_underscore";
    resultado = Utils::removerDetalhesPalavras(str);
    CHECK(resultado == "textocomunderscore");
}
