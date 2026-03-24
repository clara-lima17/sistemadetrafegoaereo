# 📁 include/ — Arquivos de Cabeçalho

Esta pasta contém os **arquivos de cabeçalho** do projeto, que funcionam como uma "lista de declarações" das funções e estruturas usadas no código.

---

## O que é essa pasta?

Em C e C++, antes de usar uma função, o compilador precisa saber que ela existe — mesmo que ela esteja definida em outro arquivo.  
Os arquivos de cabeçalho (`.h`) fazem exatamente isso: **declaram** funções, tipos e constantes para que outros arquivos possam usá-los.

Pense neles como um **sumário ou índice** do seu código.

---

## Tipos de arquivo que pertencem aqui

| Extensão | O que é |
|---|---|
| `.h` | Cabeçalho em C (header file) |
| `.hpp` | Cabeçalho em C++ |

> ⚠️ **Não coloque** arquivos `.c` ou `.cpp` aqui. A implementação fica em `src/`

---

## Exemplos de arquivos que ficam aqui

```
include/
├── calculadora.h   ← declara as funções da calculadora
├── utils.h         ← declara funções auxiliares
└── jogador.h       ← declara a estrutura e funções do jogador
```

### Exemplo do que há dentro de um `.h`

```c
// include/calculadora.h

#ifndef CALCULADORA_H
#define CALCULADORA_H

float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

#endif
```

> As linhas `#ifndef` / `#define` / `#endif` evitam que o mesmo arquivo seja incluído duas vezes — isso é chamado de **include guard**.

---

## Por que usar essa pasta?

Separar as declarações (`.h`) das implementações (`.c`) é uma das práticas mais importantes em C.  
Isso permite que diferentes partes do projeto "se conheçam" sem precisar acessar o código completo umas das outras, facilitando a manutenção e a reutilização.

---

## 📚 Quer entender mais sobre essa arquitetura?

- [Header Files em C — Programiz (inglês)](https://www.programiz.com/c-programming/c-header-files)
- [O que são arquivos .h em C? — DevMedia](https://www.devmedia.com.br/arquivos-header-em-c/28540)
- [Include Guards explicados — GeeksForGeeks (inglês)](https://www.geeksforgeeks.org/header-guard-in-c/)
