#ifndef _ARRAY_CPP_
#define _ARRAY_CPP_

#include <iostream>
#include <vector>

#include "array.hpp"

using namespace std;

void adicionarAoArray(int abc, vector<int> &array)
{
    array.push_back(abc);
}

void read(vector<int> &array)
{
    int size = 0;
    while(cin >> size)
    {
        adicionarAoArray(size, array);
    }
}

void mostrarEspaco()
{
    cout << " ";
}

void incrementaUm(unsigned int &abc)
{
    abc++;
}

void write(vector<int> &array)
{
    unsigned int walk = 0;
    while(walk < array.size())
    {
        cout << array[walk];
        mostrarEspaco();
        incrementaUm(walk);
    }
    cout << endl;   
}

void rotate(vector<int> &array, int r)
{
    int indiceRotacao = r;
    if (indiceRotacao <= 0)
    {
        int rotacaoNegativa = indiceRotacao * -1;
        int contadorRotacao = 0;
        while (contadorRotacao < rotacaoNegativa)
        {
            int arrayZero = array[0];
            int contadorRotacaoSecundario = 0;
            int tamanhoReverso = array.size() - 1;
            while(contadorRotacaoSecundario < tamanhoReverso)
            {
                int proximaRotacao = contadorRotacaoSecundario + 1;
                array[contadorRotacaoSecundario] = array[proximaRotacao];
                contadorRotacaoSecundario++;
            }
            int tamanhoReversoPosRotacao = array.size() - 1;
            array[tamanhoReversoPosRotacao] = arrayZero;
            contadorRotacao++;
        }
    }
    else
    {
        for (int i = 0; i < indiceRotacao; i++)
        {
            int tamanhoFinal = array.size() - 1;
            int arrayFinal = array[tamanhoFinal];
            int contadorRotacao = tamanhoFinal;
            while (contadorRotacao > 0)
            {
                int rotacaoAnterior = contadorRotacao - 1;
                array[contadorRotacao] = array[rotacaoAnterior];
                contadorRotacao--;
            }
            array[0] = arrayFinal;
        }
    }
}

void chamaWrite(vector<int> &array)
{
    write(array);
}

void print(vector<int> &array)
{
    chamaWrite(array);
}

#endif