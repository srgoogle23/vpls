#include<iostream>
#include <vector>

using namespace std;

typedef struct Categoria{
	// codigo inteiro
	int codigo;
	// valor gasto, double
	double valor;
} Categoria;

// cria um enum com os tipos de categoria
//     0 - Saúde
// 1 - Educação
//2 - Segurança
//3 - Previdência
//4 - Administração Pública
enum TipoCategoria{
	SAUDE = 0,
	EDUCACAO = 1,
	SEGURANCA = 2,
	PREVIDENCIA = 3,
	ADMINISTRACAO_PUBLICA = 4
};

// Inicializa um objeto categoria com seu código e o valor que ela deve ter em caixa para gastos com sua pasta.
void inicia_categoria(Categoria *categoria,
              int codigo_categoria, double valor_caixa) {
	categoria->codigo = codigo_categoria;
	categoria->valor = valor_caixa;
}

// Recupera o código correspondente a uma categoria.
int codigo_categoria(Categoria *categoria) {
	return categoria->codigo;
}

// Recupera o valor em caixa de uma categoria.
double valor_caixa_categoria(Categoria *categoria){
	return categoria->valor;
}

// Adiciona uma quantia ao caixa de uma categoria.
void adiciona_caixa_categoria(Categoria *categoria, double valor) {
	categoria->valor += valor;
}

// Remove uma quantia ao caixa de uma categoria.
void gasta_caixa_categoria(Categoria *categoria, double valor) {
	categoria->valor -= valor;
}


typedef struct Orcamento {
	// vetor de categorias
	vector<Categoria> categorias;
	// valor monetário total do orçamento
	double valor_total;
} Orcamento;

// Inicializa um objeto Orçamento, sendo que ele deve conter um objeto categoria para cada pasta.
// Recebe como parâmetro o valor monetário que deve ser atribuído a aquele orçamento.
// Este valor deve ser distribuído a cada categoria, nos percentuais descritos anteriormente.
void inicia_orcamento(Orcamento *orcamento, double impostos) {
//0 - Saúde - 15%
//1 - Educação - 15%
//2 - Segurança - 20%
//3 - Previdência - 35%
//4 - Administração Pública - 15%

	orcamento->valor_total = impostos;
	orcamento->categorias.resize(5);
	inicia_categoria(&orcamento->categorias[SAUDE], SAUDE, impostos * 0.15);
	inicia_categoria(&orcamento->categorias[EDUCACAO], EDUCACAO, impostos * 0.15);
	inicia_categoria(&orcamento->categorias[SEGURANCA], SEGURANCA, impostos * 0.20);
	inicia_categoria(&orcamento->categorias[PREVIDENCIA], PREVIDENCIA, impostos * 0.35);
	inicia_categoria(&orcamento->categorias[ADMINISTRACAO_PUBLICA], ADMINISTRACAO_PUBLICA, impostos * 0.15);
}

// Reduz o valor no caixa da categoria especificada.
void gasto_categoria(Orcamento *orcamento, int codigo_categoria, double valor) {
	gasta_caixa_categoria(&orcamento->categorias[codigo_categoria], valor);
}

// Retorna o valor em caixa da categoria especificada.
double saldo_categoria(Orcamento *orcamento, int codigo_categoria) {
	return valor_caixa_categoria(&orcamento->categorias[codigo_categoria]);
}

// Retorna o ponteiro para o objeto da categoria especificada.
Categoria* recupera_categoria(Orcamento *orcamento, int codigo_categoria) {
	return &orcamento->categorias[codigo_categoria];
}

int main() {
  Orcamento orcamento;

  char test = 0;
  while(cin >> test) {
  switch (test) {
    case 'o': {
      double valor = 0;
      cin >> valor;
      inicia_orcamento(&orcamento, valor);
    }
    break;
    case 'g': {
      int categoria = 0;
      double valor = 0;
      cin >> categoria >> valor;
      gasto_categoria(&orcamento, categoria, valor);
      cout << categoria << ": " << saldo_categoria(&orcamento, categoria) << endl;
    }
    break;
    case 'p': {
      for (int categoria = 0; categoria < 5; categoria++) {
        cout << categoria << ": " << saldo_categoria(&orcamento, categoria) << endl;
      }
    }
    break;
    default: {
      cout << "----------" << endl;
    } break;
  }
  }
  return 0;
}
