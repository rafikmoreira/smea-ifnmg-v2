#include "./menu.h"
#include <stdio.h>
#include <string.h>

void obterDado(char string[], char tipo[], void *enderecoMemoria)
{
  printf("-----------------------------------------------------------\n");
  printf("%s\n", string);

  if (strcmp("int", tipo) == 0)
  {
    scanf("%i", enderecoMemoria);
  }
  else if (strcmp("float", tipo) == 0)
  {
    scanf("%f", enderecoMemoria);
  }
  else if (strcmp("double", tipo) == 0)
  {
    scanf("%lf", enderecoMemoria);
  }
  else if (strcmp("string", tipo) == 0)
  {
    setbuf(stdin, NULL);
    gets(enderecoMemoria);
  }
  else
  {
    printf("Tipo inválido.\n");
  }
}

void exibirTitulo(char titulo[])
{
  printf("-----------------------------------------------------------\n");
  printf("| %s\n", titulo);
  printf("-----------------------------------------------------------\n\n");
}

int menu(char opcoes[10][200], int numeroOpcoes, char titulo[])
{
  int resposta;
  exibirTitulo(titulo);
  for (int i = 0; i < numeroOpcoes; i++)
  {
    printf("[%i] -> %s\n", i + 1, opcoes[i]);
  }

  printf("\n-----------------------------------------------------------\n");
  printf("\nPor favor, digite o número relacionado a opção desejada:\n");
  scanf("%i", &resposta);
  return resposta;
}