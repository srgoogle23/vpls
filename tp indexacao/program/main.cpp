#include "arquivo.hpp"
#include "pesquisa.hpp"

int main(int argc, char *argv[])
{
	vector<Arquivo> arquivos;
	for (int i = 1; i < argc; i++)
		arquivos.push_back(Arquivo(argv[i]));

	for(unsigned int i = 0; i < arquivos.size(); i++)
		arquivos[i].lerArquivo();

	Arquivo arquivo;
	for(unsigned int i = 0; i < arquivos.size(); i++)
		arquivo.mesclarWords(arquivos[i].getWords(), arquivos[i].getNome());

	cout << "Digite uma frase para a pesquisa: " << endl;
	string frase;
	getline(cin, frase);
	
	Pesquisa pesquisa(arquivo);
	pesquisa.pesquisaRelavancia(frase);
	
	return 0;
}