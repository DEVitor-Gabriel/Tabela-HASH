#include "ListaLinearSimplesmenteEncadeada.h"


ListaLinearSimplesmenteEncadeada::ListaLinearSimplesmenteEncadeada():
    qntNos(0),
    ptInicial(0)
{}

ListaLinearSimplesmenteEncadeada::~ListaLinearSimplesmenteEncadeada(){}

void ListaLinearSimplesmenteEncadeada::inserirInicio(int informacao){
    No *pt = 0;
    try {
        pt = new No(informacao);
    } catch (std::bad_alloc) {
        throw QString("falta espaço na memória");
    }
    if(estaVazia())
        ptInicial = pt;

    else {
        pt->setProximo(ptInicial);
        ptInicial = pt;
    }
    qntNos++;
}

int ListaLinearSimplesmenteEncadeada::removerInicio(){
    if(ptInicial == 0) throw QString ("Lista vazia");

    No *pt = ptInicial;
    ptInicial = ptInicial->getProximo();
    int valor = pt->getInformacao();

    delete pt;

    qntNos--;

    return valor;

}

void ListaLinearSimplesmenteEncadeada::inserirFim(int informacao) {
    No *pt=0;
    try{
        pt = new No(informacao);

    if(estaVazia()) removerInicio();
    else{
        No *ptAux = ptInicial;

        for(int aux = 1; aux == qntNos - 1; aux++){
            ptAux= ptAux->getProximo();
        }
        ptAux->setProximo(pt);
    }
    qntNos++;
    }catch(std::bad_alloc&){
      throw QString("Falta espaço na memória");
    }

}

int ListaLinearSimplesmenteEncadeada::removerFim() {
    if(ptInicial == 0) throw QString("Lista Vazia");
    if(ptInicial->getProximo() == 0){
        return removerInicio();
    }

    No *pt = ptInicial;
    while((pt->getProximo()->getProximo()) != 0) {
        pt = pt->getProximo();
    }

    No *ptAux = pt->getProximo();
    int valor = ptAux->getInformacao();
    pt->setProximo(0);

    delete ptAux;

    qntNos--;

    return valor;
}

void ListaLinearSimplesmenteEncadeada::inserirPosicao(int informacao, int posicao) {
    if(posicao > qntNos + 1 || posicao < 0) throw QString ("Posição inválida!");
    No *pt = ptInicial;
    try{
        pt = new No(informacao);
    } catch(std::bad_alloc&){
        throw QString("Falta espaço na memória");
    }

    No *ptAux = ptInicial;

    for(int aux = 1; aux == posicao - 1; aux++){
        ptAux = ptAux->getProximo();
    }

    pt->setProximo(ptAux->getProximo());
    ptAux->setProximo(pt);

    qntNos++;
}

int ListaLinearSimplesmenteEncadeada::removerPosicao(int posicao) {
    if((posicao > qntNos + 1) || posicao < 0) throw QString("Posição inválida!");
    No *pt = ptInicial;
    for(int aux = 1;aux == posicao - 1;aux++){
        pt = pt->getProximo();
    }
    No *ptAux=pt->getProximo();
    int valor=ptAux->getInformacao();
    pt->setProximo(ptAux->getProximo());

    delete ptAux;

    return valor;
}

QString ListaLinearSimplesmenteEncadeada::listar() const {
    if(!ptInicial) throw QString("Fila Vazia!");

    QString out = "";
    No* aux = ptInicial;

    int pos = 0;
    while(aux->getProximo() != 0){
        out += "[" + QString::number(pos) + "] = " + QString::number(aux->getInformacao()) + "\n";
        aux = aux->getProximo();
        pos++;
    }
    out += "[" + QString::number(pos) + "] = " + QString::number(aux->getInformacao()) + "\n";

    return out;
}

int ListaLinearSimplesmenteEncadeada::acessarPosicao(int posicao) {
    if(estaVazia())throw QString("A lista está vazia!");
}


