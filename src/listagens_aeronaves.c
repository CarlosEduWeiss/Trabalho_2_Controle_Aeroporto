

#include "../include/listagens_aeronaves.h"
#include "../include/types.h"

void listar_Aeronaves(struct Aeronaves *inicio_lista)
{
    while (inicio_lista) {

        mostrar_dados_aeronaves(inicio_lista, stdout);
        inicio_lista = inicio_lista->prox;
    }
}

void mostrar_dados_aeronaves(struct Aeronaves *aeronaves, FILE *fp){
    fprintf(fp, "indentificacao................: %s\n", aeronaves->indentificacao);
    fprintf(fp, "modelo.......: %s\n", aeronaves->modelo);
    fprintf(fp, "fabricante.................: %s\n", aeronaves->fabricante);
    fprintf(fp, "matricula...: %s\n\n", aeronaves->matricula);
    fprintf(fp, "ano_de_fabricacao.......: %i\n", aeronaves->ano_de_fabricacao);
    fprintf(fp, "tipo.................: %c\n", aeronaves->tipo);
    fprintf(fp, "numero_de_passageiros...: %i\n\n", aeronaves->numero_de_passageiros);
    fprintf(fp, "situacao.......: %c\n", aeronaves->ano_de_fabricacao);
    fprintf(fp, "piloto.................: %i\n", aeronaves->tripulacao.piloto);
    fprintf(fp, "copiloto.................: %i\n", aeronaves->tripulacao.copiloto);
    fprintf(fp, "comissaria.................: %i\n", aeronaves->tripulacao.comissaria);

    

    
}
void lista_por_fabricante(Aeronaves_t *lista){                  }
void lista_por_modelo(Aeronaves_t *lista);
void lista_por_ano(Aeronaves_t *lista);
void lista_por_situacao(Aeronaves_t *lista);
