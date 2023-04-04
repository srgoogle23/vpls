#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Lendo número de palavras proibidas
    int n;
    cin >> n;
    cin.ignore(); // consumindo o caractere de quebra de linha pendente

    // Lendo palavras proibidas e armazenando em um vetor
    vector<string> proibidas(n);
    for (int i = 0; i < n; i++) {
        cin >> proibidas[i];
    }

    // Lendo comentário
    string comentario;
    getline(cin.ignore(), comentario); // lendo a linha completa, incluindo a primeira palavra

    // Substituindo palavras proibidas por asteriscos
    int n_ocorrencias;
    int total_substituicoes = 0;
	string mensagemFinal = "";
    for (int i = 0; i < n; i++) {
        n_ocorrencias = 0;
        size_t pos = comentario.find(proibidas[i]);
        while (pos != string::npos) {
            n_ocorrencias++;
            comentario.replace(pos, proibidas[i].size(), string(proibidas[i].size(), '*'));
            pos = comentario.find(proibidas[i], pos + proibidas[i].size());
        }
        if (n_ocorrencias >= 0) {
			mensagemFinal += "Palavra " + proibidas[i] + " substituida " + to_string(n_ocorrencias) + " vez(es)." + "\n";
            total_substituicoes += n_ocorrencias;
        }
    }

    // Imprimindo resultado final
    cout << comentario << endl;
	cout << mensagemFinal;

    return 0;
}
