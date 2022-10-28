#include <iostream>
#include <cstring>

#include <string>
#include <vector>

using namespace std;

class Intruso{
    private:
        vector<string> senha;
    public:
        void set_senha_vazada(string vazou);
        string crack_senha();
};


int possivel[6][11], digito1[20], digito2[20], n, teste;

void Intruso::set_senha_vazada(string vazou)
{
    this->senha.push_back(vazou);
}

string Intruso::crack_senha()
{
    //int possivel[6][11], digito1[20], digito2[20], teste;
    int n = this->senha.size();
	memset(possivel, 1, sizeof(possivel));
	for (auto s : this->senha)
	{
		// substitui ' ' por ''
		std::string senha2 = "";
		for(auto c : s)
		{
			if(c != ' ')
				senha2 += c;
		}

		// pega os primeios e separa em dois grupos
		for(int i = 0, j = 0; i < 10; j++)
		{
			digito1[j] = senha2[i] - '0';
			i++;
			digito2[j] = senha2[i] - '0';
			i++;
		}

		for (int digitodavez = 0, i = 10; digitodavez < 6; digitodavez++, i++)
		{
			char c = senha2[i];
			for (int novodigito = 0; novodigito <= 9; novodigito++) {
				if (novodigito == digito1[c - 'A'] ||
					novodigito == digito2[c - 'A'])
					continue;
				possivel[digitodavez][novodigito] = 0;
			}
		}
	}

	string digitoFinal = "";
	for (int digitodavez = 0; digitodavez < 6; digitodavez++)
	{
		for (int novodigito = 0; novodigito <= 9; novodigito++) {
			if (possivel[digitodavez][novodigito]) {
				digitoFinal += to_string(novodigito);
				digitoFinal += " ";
			}
		}
	}

	return digitoFinal;
}



int main(){
    int num_entradas, i;
    std::string senha;
    Intruso intruso;
    
    std::cin >> num_entradas;
    std::cin.ignore();

    for(i=0; i < num_entradas; i++){
        std::getline(std::cin, senha);
        intruso.set_senha_vazada(senha);
    }
    std::cout << intruso.crack_senha() <<std::endl;
    
    return 0;
}