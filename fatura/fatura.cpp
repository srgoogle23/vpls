#include <iostream>
#include <string>
#include <map>

class Fatura
{
	private:
		std::string numero;
		char tipo;
		double valor;
	public:
	    Fatura()
	    {
	        
	    }
		Fatura(std::string numero, char tipo, double valor)
		{
			this->numero = numero;
			this->tipo = tipo;
			this->valor = valor;
		}
		void imprimir()
		{
			//"tipo valor codigo\n";
			std::cout << tipo << " " << valor << " " << numero << std::endl;
		}
		double getValor()
		{
			return valor;
		}
		char getTipo()
		{
			return tipo;
		}
		std::string getNumero()
		{
			return numero;
		}
};

class Colecao
{
	private:
		std::map<double, std::map<std::string, Fatura>, std::less<double>> faturas;
		std::map<char, int> status;
	public:
		Colecao()
		{
			status['p'] = 0;
			status['b'] = 0;
			status['g'] = 0;
		};
		void adicionar(Fatura f)
		{
			faturas[f.getValor()][f.getNumero()] = f;
			status[f.getTipo()]++;
		}
		void proxima()
		{
			// remove a fatura de maior valor, que deve estar no final da sua coleção (nenhuma verificação de valor deve ser feita nesse momento).
    // Invoca a função imprimir() da fatura que foi removida (se a coleção estiver vazia nada é impresso).
    // decrementa o map de contagem de acordo com o tipo da fatura removida.
			if(faturas.size() > 0)
			{
				auto it = faturas.end();
				it--;
				auto it2 = it->second.end();
				it2--;
				it->second.erase(it2);
				if(it->second.size() == 0)
				{
					faturas.erase(it);
				}
				it2->second.imprimir();
				status[it2->second.getTipo()]--;
			}
		}
		void imprimir()
		{
			for(auto it = faturas.begin(); it != faturas.end(); it++)
			{
				for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
				{
					it2->second.imprimir();
				}
			}
		}
		void statusFaturas()
		{
			// imprime os dados do map de contagem no formato “tipo contagem” seguido de uma quebra de linha, para cada tipo.
			for(auto it = status.begin(); it != status.end(); it++)
			{
				std::cout << it->first << " " << it->second << std::endl;
			}
		}
};

int main()
{
	Colecao c;
    char opcao;
    while (std::cin >> opcao) {
        if(opcao == 'f')
        {
            // cria uma fatura
			// f tipo valor codigo
			char tipo;
			std::cin >> tipo;
			double valor;
			std::cin >> valor;
			std::string codigo;
			std::cin >> codigo;
			// cria a fatura
			Fatura f = Fatura(codigo, tipo, valor);
			// adiciona a fatura à coleção
			c.adicionar(f);
        }
		else if (opcao == 'r')
		{
			// 'r': invoca a função proxima() da coleção
			c.proxima();
		}
		else if (opcao == 'p')
		{
			// imprime
			c.imprimir();
		}
		else if (opcao == 's')
		{
			// imprime o status das faturas pendentes
            c.statusFaturas();
		}
		else if (opcao == 'e')
		{
			// termina o programa
			break;
		}
	}
	return 0;
}