#include "./include/menus.h"
#include "./include/listagens_aeronaves.h"
#include "./include/listagens_rotas.h"
#include "./include/relatorios.h"
#include "./include/types.h"
#include "./include/utils.h"
#include "./include/cadastros.h"
#include "./include/consultas.h"
#include "./include/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define T_STR   100;
#define FIM     0

int main()
{
    int opcao_menu_principal, opcao_menu_aeronaves, opcao_menu_rotas, opcao_salvar_aeronave, opcao_salvar_rota;
    string prefixo;
    string destino;
    string nome_arq;
    unsigned int dia, mes, ano;
    unsigned int dia_inicio, mes_inicio, ano_inicio;
    unsigned int dia_fim, mes_fim, ano_fim;
    int codigo_aeronave;
    float percentual;
    float consumo;
    struct Aeronaves *lista_aeronaves = NULL;
    struct Rotas *lista_rotas = NULL;

    struct base_dados_aeronave aeronaves;
    struct bases_dados_rotas rotas;
    inicializar_base_aeronaves(&aeronaves);
    inicializar_base_rotas(&rotas);

    carregar_dados_aeronaves(&aeronaves);
    carregar_dados_rotas(&rotas);
    
    do{ 
        opcao_menu_principal = menu_principal();
        switch(opcao_menu_principal){
            case 1: // Cadastrar aeronave
                inserir_aeronave_base_dados(&aeronaves, nova_aeronave(&aeronaves.contador), 2);
                break;
                
            case 2: // Cadastrar rota
                inserir_rotas_base_dados(&rotas, nova_rota(&rotas.contador), 2);
                break;
                
            case 3: // Consultar aeronaves
                do{
                    opcao_menu_aeronaves = menu_aeronaves();
                    switch(opcao_menu_aeronaves){
                        case 1: // Buscar aeronave por prefixo
                            printf("Digite o prefixo da aeronave: ");
                            getchar();
                            fgets(prefixo, TAMANHO, stdin);
                            remover_enter(prefixo);
                            struct Aeronaves *aeronave = buscar_aeronave_por_prefixo(&aeronaves, prefixo);
                            if(aeronave != NULL) {
                                mostrar_dados_aeronaves(aeronave, stdout);
                            } else {
                                printf("Aeronave nao encontrada.\n");
                            }
                            break;
                            
                        case 2: // Listagem por fabricante
                            lista_por_fabricante(aeronaves.inicio);
                            break;
                            
                        case 3: // Listagem por modelo
                            lista_por_modelo(aeronaves.inicio);
                            break;
                            
                        case 4: // Listagem por ano
                            lista_por_ano(aeronaves.inicio);
                            break;
                            
                        case 5: // Listagem por situacao
                            lista_por_situacao(aeronaves.inicio);
                            break;
                            
                        case 6: // Listagem de todas as aeronaves
                            if(aeronaves.inicio == NULL) {
                                printf("Nenhuma aeronave cadastrada.\n");
                            } else {
                                listar_Aeronaves(aeronaves.inicio);
                            }
                            break;

                            
                        case 7: 
                        do{ 
                            opcao_salvar_aeronave = sub_menu_tipo_relatorio();
                            switch(opcao_salvar_aeronave){
                                case 1:listar_Aeronaves(aeronaves.inicio);
                                    break;       
                                case 2: 
                                    printf("Nome do arquivo? ");
                                    fgets(nome_arq, TAMANHO, stdin);
                                    remover_enter(nome_arq);
                                    strcat(nome_arq, ".csv");
                                    exportar_dados_aeronaves_csv(aeronaves.inicio, nome_arq);
                                break;
                                    
                                case 3:                             
                                    printf("Nome do arquivo? ");
                                    fgets(nome_arq, TAMANHO, stdin);
                                    remover_enter(nome_arq);
                                    strcat(nome_arq, ".html");
                                    exportar_dados_aeronaves_html(aeronaves.inicio, nome_arq);
                                    break;
                                case 4: 
                                    break;
                                case 0:
                                    break;
                            }
                            }while(opcao_salvar_aeronave != FIM);
                            break;    
                        case 0:
                            break;
                            
                        default:
                            printf("Opcao invalida.\n");
                            break;
                    }
                } while(opcao_menu_aeronaves != FIM);
                break;
                
            case 4: // Consultar rotas
                do{
                    opcao_menu_rotas = menu_rotas();
                    switch(opcao_menu_rotas){
                        case 1: // Consultar rotas por data
                            consultar_rotas_por_data(&rotas);
                            break;
                            
                        case 2: // Listagem por destino
                            lista_por_destino(rotas.inicio);
                            break;
                            
                        case 3: // Listagem por origem
                            lista_por_origem(rotas.inicio);
                            break;
                            
                        case 4: // Percentual de voos para determinado destino em uma data
                            printf("Digite o destino: ");
                            getchar();
                            fgets(destino, TAMANHO, stdin);
                            remover_enter(destino);
                            printf("Digite o dia: ");
                            scanf("%u", &dia);
                            getchar();
                            printf("Digite o mes: ");
                            scanf("%u", &mes);
                            getchar();
                            printf("Digite o ano: ");
                            scanf("%u", &ano);
                            getchar();
                            percentual = percentual_voos_destino_data(&rotas, destino, dia, mes, ano);
                            printf("Percentual de voos para %s na data %02u/%02u/%04u: %.2f%%\n", 
                                   destino, dia, mes, ano, percentual);
                            break;
                            
                        case 5: // Percentual de voos por aeronave
                            printf("Digite o codigo da aeronave: ");
                            scanf("%s", &codigo_aeronave);
                            getchar();
                            percentual = percentual_voos_por_aeronave(&rotas, codigo_aeronave);
                            printf("Percentual de voos da aeronave %i: %.2f%%\n", codigo_aeronave, percentual);
                            break;
                            
                        case 6: // Consumo de combustivel total em determinado intervalo
                            printf("Digite a data de inicio (dia mes ano): ");
                            scanf("%u %u %u", &dia_inicio, &mes_inicio, &ano_inicio);
                            getchar();
                            printf("Digite a data de fim (dia mes ano): ");
                            scanf("%u %u %u", &dia_fim, &mes_fim, &ano_fim);
                            getchar();
                            consumo = consumo_combustivel_intervalo(&rotas, dia_inicio, mes_inicio, ano_inicio, dia_fim, mes_fim, ano_fim);
                            printf("Consumo total de combustivel no intervalo: %.2f\n", consumo);
                            break;
                            
                        case 7: // Listagem de rotas por quantidade crescente de passageiros
                            lista_Menor_passageiros(rotas.inicio);
                            break;
                            
                        case 8: // Listagem de rotas por quantidade decrescente de passageiros
                            lista_Maior_passageiros(rotas.inicio);
                            break;
                        case 9:listar_Rotas(rotas.inicio);
                                break;

                        case 10: 
                        do{ 
                            opcao_salvar_rota = sub_menu_tipo_relatorio();
                            switch(opcao_salvar_rota){
                                case 1:listar_Rotas(rotas.inicio);
                                    break;       
                                case 2: 
                                    printf("Nome do arquivo? ");
                                    fgets(nome_arq, TAMANHO, stdin);
                                    remover_enter(nome_arq);
                                    strcat(nome_arq, ".csv");
                                    exportar_dados_rotas_csv(rotas.inicio, nome_arq);
                                    
                                    break;
                                    
                                case 3:
                                   
                                    printf("Nome do arquivo? ");
                                    fgets(nome_arq, TAMANHO, stdin);
                                    remover_enter(nome_arq);
                                    strcat(nome_arq, ".html");
                                    exportar_dados_rotas_html(rotas.inicio, nome_arq);

                                    break;
                                case 4: 
                                    break;
                                case 0:
                                    break;
                            }
                            }while(opcao_salvar_rota != FIM);
                            break;    
                            
                        case 0:
                            break;
                            
                        default:
                            printf("Opcao invalida.\n");
                            break;
                    }
                } while(opcao_menu_rotas != FIM);
                break;
                
            case 0:
                
                printf("Saindo...\n");
                salvar_dados_aeronaves(aeronaves.inicio);
                salvar_dados_rotas(rotas.inicio);
                break;
                
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while(opcao_menu_principal != FIM);
    
    return 0;
}
