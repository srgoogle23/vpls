#include <iostream>
#include <vector>
#include <string>
#include "arquivo.hpp"
#include "pesquisa.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    string localizacaoArquivos = "./documentos/";
    vector<string> nomesArquivosDaPasta = Utils::pegarArquivosPasta(localizacaoArquivos);
    vector<Arquivo> arquivosDaPasta;

    for (const string& nomeArquivoDaPasta : nomesArquivosDaPasta) {
        string caminhoArquivoDaPasta = localizacaoArquivos + "/" + nomeArquivoDaPasta;
        arquivosDaPasta.push_back(Arquivo(caminhoArquivoDaPasta));
    }

    unsigned int contador = 0;
    unsigned int parametro = arquivosDaPasta.size();
    while (contador < parametro) {
        arquivosDaPasta[contador].pegarArquivo();
        contador++;
    }

    contador = 0;
    Arquivo arquivo;
    while (contador < parametro) {
        arquivo.misturarPalavrasFormatadas(arquivosDaPasta[contador].pegarPalavrasFormatadas(), arquivosDaPasta[contador].pegarNome());
        contador++;
    }

    cout << "Qual frase deseja pesquisar?" << endl;
    string frasePesquisa;
    getline(cin, frasePesquisa);

    Pesquisa pesquisa(arquivo);
    pesquisa.retornarRelevanciaFrase(frasePesquisa);

    return 0;
}
