// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_alocacao.hpp"

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include "QuadroAlocacao.hpp"

 int main() {

    // Criando as variaveis
    QuadroAlocacao quadroAlocacao;
    std :: string codigo, nome, dia, horario, sala;
    std :: vector<Disciplina> disciplinaMaisOfertada;
    // Executando as ações
    char data;

    while (std :: cin >> data) {
        switch (data) {
            
            // Adicionando nova alocacao
            case 'a':   
                
                std :: cin >> codigo >> nome >> dia >> horario >> sala;
                quadroAlocacao.inserir_alocacao(codigo, nome, dia, horario, sala);
                break;

            // comando para recuperar as disciplinas mais ofertas
            case 'm': 
                disciplinaMaisOfertada = quadroAlocacao.recuperar_disciplinas_mais_ofertadas();
                for(Disciplina x : disciplinaMaisOfertada){
                    x.imprimir_alocacao();
                }
                break;

            // remove uma alocação do quadro de acordo com o código da disciplina e horário informados
            case 'r':                  
                
                std :: cin >> codigo >> horario;
                quadroAlocacao.remover_alocacao_disciplina(codigo, horario);
                
                break;     

            // Imprime o quadro
            case 'p':                  
                
                quadroAlocacao.imprimir_alocacao_completa();
                
                break;

            //Comando de avaliação    
            case 'b':                  
                
                avaliacao_basica();
                
                break;                                            
        }
    }
    //
    

    return 0;
}