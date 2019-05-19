#ifndef __WINDOWS_H
#include <windows.h>
#endif

#define MAX_CID 8



 typedef struct cidade {
    int cod_cid;
    int cid_visitada;
}cidade;


 typedef struct caminho {
        cidade * cid_atual;
        cidade * cid_vizinha;
        int adj;
        int distancia;
        caminho * link;
    }caminho;

// Mapeando as Cidades
#define PORTLAND 0
#define SEATLE 1
#define BOISE 2
#define SAN_FRANCISCO 3
#define LAKE_TAHOE 4
#define LOS_ANGELES 5
#define SAN_DIEGO 6
#define PALM_SPRINGS 7

