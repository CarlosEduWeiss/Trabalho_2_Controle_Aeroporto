#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "types.h"
#include <stdio.h>

// Consultas de aeronaves
struct Aeronaves *buscar_aeronave_por_prefixo(struct base_dados_aeronave *aeronaves, string prefixo);

// Consultas de rotas
void consultar_rotas_por_data(struct bases_dados_rotas *rotas);
int consultar_se_aeronave_existe(struct base_dados_aeronave *aeronave, char *aeronave_pedida);
int consultar_se_aeronave_esta_em_manutencao(struct base_dados_aeronave *aeronave_alocada, char *aeronave_pedida);
#endif

