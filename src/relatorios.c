#include "../include/relatorios.h"
#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>
#include <string.h>



int data_maior_igual(unsigned int dia1, unsigned int mes1, unsigned int ano1, unsigned int dia2, unsigned int mes2, unsigned int ano2) {
    if(ano1 > ano2){ 
        return 1;}
    if(ano1 < ano2) {
        return 0;}
    if(mes1 > mes2) {
        return 1;}
    if(mes1 < mes2){
         return 0;}
    if(dia1 >= dia2) {
        return 1;}
    return 0;
}

int data_menor_igual(unsigned int dia1, unsigned int mes1, unsigned int ano1, unsigned int dia2, unsigned int mes2, unsigned int ano2) {
    if(ano1 < ano2){
         return 1;}
    if(ano1 > ano2){ 
        return 0;}
    if(mes1 < mes2) {
        return 1;}
    if(mes1 > mes2){ 
        return 0;}
    if(dia1 <= dia2){
         return 1;}
    return 0;
}

int data_no_intervalo(unsigned int dia, unsigned int mes, unsigned int ano,unsigned int dia_inicio, unsigned int mes_inicio, unsigned int ano_inicio, unsigned int dia_fim, unsigned int mes_fim, unsigned int ano_fim) {
    return (data_maior_igual(dia, mes, ano, dia_inicio, mes_inicio, ano_inicio) && data_menor_igual(dia, mes, ano, dia_fim, mes_fim, ano_fim));
}

float percentual_voos_destino_data(struct bases_dados_rotas *rotas, string destino, unsigned int dia_inicio, unsigned int mes_inicio, unsigned int ano_inicio,unsigned int dia_fim, unsigned int mes_fim, unsigned int ano_fim){
    if(rotas == NULL || rotas->inicio == NULL) {
        return 0;
    }
    
    int total_voos_intervalo = 0;
    int voos_destino = 0;
    
 
    struct Rotas *atual_rota = rotas->inicio;
    
    while(atual_rota != NULL) {
    
        if(data_no_intervalo(atual_rota->data.dia, atual_rota->data.mes, atual_rota->data.ano,dia_inicio, mes_inicio, ano_inicio,dia_fim, mes_fim, ano_fim)) {
            
            total_voos_intervalo++;
            
        
            if(strcmp(atual_rota->localDeDestino, destino) == 0) {
                voos_destino++;
            }
        }
        atual_rota = atual_rota->prox;
    }
    
    if(total_voos_intervalo == 0) {
        return 0;
    }
    
    return (float)voos_destino / total_voos_intervalo * 100.0;
}

float percentual_voos_por_aeronave(struct bases_dados_rotas *rotas, char *codigo_aeronave){
    if(rotas == NULL || rotas->inicio == NULL) {
        return 0;
    }
    
    int total_voos = 0;
    int voos_aeronave = 0;
    

    struct Rotas *atual_rota = rotas->inicio;
    
    while(atual_rota != NULL) {
        total_voos++;
        
   
        if(strcmp(atual_rota->Aeronave_alocada, codigo_aeronave) ==  0) {
            voos_aeronave++;
        }
        
        atual_rota = atual_rota->prox;
    }
    
    if(total_voos == 0) {
        return 0;
    }
    
    return (float)voos_aeronave / total_voos * 100.0;
}

float consumo_combustivel_intervalo(struct bases_dados_rotas *rotas, unsigned int dia_inicio, unsigned int mes_inicio, unsigned int ano_inicio,  unsigned int dia_fim, unsigned int mes_fim, unsigned int ano_fim){
    if(rotas == NULL || rotas->inicio == NULL) {
        return 0;
    }
    
    float total_combustivel = 0;
    
    struct Rotas *atual_rota = rotas->inicio;
    
    while(atual_rota != NULL) {

        if(data_no_intervalo(atual_rota->data.dia, atual_rota->data.mes, atual_rota->data.ano,dia_inicio, mes_inicio, ano_inicio, dia_fim, mes_fim, ano_fim)) {
            
            total_combustivel += atual_rota->combustivel_necessario;
        }
        atual_rota = atual_rota->prox;
    }
    
    return total_combustivel;
}
