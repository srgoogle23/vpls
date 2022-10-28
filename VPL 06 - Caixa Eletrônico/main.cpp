#include <iostream>
#include <cstring>

using namespace std;
int possivel[6][11], digito1[20], digito2[20], n, teste;
int main()
{
    while (cin >> n && n) {
        memset(possivel, 1, sizeof(possivel));
        for (int vez = 1; vez <= n; vez++) {
            for (char c = 'A'; c <= 'E'; c++) {
                cin >> digito1[c - 'A'] >> digito2[c - 'A'];
            }
            
            for (int digitodavez = 0; digitodavez < 6; digitodavez++)
            {
                char c;
                cin >> c;
                for (int novodigito = 0; novodigito <= 9; novodigito++) {
                    if (novodigito == digito1[c - 'A'] ||
                        novodigito == digito2[c - 'A'])
                        continue;
                    possivel[digitodavez][novodigito] = 0;
                }
            }
        }
        //cout << "Teste " << ++teste << endl;
        for (int digitodavez = 0; digitodavez < 6; digitodavez++) {
            for (int novodigito = 0; novodigito <= 9; novodigito++) {
                if (possivel[digitodavez][novodigito]) {
                    cout << novodigito << " ";
                }
            }
        }
        cout << endl << endl;
    }
    return 0;
}