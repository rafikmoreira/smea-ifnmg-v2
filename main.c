#include <stdio.h>
#include <string.h>
#include "headers/lista.h"
#include "headers/menu.h"

int main(void)
{
  printf("Entrega dia 17/05/2021!\n");
  ListaEspecies *especies = inicializarLista();

  char opcoes[10][200];
  int resposta, id;

  while (1)
  {
    strcpy(opcoes[0], "Gerenciar espécies");
    strcpy(opcoes[1], "Monitorar árvores");
    resposta = menu(opcoes, 2, "Sistema de monitoramento de espécies arbóreas");

    switch (resposta)
    {
    case 1:
      strcpy(opcoes[0], "Cadastrar espécie");
      strcpy(opcoes[1], "Atualizar espécie");
      strcpy(opcoes[2], "Lista de espécies cadastradas");
      strcpy(opcoes[3], "Remover espécie");
      resposta = menu(opcoes, 4, "Gerenciar espécies");
      switch (resposta)
      {
      case 1:
        especies = addEspecie(especies);
        break;
      case 2:
        atualizarEspecie(especies);
        break;
      case 3:
        listarEspecies(especies);
        break;
      case 4:
        especies = removerEspecie(especies);
        break;
      default:
        printf("Opção inválida.\n");
        break;
      }
      break;
    case 2:
      obterDado("Informe o ID da espécie:", "int", &id);
      ListaEspecies *especie = buscarEspecie(especies, id);
      if (!estaVazia(especie))
      {
        strcpy(opcoes[0], "Cadastrar árvore");
        strcpy(opcoes[1], "Atualizar árvore");
        strcpy(opcoes[2], "Lista de árvores");
        strcpy(opcoes[3], "Remover árvore");
        resposta = menu(opcoes, 4, "Monitorar árvores");
        switch (resposta)
        {
        case 1:
          especie->listaArvores = addArvore(especie->listaArvores);
          break;
        case 2:
          atualizarArvore(especie->listaArvores);
          break;
        case 3:
          listarArvores(especie->listaArvores, especie);
          break;
        case 4:
          especie->listaArvores = removerArvore(especie->listaArvores);
          break;
        default:
          printf("Opção inválida.\n");
          break;
        }
      }
      else
      {
        printf("Espécies não cadastrada.\n");
      }
      break;
    default:
      printf("Opção inválida.\n");
      break;
    }
  }
  return 0;
}