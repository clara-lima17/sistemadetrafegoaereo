#ifndef CONFLITO_H
#define CONFLITO_H

/*
 * conflito.h
 * ----------
 * Módulo de detecção de conflito entre aeronaves.
 *
 * Convenção de unidades (S.I.):
 *   x, y      → metros (m)
 *   altitude  → metros (m)
 *   velocidade → metros por segundo (m/s)
 */

#include "aeronave.h"

/* Separações mínimas convertidas para metros */
#define CONFLITO_SEP_HORIZONTAL_M 9260.0   /* 5 NM */
#define CONFLITO_SEP_VERTICAL_M   304.8    /* 1000 ft */

typedef enum {
    CONFLITO_NENHUM  = 0,
    CONFLITO_ALERTA  = 1,
    CONFLITO_CRITICO = 2
} ConflitoNivel;

typedef struct {
    int           id_aeronave_a;
    int           id_aeronave_b;
    char          codigo_a[10];
    char          codigo_b[10];
    double        distancia_horizontal; /* metros */
    double        diferenca_altitude;   /* metros */
    ConflitoNivel nivel;
} ResultadoConflito;

ResultadoConflito conflito_verificar_par(const Aeronave *a,
                                          const Aeronave *b);

#endif