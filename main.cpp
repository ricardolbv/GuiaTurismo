#define MAX_CID 8

#define PORTLAND 0
#define SEATLE 1
#define BOISE 2
#define SAN_FRANCISCO 3
#define LAKE_TAHOE 4
#define LOS_ANGELES 5
#define SAN_DIEGO 6
#define PALM_SPRINGS 7


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX_CID 8
#include "Struct.h"
#include "Funcoes.h"
#include "Pilha.h"

#include <iostream>

using namespace std;

string vet_pritavel[MAX_CID] = {"PORTLAND",
"SEATLE",
"BOISE",
"SAN_FRANCISCO",
"LAKE_TAHOE",
"LOS_ANGELES",
"SAN_DIEGO",
"PALM_SPRINGS"};


void printa_cidades (struct cidade vet_cid[MAX_CID]);
void printa_grafo(caminho grafo[MAX_CID][MAX_CID]);
void insere_adj(int cod_cid, caminho cid[][MAX_CID], caminho ** Pilha);


/*int matriz_adj[][8] =
{                    PO  SE   BO  SAN   LAK  LOS SAN PAL
    PORTLAND        {0,   170, 420, 640, 580,  0,  0,  0},
    SEATLE          {170,  0,  500,   0,   0,  0,  0,  0},
    BOISE           {420, 500,   0,   0, 420,  0,  0,  0},
    SAN_FRANCISCO   {640,   0,   0,   0, 300,380,  0,  0},
    LAKE_TAHOE      {580,   0, 420, 300,   0,  0,  0, 780},
    LOS_ANGELES     {0,     0,   0, 380,   0,  0,120, 160},
    SAN_DIEGO       {0,     0,   0,   0,   0,120,  0, 140},
    PALM_SPRINGS    {0,     0,   0,   0, 780,160,140,   0},
};*/
int main()
{
    //Minhas inicializacoes

    cidade vet_cidades[MAX_CID];
    init_cidade(vet_cidades);
    caminho grafo[MAX_CID][MAX_CID];
    init_caminho(grafo);

    caminho * Pilha[MAX_CID];
    init_pilha(Pilha,MAX_CID);

    // ______INSERINDO CIDADES NA LISTA_______
    insere_cidade(vet_cidades, PORTLAND);
    insere_cidade(vet_cidades, SEATLE);
    insere_cidade(vet_cidades, BOISE);
    insere_cidade(vet_cidades, SAN_FRANCISCO);
    insere_cidade(vet_cidades, LAKE_TAHOE);
    insere_cidade(vet_cidades, LOS_ANGELES);
    insere_cidade(vet_cidades, SAN_DIEGO);
    insere_cidade(vet_cidades, PALM_SPRINGS);

    //_______INSERINDO CAMINHOS NO GRAFO _______
    //## PORTLAND:
    insere_caminho(grafo, vet_cidades[PORTLAND], vet_cidades[SEATLE], 170);
    insere_caminho(grafo, vet_cidades[PORTLAND], vet_cidades[BOISE], 420);
    insere_caminho(grafo, vet_cidades[PORTLAND], vet_cidades[SAN_FRANCISCO], 640);
    insere_caminho(grafo, vet_cidades[PORTLAND], vet_cidades[LAKE_TAHOE], 580);

    //## SEATLE:
    insere_caminho(grafo, vet_cidades[SEATLE], vet_cidades[SEATLE], 170);
    insere_caminho(grafo, vet_cidades[SEATLE], vet_cidades[BOISE], 500);

    //## BOISE:
    insere_caminho(grafo, vet_cidades[BOISE], vet_cidades[PORTLAND], 420);
    insere_caminho(grafo, vet_cidades[BOISE], vet_cidades[SEATLE], 500);
    insere_caminho(grafo, vet_cidades[BOISE], vet_cidades[LAKE_TAHOE], 420);

    //## SAN_FRANCISCO:
    insere_caminho(grafo, vet_cidades[SAN_FRANCISCO], vet_cidades[PORTLAND], 640);
    insere_caminho(grafo, vet_cidades[SAN_FRANCISCO], vet_cidades[LAKE_TAHOE], 300);
    insere_caminho(grafo, vet_cidades[SAN_FRANCISCO], vet_cidades[LOS_ANGELES], 380);

    //## LAKE TAHOE:
    insere_caminho(grafo, vet_cidades[LAKE_TAHOE], vet_cidades[PORTLAND], 580);
    insere_caminho(grafo, vet_cidades[LAKE_TAHOE], vet_cidades[BOISE], 420);
    insere_caminho(grafo, vet_cidades[LAKE_TAHOE], vet_cidades[SAN_FRANCISCO], 300);
    insere_caminho(grafo, vet_cidades[LAKE_TAHOE], vet_cidades[PALM_SPRINGS], 780);

    //## LOS ANGELES:
    insere_caminho(grafo, vet_cidades[LOS_ANGELES], vet_cidades[SAN_FRANCISCO], 380);
    insere_caminho(grafo, vet_cidades[LOS_ANGELES],  vet_cidades[SAN_DIEGO], 120);
    insere_caminho(grafo, vet_cidades[LOS_ANGELES], vet_cidades[PALM_SPRINGS], 160);

    //## SAN DIEGO:
    insere_caminho(grafo, vet_cidades[SAN_DIEGO], vet_cidades[LOS_ANGELES], 120);
    insere_caminho(grafo, vet_cidades[SAN_DIEGO], vet_cidades[PALM_SPRINGS], 140);

    //## PALM SPRINGS:
    insere_caminho(grafo, vet_cidades[PALM_SPRINGS], vet_cidades[LAKE_TAHOE], 780);
    insere_caminho(grafo, vet_cidades[PALM_SPRINGS], vet_cidades[LOS_ANGELES], 160);
    insere_caminho(grafo, vet_cidades[PALM_SPRINGS], vet_cidades[SAN_DIEGO], 140);


    //__________Testes____________

    //Algoritmo ---- Andar em todas as cidades e voltar

    int cid_inic, custo = 0;
    caminho desimpilha;

    cout<<"\nInsira a cidade inicial ";
    cin>> cid_inic;
    cout<<"\n\n Otima Escolha "<<vet_pritavel[cid_inic];

    insere_adj(cid_inic, grafo, Pilha);

    cout<<"\nPercurso: "<<vet_pritavel[cid_inic];
    int nao_visitados;

    while (nao_visitados > 1)
    {
        desimpilha = remove(Pilha);


        cout<<" ->"<<vet_pritavel[desimpilha.cid_vizinha->cod_cid];
        custo += desimpilha.distancia;

        desimpilha.cid_vizinha->cid_visitada = 1;
        //cout <<"\nCusto : "<< custo;

        nao_visitados = nao_visitado(vet_cidades);


            if(desimpilha.cid_vizinha->cod_cid == cid_inic && nao_visitados > 1)
             {
                desimpilha.cid_vizinha->cid_visitada = 0;
                custo += desimpilha.distancia;
             }


        init_pilha(Pilha,4);
        insere_adj(desimpilha.cid_vizinha->cod_cid,grafo, Pilha);





    }
   // cout<<"->"<<vet_pritavel[cid_inic];
    cout<<"\n\n Custo da viagem: "<<custo;


    return 0;
}



void printa_grafo(caminho grafo[MAX_CID][MAX_CID])
{
    int i, j;
    for (i = 0; i < MAX_CID; i ++)
    {
        cout<<"\ncidade["<<vet_pritavel[i]<<"]";
        for(j = 0; j < MAX_CID; j ++)
        {
            if(grafo[i][j].adj == 1)
            cout<<"->["<<vet_pritavel[j]<<"]";
        }
    }
}

void printa_cidades (struct cidade vet_cid[MAX_CID])
{
    for (int i = 0; i < MAX_CID; i++)
    {
        cout<<"\nCidade: "<<vet_pritavel[vet_cid[i].cod_cid]<<" -> Visitado: "<<vet_cid[i].cid_visitada;
    }
}


void insere_adj(int cod_cid, caminho grafo[][MAX_CID], caminho ** Pilha)
{
    int j;
    for (j = 0; j < MAX_CID; j++)
    {
        if (grafo[cod_cid][j].adj == 1 && (grafo[cod_cid][j].cid_vizinha->cid_visitada != 1))
        {
            insere(grafo[cod_cid][j],Pilha);
           // cout<<"Inserindo "<<vet_pritavel[j];
        }
    }

}
