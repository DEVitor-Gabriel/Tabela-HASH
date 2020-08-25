#include "No.h"
#include<iostream>
using namespace std;


int No::getInformacao() const
{
    return informacao;
}

No *No::getProximo() const
{
    return proximo;
}

void No::setInformacao(int informacao)
{
    this->informacao = informacao;
}

void No::setProximo(No *proximo)
{
    this->proximo = proximo;
}

