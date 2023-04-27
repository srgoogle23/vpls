// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_playlists.hpp"

#include "CadastroUsuario.hpp"

int main() {

    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //
	CadastroUsuario lista;
    char comando;
	string nome_playlist, nome_filme, genero_filme;
	int duracao_filme, tipo_ordenacao;
	while (cin >> comando) {
        switch (comando) {
            case 'p': // 'p nome_playlist': comando para adicionar uma nova playlist.
				cin >> nome_playlist;
				lista.adicionar_playlist(nome_playlist);
                break;
			case 'f': // 'f nome_playlist nome_filme genero_filme duracao_filme': comando para adicionar um filme a uma determinada playlist.
				cin >> nome_playlist >> nome_filme >> genero_filme >> duracao_filme;
				lista.adicionar_filme(nome_playlist, nome_filme, genero_filme, duracao_filme);
                break;
			case 'd': // 'd nome_playlist tipo_ordenacao': comando para imprimir os filmes de uma playlist.
				cin >> nome_playlist >> tipo_ordenacao;	
				lista.imprimir_detalhes_playlist(nome_playlist, tipo_ordenacao);
                break;
			case 'r': // 'r nome_playlist nome_filme': comando para remover um filme de uma determinada playlist.
				cin >> nome_playlist >> nome_filme;
				lista.remover_filme_por_nome(nome_playlist, nome_filme);
                break;
			case 'g': // comando para imprimir as informações de todas as playlists.
				lista.imprimir_informacoes_gerais();
                break;
            case 'b':
                avaliacao_basica();
                break;
        }
    }

    return 0;
}