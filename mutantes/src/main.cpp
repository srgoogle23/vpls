// inclui a biblioteca de entrada e saida padrao
#include <iostream>
#include <string>
#include <map>
#include <vector>

// create function to return char[26]
char* getAlphabet() {
	char* alphabet = new char[26];
	for (int i = 0; i < 26; i++) {
		alphabet[i] = 'a' + i;
	}
	return alphabet;
}

int main()
{
	// le um numero inteiro representando o numero de individuos 0 < n < 10000
	int n;
	std::vector<int> vetor;
	std::cin >> n;
	// verifica se 0 < n < 10000
	while(n > 0 && n < 10000)
	{
		std::map<int, std::map<char, int>> relacao;

		for (int i = 0; i < n; i++)
		{
			// le a descricao, composta por somente letras maiusculas de A a Z
			std::string descricao;
			std::cin >> descricao;
			// verifica se a descricao tem no maximo 100 caracteres
			if (descricao.length() > 100)
				continue;
			
			// armazena os caracteres e numeros de caracteres de cada descricao
			// create char alphabet[26] using getAlphabet
			char* alphabet = getAlphabet();
			int numeros[26];
			unsigned int j = 0;
			// preenche o vetor de caracteres com os caracteres de A a Z
			for (j = 0; j < 26; j++)
				caracteres[j] = 'A' + j;
			
			// preenche o vetor de numeros com 0
			for (j = 0; j < 26; j++)
				numeros[j] = 0;
			
			// percorre a descricao
			for(unsigned int i = 0; i < descricao.length(); i++)
			{
				// verifica se o caracter esta entre A e Z
				if (descricao[i] >= 'A' && descricao[i] <= 'Z')
				{
					// incrementa o numero de caracteres
					numeros[descricao[i] - 'A']++;
				}
			}
			// armazena a descricao em um mapa
			for (j = 0; j < 26; j++)
			{
				// adiciona o caracter e o numero de caracteres no mapa
				relacao[i][caracteres[j]] = numeros[j];
			}
		}

		// descobre o numero de relacoes distintas
		std::map<int, std::map<char, int>> distintas;
		// cria um iterador para o mapa de relacoes
		std::map<int, std::map<char, int>>::iterator it;
		// percorre o mapa de relacoes
		for (it = relacao.begin(); it != relacao.end(); it++)
		{
			bool existe = false;
			// cria um iterador para o mapa de relacoes distintas
			std::map<int, std::map<char, int>>::iterator it2;
			// percorre o mapa de relacoes distintas
			for (it2 = distintas.begin(); it2 != distintas.end(); it2++)
			{
				// verifica se a relacao ja existe no mapa de relacoes distintas
				if (it->second == it2->second)
				{
					existe = true;
					break;
				}
			}
			// se a relacao nao existe no mapa de relacoes distintas, adiciona
			if (!existe)
				distintas[it->first] = it->second;
		}

		int contador = 0;
		for (unsigned int i = 0; i < distintas.size(); i++)
		{
			if(distintas[i].size() > 0)
			{
				contador++;
			}
		}

		vetor.push_back(contador);
		if(n < 30)
			std::cin >> n;
		else
		    n = 0;
	}

	// imprime o numero de individuos diferentes
	for (unsigned int i = 0; i < vetor.size(); i++)
	{
		std::cout << vetor[i] << std::endl;
	}

	return 0;
}