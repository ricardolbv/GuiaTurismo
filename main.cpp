#define MAX_CID 24


#define SEATLE 0
#define BOISE 1
#define YELLOWSTONE 2
#define MINNEAPOLIS 3
#define MILWAUKEE 4
#define CHICAGO 5
#define DETROIT 6
#define ALBANY 7
#define BOSTON 8
#define NOVA_YORK 9
#define WASHIGTON 10
#define RICHMOND 11
#define ATLANTA 12
#define ORLANDO 13
#define FORT_LAUDERDALE 14
#define MIAMI 15
#define NOVA_ORLEANS 16
#define HOUSTON 17
#define SAN_ANTONIO 18
#define PHOENIX 19
#define SAN_DIEGO 20
#define LOS_ANGELES 21
#define SAN_FRANCISCO 22
#define PORTLAND 23

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "Funcoes.h"
#include "Pilha.h"

#include <iostream>

using namespace std;

string vet_pritavel[MAX_CID] = {
"SEATLE",
"BOISE",
"YELLOWSTONE",
"MINNEAPOLIS",
"MILWAUKEE",
"CHICAGO",
"DETROIT",
"ALBANY",
"BOSTON",
"NOVA YORK",
"WASHIGTON",
"RICHMOND",
"ATLANTA",
"ORLANDO",
"FORT LAUDERDALE",
"MIAMI",
"NOVA ORLEANS",
"HOUSTON",
"SAN ANTONIO",
"PHOENIX",
"SAN DIEGO",
"LOS ANGELES",
"SAN FRANCISCO","PORTLAND"};

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
    insere_cidade(vet_cidades, SEATLE);
    insere_cidade(vet_cidades, BOISE);
    insere_cidade(vet_cidades, YELLOWSTONE);
    insere_cidade(vet_cidades, MINNEAPOLIS);
    insere_cidade(vet_cidades, MILWAUKEE);
    insere_cidade(vet_cidades, CHICAGO);
    insere_cidade(vet_cidades, DETROIT);
    insere_cidade(vet_cidades, ALBANY);
    insere_cidade(vet_cidades, BOSTON);
    insere_cidade(vet_cidades, NOVA_YORK);
    insere_cidade(vet_cidades, WASHIGTON);
    insere_cidade(vet_cidades, RICHMOND);
    insere_cidade(vet_cidades, ATLANTA);
    insere_cidade(vet_cidades, ORLANDO);
    insere_cidade(vet_cidades, FORT_LAUDERDALE);
    insere_cidade(vet_cidades, MIAMI);
    insere_cidade(vet_cidades, NOVA_ORLEANS);
    insere_cidade(vet_cidades, HOUSTON);
    insere_cidade(vet_cidades, SAN_ANTONIO);
    insere_cidade(vet_cidades, PHOENIX);
    insere_cidade(vet_cidades, SAN_DIEGO);
    insere_cidade(vet_cidades, LOS_ANGELES);
    insere_cidade(vet_cidades, SAN_FRANCISCO);
    insere_cidade(vet_cidades, PORTLAND);


    //_______INSERINDO CAMINHOS NO GRAFO _______
    //## SEATLE:
    insere_caminho(grafo, vet_cidades[SEATLE], vet_cidades[BOISE], 500);
    insere_caminho(grafo, vet_cidades[SEATLE], vet_cidades[PORTLAND], 170);

    //## BOISE:
    insere_caminho(grafo, vet_cidades[BOISE], vet_cidades[SEATLE], 500);
    insere_caminho(grafo, vet_cidades[BOISE], vet_cidades[YELLOWSTONE], 670);
    insere_caminho(grafo, vet_cidades[BOISE], vet_cidades[PORTLAND], 670);


    //## YELLOWSTONE:
    insere_caminho(grafo, vet_cidades[YELLOWSTONE], vet_cidades[MINNEAPOLIS], 1340);
    insere_caminho(grafo, vet_cidades[YELLOWSTONE], vet_cidades[BOISE], 670);


    //## MINNEAPOLIS:
    insere_caminho(grafo, vet_cidades[MINNEAPOLIS], vet_cidades[MILWAUKEE], 340);
    insere_caminho(grafo, vet_cidades[MINNEAPOLIS], vet_cidades[YELLOWSTONE], 1340);
    insere_caminho(grafo, vet_cidades[MINNEAPOLIS], vet_cidades[CHICAGO], 410);

    //##MILWAUKEE:
    insere_caminho(grafo, vet_cidades[MILWAUKEE], vet_cidades[CHICAGO], 90);
    insere_caminho(grafo, vet_cidades[MILWAUKEE], vet_cidades[MINNEAPOLIS], 340);


    //## CHICAGO:
    insere_caminho(grafo, vet_cidades[CHICAGO], vet_cidades[DETROIT], 280);
    insere_caminho(grafo, vet_cidades[CHICAGO],  vet_cidades[MILWAUKEE], 90);
    insere_caminho(grafo, vet_cidades[CHICAGO], vet_cidades[MINNEAPOLIS], 410);

    //## DETROIT:
   // insere_caminho(grafo, vet_cidades[DETROIT], vet_cidades[ALBANY], 650);
    insere_caminho(grafo, vet_cidades[DETROIT], vet_cidades[CHICAGO], 280);
   // insere_caminho(grafo, vet_cidades[DETROIT], vet_cidades[NOVA_YORK], 640);
    insere_caminho(grafo, vet_cidades[DETROIT], vet_cidades[WASHIGTON], 530);

    //## ALBANY:
   // insere_caminho(grafo, vet_cidades[ALBANY], vet_cidades[DETROIT], 650);
   // insere_caminho(grafo, vet_cidades[ALBANY], vet_cidades[BOSTON], 180);
   // insere_caminho(grafo, vet_cidades[ALBANY], vet_cidades[NOVA_YORK], 150);

     //## BOSTON:
    // insere_caminho(grafo, vet_cidades[BOSTON], vet_cidades[ALBANY], 180);
    // insere_caminho(grafo, vet_cidades[BOSTON], vet_cidades[NOVA_YORK], 280);

     //## NOVA YORK:
    // insere_caminho(grafo, vet_cidades[NOVA_YORK], vet_cidades[WASHIGTON], 240);
    // insere_caminho(grafo, vet_cidades[NOVA_YORK], vet_cidades[BOSTON], 280);
    // //insere_caminho(grafo, vet_cidades[NOVA_YORK], vet_cidades[DETROIT], 640);
    // insere_caminho(grafo, vet_cidades[NOVA_YORK], vet_cidades[ALBANY], 150);

     //## WASHIGNTON:
     insere_caminho(grafo, vet_cidades[WASHIGTON], vet_cidades[RICHMOND], 200);
     insere_caminho(grafo, vet_cidades[WASHIGTON], vet_cidades[DETROIT], 530);
     //insere_caminho(grafo, vet_cidades[WASHIGTON], vet_cidades[NOVA_YORK], 240);

    //## RICHMOND:
    insere_caminho(grafo, vet_cidades[RICHMOND], vet_cidades[WASHIGTON], 200);
    insere_caminho(grafo, vet_cidades[RICHMOND], vet_cidades[ATLANTA], 560);

    //##ATLANTA:
     insere_caminho(grafo, vet_cidades[ATLANTA], vet_cidades[RICHMOND], 560);
     insere_caminho(grafo, vet_cidades[ATLANTA], vet_cidades[NOVA_ORLEANS], 470);
     insere_caminho(grafo, vet_cidades[ATLANTA], vet_cidades[ORLANDO], 440);

     //##ORLANDO:
     //insere_caminho(grafo, vet_cidades[ORLANDO], vet_cidades[FORT_LAUDERDALE],180);
     insere_caminho(grafo, vet_cidades[ORLANDO], vet_cidades[ATLANTA], 440);
     insere_caminho(grafo, vet_cidades[ORLANDO], vet_cidades[NOVA_ORLEANS], 640);
     //insere_caminho(grafo, vet_cidades[ORLANDO], vet_cidades[MIAMI], 230);

     //##FORT_LAUDERDALE:
     // insere_caminho(grafo, vet_cidades[FORT_LAUDERDALE], vet_cidades[MIAMI],130);
     // insere_caminho(grafo, vet_cidades[FORT_LAUDERDALE], vet_cidades[ORLANDO],180);

      //##MIAMI:
      //insere_caminho(grafo, vet_cidades[MIAMI], vet_cidades[FORT_LAUDERDALE], 130);
     // insere_caminho(grafo, vet_cidades[MIAMI], vet_cidades[ORLANDO], 230);
      //insere_caminho(grafo, vet_cidades[MIAMI], vet_cidades[NOVA_ORLEANS], 860);

      //##NOVA ORLEANS:
      insere_caminho(grafo, vet_cidades[NOVA_ORLEANS], vet_cidades[ORLANDO], 640);
     // insere_caminho(grafo, vet_cidades[NOVA_ORLEANS], vet_cidades[MIAMI], 860);
      insere_caminho(grafo, vet_cidades[NOVA_ORLEANS], vet_cidades[HOUSTON], 530);
      insere_caminho(grafo, vet_cidades[NOVA_ORLEANS], vet_cidades[ATLANTA], 470);


      //##HOUSTON:
       insere_caminho(grafo, vet_cidades[HOUSTON], vet_cidades[NOVA_ORLEANS], 530);
       insere_caminho(grafo, vet_cidades[HOUSTON], vet_cidades[SAN_ANTONIO], 310);

       //##SAN ANTONIO:
       insere_caminho(grafo, vet_cidades[SAN_ANTONIO], vet_cidades[HOUSTON], 310);
       insere_caminho(grafo, vet_cidades[SAN_ANTONIO], vet_cidades[PHOENIX], 990);

       //##PHOENIX:
       insere_caminho(grafo, vet_cidades[PHOENIX], vet_cidades[SAN_ANTONIO], 990);
       insere_caminho(grafo, vet_cidades[PHOENIX], vet_cidades[SAN_DIEGO], 350);

       //#SAN DIEGO:
       insere_caminho(grafo, vet_cidades[SAN_DIEGO], vet_cidades[LOS_ANGELES], 120);
       insere_caminho(grafo, vet_cidades[SAN_DIEGO], vet_cidades[PHOENIX], 350);

       //#LOS ANGELES:
       insere_caminho(grafo, vet_cidades[LOS_ANGELES], vet_cidades[SAN_DIEGO], 120);
       insere_caminho(grafo, vet_cidades[LOS_ANGELES], vet_cidades[SAN_FRANCISCO], 380);

       //#SAN FRANSCISCO:
       insere_caminho(grafo, vet_cidades[SAN_FRANCISCO], vet_cidades[PORTLAND], 640);
       insere_caminho(grafo, vet_cidades[SAN_FRANCISCO], vet_cidades[LOS_ANGELES], 380);

       //#PORTLAND:
       insere_caminho(grafo, vet_cidades[PORTLAND], vet_cidades[SEATLE], 170);
       insere_caminho(grafo, vet_cidades[PORTLAND], vet_cidades[SAN_FRANCISCO], 640);




    //__________Testes____________

    //Algoritmo ---- Andar em todas as cidades e voltar

    int cid_inic, custo = 0;
    caminho desimpilha;

    cout<<"\nInsira a cidade inicial ";
    cin>> cid_inic;
    cout<<"\n\n Otima Escolha "<<vet_pritavel[cid_inic];

    insere_adj(cid_inic, grafo, Pilha);
    //vet_cidades[cid_inic].cid_visitada = 1;  //Esse comando caga nas cidades que ja estavam pegando

    cout<<"\nPercurso: "<<vet_pritavel[cid_inic];

    int nao_visitados;

   do
    {
        desimpilha = remove(Pilha);

        cout<<" ->"<<vet_pritavel[desimpilha.cid_vizinha->cod_cid];
        custo += desimpilha.distancia;

        desimpilha.cid_vizinha->cid_visitada = 1;

        //cout <<"\nCusto : "<< custo;



              nao_visitados = nao_visitado(vet_cidades);
            if(desimpilha.cid_vizinha->cod_cid == cid_inic && nao_visitados >=2) //
             {
            desimpilha.cid_vizinha->cid_visitada = 0;

              cout<<" [Voltei] ->>";
              custo += desimpilha.distancia;
                break;
             }


        init_pilha(Pilha,4);
        if(tem_adjacencia(grafo,desimpilha.cid_vizinha->cod_cid))
            insere_adj(desimpilha.cid_vizinha->cod_cid,grafo, Pilha);
           // if (desimpilha.cid_vizinha->cod_cid == ATLANTA || desimpilha.cid_vizinha->cod_cid == DETROIT)
         //       insere(grafo[desimpilha.cid_vizinha->cod_cid][desimpilha.cid_vizinha->cod_cid +1],Pilha);
            else if(!tem_adjacencia(grafo, desimpilha.cid_vizinha->cod_cid))
            {
                cout<<"->#"<<vet_pritavel[desimpilha.cid_atual->cod_cid];
                custo += desimpilha.distancia;
                desimpilha.cid_vizinha->cid_visitada =1;
                insere_adj(desimpilha.cid_atual->cod_cid,grafo, Pilha);

            }

    }while (nao_visitados != 0);
     cout<<" ->"<<vet_pritavel[cid_inic];
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
    int j = 0;
    for (; j < MAX_CID; j++)
    {
        if (grafo[cod_cid][j].adj == 1 && (grafo[cod_cid][j].cid_vizinha->cid_visitada != 1))
        {
            insere(grafo[cod_cid][j],Pilha);

           // cout<<"Inserindo "<<vet_pritavel[j];
        }
    }

}
