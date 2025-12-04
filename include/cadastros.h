#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


#ifndef CADASTROS_H
#define CADASTROS_H

#include "./types.h"

void inicializar_base_aeronaves(struct base_dados_aeronave *aviao);
void inicializar_base_rotas(struct bases_dados_rotas *livros);
void inserir_aeronave_base_dados(struct base_dados_aeronave *aeronaves, struct Aeronaves *aeronave, int modo);
void inserir_rotas_base_dados(struct bases_dados_rotas *rotas, struct Rotas *rota, int modo);
struct Aeronaves *nova_aeronave(unsigned int *codigo);
struct Rotas *nova_rota(unsigned int *codigo);

#endif