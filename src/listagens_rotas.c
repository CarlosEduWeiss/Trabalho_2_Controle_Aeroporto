#include "../include/listagens_rotas.h"
#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostrar_dados_rotas(struct Rotas *rotas, FILE *fp){
    if(rotas == NULL) 
    
    fprintf(fp, "Codigo: %i\n", rotas->codigo);
    fprintf(fp, "Data: %02u/%02u/%04u\n", rotas->data.dia, rotas->data.mes, rotas->data.ano);
    fprintf(fp, "Hora: %02u:%02u\n", rotas->hora.horas, rotas->hora.minutos);
    fprintf(fp, "Local de partida: %s\n", rotas->localDePartida);
    fprintf(fp, "Local de destino: %s\n", rotas->localDeDestino);
    fprintf(fp, "Combustivel necessario: %.2f\n", rotas->combustivel_necessario);
    fprintf(fp, "Quantidade de passageiros: %i\n", rotas->qtd_passageiros);
    fprintf(fp, "Quantidade de cargas: %i\n", rotas->qtd_cargas);
    fprintf(fp, "Aeronave alocada: %s\n", rotas->Aeronave_alocada);
    fprintf(fp, "Nome do piloto: %s\n", rotas->nome_piloto);
    fprintf(fp, "Nome do copiloto: %s\n", rotas->nome_copiloto);
    fprintf(fp, "Nome do comissario: %s\n", rotas->nome_comissario);
    fprintf(fp, "----------------------------------------\n");
}

void lista_por_destino(struct Rotas *lista){
    if(lista == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }
    
    string destino;
    printf("Digite o destino para buscar: ");
    getchar();
    fgets(destino, TAMANHO, stdin);
    remover_enter(destino);
    
    int encontrou = 0;
    struct Rotas *atual = lista;
    while(atual != NULL) {
        if(strcmp(atual->localDeDestino, destino) == 0) {
            mostrar_dados_rotas(atual, stdout);
            encontrou = 1;
        }
        atual = atual->prox;
    }
    
    if(!encontrou) {
        printf("Nenhuma rota encontrada para o destino %s.\n", destino);
    }
}

void lista_por_origem(struct Rotas *lista){
    if(lista == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }
    
    string origem;
    printf("Digite a origem para buscar: ");
    getchar();
    fgets(origem, TAMANHO, stdin);
    remover_enter(origem);
    
    int encontrou = 0;
    struct Rotas *atual = lista;
    while(atual != NULL) {
        if(strcmp(atual->localDePartida, origem) == 0) {
            mostrar_dados_rotas(atual, stdout);
            encontrou = 1;
        }
        atual = atual->prox;
    }
    
    if(!encontrou) {
        printf("Nenhuma rota encontrada com origem %s.\n", origem);
    }
}


void lista_Maior_passageiros(struct Rotas *lista) {
    if (lista == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }

    struct Rotas *i, *j;
    struct Rotas temp_dados;
    struct Rotas *temp_prox_i;
    struct Rotas *temp_prox_j;

    for (i = lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->qtd_passageiros < j->qtd_passageiros) {
                temp_dados = *i;
                temp_prox_i = i->prox;
                temp_prox_j = j->prox;

                *i = *j;
                i->prox = temp_prox_i;

                *j = temp_dados;
                j->prox = temp_prox_j;
            }
        }
    }

    printf("Rotas ordenadas por quantidade decrescente de passageiros:\n");
    struct Rotas *atual = lista;
    while (atual != NULL) {
        mostrar_dados_rotas(atual, stdout);
        atual = atual->prox;
    }
}

void lista_Menor_passageiros(struct Rotas *lista) {
    if (lista == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }

    struct Rotas *i, *j;
    struct Rotas temp_dados;
    struct Rotas *temp_prox_i;
    struct Rotas *temp_prox_j;

    for (i = lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->qtd_passageiros > j->qtd_passageiros) {
                temp_dados = *i;
                temp_prox_i = i->prox;
                temp_prox_j = j->prox;

                *i = *j;
                i->prox = temp_prox_i;

                *j = temp_dados;
                j->prox = temp_prox_j;
            }
        }
    }

    printf("Rotas ordenadas por quantidade crescente de passageiros:\n");
    struct Rotas *atual = lista;
    while (atual != NULL) {
        mostrar_dados_rotas(atual, stdout);
        atual = atual->prox;
    }
}

void listar_Rotas(struct Rotas *inicio_lista)
{
    while (inicio_lista) {

        mostrar_dados_rotas(inicio_lista, stdout);
        inicio_lista = inicio_lista->prox;
    }
}





