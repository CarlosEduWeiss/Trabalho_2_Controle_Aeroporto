#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#ifndef LISTAGENS_ROTAS_H
#define LISTAGENS_ROTAS_H

#include "types.h"
#include <stdio.h>

void mostrar_dados_rotas(struct Rotas *rotas, FILE *fp);
void lista_por_destino(struct Rotas *lista);
void lista_por_origem(struct Rotas *lista);
void lista_Maior_passageiros(struct Rotas *lista);
void lista_Menor_passageiros(struct Rotas *lista);
void listar_Rotas(struct Rotas *inicio_lista);

#endif