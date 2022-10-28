// NÃO ALTERE ESSA LINHA
#include "avaliacao.hpp"
#include "ListaFatura.hpp"

int main()
{
	ListaFatura lista;
    char opcao;
    while (std::cin >> opcao) {
        if(opcao == 'f')
        {
			// 'f id valor': comando para criar uma nova fatura e adicioná-la na lista de acordo com os parâmetros passados.
			int id;
			std::cin >> id;
			double valor;
			std::cin >> valor;
			Fatura *f = new Fatura(id, valor);
			lista.insere_fatura(f);
		}
		else if(opcao == 'r')
        {
			// comando para remover o processo de MAIOR valor da lista
			Fatura *f = lista.proxima_fatura();
			if(f != nullptr)
			{
				// imprime o item
				f->imprimir_dados();
				// remove o item
                delete f;
			}
		}
		else if(opcao == 'p')
        {
			// imprime a lista
			lista.imprimir_lista();
		}
		else if(opcao == 'a')
        {
			avaliacao_basica();
		}
	}
    return 0;
}
