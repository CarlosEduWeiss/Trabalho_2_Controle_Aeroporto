#include <stdio.h>

int menu_principal(){
        
    int opc;
    

    printf("-----MENU PRINCIPAL-----\n");
    printf("o que deseja fazer no controle de frotas?\n");
    printf("1 para cadastrar uma aeronave\n");
    printf("2 para cadastrar uma rota\n");
    printf("3 para consultar aeronaves\n");
    printf("4 para consultar rotas\n");
    printf("0 para sair\n");
    printf("::::");
    scanf("%i", &opc);

    return opc;

};
int menu_aeronaves(){
    int opc;
    
    printf("-----MENU DE AERONAVES-----\n");
    printf("1 buscar aeronave por prefixo\n");
    printf("2 listagem por fabricante\n");
    printf("3 listagem por modelo\n");
    printf("4 listagem por ano\n");
    printf("5 listagem por situacao\n");
    printf("6. listagem de todas as aeronaves\n");
    printf("0 para voltar\n");
    printf("::::");
    scanf("%i", &opc);

    return opc;

}
int menu_rotas(){
    int opc;
        
    printf("-----MENU DE ROTAS-----\n");
    printf("1 para consultar rotas por data\n");
    printf("2 listagem por destino\n");
    printf("3 listagem por origem\n");
    printf("4 para percentual de voos para determinado destino em uma data\n");
    printf("5 percentual de voos por aeronave\n");
    printf("6 consumo de combustivel total em determinado intervalo\n");
    printf("7 listagem de rotas por quantidade crescente de passageiros\n");
    printf("8 listagem de rotas por quantidade decrescente de passageiros\n");
    printf("0 para voltar\n");
    printf("::::");
    scanf("%i", &opc);
    getchar();

    return opc;

}

