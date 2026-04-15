#include "lista_aeronaves.h"
#include <stdio.h>
#include <string.h>

void inicializarLista(ListaAeronaves *lista) {
    lista->contador = 0;
}

int addAeronave(ListaAeronaves *lista) {
    if (lista->contador >= MAX_AERONAVES) {
        printf("Erro: lista cheia!\n");
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

    int novoId = lista->contador + 1;

    lista->aeronaves[lista->contador] =
        criarAeronave(novoId, codigo, x, y, altitude, velocidade, 2);
    lista->contador++;

    printf("\nAeronave '%s' adicionada! (ID: %d) - Status: Aguardando\n",
           codigo, novoId);
    return 1;
}

int alterarStatusAeronave(ListaAeronaves *lista, int id, int novoStatus) {
    int i;
    for (i = 0; i < lista->contador; i++) {
        if (lista->aeronaves[i].id == id) {
            lista->aeronaves[i].status = novoStatus;
            const char *statusTexto[] = {"Voando", "Pousando", "Aguardando"};
            printf("Status ID %d → %s\n", id, statusTexto[novoStatus]);
            return 1;
        }
    }
    printf("ID %d não encontrado.\n", id);
    return 0;
}

int findAeronave(Aeronave lista[], int tamanho, char callsign[]) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (strcmp(lista[i].codigo_voo, callsign) == 0) {
            return i;
        }
    }
    return -1;
}

void listarAeronaves(ListaAeronaves *lista) {
    if (lista->contador == 0) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }
    int i;
    for (i = 0; i < lista->contador; i++) {
        printf("\n=== Aeronave %d ===\n", i + 1);
        exibirAeronave(lista->aeronaves[i]);
    }
}

int removerAeronave(ListaAeronaves *lista, int id) {
    int i;
    for (i = 0; i < lista->contador; i++) {
        if (lista->aeronaves[i].id == id) {
            int j;
            for (j = i; j < lista->contador - 1; j++) {
                lista->aeronaves[j] = lista->aeronaves[j + 1];
            }
            lista->contador--;
            printf("Aeronave ID %d removida.\n", id);
            return 1;
        }
    }
    printf("ID %d não encontrado.\n", id);
    return 0;
}
