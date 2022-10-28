#ifndef CACHORRO_QUENTE_H
#define CACHORRO_QUENTE_H

#include "produto.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um produto do tipo Cachorro-Quente.
 *
 */
class CachorroQuente : public Produto {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis da classe.
   * Note que o valor unitario (membro da classe mãe) deve ser calculado 
   * através do método calcPreco.
   *
   * @param num_salsichas número de salsichas
   * @param complementos coleção de complementos
   * @param prensado se o cachorro quente deve ser prensado
   * @param qtd Quantidade do item.
   */
  CachorroQuente(int num_salsichas,
           std::vector<std::string>& complementos,
           bool prensado,
           int qtd);

  /**
   * @brief Calcula o valor do cachorro quente de acordo com as regras:
   * 5 reais preço base + 1.50 real por salsicha 
   * + 1 real por complemento + 0.50 centavos se for prensar
   * 
   * @return float preço do cachorro quente em reais
   */
  float calcPreco() override;

  /**
   * @brief Retorna a descricao detalhada da comida japonesa.
   * Ex: 4X cachorro-quente com 2 salsichas, milho, queijo ralado.
   *
   * @return std::string Descricao da comida japonesa.
   */
  std::string descricao() const override;

 private:
  // TODO: Declare aqui as variaveis da classe. Note que as variaveis quantidade
  // quantidade e valor_unitario ja sao herdadas de Produto
  int num_salsichas;
  std::vector<std::string> complementos;
  bool prensado;
  int qtd;
  
};
#endif