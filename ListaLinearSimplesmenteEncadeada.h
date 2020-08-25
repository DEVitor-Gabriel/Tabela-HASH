#ifndef LISTALINEARSIMPLESMENTEENCADEADA_H
#define LISTALINEARSIMPLESMENTEENCADEADA_H

#include "No.h"
#include "QString"

class ListaLinearSimplesmenteEncadeada
{
private:
    int qntNos;
    No* ptInicial;

public:
    ListaLinearSimplesmenteEncadeada();
    ~ListaLinearSimplesmenteEncadeada();

    int getQntNos() const {return qntNos;}

    void inserirInicio(int informacao);
    void inserirFim(int informacao);
    void inserirPosicao(int informacao, int posicao);

    int removerInicio();
    int removerFim();
    int removerPosicao(int posicao);
    int removerInformacao(int informacao);

    int acessarInformacao(int informacao);
    int acessarPosicao(int posicao);

    bool estaVazia() const {return ptInicial == 0;}

    QString listar() const;
};

#endif // LISTALINEARSIMPLESMENTEENCADEADA_H
