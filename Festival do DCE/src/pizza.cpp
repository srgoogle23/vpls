// TODO implemente essa classe de acordo com o hpp correspondente
#include "pizza.hpp"

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd) {
  this->sabor = sabor;
  this->pedacos = pedacos;
  this->borda_recheada = borda_recheada;
  this->qtd = qtd;
}
float Pizza::calcPreco() {
  // 5 reais por pedaço + 10 reais se borda recheada 
  // + 8 reais se sabor tiver a palavra "especial"
  // (ex: especial bacon, frango com catupiry especial)
  float preco = 0;
  preco += pedacos * 5;
  if (borda_recheada) {
    preco += 10;
  }
  if (sabor.find("especial") != std::string::npos) {
    preco += 8;
  }
  preco *= qtd;
  return preco;
}
std::string Pizza::descricao() const {
  std::string desc = std::to_string(qtd) + "X pizza " + sabor + ", ";
  desc += std::to_string(pedacos) + " pedaços";
  if (borda_recheada) {
    desc += " e borda recheada.";
  }
  else{
    desc+= " sem borda recheada.";
  }
  return desc;
}