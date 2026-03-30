#ifndef AERONAVE_H
#define AERONAVE_H

#include <stdio.h>
#include <string.h>

// Estrutura que representa uma aeronave
typedef struct {
    int id;                // Identificador único
    char codigo_voo[10];   // Código do voo, ex: "AZ1234"
    float x, y;            // Posição no espaço
    float altitude;        // Altitude do avião
    float velocidade;      // Velocidade do avião
    int status;            // 0 = voando, 1 = pousando, 2 = aguardando
} Aeronave;

// Protótipos das funções
Aeronave criarAeronave(int id, char codigo[], float x, float y, float altitude, float velocidade, int status);
void exibirAeronave(Aeronave a);
void moverAeronave(Aeronave *a,float deltaX,float deltaY);// move a aeronave para os eixos 
//x e y

#endif // AERONAVE_H
