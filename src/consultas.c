#include "../include/consultas.h"
#include "../include/types.h"
#include "../include/utils.h"
#include "../include/listagens_aeronaves.h"
#include "../include/listagens_rotas.h"
#include <stdio.h>
#include <string.h>

struct Aeronaves *buscar_aeronave_por_prefixo(struct base_dados_aeronave *aeronaves, string prefixo){
    if(aeronaves == NULL || aeronaves->inicio == NULL) {
        return NULL;
    }
    
    struct Aeronaves *atual = aeronaves->inicio;
    while(atual != NULL) {
        if(strcmp(atual->indentificacao, prefixo) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    
    return NULL;
}

void consultar_rotas_por_data(struct bases_dados_rotas *rotas){
    if(rotas == NULL || rotas->inicio == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }
    
    unsigned int dia, mes, ano;
    printf("Digite o dia: ");
    scanf("%u", &dia);
    getchar();
    
    printf("Digite o mes: ");
    scanf("%u", &mes);
    getchar();
    
    printf("Digite o ano: ");
    scanf("%u", &ano);
    getchar();
    
    int encontrou = 0;
    struct Rotas *atual = rotas->inicio;
    while(atual != NULL) {
        if(atual->data.dia == dia && 
           atual->data.mes == mes && 
           atual->data.ano == ano) {
            mostrar_dados_rotas(atual, stdout);
            encontrou = 1;
        }
        atual = atual->prox;
    }
    
    if(!encontrou) {
        printf("Nenhuma rota encontrada para a data %02u/%02u/%04u.\n", dia, mes, ano);
    }
    
}

int consultar_se_aeronave_existe(struct base_dados_aeronave *aeronave_alocada, char *aeronave_pedida) {
    
    struct Aeronaves *atual = aeronave_alocada->inicio;
    
    while(atual != NULL) {
        if(strcmp(atual->indentificacao, aeronave_pedida) == 0) {
            return 1; // Encontrou
        }
        

        atual = atual->prox; 
    }
    
    return 0; 
}
int consultar_se_aeronave_esta_em_manutencao(struct base_dados_aeronave *aeronave_alocada, char *aeronave_pedida){
    

    if (aeronave_alocada == NULL || aeronave_alocada->inicio == NULL) {
        return 0; 
    }

    struct Aeronaves *atual = aeronave_alocada->inicio;


    while (atual != NULL) {
        
        if (strcmp(atual->indentificacao, aeronave_pedida) == 0) {
            
    
            if (atual->situacao == 'm' || atual->situacao == 'M') {
                return 1; 
            } else {
                return 0; 
            }
        }

        atual = atual->prox;
    }


    return 0; 
}






