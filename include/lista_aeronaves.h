#ifndef LISTA_AERONAVES_H
#define LISTA_AERONAVES_H

#include "aeronave.h"
#include <string.h>

#define MAX_AERONAVES 100

typedef struct {
    Aeronave aeronaves[MAX_AERONAVES];
    int contador;
} ListaAeronaves;

void inicializarLista(ListaAeronaves *lista);
int addAeronave(ListaAeronaves *lista);
int alterarStatusAeronave(ListaAeronaves *lista, int id, int novoStatus);
int findAeronave(Aeronave lista[], int tamanho, char callsign[]);
void listarAeronaves(ListaAeronaves *lista);
int removerAeronave(ListaAeronaves *lista, int id);

#endif
