#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <map>          // std::map
#include <queue>        // std::priority_queue
#include <utility>      // std::pair
#include <cctype>       // std::tolower
#include <algorithm>    // std::sort

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

		bool operator>(const Time &t) const
		{
			if (pontos != t.pontos)
				return pontos > t.pontos;
			else
				return nome > t.nome;
		}

		bool operator<(const Time& t) const
		{
			if (pontos != t.pontos)
				return pontos > t.pontos;
			else
				return nome < t.nome;
		}

		bool operator==(const Time& t) const
		{
			return pontos == t.pontos;
		}
};

map<string, Time> getTimes(int numeroDeTimes);
int leInteiro();
string leString();
map<string, Time> leJogos(map<string, Time> times, int numeroDeJogos);

map<int, map<int, map<string, Time, less<string>>, greater<int>>, greater<int>> ordenaTimes(map<string, Time> times)
{
    map<int, map<int, map<string, Time, less<string>>, greater<int>>, greater<int>> timesParaOrdenar;
	for (auto it = times.begin(); it != times.end(); it++)
	{
		timesParaOrdenar[it->second.getPontos()][it->second.getGolsMarcados()][it->second.getNomeFormatado()] = it->second;
	}

	return timesParaOrdenar;
}

int main()
{
	int numeroDeTimes = leInteiro();
	int numeroDeJogos = leInteiro();
    map<int, map<int, map<string, Time, less<string>>, greater<int>>, greater<int>> times = ordenaTimes(leJogos(getTimes(numeroDeTimes), numeroDeJogos));
	int posicao = 1, golsAnteriores = -1, pontosAnteriores = -1;
	for (auto t1 = times.begin(); t1 != times.end(); t1++)
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
	return 0;   
}

map<string, Time> leJogos(map<string, Time> times, int numeroDeJogos)
{
	string tA, tB;
	int gA, gB;
	for (int i = 0; i < numeroDeJogos; i++)
	{
		tA = leString();
		gA = leInteiro();
		leString();
		gB = leInteiro();
		tB = leString();

		if (gA > gB)
		{
			times[tA].vitoria(gA, gB);
			times[tB].derrota(gB, gA);
		}
		else if (gA < gB)
		{
			times[tA].derrota(gA, gB);
			times[tB].vitoria(gB, gA);
		}
		else
		{
			times[tA].empate(gA, gB);
			times[tB].empate(gB, gA);
		}
	}
	return times;
}

map<string, Time> getTimes(int numeroDeTimes)
{
	map<string, Time> times;
	for (int i = 0; i < numeroDeTimes; i++)
	{
		string nome = leString();
		times[nome] = Time();
		times[nome].setNome(nome);
	}
	return times;
}

string leString()
{
	string s;
	cin >> s;
	return s;
}

int leInteiro()
{
	int n;
	cin >> n;
	return n;
}