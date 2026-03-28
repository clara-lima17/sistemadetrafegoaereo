#include <stdio.h>      // biblioteca para usar printf
#include "aeronave.h"  // importa a struct e os protótipos

// Função para criar a aeronave
Aeronave criarAeronave(int id, char codigo[], float x, float y, float altitude, float velocidade, int status) {
    
    Aeronave a; // cria uma variável do tipo Aeronave

    a.id = id; // atribui o identificador
    strcpy(a.codigo_voo, codigo); // copia o código do voo (string)
    a.x = x; // define posição X
    a.y = y; // define posição Y
    a.altitude = altitude; // define altitude
    a.velocidade = velocidade; // define velocidade
    a.status = status; // define status (0, 1 ou 2)

    return a; // retorna a aeronave criada
}

// Função para exibir a aeronave
void exibirAeronave(Aeronave a) {

    printf("ID: %d\n", a.id); // imprime o ID
    printf("Codigo: %s\n", a.codigo_voo); // imprime o código do voo
    printf("Posicao: (%.2f, %.2f)\n", a.x, a.y); // imprime posição X e Y com 2 casas decimais
    printf("Altitude: %.2f\n", a.altitude); // imprime altitude
    printf("Velocidade: %.2f\n", a.velocidade); // imprime velocidade
    printf("Status: %d\n", a.status); // imprime status

}
