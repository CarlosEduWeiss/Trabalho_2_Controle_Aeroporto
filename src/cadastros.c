#include "../include/cadastros.h"
#include "../include/listagens_aeronaves.h"
#include "../include/utils.h"
#include "../include/consultas.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void inicializar_base_aeronaves(struct base_dados_aeronave *aviao){
    aviao->inicio = NULL;
    aviao->fim = NULL;
    aviao->contador = 0;
    
}
void inicializar_base_rotas(struct bases_dados_rotas *rotas)
{
    rotas->inicio = NULL;
    rotas->fim = NULL;
    rotas->contador = 0;
}
void inserir_aeronave_base_dados(struct base_dados_aeronave *aeronaves, struct Aeronaves *aeronave, int modo){
    if(aeronave == NULL) return;
    
    aeronave->prox = NULL;
    
    if(aeronaves->inicio == NULL){
        aeronaves->fim = aeronave;
        aeronaves->inicio = aeronave;
    } else {
        if(modo == 1){
            aeronave->prox = aeronaves->inicio;
            aeronaves->inicio = aeronave;
        }
        else if(modo == 2){
           
            aeronaves->fim->prox = aeronave;
            aeronaves->fim = aeronave;
        }
    }
    aeronaves->contador++;
}
void inserir_rotas_base_dados(struct bases_dados_rotas *rotas, struct Rotas *rota, int modo){
    if(rota == NULL) return;
    
    rota->prox = NULL;
    
    if(rotas->inicio == NULL){
        rotas->fim = rota;
        rotas->inicio = rota;
    } else {
        if(modo == 1){
            // Inserir no início
            rota->prox = rotas->inicio;
            rotas->inicio = rota;
        }
        else if(modo == 2){
            // Inserir no fim
            rotas->fim->prox = rota;
            rotas->fim = rota;
        }
    }
    rotas->contador++;
}

struct Aeronaves *nova_aeronave(unsigned int *codigo){
    struct Aeronaves *novo_aviao = NULL;

    novo_aviao = (struct Aeronaves*)malloc(sizeof(struct Aeronaves));
    if(novo_aviao == NULL) return NULL;


    novo_aviao->id = *codigo;
    
    printf("Digite a identificacao da aeronave: ");
    getchar();
    fgets(novo_aviao->indentificacao, TAMANHO, stdin);
    remover_enter(novo_aviao->indentificacao);

    printf("Digite o modelo da aeronave: ");
    fgets(novo_aviao->modelo, TAMANHO, stdin);
    remover_enter(novo_aviao->modelo);

    printf("Digite o fabricante da aeronave: ");
    fgets(novo_aviao->fabricante, TAMANHO, stdin);
    remover_enter(novo_aviao->fabricante);

    printf("Digite a matricula da aeronave: ");
    fgets(novo_aviao->matricula, TAMANHO, stdin);
    remover_enter(novo_aviao->matricula);

    printf("Digite o ano de fabricacao: ");
    scanf("%i", &novo_aviao->ano_de_fabricacao);
    getchar();

    printf("Digite o numero de passageiros: ");
    scanf("%i", &novo_aviao->numero_de_passageiros);
    getchar();

    printf("Digite (p) para aeronave do tipo passageiro ou (c) para aeronave de carga: ");
    scanf(" %c", &novo_aviao->tipo); 
    getchar(); 
    
    int verificacao_tipo = 0; 
    
    do {
        
        if (novo_aviao->tipo == 'p' || novo_aviao->tipo == 'P' || 
            novo_aviao->tipo == 'c' || novo_aviao->tipo == 'C') {
            
            verificacao_tipo = 1; 
    
        } else {
            
            printf("Opcao invalida! Digite apenas p ou c: ");
            scanf(" %c", &novo_aviao->tipo);
            getchar(); 
            verificacao_tipo = 0; 
        }
    
    } while (verificacao_tipo == 0); 
    
    printf("Digite a situacao da aeronave, (o) para operante e (m) para manutencao: ");
    scanf("%c", &novo_aviao->situacao);
    getchar();

    int verificacao_situacao = 0;

    do {
        
        if (novo_aviao->situacao == 'O' || novo_aviao->situacao == 'o' || 
            novo_aviao->situacao == 'M' || novo_aviao->situacao == 'm') {
            
            verificacao_situacao = 1; 
    
        } else {
            
            printf("Opcao invalida! Digite apenas p ou c: ");
            scanf(" %c", &novo_aviao->situacao);
            getchar(); 
            verificacao_situacao = 0; 
        }
    
    } while (verificacao_situacao == 0); 

    printf("Digite o numero de pilotos: ");
    scanf("%i", &novo_aviao->tripulacao.piloto);
    getchar();

