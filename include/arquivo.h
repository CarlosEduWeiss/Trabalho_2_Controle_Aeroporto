#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_dados_aeronaves(struct Aeronaves *inicio);
void salvar_dados_rotas(struct Rotas *inicio);
void carregar_dados_aeronaves(struct base_dados_aeronave *aeronave);
void carregar_dados_rotas(struct bases_dados_rotas *rotas);
void exportar_dados_aeronaves_csv(struct Aeronaves *aeronave, char *nome_arq);
void exportar_dados_rotas_csv(struct Rotas *rotas, char *nome_arq);
void exportar_dados_aeronaves_html(struct Aeronaves *aeronave, char *nome_arq);
void exportar_dados_rotas_html(struct Rotas *rotas, char *nome_arq);

#endif