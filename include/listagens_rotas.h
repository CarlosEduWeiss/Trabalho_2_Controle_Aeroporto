#ifndef LISTAGENS_ROTAS_H
#define LISTAGENS_ROTAS_H

#include "types.h"
#include <stdio.h>

void mostrar_dados_rotas(struct Rotas *rotas, FILE *fp);
void lista_por_destino(Rotas_t *lista);
void lista_por_origem(Rotas_t *lista);
void lista_Maior_passageiros(Rotas_t *lista);
void lista_Menor_passageiros(Rotas_t *lista);

#endif