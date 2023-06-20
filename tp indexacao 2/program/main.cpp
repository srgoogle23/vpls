#include <iostream>
#include <vector>
#include <string>
#include "arquivo.hpp"
#include "pesquisa.hpp"
#include "utils.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Uso: " << argv[0] << " <caminho_para_pasta>" << std::endl;
        return 1;
    }

    std::string pasta(argv[1]);
    std::vector<std::string> nomesArquivos = Utils::obterArquivosDaPasta(pasta);
    std::vector<Arquivo> arquivos;

    for (const std::string& nomeArquivo : nomesArquivos) {
        std::string caminhoArquivo = pasta + "/" + nomeArquivo;
        arquivos.push_back(Arquivo(caminhoArquivo));
    }

    for (unsigned int i = 0; i < arquivos.size(); i++) {
        arquivos[i].lerArquivo();
    }

    Arquivo arquivo;
    for (unsigned int i = 0; i < arquivos.size(); i++) {
        arquivo.mesclarWords(arquivos[i].getWords(), arquivos[i].getNome());
    }

    std::cout << "Digite uma frase para a pesquisa: " << std::endl;
    std::string frase;
    std::getline(std::cin, frase);

    Pesquisa pesquisa(arquivo);
    pesquisa.pesquisaRelavancia(frase);

    return 0;
}
