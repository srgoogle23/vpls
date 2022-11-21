#include "dicionario.h"

// implementação de Dicionario
Dicionario::Dicionario() {
}

int Dicionario::tamanho() {
  return elementos_.size();
}

bool Dicionario::pertence(string chave) {
  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave == chave) {
	  return true;
	}
  }
  return false;
}

string Dicionario::menor() {
  // o dicionário não está vazio.
  if(elementos_.empty()) throw DicionarioVazio();

  string menor = elementos_.front().chave;
  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
    if (it->chave < menor) {
      menor = it->chave;
    }
  }
  return menor;
}

string Dicionario::valor(string chave) {
  //se a chave está no dicionário
  if(!pertence(chave)) throw ChaveInexistente();


  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave == chave) {
	  return it->valor;
	}
  }
  return "";
}

void Dicionario::Inserir(string chave, string valor) {
  if(pertence(chave)) throw ChaveRepetida();

  Elemento e;
  e.chave = chave;
  e.valor = valor;
  elementos_.push_back(e);
}

void Dicionario::Remover(string chave) {
  if(!pertence(chave)) throw ChaveInexistente();

  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave == chave) {
	  elementos_.erase(it);
	  return;
	}
  }
}

void Dicionario::Alterar(string chave, string valor) {
  if(!pertence(chave)) throw ChaveInexistente();

  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave == chave) {
	  it->valor = valor;
	  return;
	}
  }
}
Dicionario::~Dicionario() {
	
}