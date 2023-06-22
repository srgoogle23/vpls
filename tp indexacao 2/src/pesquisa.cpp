#include "pesquisa.hpp"
#include <iostream>

Pesquisa::Pesquisa() {}

Pesquisa::Pesquisa(const Arquivo& arquivo) : arquivo(arquivo) {}

bool Pesquisa::seraQueEhRelevante(const std::map<std::string, std::vector<std::string>>& words, const std::vector<std::string>& palavras, const std::string& arquivo)
{
    std::map<std::string, std::string> wordsDoArquivo;
    for (const auto& word : words)
    {
        for (const auto& file : word.second)
        {
            if (file == arquivo)
            {
                wordsDoArquivo[word.first] = file;
            }
        }
    }

    unsigned int qtdPalavras = palavras.size();
    unsigned int contador = 0;
    for (const auto& wordDoArquivo : wordsDoArquivo)
    {
        for (const auto& palavra : palavras)
        {
            if (wordDoArquivo.first == palavra)
            {
                contador++;
            }
        }
    }

    return contador == qtdPalavras;
}

int Pesquisa::quantidadeRelevancia(const std::map<std::string, std::vector<std::string>>& words, const std::vector<std::string>& palavras, const std::string& arquivo, std::map<std::string, std::map<std::string, int>> contadorPalavras)
{
    std::map<std::string, std::string> wordsDoArquivo;
    for (const auto& word : words)
    {
        for (const auto& file : word.second)
        {
            if (file == arquivo)
            {
                wordsDoArquivo[word.first] = file;
            }
        }
    }

    int menorAparicao = 0;
    for (const auto& wordDoArquivo : wordsDoArquivo)
    {
        for (const auto& palavra : palavras)
        {
            if (wordDoArquivo.first == palavra)
            {
                menorAparicao = contadorPalavras[palavra][arquivo];
            }
        }
    }

    return menorAparicao;
}

std::map<std::string, int> Pesquisa::retornarRelevanciaFrase(const std::string& frase)
{
    std::map<std::string, std::vector<std::string>> words = arquivo.pegarPalavrasFormatadas();
    std::vector<std::string> palavrasFrase = ajustarPesquisaFrase(frase);
    std::vector<std::string> arquivos = nomesDosArquivos(words);
    std::map<std::string, int> arquivosPesquisa;
    std::map<std::string, std::map<std::string, int>> contadorPalavras = arquivo.pegarContadorPalavras();
    for (const auto& arquivo : arquivos)
    {
        arquivosPesquisa[arquivo] = 0;
    }

    for (auto& arquivo : arquivosPesquisa)
    {
        if (seraQueEhRelevante(words, palavrasFrase, arquivo.first))
        {
            arquivo.second = quantidadeRelevancia(words, palavrasFrase, arquivo.first, contadorPalavras);
        }
    }

    bool primeiroArquivo = true;
    for (const auto& arquivo : arquivosPesquisa)
    {
        if (arquivo.second > 0)
        {
            if (primeiroArquivo)
            {
                std::cout << "(" << arquivo.first << ", " << arquivo.second << ")";
                primeiroArquivo = false;
            }
            else
            {
                std::cout << ", (" << arquivo.first << ", " << arquivo.second << ")";
            }
        }
    }
    std::cout << std::endl;

    return arquivosPesquisa;
}

std::vector<std::string> Pesquisa::nomesDosArquivos(const std::map<std::string, std::vector<std::string>>& words)
{
    std::vector<std::string> arquivos;
    for (const auto& word : words)
    {
        for (const auto& file : word.second)
        {
            arquivos.push_back(file);
        }
    }
    return arquivos;
}

std::vector<std::string> Pesquisa::ajustarPesquisaFrase(const std::string& frase)
{
    std::vector<std::string> palavrasFrase;
    std::stringstream ss(frase);
    std::string palavra;
    while (ss >> palavra)
    {
        palavrasFrase.push_back(Utils::removerDetalhesPalavras(palavra));
    }
    return palavrasFrase;
}
