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
  string menor = elementos_.front().chave;
  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave < menor) {
	  menor = it->chave;
	}
  }
  return menor;
}

string Dicionario::valor(string chave) {
  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave == chave) {
	  return it->valor;
	}
  }
  return "";
}

void Dicionario::Inserir(string chave, string valor) {
  Elemento e;
  e.chave = chave;
  e.valor = valor;
  elementos_.push_back(e);
}

void Dicionario::Remover(string chave) {
  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave == chave) {
	  elementos_.erase(it);
	  return;
	}
  }
}

void Dicionario::Alterar(string chave, string valor) {
  for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); ++it) {
	if (it->chave == chave) {
	  it->valor = valor;
	  return;
	}
  }
}
Dicionario::~Dicionario() {
	
}