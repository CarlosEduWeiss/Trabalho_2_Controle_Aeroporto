#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"
#include <stdio.h>

// Relatórios de rotas
float percentual_voos_destino_data(struct bases_dados_rotas *rotas, string destino, unsigned int dia, unsigned int mes, unsigned int ano);
float percentual_voos_por_aeronave(struct bases_dados_rotas *rotas, int codigo_aeronave);
float consumo_combustivel_intervalo(struct bases_dados_rotas *rotas, unsigned int dia_inicio, unsigned int mes_inicio, unsigned int ano_inicio, unsigned int dia_fim, unsigned int mes_fim, unsigned int ano_fim);

#endif

