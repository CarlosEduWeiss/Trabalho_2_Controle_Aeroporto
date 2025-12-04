#include "./include/menus.h"
#include "./include/listagens_aeronaves.h"
#include "./include/listagens_rotas.h"
#include "./include/relatorios.h"
#include "./include/types.h"
#include "./include/utils.h"
#include "./include/cadastros.h"
#include "./include/consultas.h"
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define FIM     0

int main()
{
    int opcao_menu_principal, opcao_menu_aeronaves, opcao_menu_rotas;

    struct base_dados_aeronave aeronaves;
    struct bases_dados_rotas rotas;
    inicializar_base_aeronaves(&aeronaves);
    inicializar_base_rotas(&rotas);
    

    int opcao_menu_principal, opcao_menu_aeronaves, opcao_menu_rotas;
    do{ 
        opcao_menu_principal = menu_principal();
        switch(opcao_menu_principal){
            case 1: do{
                opcao_menu_aeronaves = menu_aeronaves();
                switch(opcao_menu_aeronaves){
                    case 1: inserir_aeronave_base_dados(&aeronaves, nova_aeronave(&aeronaves.contador), 1);
                        break;
                }
            }break;
            while(opcao_menu_aeronaves != FIM); 


        };


    }while(opcao_menu_principal != FIM);
    







    return 0;
}