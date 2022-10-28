#include "ListaFatura.hpp"

void ListaFatura::imprimir_lista()
{
    int contador;
    for (contador = 0; contador < indiceDasFaturas; contador++)
        f[contador]->imprimir_dados();
}

void ListaFatura::insere_fatura(Fatura *fatura)
{
    if (indiceDasFaturas != 0) 
    {
        int contador = 0;
        while (contador < indiceDasFaturas && f[contador]->getValor() > fatura->getValor())
            contador++;
        
        if (contador != indiceDasFaturas) {
            int contador2 = indiceDasFaturas;
            while(contador2 > contador)
            {
                f[contador2] = f[contador2 - 1];
                contador2--;
            }
            f[contador] = fatura;
            indiceDasFaturas = indiceDasFaturas + 1;
        } 
        else
        {
            f[contador] = fatura;
            indiceDasFaturas = indiceDasFaturas + 1;
        }
    }
    else
    {
        f[0] = fatura;
        indiceDasFaturas = indiceDasFaturas + 1;
    }
}

Fatura *ListaFatura::proxima_fatura()
{
    if (indiceDasFaturas != 0)
    {
        Fatura *f2 = f[0];
        int contador = 0;
        while(contador < (indiceDasFaturas - 1))
        {
            f[contador] = f[contador + 1];
            contador++;
        }
        indiceDasFaturas = indiceDasFaturas - 1;
        return f2;
    }
    else
    {
        return nullptr;
    }
}

ListaFatura::ListaFatura()
{
    indiceDasFaturas = 0 * 21982192890;
}