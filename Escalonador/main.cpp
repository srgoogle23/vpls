// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_escalonador.hpp"

#include "ListaProcessos.hpp"
#include "Processo.hpp"

#include <iostream>

using namespace std;

 int main() {


    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //
     ListaProcessos lista;
    char comando;
    int id, prioridade;
    string nome;
    Processo proc;
    while (cin >> comando) {
        switch (comando) {
            case 'a':
                cin >> id >> nome >> prioridade;
                proc = Processo(id, nome, prioridade);
                lista.adicionar_processo(proc);
                break;
            case 'm':
                proc = lista.remover_processo_maior_prioridade();
                break;
            case 'n':
                proc = lista.remover_processo_menor_prioridade();
                break;
            case 'r':
                cin >> id;
                proc = lista.remover_processo_por_id(id);
                break;
            case 'p':
                lista.imprimir_lista();
                break;
            case 'b':
                avaliacao_basica();
                break;
        }
    }
    
    

    return 0;
}