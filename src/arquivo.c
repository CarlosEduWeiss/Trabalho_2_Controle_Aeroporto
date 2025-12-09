#include "../include/arquivo.h"
#include "../include/cadastros.h"
#include "../include/types.h"
#include "../include/relatorios.h"
#include <stdlib.h>
#include <stdio.h>



void salvar_dados_aeronaves(struct Aeronaves *inicio){
    FILE *fp = NULL;

    fp = fopen("Aeronaves.bin", "wb");

    if(!fp){   
        printf("Erro ao tentar abrir aeronave.bin");
        return;
    }
    while (inicio){
        fwrite(inicio, sizeof(struct Aeronaves), 1, fp);
        inicio = inicio -> prox;
    }

    fclose(fp);

}
void salvar_dados_rotas(struct Rotas *inicio){
    FILE *fp = NULL;

    fp = fopen("Rotas.bin", "wb");

    if(!fp){
        printf("Erro ao tentar abrir Rotas.bin");
        return;
    }
    while (inicio){
        fwrite(inicio, sizeof(struct Rotas), 1, fp);
        inicio = inicio -> prox;
    }

    fclose(fp);
    
}
void carregar_dados_aeronaves(struct base_dados_aeronave *aeronave){
    FILE *fp = NULL;
    struct Aeronaves *novo = NULL;

    fp = fopen("Aeronaves.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo Aeronaves.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (struct Aeronaves*)malloc(sizeof(struct Aeronaves));

        fread(novo, sizeof(struct Aeronaves), 1, fp);
        novo->prox = NULL;
        if (!feof(fp)) {
            inserir_aeronave_base_dados(aeronave, novo, 2);
        }
        else {
            free(novo);
        }
    }

    fclose(fp);
}
void carregar_dados_rotas(struct bases_dados_rotas *rotas){
    FILE *fp = NULL;
    struct Rotas *novo = NULL;

    fp = fopen("Rotas.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo Rotas.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (struct Rotas*)malloc(sizeof(struct Rotas));

        fread(novo, sizeof(struct Rotas), 1, fp);
        novo->prox = NULL;
        if (!feof(fp)) {
            inserir_rotas_base_dados(rotas, novo, 2);
        }
        else {
            free(novo);
        }
    }

    fclose(fp);
    
}

void exportar_dados_aeronaves_csv(struct Aeronaves *aeronave, char *nome_arq){
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "indentificacao;modelo;fabricante;matricula;ano_de_fabricacao;tipo;numero_de_passageiros;situacao;piloto;copiloto;comissaria\n");
    while (aeronave){
        fprintf(fp, "%s;%s;%s;%s;%d;%c;%d;%c;%d;%d;%d;\n", aeronave->indentificacao, aeronave->modelo, aeronave->fabricante, aeronave->matricula, aeronave->ano_de_fabricacao, aeronave->tipo, aeronave->numero_de_passageiros, aeronave->situacao,
        aeronave->tripulacao.piloto, aeronave->tripulacao.copiloto, aeronave->tripulacao.comissaria);
        aeronave = aeronave->prox;
    }

    fclose(fp);
    
}
void exportar_dados_rotas_csv(struct Rotas *rotas, char *nome_arq){
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "indentificacao;modelo;fabricante;matricula;ano_de_fabricacao;tipo;numero_de_passageiros;situacao;piloto;copiloto;comissaria\n");
    while (rotas){
        fprintf(fp, "%i;%u;%u;%u;%u;%s;%s;%.2f;%d;%d;%s;%s;%s\n", rotas->data.dia, rotas->data.mes, rotas->data.ano, rotas->hora.horas, rotas->hora.minutos, rotas->localDePartida, rotas->localDeDestino, rotas->combustivel_necessario,
        rotas->qtd_passageiros, rotas->qtd_cargas, rotas->Aeronave_alocada, rotas->nome_piloto, rotas->nome_copiloto);
        rotas = rotas->prox;
    }

    fclose(fp);
}
void exportar_dados_aeronaves_html(struct Aeronaves *aeronave, char *nome_arq){
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<HTML> <HEAD> <TITLE> RELATORIO DE AERONAVES </TITLE> </HEAD> <BODY> \n");
    fprintf(fp, "<TABLE border = '1'> <TR> <TH> indentificacao </TH> <TH> modelo </TH> <TH> fabricante </TH> <TH> matricula </TH><TH> ano_de_fabricacao </TH><TH> tipo </TH><TH> numero_de_passageiros </TH><TH> situacao </TH><TH> quantidade de piloto </TH><TH> quantidade de copiloto </TH> <TH> quantidade de comissaria </TH></TR>\n");
    while (aeronave) {
        fprintf(fp, "<TR> <TD> %s </TD> <TD> %s </TD><TD> %s </TD><TD> %s </TD><TD> %d </TD><TD> %c </TD> <TD>%d</TD> <TD>%c</TD>  <TD>%d</TD> <TD>%d</TD> <TD>%d</TD></TR> \n", aeronave->indentificacao, aeronave->modelo, aeronave->fabricante, aeronave->matricula, aeronave->ano_de_fabricacao, aeronave->tipo, aeronave->numero_de_passageiros, aeronave->situacao,
            aeronave->tripulacao.piloto, aeronave->tripulacao.copiloto, aeronave->tripulacao.comissaria);
        aeronave = aeronave->prox;
        printf("html criado com sucesso");
    }
    fprintf(fp, "</TABLE> </BODY> </HTML>\n");

    fclose(fp);
}
void exportar_dados_rotas_html(struct Rotas *rotas, char *nome_arq){
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<HTML> <HEAD> <TITLE> RELATORIO DE ROTAS </TITLE> </HEAD> <BODY> \n");
    fprintf(fp, "<TABLE border = '1'> <TR> <TH> dia </TH> <TH> mes </TH> <TH> ano </TH> <TH> horas </TH><TH> minutos </TH><TH> Local de Partida </TH><TH> Local de Destino </TH><TH> combustivel necessario </TH><TH>  Quantidade de passageiros </TH><TH> quantidade de cargas (KG) </TH> <TH> Nome do piloto </TH><TH> Nome do comissario </TH><TH> Nome do copiloto </TH></TR>\n");
    while (rotas) {
        fprintf(fp, "<TR> <TD> %u </TD> <TD> %u </TD><TD> %u </TD><TD> %u </TD><TD> %u </TD><TD> %s </TD> <TD>%s</TD> <TD>%f</TD>  <TD>%d</TD> <TD>%d</TD> <TD>%s</TD><TD>%s</TD><TD>%s</TD><TD>%s</TD></TR> \n",rotas->data.dia, rotas->data.mes, rotas->data.ano, rotas->hora.horas, rotas->hora.minutos, rotas->localDePartida, rotas->localDeDestino, rotas->combustivel_necessario,
            rotas->qtd_passageiros, rotas->qtd_cargas, rotas->Aeronave_alocada, rotas->nome_piloto, rotas->nome_copiloto );
        rotas = rotas->prox;
        printf("html criado com sucesso");
    }
    fprintf(fp, "</TABLE> </BODY> </HTML>\n");

    fclose(fp);
    
}