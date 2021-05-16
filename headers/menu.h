#ifndef MENU_H
#define MENU_H

void obterDado(char string[], char tipo[], void *enderecoMemoria);
void exibirTitulo(char titulo[]);
int menu(char opcoes[10][200], int numeroOpcoes, char titulo[]);

#endif