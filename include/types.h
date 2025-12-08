#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#ifndef TYPES_H
#define TYPES_H

#define TAMANHO   100

typedef char string[TAMANHO];

struct Aeronaves{

    int id;
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
    

};


struct Rotas{
    int codigo;

    struct data{
        unsigned int dia;
        unsigned int mes;
        unsigned int ano;
    }data;

    struct hora{
        unsigned int horas;
        unsigned int minutos;
    }hora;

    string localDePartida;
    string localDeDestino;
    float combustivel_necessario;
    int qtd_passageiros;
    int qtd_cargas;
    string Aeronave_alocada;
    string nome_piloto;
    string nome_comissario;//
    string nome_copiloto;
    
    struct Rotas *prox;
 

};

struct base_dados_aeronave {
    unsigned int contador;
    struct Aeronaves *inicio;
    struct Aeronaves *fim;

};

struct bases_dados_rotas{
    unsigned int contador;
    struct Rotas *inicio;
    struct Rotas *fim; 
};

#endif