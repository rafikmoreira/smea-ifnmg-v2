#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lista.h"
#include "menu.h"

int estaVazia(void *lista)
{
  return lista == NULL;
}

ListaEspecies *inicializarLista()
{
  return NULL;
}
ListaEspecies *buscarEspecie(ListaEspecies *lista, int id)
{
  if (estaVazia(lista))
  {
    return NULL;
  }

  if (lista->id == id)
  {
    return lista;
  }
  else
  {
    buscarEspecie(lista->ant, id);
  }
}
ListaEspecies *addEspecie(ListaEspecies *lista)
{
  ListaEspecies *novaEspecie = malloc(sizeof(ListaEspecies));

  if (estaVazia(lista))
  {
    novaEspecie->id = 1;
    novaEspecie->prox = NULL;
    novaEspecie->ant = NULL;
  }
  else
  {
    novaEspecie->id = lista->id + 1;
    novaEspecie->prox = NULL;
    lista->prox = novaEspecie;
    novaEspecie->ant = lista;
  };

  novaEspecie->listaArvores = malloc(sizeof(ListaArvores));
  novaEspecie->listaArvores = NULL;

  exibirTitulo("Cadastrar espécie");
  obterDado("Informe o nome popular da espécie:", "string", &novaEspecie->dado.nomePopular);
  obterDado("Informe o nome científico da espécie:", "string", &novaEspecie->dado.nomeCientifico);
  obterDado("Área de distribuição, tipo de habitat,\nelevação e clima preferido conhecidos:", "string", &novaEspecie->dado.ecologia.areaDeDistribuicao);
  obterDado("Taxonomia e identificação. Existem outras\nespécies de árvores que possam ser\nconfundidas com essa espécie na área? Como você as diferencia?", "string", &novaEspecie->dado.ecologia.taxonomia);
  obterDado("Fenologia. Em que época do ano floresce,\nfrutifica ou caem suas folhas?", "string", &novaEspecie->dado.ecologia.fenologia);
  obterDado("Reprodução. Como é polinizada e como as\nsementes são dispersas?", "string", &novaEspecie->dado.ecologia.reproducao);

  // automático
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  novaEspecie->dado.dataRegistro.dia = tm.tm_mday;
  novaEspecie->dado.dataRegistro.mes = tm.tm_mon + 1;
  novaEspecie->dado.dataRegistro.ano = tm.tm_year + 1900;

  return novaEspecie;
};
ListaEspecies *removerEspecie(ListaEspecies *lista)
{
  if (estaVazia(lista))
  {
    return lista;
  }

  int id;

  obterDado("Digite o ID da espécie que deseja remover os dados:", "int", &id);

  ListaEspecies *aux = buscarEspecie(lista, id);

  if (!estaVazia(aux))
  {
    ListaEspecies *noRemover = aux, *noProximo = aux->prox, *noAnterior = aux->ant;
    ListaEspecies *No = malloc(sizeof(ListaEspecies));
    // primeiro elemento da lista
    if (noAnterior == NULL)
    {
      if (noProximo == NULL)
      {
        No = NULL;
        return No;
      }
      else
      {
        No = noProximo;
        No->ant = NULL;
        return No;
      }
    }
    else if (noProximo == NULL)
    {
      No = noAnterior;
      No->prox = NULL;
      return No;
    }
    else
    {
      noAnterior->prox = noProximo;
      noProximo->ant = noAnterior;
      return lista;
    }
  }
  return lista;
};
void atualizarEspecie(ListaEspecies *lista)
{
  int id, resposta;
  char opcoes[20][200];

  obterDado("Digite o ID da espécie que deseja atualizar os dados:", "int", &id);

  ListaEspecies *aux = buscarEspecie(lista, id);

  if (estaVazia(aux))
  {
    return;
  }
  else
  {
    strcpy(opcoes[0], "Sim");
    strcpy(opcoes[1], "Não");

    resposta = menu(opcoes, 2, "Você deseja atualizar o nome popular da espécie?");
    if (resposta == 1)
    {
      obterDado("Informe o nome popular da espécie:", "string", &aux->dado.nomePopular);
    }
    resposta = menu(opcoes, 2, "Você deseja atualizar o nome científico da espécie?");
    if (resposta == 1)
    {
      obterDado("Informe o nome científico da espécie:", "string", &aux->dado.nomeCientifico);
    }
    resposta = menu(opcoes, 2, "Você deseja atualizar a área de distribuição, tipo de habitat?");
    if (resposta == 1)
    {
      obterDado("Área de distribuição, tipo de habitat,\n| elevação e clima preferido conhecidos:", "string", &aux->dado.ecologia.areaDeDistribuicao);
    }
    resposta = menu(opcoes, 2, "Você deseja atualizar a taxonomia e identificação?");
    if (resposta == 1)
    {
      obterDado("Taxonomia e identificação. Existem outras\n| espécies de árvores que possam ser\nconfundidas com essa espécie na área? Como você as diferencia?", "string", &aux->dado.ecologia.taxonomia);
    }
    resposta = menu(opcoes, 2, "Você deseja atualizar a fenologia?");
    if (resposta == 1)
    {
      obterDado("Fenologia. Em que época do ano floresce, frutifica ou caem suas folhas?", "string", &aux->dado.ecologia.taxonomia);
    }
    resposta = menu(opcoes, 2, "Você deseja atualizar as informações sobre reprodução?");
    if (resposta == 1)
    {
      obterDado("Reprodução. Como é polinizada e como as\n| sementes são dispersas?", "string", &aux->dado.ecologia.reproducao);
    }
  }
};
void listarEspecies(ListaEspecies *lista)
{
  if (lista != NULL)
  {
    printf("\n-----------------------------------------------------------\n");
    printf("| ID: %i \n", lista->id);
    printf("| Nome científico: %s \n", lista->dado.nomeCientifico);
    printf("| Nome popular: %s \n", lista->dado.nomePopular);
    printf("| Data do registro: %i/%i/%i\n", lista->dado.dataRegistro.dia, lista->dado.dataRegistro.mes, lista->dado.dataRegistro.ano);
    printf("-----------------------------------------------------------\n");
    printf("| Dados ecológicos da espécie\n");
    printf("-----------------------------------------------------------\n");
    printf("| Taxonomia e identificação:\n");
    printf("-----------------------------------------------------------\n");
    printf("%s\n", lista->dado.ecologia.taxonomia);
    printf("-----------------------------------------------------------\n");
    printf("| Área de distribuição, tipo de habitat,\n| elevação e clima preferido conhecidos:\n");
    printf("-----------------------------------------------------------\n");
    printf("%s\n", lista->dado.ecologia.areaDeDistribuicao);
    printf("-----------------------------------------------------------\n");
    printf("| Fenologia. Em que época do ano floresce,\n| frutifica ou caem suas folhas:\n");
    printf("-----------------------------------------------------------\n");
    printf("%s\n", lista->dado.ecologia.fenologia);
    printf("-----------------------------------------------------------\n");
    printf("| Reprodução. Como é polinizada e como as\n| sementes são dispersas:\n");
    printf("-----------------------------------------------------------\n");
    printf("%s\n", lista->dado.ecologia.reproducao);
    listarEspecies(lista->ant);
  }
};

