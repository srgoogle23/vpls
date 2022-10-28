// TODO implemente essa classe de acordo com o hpp correspondente
#include "cachorro_quente.hpp"

CachorroQuente::CachorroQuente(int num_salsichas,
            std::vector<std::string>& complementos,
            bool prensado,
            int qtd) {
  this->num_salsichas = num_salsichas;
  this->complementos = complementos;
  this->prensado = prensado;
  this->qtd = qtd;
}
float CachorroQuente::calcPreco() {
  float preco = 5;
  preco += 1.5 * num_salsichas;
  preco += 1 * complementos.size();
  if (prensado) {
    preco += 0.5;
  }
  preco *= this->qtd;
  return preco;
}
std::string CachorroQuente::descricao() const {
std::string desc = std::to_string(qtd) + "X cachorro-quente ";
  if (prensado) {
    desc += "prensado ";
  }
  desc += "com " + std::to_string(num_salsichas) + " salsicha(s), ";
  for (unsigned int i = 0; i < complementos.size(); i++) {
    desc += complementos[i];
    if (i != complementos.size() - 1) {
      desc += ", ";
    }
    else{
        desc += ". ";
    }
  }
  return desc;
  
}

