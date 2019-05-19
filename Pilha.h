#ifndef __WINDOWS_H
#include <windows.h>
#endif
#define MAX_CID 8

// Possivel problema na pilha ---  Nao conisgo por null na inicialização!! ou seja sempre estoura o desimpilhamento


int insere (caminho &Caminho,caminho **pilha)
{
    struct caminho * aux;
    aux =  new caminho;
    aux->adj = Caminho.adj;
    aux->distancia = Caminho.distancia;
    aux->cid_atual = Caminho.cid_atual;
    aux->cid_vizinha = Caminho.cid_vizinha;
    aux->link = *pilha;
    *pilha = aux;
    return 1;
}

struct caminho remove(struct caminho ** pilha)
{
    struct caminho * aux;
    aux = *pilha;
    *pilha = (*pilha)->link;
    return *aux;
}

void init_pilha(caminho ** pilha, int tam)
{
    int j = 0;
    while(j < tam)
    {
        pilha[j] = NULL;
        j ++;
    }
}