ListaArvores *addArvore(ListaArvores *lista)
{
  ListaArvores *no = malloc(sizeof(ListaArvores));

  obterDado("Tamanho:", "float", &no->dado.tamanho);
  obterDado("Latitude:", "string", &no->dado.localizacao.latitude);
  obterDado("Longitude:", "string", &no->dado.localizacao.longitude);
  if (lista == NULL)
  {
    no->id = 1;
  }
  else
  {
    lista->prox = no;
    no->id = lista->id + 1;
  }
  no->ant = lista;
  no->prox = NULL;
  // automático
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  no->dado.dataRegistro.dia = tm.tm_mday;
  no->dado.dataRegistro.mes = tm.tm_mon + 1;
  no->dado.dataRegistro.ano = tm.tm_year + 1900;
  return no;
};
ListaArvores *buscarArvore(ListaArvores *lista, int id)
{
  if (lista->id == id)
  {
    return lista;
  }
  else
  {
    if (lista != NULL)
    {
      buscarArvore(lista->ant, id);
    }
  }
};
ListaArvores *removerArvore(ListaArvores *lista)
{
  if (estaVazia(lista))
  {
    return lista;
  }

  int id;

  obterDado("Digite o ID da árvore que deseja remover os dados:", "int", &id);

  ListaArvores *aux = buscarArvore(lista, id);

  if (!estaVazia(aux))
  {
    ListaArvores *noRemover = aux, *noProximo = aux->prox, *noAnterior = aux->ant;
    ListaArvores *No = malloc(sizeof(ListaArvores));
    if (noAnterior == NULL)
    {
      if (noProximo == NULL)
      {
        No = NULL;
        return No;
      }
      else
      {
        No = noProximo;
        No->ant = NULL;
        return No;
      }
    }
    else if (noProximo == NULL)
    {
      No = noAnterior;
      No->prox = NULL;
      return No;
    }
    else
    {
      noAnterior->prox = noProximo;
      noProximo->ant = noAnterior;
      return lista;
    }
  }
  return lista;
};
void atualizarArvore(ListaArvores *lista)
{
  int id;
  char opcoes[2][200];
  int resposta;
  strcpy(opcoes[0], "Sim");
  strcpy(opcoes[1], "Não");

  obterDado("Informe o ID da árvore:", "int", &id);
  ListaArvores *no = buscarArvore(lista, id);
  if (!estaVazia(no))
  {
    resposta = menu(opcoes, 2, "Deseja atualizar a altura da árvore?");
    if (resposta == 1)
    {
      obterDado("Tamanho:", "float", &no->dado.tamanho);
    }
    resposta = menu(opcoes, 2, "Deseja atualizar a coordenada X da posição da árvore?");
    if (resposta == 1)
    {
      obterDado("Latitude:", "string", &no->dado.localizacao.latitude);
    }
    resposta = menu(opcoes, 2, "Deseja atualizar a coordenada Y da posição da árvore?");
    if (resposta == 1)
    {
      obterDado("Longitude:", "string", &no->dado.localizacao.longitude);
    }
  }
  else
  {
    printf("Árvore não encontrada.\n");
  }
};
void *listarArvores(ListaArvores *lista, ListaEspecies *especie)
{
  printf("\n-----------------------------------------------------------\n");
  printf("| Lista de árvores da espécie: %s\n", especie->dado.nomeCientifico);
  printf("-----------------------------------------------------------\n");
  while (lista != NULL)
  {
    printf("\n-----------------------------------------------------------\n");
    printf("| ID Árvore: %i\n", lista->id);
    printf("| Altura: %.2fm\n", lista->dado.tamanho);
    printf("| Latitute: %s\n", lista->dado.localizacao.latitude);
    printf("| Longitude: %s\n", lista->dado.localizacao.longitude);
    printf("| Data do registro: %i/%i/%i\n", lista->dado.dataRegistro.dia, lista->dado.dataRegistro.mes, lista->dado.dataRegistro.ano);
    printf("-----------------------------------------------------------\n");
    lista = lista->ant;
  }
};