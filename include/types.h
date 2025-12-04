#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#ifndef TYPES_H
#define TYPES_H

#define TAMANHO   100

typedef char string[TAMANHO];

typedef struct Aeronaves{

    string indentificacao;
    string modelo;
    string fabricante;
    string matricula;
    int ano_de_fabricacao;
    char tipo;
    int numero_de_passageiros;
    char situacao;

    struct {
        int piloto;
        int copiloto;
        int comissaria;
    }tripulacao;

    struct Aeronaves *prox;
    

}Aeronaves_t;


typedef struct Rotas{
    int codigo;

    struct data{
        unsigned dia;
        unsigned mes;
        unsigned ano;
    }data;

    struct hora{
        unsigned horas;
        unsigned minutos;
    }hora;

    string localDePartida;
    string localDeDestino;
    float combustivel_necessario;
    int qtd_passageiros;
    int qtd_cargas;
    int Aeronave_alocada;
    string nome_piloto;
    string nome_comissario;//
    string nome_copiloto;
    
    struct Rotas *prox;
 

}Rotas_t;

struct base_dados_aeronave {
    unsigned int contador;
    Aeronaves_t *inicio;
    Aeronaves_t *fim;

};

struct bases_dados_rotas{
    unsigned int contador;
    Rotas_t *inicio;
    Rotas_t *fim; 
};

#endif