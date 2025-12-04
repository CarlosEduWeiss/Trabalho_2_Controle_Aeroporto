#include "../include/cadastros.h"
//#include "../include/utils.h"
#include "../include/utils.h"
#include <linux/limits.h>
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
    if(aeronaves->inicio == NULL){
        aeronaves->fim = aeronave;
        aeronaves->inicio = aeronave;
        if(modo == 1){
            aeronave->prox = aeronaves->inicio;
            aeronaves->inicio = aeronave;
        }
        else if(modo == 2){
            aeronaves->fim->prox = aeronave;
            aeronaves->fim = aeronave;

        }
    }
}
void inserir_rotas_base_dados(struct bases_dados_rotas *rotas, struct Rotas *rota, int modo);
struct Aeronaves *nova_aeronave(unsigned int *codigo){
    struct Aeronaves *novo_aviao = NULL;

    novo_aviao = (struct Aeronaves* )malloc(sizeof(struct Aeronaves));

    
    printf("Digite a identificacao da aeronave.\n");
    getchar();
    fgets(novo_aviao->indentificacao,TAMANHO,stdin);
    remover_enter(novo_aviao->indentificacao);
    //todo fgets do codigo tera um remover enter no codigo/ para que nao deixe nenhum /n perdido
    

    printf("Digite o modelo da aeronave\n");
    fgets(novo_aviao->modelo, TAMANHO, stdin);
    getchar();
    fgets(novo_aviao->indentificacao,TAMANHO,stdin);
    remover_enter(novo_aviao->indentificacao);
    //todo fgets do codigo tera um remover enter no codigo/ para que nao deixe nenhum /n perdido
    

    printf("Digite o modelo da aeronave\n");
    fgets(novo_aviao->modelo, TAMANHO, stdin);
    remover_enter(novo_aviao->modelo);

    

    printf("Fabricante da aeronave\n");
    fgets(novo_aviao->fabricante, TAMANHO, stdin);
    remover_enter(novo_aviao->fabricante);


    printf("Matricula da aeronave\n");
    fgets(novo_aviao->matricula, TAMANHO, stdin);
    remover_enter(novo_aviao->matricula);

    

    printf("Ano de fabricacao\n");
    scanf("%i", &novo_aviao->ano_de_fabricacao);
    getchar();

    

    printf("Digite (p) para aeronave do tipo passageiro/ digite (c) para aeronave de carga\n");
    scanf("%c", &novo_aviao->tipo);
    getchar();


    printf("Digite a situacao da aeronave, digite (o) para operante e (m) para manuntencao\n");
    scanf("%c", &novo_aviao->situacao);
    getchar();

    

    printf("Fabricante da aeronave\n");
    fgets(novo_aviao->fabricante, TAMANHO, stdin);
    remover_enter(novo_aviao->fabricante);


    printf("Matricula da aeronave\n");
    fgets(novo_aviao->matricula, TAMANHO, stdin);
    remover_enter(novo_aviao->matricula);

    

    printf("Ano de fabricacao\n");
    scanf("%i", &novo_aviao->ano_de_fabricacao);
    getchar();

    

    printf("Digite (p) para aeronave do tipo passageiro/ digite (c) para aeronave de carga\n");
    scanf("%c", &novo_aviao->tipo);
    getchar();


    printf("Digite a situacao da aeronave, digite (o) para operante e (m) para manuntencao\n");
    scanf("%c", &novo_aviao->situacao);
    getchar();
}
struct Rotas *nova_rota(unsigned int *codigo);
