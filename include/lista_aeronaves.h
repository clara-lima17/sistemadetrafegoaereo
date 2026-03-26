#ifndef LISTA_AERONAVES_H
#define LISTA_AERONAVES_H

#include "aeronave.h"

#define MAX_AERONAVES 100

// Estrutura que representa a lista de aeronaves
typedef struct {
    Aeronave aeronaves[MAX_AERONAVES];
    int contador;
} ListaAeronaves;

// Inicializa a lista (deve ser chamada antes de qualquer outra função)
void inicializarLista(ListaAeronaves *lista);

// Adiciona uma aeronave à lista via terminal (status padrão: aguardando)
int addAircraft(ListaAeronaves *lista);

// Altera o status de uma aeronave pelo ID
// status: 0 = voando, 1 = pousando, 2 = aguardando
int alterarStatusAeronave(ListaAeronaves *lista, int id, int novoStatus);

#endif // LISTA_AERONAVES_H
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "lista_aeronaves.h"
#include <stdio.h>

// Inicializa a lista zerando o contador
void inicializarLista(ListaAeronaves *lista) {
    lista->contador = 0;
}

// Adiciona uma aeronave à lista com dados do usuário via terminal
// Status começa como 2 (aguardando) por padrão
int addAircraft(ListaAeronaves *lista) {
    if (lista->contador >= MAX_AERONAVES) {
        printf("Erro: lista de aeronaves está cheia!\n");
        return 0;
    }

    char codigo[10];
    float x, y, altitude, velocidade;

    printf("\n=== Adicionar nova aeronave ===\n");
    printf("Código do voo (ex: AZ1234): ");
    scanf("%9s", codigo);

    printf("Posição X: ");
    scanf("%f", &x);

    printf("Posição Y: ");
    scanf("%f", &y);

    printf("Altitude: ");
    scanf("%f", &altitude);

    printf("Velocidade: ");
    scanf("%f", &velocidade);

    // ID gerado automaticamente
    int novoId = lista->contador + 1;

    // Status padrão: 2 = aguardando (sugestão de Thayanne)
    lista->aeronaves[lista->contador] = criarAeronave(novoId, codigo, x, y, altitude, velocidade, 2);
    lista->contador++;

    printf("\nAeronave '%s' adicionada com sucesso! (ID: %d) - Status: Aguardando\n", codigo, novoId);
    return 1;
}

// Altera o status de uma aeronave pelo ID
int alterarStatusAeronave(ListaAeronaves *lista, int id, int novoStatus) {
    for (int i = 0; i < lista->contador; i++) {
        if (lista->aeronaves[i].id == id) {
            lista->aeronaves[i].status = novoStatus;

            const char *statusTexto[] = {"Voando", "Pousando", "Aguardando"};
            printf("Status da aeronave ID %d atualizado para: %s\n", id, statusTexto[novoStatus]);
            return 1;
        }
    }

    printf("Aeronave com ID %d não encontrada.\n", id);
    return 0;
}

