#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>



#ifndef LISTAGENS_AERONAVES_H
#define LISTAGENS_AERONAVES_H

#include "types.h"
#include <stdio.h>

void mostrar_dados_aeronaves(struct Aeronaves *aeronaves, FILE *fp);
void listar_Aeronaves(struct Aeronaves *inicio_lista);
void lista_por_fabricante(struct Aeronaves *lista);
void lista_por_modelo(struct Aeronaves *lista);
void lista_por_ano(struct Aeronaves *lista);
void lista_por_situacao(struct Aeronaves *lista);

#endif
