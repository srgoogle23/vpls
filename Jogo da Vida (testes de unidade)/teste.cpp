/*Você, aluno de PDS 2, após comprovada notoriedade atuarial produzindo programas e sistemas computacionais, foi escalado para compor o time de desenvolvedores que auxiliará a CBF a organizar o Brasileirão.

Para realizar esta tarefa, escreva um programa que, dados os resultados dos jogos do Brasileirão, imprime a classificação correspondente seguindo o formato especificado mais abaixo. Vitória, empate e derrota valem três, um e zero pontos, respectivamente.

O critério de classificação funciona conforme o exposto abaixo:
- o número de pontos marcados
- saldo de gols (gols marcados - gols sofridos)
- número de gols marcados.

Importante: Quando houver empate nos três critérios acima, considerar-se-á que esses times ocupam a mesma posição na tabela de classificação. A ordem lexicográfica deve ser considerada neste caso, contudo, não se deve diferenciar letras maiúsculas de minúsculas.
Entrada

A primeira linha contém dois inteiros positivos T e J.
- T representa o número de times.
- J informa o número de jogos que foram disputados até o momento.

Em seguida, temos T linhas, cada uma contendo o nome de um time.
Nomes de times podem conter somente letras e caracteres de travessão ('-').
Seguem-se G linhas, contendo o resultado dos jogos, um jogo por linha.
Os jogos são mostrados no seguinte formato:
- nome do time da casa
- número de gols marcados pelo time da casa
- um travessão
- número de gols marcados pelo time visitante
- nome do time visitante.
Saída

O programa deve imprimir a tabela de classificação.
Os times devem aparecer em ordem de classificação, ressalvada a ordem alfabeticamente, quando eles ocuparem a mesma posição.
As estatísticas de cada time são mostradas em uma única linha contendo:
- posição do time
- número de pontos
- número de jogos disputados
- número de gols marcados
- número de gols sofridos
- saldo de gols
- porcentagem de pontos ganhos, quando disponível.

Note que quando vários times estão empatados, somente a posição do primeiro é impressa.
Campos devem ser rigorosamente formatados e alinhados, conforme disposto no exemplo de saída abaixo.

Entrada:
6 10
tA
tB
tC
td
tE
tF
tA 1 - 1 tB
tC 0 - 0 td
tE 0 - 0 tA
tC 0 - 0 tB
td 0 - 0 tE
tA 0 - 0 tC
tB 0 - 0 tE
td 0 - 0 tA
tE 0 - 0 tC
tB 0 - 0 td

Saída
 1.              tA   4   4   1   1   0  33.33
                 tB   4   4   1   1   0  33.33
 3.              tC   4   4   0   0   0  33.33
                 td   4   4   0   0   0  33.33
                 tE   4   4   0   0   0  33.33
 6.              tF   0   0   0   0   0    N/A

Dicas:
- Utilize os comandos abaixo para exibir o percentual corretamente:
cout.setf(ios::fixed, ios::floatfield); // set fixed floating format
cout.precision(2);                      // for fixed format, two decimal places

- Utilize o comando abaixo para controlar a quantidade de espaços:
setw(4);

- Utilize o comando abaixo para controlar a precisão em casas decimais:
cout << setprecision(2) << 3.1415; 

- Você pode converter as strings para minúsculas, se necessário, caractere por caractere, conforme abaixo:
https://cplusplus.com/reference/cctype/tolower/

Sugestões de contêineres da STL encontram-se adicionadas no arquivo main.c. Porém, seu uso NÃO é obrigatório.

Se você gosta de futebol, confira o projeto FAME22:
Notícia FAME22*/
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <map>          // std::map
#include <queue>        // std::priority_queue
#include <utility>      // std::pair
#include <cctype>       // std::tolower
#include <algorithm>    // std::sort

using namespace std;

main() {
	int T, J, G;
	cin >> T >> J;
	G = J;
	string times[T];
	for (int i = 0; i < T; i++) {
		cin >> times[i];
	}
	map<string, int> pontos;
	map<string, int> jogos;
	map<string, int> gols_marcados;
	map<string, int> gols_sofridos;
	map<string, int> saldo_gols;
	map<string, int> porcentagem;
	while (J--) {
		string time1, time2;
		int gols1, gols2;
		cin >> time1 >> gols1 >> gols2 >> time2;
		gols_marcados[time1] += gols1;
		gols_sofridos[time1] += gols2;
		gols_marcados[time2] += gols2;
		gols_sofridos[time2] += gols1;
		jogos[time1]++;
		jogos[time2]++;
		if (gols1 > gols2) {
			pontos[time1] += 3;
		} else if (gols1 < gols2) {
			pontos[time2] += 3;
		} else {
			pontos[time1]++;
			pontos[time2]++;
		}
	}
	for (int i = 0; i < T; i++) {
		saldo_gols[times[i]] = gols_marcados[times[i]] - gols_sofridos[times[i]];
		porcentagem[times[i]] = (pontos[times[i]] * 100) / (jogos[times[i]] * 3);
	}
	for (int i = 0; i < T; i++) {
		for (int j = i + 1; j < T; j++) {
			if (pontos[times[i]] < pontos[times[j]]) {
				swap(times[i], times[j]);
			} else if (pontos[times[i]] == pontos[times[j]]) {
				if (saldo_gols[times[i]] < saldo_gols[times[j]]) {
					swap(times[i], times[j]);
				} else if (saldo_gols[times[i]] == saldo_gols[times[j]]) {
					if (gols_marcados[times[i]] < gols_marcados[times[j]]) {
						swap(times[i], times[j]);
					} else if (gols_marcados[times[i]] == gols_marcados[times[j]]) {
						if (jogos[times[i]] > jogos[times[j]]) {
							swap(times[i], times[j]);
						} else if (jogos[times[i]] == jogos[times[j]]) {
							if (times[i] > times[j]) {
								swap(times[i], times[j]);
							}
						}
					}
				}
			}
		}
	}
 
  return 0;   
}