#include "acai.hpp"

Acai::Acai(int tamanho, std::vector<std::string>& complementos, int qtd) {
  this->tamanho = tamanho;
  this->complementos = complementos;
  this->qtd = qtd;
}
float Acai::calcPreco() {
  // 0.02 centavos por ml + 2 reais cada complemento
  float preco = 0;
  preco += tamanho * 0.02;
  preco += complementos.size() * 2;
  preco *= qtd;
  return preco;
}
std::string Acai::descricao() const {
  std::string desc = std::to_string(qtd) + "X açai " + std::to_string(tamanho) + "ml com ";
  for (unsigned int i = 0; i < complementos.size(); i++) {
    desc += complementos[i];
    if (i != complementos.size() - 1) {
      desc += ", ";
    }
    else {
      desc += ".";
    }
  }
  return desc;
}