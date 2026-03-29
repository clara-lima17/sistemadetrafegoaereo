#include <stdio.h>
#include "aeronave.h"
#include "trajetoria.h"

// função que move a aeronave somando os valores das posições
void moverAeronave(Aeronave *a, float deltaX, float deltaY){
    a-> x +=deltaX; //adiciona valor ao eixo X
    a-> y +=deltaY; //adiciona valor ao eixo y
}
// função que altera a altitude da aeronave
void alteraAltitude(Aeronave *a,float novaAltitude){
    a-> altitude = novaAltitude; // define a nova altitude
}

// função que atualiza automaticamente a posição com base na velocidade
void atualizarPosicao(Aeronave *a){
    a->x += a->velocidade *0.1;//movimenta no eixo x
    a->y += a->velocidade *0.1; //movimenta no eixo y
}

// função em que simula a trajetória da aeronave 

void simularPasso(Aeronave *a) {
    atualizarPosiçao(a); // chama a função que atualiza a posição da aeronave
}
