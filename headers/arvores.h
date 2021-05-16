#ifndef ARVORES_H
#define ARVORES_H

typedef struct
{
  int dia, mes, ano;
} Data;

typedef struct
{
  char latitude[50], longitude[50];
} Localizacao;

typedef struct
{
  Data dataRegistro;
  float tamanho;
  Localizacao localizacao;
} Arvore;

#endif