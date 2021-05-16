#ifndef ESPECIES_H
#define ESPECIES_H

typedef struct
{
  char taxonomia[2000],
      areaDeDistribuicao[2000],
      fenologia[2000],
      reproducao[2000];
} Ecologia;

typedef struct
{
  char nomePopular[200];
  char nomeCientifico[200];
  Ecologia ecologia;
  Data dataRegistro;
} Especie;

#endif