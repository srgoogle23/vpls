#ifndef FATURA_H
#define FATURA_H

class Fatura
{
	private:
		int codigo;
		double valor;
	public:
		Fatura(int id, double valor);
		void imprimir_dados();
		double getValor();
		int getCodigo();
};

#endif