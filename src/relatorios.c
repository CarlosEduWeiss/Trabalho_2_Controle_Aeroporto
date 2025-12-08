#include "../include/relatorios.h"
#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>
#include <string.h>

float percentual_voos_destino_data(struct bases_dados_rotas *rotas, string destino, unsigned int dia, unsigned int mes, unsigned int ano){
    if(rotas == NULL || rotas->inicio == NULL) {
        return 0;
    }
    
    int total_voos_data = 0;
    int voos_destino = 0;
    
    struct Rotas *atual = rotas->inicio;
    while(atual != NULL) {
        if(atual->data.dia == dia && 
           atual->data.mes == mes && 
           atual->data.ano == ano) {
            total_voos_data++;
            if(strcmp(atual->localDeDestino, destino) == 0) {
                voos_destino++;
            }
        }
        atual = atual->prox;
    }
    
    if(total_voos_data == 0) {
        return 0;
    }
    
    return (float)voos_destino / total_voos_data * 100.0;
}

float percentual_voos_por_aeronave(struct bases_dados_rotas *rotas, int codigo_aeronave){
    if(rotas == NULL || rotas->inicio == NULL) {
        return 0;
    }
    
    int total_voos = 0;
    int voos_aeronave = 0;
    
    struct Aeronaves *aeronave;
    struct Rotas *atual = rotas->inicio;
    while(atual != NULL) {
        total_voos++;
        if(strcmp(atual->Aeronave_alocada, aeronave->indentificacao)== 0) {
            voos_aeronave++;
        }
        atual = atual->prox;
    }
    
    if(total_voos == 0) {
        return 0;
    }
    
    return (float)voos_aeronave / total_voos * 100.0;
}


int data_maior_igual(unsigned int dia1, unsigned int mes1, unsigned int ano1, unsigned int dia2, unsigned int mes2, unsigned int ano2) {
    if(ano1 > ano2) return 1;
    if(ano1 < ano2) return 0;
    if(mes1 > mes2) return 1;
    if(mes1 < mes2) return 0;
    if(dia1 >= dia2) return 1;
    return 0;
}

int data_menor_igual(unsigned int dia1, unsigned int mes1, unsigned int ano1,unsigned int dia2, unsigned int mes2, unsigned int ano2) {
    if(ano1 < ano2) return 1;
    if(ano1 > ano2) return 0;
    if(mes1 < mes2) return 1;
    if(mes1 > mes2) return 0;
    if(dia1 <= dia2) return 1;
    return 0;
}

float consumo_combustivel_intervalo(struct bases_dados_rotas *rotas, unsigned int dia_inicio, unsigned int mes_inicio, unsigned int ano_inicio, unsigned int dia_fim, unsigned int mes_fim, unsigned int ano_fim){
    if(rotas == NULL || rotas->inicio == NULL) {
        return 0;
    }
    
    float total_combustivel = 0.0;
    
    struct Rotas *atual = rotas->inicio;
    while(atual != NULL) {
        if(data_maior_igual(atual->data.dia, atual->data.mes, atual->data.ano, 
                           dia_inicio, mes_inicio, ano_inicio) &&
           data_menor_igual(atual->data.dia, atual->data.mes, atual->data.ano,
                           dia_fim, mes_fim, ano_fim)) {
            total_combustivel += atual->combustivel_necessario;
        }
        atual = atual->prox;
    }
    
    return total_combustivel;
}

