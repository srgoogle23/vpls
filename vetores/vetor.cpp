#include "vetor.h"

Vetor::Vetor(int inicio, int fim)
{
	if (fim < inicio)
		throw IntervaloVazio{inicio, fim};
	inicio_ = inicio;
	fim_ = fim;
	elementos_ = new string[fim - inicio + 1];
}

void Vetor::atribuir(int i, std::string valor)
{
	// // PRECONDIÇÃO: i está dentro de [inicio, fim]
	if (i < inicio_ || i > fim_)
		throw IndiceInvalido{inicio_, fim_, i};
	elementos_[i - inicio_] = valor;
}

string Vetor::valor(int i) const
{
	//(1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
	if (i < inicio_ || i > fim_)
		throw IndiceInvalido{inicio_, fim_, i};
	if (elementos_[i - inicio_] == "")
		throw IndiceNaoInicializado{i};
	return elementos_[i - inicio_];
}

Vetor::~Vetor()
{
	delete[] elementos_;
}