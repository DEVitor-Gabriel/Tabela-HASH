#ifndef HASH_H
#define HASH_H
#include<string>
class Hash
{
private:
    static const int Tamanho = 4;

    struct Item{
        std::string nome;
        std::string fone;
        Item* proximo;
    };

    Item* TabelaHash[Tamanho];

public:
    Hash();
    int hash(std::string chave);
    void InsertContato(std::string nome, std::string fone);
    int NumeroDeItemNoIndice(int indice);
    void MostrarTabela();
    void MostrarItensNoIndice(int indice);
    void ProcurarTelefone(std::string fone);
    void RemoveContato(std::string nome);

};

#endif // HASH_H
