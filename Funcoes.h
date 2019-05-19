#ifndef __WINDOWS_H
#include <windows.h>
#endif



//Funcao de inserir uma cidade ja construida  UM CAMINHO

void insere_caminho(struct caminho grafo[][MAX_CID],struct cidade &atual,struct cidade &vizinha, int peso)
{
    grafo[atual.cod_cid][vizinha.cod_cid].adj = 1;
    grafo[atual.cod_cid][vizinha.cod_cid].distancia = peso;
    grafo[atual.cod_cid][vizinha.cod_cid].cid_atual = &atual; // Testar esse trecho, estou relamete atribuindo ao ponteiro?s
    grafo[atual.cod_cid][vizinha.cod_cid].cid_vizinha = &vizinha;
}

void init_caminho (struct caminho grafo[][MAX_CID]) // Implementar
{
    int i, j;
    for (i = 0; i < MAX_CID; i++)
    {
        for (j = 0; j < MAX_CID; j++)
        {
        grafo[i][j].adj = 0;
        grafo[i][j].distancia = 0;
        grafo[i][j].cid_atual = NULL; // Testar esse trecho, estou relamete atribuindo ao ponteiro?s
        grafo[i][j].cid_vizinha = NULL;
        }
    }
}
//Implmentar metodo de contrução do vetor de cidades

void insere_cidade(struct cidade vet_cid[MAX_CID],int cod)
{
    vet_cid[cod].cod_cid = cod;
    vet_cid[cod].cid_visitada = 0;
}

void init_cidade (struct cidade vet_cid[MAX_CID]) //   Implementar
{
    for (int i = 0; i< MAX_CID; i++)
    {
        vet_cid[i].cod_cid = -1;
        vet_cid[i].cid_visitada = 0;
    }
}

int nao_visitado(cidade lista[MAX_CID])
{
    int j;

        for (j = 0; j < MAX_CID; j++)
        {
            if(lista[j].cid_visitada == 0)
                return j;
        }
    return -1;
}


