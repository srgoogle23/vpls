#include <string>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd)
{
    // se ja existe a mercadoria, incrementa a quantidade
    if (mercadorias.find(mercadoria) != mercadorias.end())
        mercadorias[mercadoria] += qtd;
    else
        mercadorias[mercadoria] = qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd)
{
    // se existe a mercadoria, decrementa a quantidade
    if (mercadorias.find(mercadoria) != mercadorias.end())
        if(mercadorias[mercadoria] >= qtd)
            mercadorias[mercadoria] -= qtd;
        else
            mercadorias[mercadoria] = 0;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
    if (mercadorias.find(mercadoria) != mercadorias.end())
    {
        return mercadorias.at(mercadoria);
    }
    else
    {
        return 0;
    }
}

void Estoque::imprime_estoque() const {
    for (auto& mercadoria : mercadorias)
    {
        std::cout << mercadoria.first << ", " << mercadoria.second << std::endl;
    }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
    for (auto& mercadoria : rhs.mercadorias)
    {
        add_mercadoria(mercadoria.first, mercadoria.second);
    }
    return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
    for (auto& mercadoria : rhs.mercadorias)
    {
        sub_mercadoria(mercadoria.first, mercadoria.second);
    }
    return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
// * Para cada mercadoria m em lhs:
// * a. Existe m em rhs;
// * b. A quantidade de m em rhs eh maior que a quantidade de m em lhs
    bool result = false;
    for (auto& m : lhs.mercadorias)
    {
        // using get_qtd
        if (rhs.get_qtd(m.first) > m.second)
        {
            result = true;
        }
        else
        {
            result = false;
            break;
        }
    }
    return result;
}

bool operator > (Estoque& lhs, Estoque& rhs)
{
    return rhs < lhs;
}