    printf("Digite o numero de copilotos: ");
    scanf("%i", &novo_aviao->tripulacao.copiloto);
    getchar();

    printf("Digite o numero de comissarias: ");
    scanf("%i", &novo_aviao->tripulacao.comissaria);
    getchar();

    novo_aviao->prox = NULL;
    
    return novo_aviao;
}

struct Rotas *nova_rota(unsigned int *codigo, struct base_dados_aeronave *db_aeronaves){
    struct Rotas *nova_rota = NULL;


    nova_rota = (struct Rotas*)malloc(sizeof(struct Rotas));
    if(nova_rota == NULL) return NULL;

    (*codigo)++;
    nova_rota->codigo = *codigo;
    
    printf("Digite o dia da rota: ");
    scanf("%u", &nova_rota->data.dia);
    getchar();

    printf("Digite o mes da rota: ");
    scanf("%u", &nova_rota->data.mes);
    getchar();

    printf("Digite o ano da rota: ");
    scanf("%u", &nova_rota->data.ano);
    getchar();

    printf("Digite a hora de partida (horas): ");
    scanf("%u", &nova_rota->hora.horas);
    getchar();

    printf("Digite a hora de partida (minutos): ");
    scanf("%u", &nova_rota->hora.minutos);
    getchar();

    printf("Digite o local de partida: ");
    fgets(nova_rota->localDePartida, TAMANHO, stdin);
    remover_enter(nova_rota->localDePartida);

    printf("Digite o local de destino: ");
    fgets(nova_rota->localDeDestino, TAMANHO, stdin);
    remover_enter(nova_rota->localDeDestino);

    printf("Digite o combustivel necessario: ");
    scanf("%f", &nova_rota->combustivel_necessario);
    getchar();

    printf("Digite a quantidade de passageiros: ");
    scanf("%i", &nova_rota->qtd_passageiros);
    getchar();

    printf("Digite a quantidade de cargas: ");
    scanf("%i", &nova_rota->qtd_cargas);
    getchar();

    printf("Digite o codigo da aeronave alocada: ");
    fgets(nova_rota->Aeronave_alocada, TAMANHO, stdin);
    remover_enter(nova_rota->Aeronave_alocada);


    int verificando_aeronave1, verificando_aeronave2; 
    do {
     
        verificando_aeronave1 = consultar_se_aeronave_existe(db_aeronaves, nova_rota->Aeronave_alocada);
    
        if(verificando_aeronave1 == 0) {
            printf("Aeronave nao encontrada\n"); 
            
            if(db_aeronaves->inicio == NULL) {
                 printf("Nenhuma aeronave cadastrada. Cadastre uma aeronave antes de criar rotas.\n");
                 free(nova_rota); 
                 return NULL; 
            } else {
                 listar_Aeronaves(db_aeronaves->inicio);
                 printf("Digite o codigo da aeronave alocada: ");
                 fgets(nova_rota->Aeronave_alocada, TAMANHO, stdin);
                 remover_enter(nova_rota->Aeronave_alocada);
                 
            }
         
        }
    } while(verificando_aeronave1 == 0);

    do {
        verificando_aeronave2 = consultar_se_aeronave_esta_em_manutencao(db_aeronaves, nova_rota->Aeronave_alocada);
    
        if(verificando_aeronave2 == 0) {
            printf("Aeronave nao encontrada\n"); 
            
            if(db_aeronaves->inicio == NULL) {
                 printf("Nenhuma aeronave cadastrada. Cadastre uma aeronave antes de criar rotas.\n");
                 free(nova_rota);
                 return NULL; 
            } else {
                 listar_Aeronaves(db_aeronaves->inicio);
                 printf("Digite o codigo da aeronave alocada QUE NAO ESTEJA EM MANUTENCAO: \n");
                 fgets(nova_rota->Aeronave_alocada, TAMANHO, stdin);
                 remover_enter(nova_rota->Aeronave_alocada);
                 
            }

        }
    } while(verificando_aeronave2 == 0);

    printf("Digite o nome do piloto: ");
    getchar();
    fgets(nova_rota->nome_piloto, TAMANHO, stdin);
    remover_enter(nova_rota->nome_piloto);

    printf("Digite o nome do copiloto: ");
    fgets(nova_rota->nome_copiloto, TAMANHO, stdin);
    remover_enter(nova_rota->nome_copiloto);

    printf("Digite o nome do comissario: ");
    fgets(nova_rota->nome_comissario, TAMANHO, stdin);
    remover_enter(nova_rota->nome_comissario);

    nova_rota->prox = NULL;
    
    return nova_rota;
}
