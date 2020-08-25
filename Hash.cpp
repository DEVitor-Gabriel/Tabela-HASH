#include "Hash.h"
#include<iostream>
using namespace std;

Hash::Hash()
{
    for(int i = 0 ; i <Tamanho ; i++){
        TabelaHash[i] = new Item;
        TabelaHash[i]->nome = "Vazio";
        TabelaHash[i]->fone = "Vazio";
        TabelaHash[i]->proximo = NULL;
    }
}

int Hash::hash(std::string chave)
{
    int hash = 0;
    int indice;
    indice = chave.length();

    for(int i = 0; i < chave.length(); i++){
        hash = ((hash) + (int)chave[i]) * 17;
    }

    indice = hash % Tamanho;

    return indice;

}

void Hash::InsertContato(string nome, string fone)
{
    int indice = hash(nome);
    if(TabelaHash[indice]->nome == "Vazio"){
       TabelaHash[indice]->nome = nome;
       TabelaHash[indice]->fone = fone;
    }
    else{
        Item* Ptr = TabelaHash[indice];
        Item* n = new Item;
        n->nome = nome;
        n->fone = fone;
        n->proximo = NULL;
        while(Ptr->proximo != NULL)
        {
            Ptr = Ptr->proximo;
        }
        Ptr->proximo = n;
    }
}

int Hash::NumeroDeItemNoIndice(int indice){
    int contador = 0;

    if(TabelaHash[indice]->nome == "Vazio"){
        return contador;
    }
    else{
        contador ++;
        Item* Ptr = TabelaHash[indice];

        while(Ptr->proximo != NULL){
            contador ++;
            Ptr = Ptr->proximo;
        }
    }
    return contador;
}

void Hash::MostrarTabela()
{
    int numero;

    for (int i =0 ; i < Tamanho; i++){
        numero = NumeroDeItemNoIndice(i);
        cout << "------------\n";
        cout << "Indice = " << i << endl;
        cout << TabelaHash[i]->nome << endl;
        cout << TabelaHash[i]->fone << endl;
        cout << "Numero de itens : " << numero << endl;
        cout << "------------\n";
    }
}

void Hash::MostrarItensNoIndice(int indice)
{
    Item* Ptr = TabelaHash[indice];

    if(Ptr->nome == "Vazio"){
        cout << "Indice = " << indice << " está vazio ";
    }
    else{
        cout << "Indice = " << indice << " contem o seguindo item \n";
        while(Ptr != NULL){
            cout << "------------------\n";
            cout << Ptr->nome << endl;
            cout << Ptr->fone << endl;
            cout << "------------------\n";
            Ptr = Ptr->proximo;
        }
    }
}

void Hash::ProcurarTelefone(string nome)
{

    int indice = hash(nome);
    bool procurarNome = false;
    std::string telefone;

    Item* Ptr = TabelaHash[indice];
    while(Ptr != NULL){
        if(Ptr->nome == nome){
            procurarNome = true;
            telefone = Ptr->fone;
        }
        Ptr = Ptr->proximo;
    }
    if(procurarNome == true)
    {
        cout << "Seu telefone = " << telefone << endl;
    }else{
        cout << nome << "Informação não encontrada na tabela hash!"<<endl;
    }
}

void Hash::RemoveContato(string nome)
{
    int indice = hash(nome);

    Item* delPtr;
    Item* P1;
    Item* P2;

    if(TabelaHash[indice]->nome == "Vazio" && TabelaHash[indice]->fone == "Vazio"){
        cout << nome << "Não encontrado na tabela hash!\n";
    }

    else if (TabelaHash[indice]->nome == nome && TabelaHash[indice]->proximo == NULL){
        TabelaHash[indice]->nome = "Vazio";
        TabelaHash[indice]->fone = "Vazio";
        cout << nome << "Foi removido da tabela Hash \n";
    }

    else if ( TabelaHash[indice]->nome == nome){
        delPtr = TabelaHash[indice];
        TabelaHash[indice] = TabelaHash[indice]->proximo;
        delete delPtr;
        cout << nome << "Foi removido da tabela Hash \n";
    }
    else{
        P1 = TabelaHash[indice]->proximo;
        P2 = TabelaHash[indice];

        while(P1 != NULL && P1->nome != nome){
            P2 = P1;
            P1 = P1->proximo;
        }
        if(P1 == NULL){
            cout << nome <<"Foi removida da tabela Hash \n";
        }
        else{
            delPtr = P1;
            P1 = P1->proximo;
            P1->proximo = P1;

            delete delPtr;

            cout << " Foi removido da tabela Hash! \n";
        }
    }

}
