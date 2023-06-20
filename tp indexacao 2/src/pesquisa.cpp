#include "pesquisa.hpp"
#include <iostream>

Pesquisa::Pesquisa() {}

Pesquisa::Pesquisa(const Arquivo& arquivo) : arquivo(arquivo) {}

bool Pesquisa::seraQueEhRelevante(const std::map<std::string, std::set<std::string>>& words, const std::set<std::string>& palavras, const std::string& arquivo)
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
    for (const auto& wordsDoArquivo : wordsDoArquivo)
    {
        for (const auto& palavra : palavras)
        {
            if (wordsDoArquivo.first == palavra)
            {
                contador++;
            }
        }
    }

    return contador == qtdPalavras;
}

std::map<std::string, int> Pesquisa::retornarRelevanciaFrase(const std::string& frase)
{
    std::map<std::string, std::set<std::string>> words = arquivo.pegarPalavrasFormatadas();
    std::set<std::string> palavrasFrase = ajustarPesquisaFrase(frase);
    std::set<std::string> arquivos = nomesDosArquivos(words);
    std::map<std::string, int> arquivosPesquisa;
    for (const auto& arquivo : arquivos)
    {
        arquivosPesquisa[arquivo] = 0;
    }

    for (auto& arquivo : arquivosPesquisa)
    {
        if (seraQueEhRelevante(words, palavrasFrase, arquivo.first))
        {
            arquivo.second++;
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

std::set<std::string> Pesquisa::nomesDosArquivos(const std::map<std::string, std::set<std::string>>& words)
{
    std::set<std::string> arquivos;
    for (const auto& word : words)
    {
        for (const auto& file : word.second)
        {
            arquivos.insert(file);
        }
    }
    return arquivos;
}

std::set<std::string> Pesquisa::ajustarPesquisaFrase(const std::string& frase)
{
    std::set<std::string> palavrasFrase;
    std::stringstream ss(frase);
    std::string palavra;
    while (ss >> palavra)
    {
        palavrasFrase.insert(Utils::removerDetalhesPalavras(palavra));
    }
    return palavrasFrase;
}
