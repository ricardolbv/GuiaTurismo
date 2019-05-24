#ifndef __WINDOWS_H
#include <windows.h>
#endif

#define MAX_CID 24



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


