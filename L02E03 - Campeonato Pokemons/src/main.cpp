// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_pokemon.hpp"

#include "Campeonato.hpp"

int main() {

    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //
	Campeonato lista;
	string nome, tipo_ataque;
	double forca_ataque, potencia_raio, litros_jato, temperatura_explosao;
	int idt, idt1, idpk1, idt2, idpk2;
	char comando;
	while (cin >> comando) {
        switch (comando) {
            case 't': // 't nome': comando para cadastrar um treinador no campeonato. 
				cin >> nome;
				lista.cadastrar_treinador(nome);
                break;
			case 'i': // i idt': comando para imprimir as informações de um treinador de acordo com o id. 
				cin >> idt;
				lista.imprimir_informacoes_treinador(idt);
                break;
			case 'e': // e idt nome tipo_ataque forca_ataque potencia_raio': comando para adicionar um PokemonEletrico ao treinador informado. 
				cin >> idt >> nome >> tipo_ataque >> forca_ataque >> potencia_raio;
				lista.cadastrar_pokemon_eletrico(idt, nome, tipo_ataque, forca_ataque, potencia_raio);
				break;
			case 'q': // 'q idt nome tipo_ataque forca_ataque litros_jato': comando para adicionar um PokemonAquatico ao treinador informado.
				cin >> idt >> nome >> tipo_ataque >> forca_ataque >> litros_jato;
				lista.cadastrar_pokemon_aquatico(idt, nome, tipo_ataque, forca_ataque, litros_jato);
                break;
			case 'x': // 'x idt nome tipo_ataque forca_ataque temperatura_explosao_jato': comando para adicionar um PokemonExplosivo ao treinador informado.
				cin >> idt >> nome >> tipo_ataque >> forca_ataque >> temperatura_explosao;
				lista.cadastrar_pokemon_explosivo(idt, nome, tipo_ataque, forca_ataque, temperatura_explosao);
                break;
			case 'h': //'h idt1 idpk1 idt1 idpk1': comando para realizar uma batalha de acordo com os ids informados.
				cin >> idt1 >> idpk1 >> idt2 >> idpk2;
				lista.executar_batalha(idt1, idpk1, idt2, idpk2);
                break;
            case 'b':
                avaliacao_basica();
                break;
        }
    }

    return 0;
}