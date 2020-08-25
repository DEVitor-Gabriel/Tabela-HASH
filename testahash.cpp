#include "testahash.h"
#include <iostream>
using namespace std;
void testahash::menu()
{
    string nome = "", fone = "";
    int n;

    obj.InsertContato("Ana","00001111");
    obj.InsertContato("Carlos","00003333");
    obj.InsertContato("Bia","00002222");
    obj.InsertContato("Fabio","00006666");
    obj.InsertContato("Gustavo","00007777");
    obj.InsertContato("Daniel","00004444");
    obj.InsertContato("Ingrid","00009999");
    obj.InsertContato("Heitor","00008888");
    obj.InsertContato("Eduardo","00005555");
    obj.MostrarItensNoIndice(7);
    short int op;
    do{
        cout << "\t MENU" << endl;
        cout << "Esse programa insere alguns exemplos automaticamente!!\n1 - Mostrar Tabela\n2 - Mostrar itens no indice\n3 - Procurar telefone\n4 - Remover um contato\n5 -  Encerrar o Programa" << endl;
        cin >> op;
        switch (op) {
        case 1:
            obj.MostrarTabela();
            break;
        case 2:
            cout<<"Qual o indice do item?"<<endl;
            cin>>n;
            obj.MostrarItensNoIndice(n);
            break;

        case 3:
            cout<<"Digitie o numero de telefone de 8 digitos"<<endl;
            getline(cin,fone);
            obj.ProcurarTelefone(fone);
            break;
        case 4:
            cout<<"Digite o nome para remover"<<endl;
            getline(cin,nome);
            obj.RemoveContato(nome);

            break;
        case 5:

            cout << "PROGRAMA ENCERRADO!!!" << endl;
            exit(0);

        default:
            cout << "Opcao invailda tente novamente" << endl;
            break;
        }
    }while(op != 5);

}

