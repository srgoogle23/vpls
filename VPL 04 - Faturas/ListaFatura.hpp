#ifndef LISTA_FATURA_H
#define LISTA_FATURA_H

#include "Fatura.hpp"

class ListaFatura
{
    private:
        Fatura *f[100];
        int indiceDasFaturas;
    public:
        ListaFatura();
        void insere_fatura(Fatura *fatura);
        Fatura *proxima_fatura();
        void imprimir_lista();
};

#endif