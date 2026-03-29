#include <stdio.h>
#include <string.h>       
#include "buscaraeronave.h"

// função que procura a aeronave pelo código
int findAeronave(Aeronave lista[], int tamanho, char callsign[]) {

    // percorre toda a lista de aeronaves
    for (int i = 0; i < tamanho; i++) {

        // compara o código da lista com o código recebido
        if (strcmp(lista[i].codigo_voo, callsign) == 0) {
            return i;  // encontrou → retorna a posição
        }
    }

    return -1;  // não encontrou nenhuma
}
