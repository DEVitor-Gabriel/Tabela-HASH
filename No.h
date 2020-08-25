#ifndef NO_H
#define NO_H

class No

{
private:

    int informacao;

    No* proximo;

public:

    No():informacao(0),proximo(0){}
    No(int informacao):informacao(informacao),proximo(0){}

    ~No(){proximo = 0;}

    int getInformacao() const;
    No* getProximo() const;

    void setInformacao(int informacao);
    void setProximo(No* proximo);
};

#endif // NO_H
