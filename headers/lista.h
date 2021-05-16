#ifndef LISTA_H
#define LISTA_H
#include "arvores.h"
#include "especies.h"

typedef struct NoListaArvores
{
  int id;
  Arvore dado;
  struct NoListaArvores *prox;
  struct NoListaArvores *ant;
} ListaArvores;

typedef struct NoListaEspecies
{
  int id;
  Especie dado;
  ListaArvores *listaArvores;
  struct NoListaEspecies *prox;
  struct NoListaEspecies *ant;
} ListaEspecies;

int estaVazia(void *lista);

ListaEspecies *inicializarLista();

ListaEspecies *buscarEspecie(ListaEspecies *lista, int id);
ListaEspecies *addEspecie(ListaEspecies *lista);
ListaEspecies *removerEspecie(ListaEspecies *lista);
void atualizarEspecie(ListaEspecies *lista);
void listarEspecies(ListaEspecies *lista);

ListaArvores *addArvore(ListaArvores *lista);
ListaArvores *removerArvore(ListaArvores *lista);
void atualizarArvore(ListaArvores *lista);
void *listarArvores(ListaArvores *lista, ListaEspecies *especie);

#endif