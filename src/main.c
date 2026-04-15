#include <stdio.h>
#include "lista_aeronaves.h"

int main() {
    int opcao;
    ListaAeronaves lista;
    inicializarLista(&lista);

    do {
        printf("\n=== Sistema de Trafego Aereo ===\n");
        printf("1 - Adicionar aeronave\n");
        printf("2 - Listar aeronaves\n");
        printf("3 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Funcao adicionar aeronave\n");
                addAeronave(&lista);
                break;
            case 2:
                printf("Funcao listar aeronaves\n");
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }

    } while(opcao != 3);

    return 0;
}