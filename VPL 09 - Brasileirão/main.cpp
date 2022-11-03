#include <iostream>
#include <iomanip>
#include <map>
#include <cctype>

using namespace std;

class Time
{
	protected:
		int pontos, jogos, golsMarcados, golsSofridos;
		string nome;

	public:
		Time() : pontos(0), jogos(0), golsMarcados(0), golsSofridos(0) {}
		void vitoria(int golsMarcados, int golsSofridos)
		{
			pontos += 3;
			jogos++;
			this->golsMarcados += golsMarcados;
			this->golsSofridos += golsSofridos;
		}

		void empate(int golsMarcados, int golsSofridos)
		{
			pontos++;
			jogos++;
			this->golsMarcados += golsMarcados;
			this->golsSofridos += golsSofridos;
		}

		void derrota(int golsMarcados, int golsSofridos)
		{
			jogos++;
			this->golsMarcados += golsMarcados;
			this->golsSofridos += golsSofridos;
		}

		double porcentagemPontosGanhos() const
		{
			return pontos > 0 && jogos > 0 ? (double) pontos / (jogos * 3) : (double) 0;
		}

		int getGolsMarcados()
		{
			return golsMarcados;
		}

		int getGolsSofridos()
		{
			return golsSofridos;
		}
		
		int getPontos()
		{
			return pontos;
		}
		
		int getJogos()
		{
			return jogos;
		}
		
		int getSaldoGols()
		{
			return golsMarcados - golsSofridos;
		}

		string getNome()
		{
			return nome;
		}

		string getNomeFormatado()
		{
			string nomeFormatado;			
			nomeFormatado = nome[0];
			nomeFormatado += toupper(nome[1]);
			return nomeFormatado;
		}

		void setNome(string nome)
		{
			this->nome = nome;
		}
};

class Jogo
{
	private:
		int numeroDeTimes, numeroDeJogos;
		map<string, Time> times1;
		map<int, map<int, map<string, Time, less<string>>, greater<int>>, greater<int>> times2;

	public:
		Jogo()
		{
			cin >> numeroDeTimes >> numeroDeJogos;
			criarTimes();
			criarJogos();
			ordenaJogos();
		}

		void criarTimes()
		{
			for (int i = 0; i < this->numeroDeTimes; i++)
			{
				string nome;
				cin >> nome;
				this->times1[nome] = Time();
				this->times1[nome].setNome(nome);
			}
		}

		void criarJogos()
		{
			for (int i = 0; i < this->numeroDeJogos; i++)
			{
				string timeA, timeB, vazio;
				int golsA, golsB;
				cin >> timeA >> golsA >> vazio >> golsB >> timeB;

				if (golsA > golsB)
				{
					this->times1[timeA].vitoria(golsA, golsB);
					this->times1[timeB].derrota(golsB, golsA);
				}
				else if (golsA < golsB)
				{
					this->times1[timeA].derrota(golsA, golsB);
					this->times1[timeB].vitoria(golsB, golsA);
				}
				else
				{
					this->times1[timeA].empate(golsA, golsB);
					this->times1[timeB].empate(golsB, golsA);
				}
			}
		}

		void ordenaJogos()
		{
			for (auto it = times1.begin(); it != times1.end(); it++)
				times2[it->second.getPontos()][it->second.getGolsMarcados()][it->second.getNomeFormatado()] = it->second;
		}

		void exibeResultado()
		{
			int posicao = 1, golsAnteriores = -1, pontosAnteriores = -1;
			for (auto t1 = times2.begin(); t1 != times2.end(); t1++)
			{
				for (auto t2 = t1->second.begin(); t2 != t1->second.end(); t2++)
				{
					for (auto t3 = t2->second.begin(); t3 != t2->second.end(); t3++)
					{
						if(golsAnteriores != t3->second.getGolsMarcados())
							cout << setw(3) << to_string(posicao) << ".";
						else if (pontosAnteriores != t3->second.getPontos())
							cout << setw(3) << to_string(posicao) << ".";
						else
							cout << setw(3) << "    ";
			
						cout << setw(17);
			
						cout << t3->second.getNome();
						cout << setw(4) << t3->second.getPontos();
						cout << setw(4) << t3->second.getJogos();
						cout << setw(4) << t3->second.getGolsMarcados();
						cout << setw(4) << t3->second.getGolsSofridos();
						cout << setw(4) << t3->second.getSaldoGols() << " ";
						// se a porcentagem de pontos ganhos for maior que 0, imprime com 2 casas decimais
						if (t3->second.porcentagemPontosGanhos() > 0 || (t3->second.porcentagemPontosGanhos() == 0 && t3->second.getJogos() > 0))
							cout << setw(6) << fixed << setprecision(2) << (t3->second.porcentagemPontosGanhos() * 100);
						else
							cout << setw(4) << "  N/A";
						cout << endl;
						golsAnteriores = t3->second.getGolsMarcados();
						pontosAnteriores = t3->second.getPontos();
						posicao++;
					}
				}
			}
		}
};



int main()
{
	Jogo jogo;
	jogo.exibeResultado();
	return 0;   
}