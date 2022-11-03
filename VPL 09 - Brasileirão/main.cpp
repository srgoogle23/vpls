#include <iostream>
#include <iomanip>
#include <map>
#include <cctype>

using namespace std;

class Time
{
	protected:
		int p;
		int j;
		int gm;
		int gs;
		string n;

	public:
		Time() : p(0), j(0), gm(0), gs(0) {}

		Time(string n) : p(0), j(0), gm(0), gs(0), n(n) {}

		void win(int g1, int g2)
		{
			this->p += 3;
			this->j++;
			this->gm += g1;
			this->gs += g2;
		}

		void tie(int g1, int g2)
		{
			this->p++;
			this->j++;
			this->gm += g1;
			this->gs += g2;
		}

		void defeat(int g1, int g2)
		{
			this->j++;
			this->gm += g1;
			this->gs += g2;
		}

		double pointsRate() const
		{
			if(this->p > 0 && this->j > 0)
			{
				return (double) this->p / (this->j * 3);
			}
			else
			{
				return 0;
			}
		}

		int ggm()
		{
			return this->gm;
		}

		int ggs()
		{
			return this->gs;
		}
		
		int gp()
		{
			return this->p;
		}
		
		int gj()
		{
			return this->j;
		}
		
		int gsg()
		{
			return this->gm - this->gs;
		}

		string gn()
		{
			return this->n;
		}

		string gnf()
		{
			string nf;			
			nf = n[0];
			nf += toupper(n[1]);
			return nf;
		}

		void showPosition(int position, int ga, int pa)
		{
			if(ga != ggm() || pa != gp())
				cout << setw(3) << to_string(position) << ".";
			else
				cout << setw(3) << "    ";
			
			cout << setw(17);
		}

		void showAtributes()
		{
			cout << gn();
			cout << setw(4) << gp();
			cout << setw(4) << gj();
			cout << setw(4) << ggm();
			cout << setw(4) << ggs();
			cout << setw(4) << gsg() << " ";
		}

		void showPointsRate()
		{
			if (pointsRate() > 0 || (pointsRate() == 0 && gj() > 0))
				cout << setw(6) << fixed << setprecision(2) << (pointsRate() * 100);
			else
				cout << setw(4) << "  N/A";
			
			cout << endl;
		}
};
class Jogo
{
	private:
		int numeroDeTimes, numeroDeJogos, position = 1, ga = -1, pa = -1;
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
				this->times1[nome] = Time(nome);
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
					this->times1[timeA].win(golsA, golsB);
					this->times1[timeB].defeat(golsB, golsA);
				}
				else if (golsA < golsB)
				{
					this->times1[timeA].defeat(golsA, golsB);
					this->times1[timeB].win(golsB, golsA);
				}
				else
				{
					this->times1[timeA].tie(golsA, golsB);
					this->times1[timeB].tie(golsB, golsA);
				}
			}
		}

		void ordenaJogos()
		{
			for (auto it = times1.begin(); it != times1.end(); it++)
				times2[it->second.gp()][it->second.ggm()][it->second.gnf()] = it->second;
		}

		void atualizaControladores(int ga, int pa)
		{
			this->position++;
			this->ga = ga;
			this->pa = pa;
		}

		void exibeResultado()
		{
			for (auto t1 = times2.begin(); t1 != times2.end(); t1++)
			{
				for (auto t2 = t1->second.begin(); t2 != t1->second.end(); t2++)
				{
					for (auto t3 = t2->second.begin(); t3 != t2->second.end(); t3++)
					{
						t3->second.showPosition(this->position, this->ga, this->pa);
						t3->second.showAtributes();
						t3->second.showPointsRate();	
						atualizaControladores(t3->second.ggm(), t3->second.gp());
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