#ifndef trajetoria_h
#define trajetoria_h

#include "aeronave.h"

void moverAeronave(Aeronave *a,float deltaX,float deltaY);// move a aeronave para os eixos 
//x e y

void alteraAltitude(Aeronave *a,float novaaltitude);//atualiza a altitude da aeronave
void altualizarPosiçao(Aeronave *a); //atualiza a posição da aeronave com base na velocidade

void simularPasso(Aeronave *a); // simula o passo da trajetória da aeronave

#endif


