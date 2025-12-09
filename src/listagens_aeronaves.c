
#include "../include/listagens_aeronaves.h"
#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>
#include <string.h>

void listar_Aeronaves(struct Aeronaves *inicio_lista)
{
    while (inicio_lista) {

        mostrar_dados_aeronaves(inicio_lista, stdout);
        inicio_lista = inicio_lista->prox;
    }
}

void mostrar_dados_aeronaves(struct Aeronaves *aeronaves, FILE *fp){
    fprintf(fp, "Identificacao: %s\n", aeronaves->indentificacao);
    fprintf(fp, "Modelo: %s\n", aeronaves->modelo);
    fprintf(fp, "Fabricante: %s\n", aeronaves->fabricante);
    fprintf(fp, "Matricula: %s\n", aeronaves->matricula);
    fprintf(fp, "Ano de fabricacao: %i\n", aeronaves->ano_de_fabricacao);
    fprintf(fp, "Tipo: %c\n", aeronaves->tipo);
    fprintf(fp, "Numero de passageiros: %i\n", aeronaves->numero_de_passageiros);
    fprintf(fp, "Situacao: %c\n", aeronaves->situacao);
    fprintf(fp, "Pilotos: %i\n", aeronaves->tripulacao.piloto);
    fprintf(fp, "Copilotos: %i\n", aeronaves->tripulacao.copiloto);
    fprintf(fp, "Comissarias: %i\n", aeronaves->tripulacao.comissaria);
    fprintf(fp, "----------------------------------------\n");
}

void lista_por_fabricante(struct Aeronaves *lista){
    if(lista == NULL) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }
    
    string fabricante;
    printf("Digite o fabricante para buscar: ");
    getchar();
    fgets(fabricante, TAMANHO, stdin);
    remover_enter(fabricante);
    
    int encontrou = 0;
    struct Aeronaves *atual = lista;
    while(atual != NULL) {
        if(strcmp(atual->fabricante, fabricante) == 0) {
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = 1;
        }
        atual = atual->prox;
    }
    
    if(!encontrou) {
        printf("Nenhuma aeronave encontrada com o fabricante %s.\n", fabricante);
    }
}

void lista_por_modelo(struct Aeronaves *lista){
    if(lista == NULL) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }
    
    string modelo;
    printf("Digite o modelo para buscar: ");
    getchar();
    fgets(modelo, TAMANHO, stdin);
    remover_enter(modelo);
    
    int encontrou = 0;
    struct Aeronaves *atual = lista;
    while(atual != NULL) {
        if(strcmp(atual->modelo, modelo) == 0) {
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = 1;
        }
        atual = atual->prox;
    }
    
    if(!encontrou) {
        printf("Nenhuma aeronave encontrada com o modelo %s.\n", modelo);
    }
}

//funcao recursiva
int lista_por_ano(struct Aeronaves *lista, int ano)
    {
        
        if(lista == NULL) {
            return 0;
        }
    
        int encontrou_neste = 0;
    
        
        if(lista->ano_de_fabricacao == ano) {
            mostrar_dados_aeronaves(lista, stdout);
            encontrou_neste = 1;
        }
    
    
        return encontrou_neste + lista_por_ano(lista->prox, ano);
    }


void lista_por_situacao(struct Aeronaves *lista){
    if(lista == NULL) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }
    
    char situacao;
    printf("Digite a situacao (o para operante, m para manutencao): ");
    scanf("%c", &situacao);
    getchar();
    
    int encontrou = 0;
    struct Aeronaves *atual = lista;
    while(atual != NULL) {
        if(atual->situacao == situacao) {
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = 1;
        }
        atual = atual->prox;
    }
    
    if(!encontrou) {
        printf("Nenhuma aeronave encontrada com a situacao %c.\n", situacao);
    }
}
