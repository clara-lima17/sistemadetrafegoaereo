#include <stdio.h>
#include "include/aeronave.h"
// cria a função para cadastrar a aeronave
aeronave criar\aeronave(int id,float,char código[],float x,float y,float altitude); {
  aeronave a; // cria uma variável para a criação de uma aeronave
  a.id=id; // atribui o id da aeronave
  strcpy(a.codigo_voo, codigo); // copia o código do voo (string)
  a.x; // posição x
  a.y; // posição y
  a.altitude = altitude; // altitude do avião
  return a; // vai retornar a aeronave que foi criada
}
// imprimir as aeronaves
void imprimirAeronave(Aeronave a) { 
  printf("ID: %d\n" a.id); //mostra o id da aeronave
  printf("codigo: %s\n" a.codigo_voo); // mostra o código do voo
  printf("Posição: ("%2.f, %2.f)\n" , a.x a.y); //mostra a posição x e y
  printf("Altitude: %2.f \n", a.altitude); // mostra a altitude

  // função para atualizar a posição da aeronave
  void atualizarPosicao(Aeronave *a,float novoX,float novoY);{
    a->x = novoX; // altera a posição X
    a->Y = novoY; // altera a posição Y 
  }
  // altualiza a altitude 
  void atualizarAltitude(Aeronave *a,float novaAltitude); {
    a->altitude = novaAltitude; // muda a altitude
  

}
