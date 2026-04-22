#include <stdio.h>
#include <math.h>
#include <string.h>
#include "conflito.h"
#include "lista_aeronaves.h"

ResultadoConflito conflito_verificar_par(const Aeronave *a,
                                          const Aeronave *b) {

    ResultadoConflito resultado;

    resultado.id_aeronave_a = a->id;
    resultado.id_aeronave_b = b->id;

    strcpy(resultado.codigo_a, a->codigo_voo);
    strcpy(resultado.codigo_b, b->codigo_voo);

    double dx = b->x - a->x;
    double dy = b->y - a->y;
    resultado.distancia_horizontal = sqrt(dx * dx + dy * dy);

    resultado.diferenca_altitude = fabs(b->altitude - a->altitude);

    if (resultado.distancia_horizontal < CONFLITO_SEP_HORIZONTAL_M &&
        resultado.diferenca_altitude < CONFLITO_SEP_VERTICAL_M) {

        resultado.nivel = CONFLITO_CRITICO;

    } else if (resultado.distancia_horizontal < CONFLITO_SEP_HORIZONTAL_M * 2 &&
               resultado.diferenca_altitude < CONFLITO_SEP_VERTICAL_M * 2) {

        resultado.nivel = CONFLITO_ALERTA;

    } else {
        resultado.nivel = CONFLITO_NENHUM;
    }

    return resultado;
}

void verificarTodosConflitos(ListaAeronaves *lista) {
    int i, j;
    int encontrou = 0;

    if (lista->contador < 2) {
        printf("Aeronaves insuficientes para verificar conflitos.\n");
        return;
    }

    for (i = 0; i < lista->contador; i++) {
        for (j = i + 1; j < lista->contador; j++) {

            ResultadoConflito r =
                conflito_verificar_par(&lista->aeronaves[i],
                                       &lista->aeronaves[j]);

            if (r.nivel != CONFLITO_NENHUM) {
                encontrou = 1;

                printf("\n=== CONFLITO DETECTADO ===\n");
                printf("Aeronaves: %s (ID %d) <-> %s (ID %d)\n",
                       r.codigo_a, r.id_aeronave_a,
                       r.codigo_b, r.id_aeronave_b);

                printf("Distancia horizontal: %.2f m\n",
                       r.distancia_horizontal);

                printf("Diferenca de altitude: %.2f m\n",
                       r.diferenca_altitude);

                if (r.nivel == CONFLITO_CRITICO) {
                    printf("Nivel: CRITICO\n");
                } else {
                    printf("Nivel: ALERTA\n");
                }
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum conflito detectado.\n");
    }
}
