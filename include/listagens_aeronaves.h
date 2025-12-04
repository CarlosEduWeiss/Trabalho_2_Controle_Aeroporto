#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>



#ifndef LISTAGENS_AERONAVES_H
#define LISTAGENS_AERONAVES_H

#include "types.h"
#include <stdio.h>

void mostrar_dados_aeronaves(struct Aeronaves *aeronaves, FILE *fp);
void lista_por_fabricante(Aeronaves_t *lista);
void lista_por_modelo(Aeronaves_t *lista);
void lista_por_ano(Aeronaves_t *lista);
void lista_por_situacao(Aeronaves_t *lista);

#endif
