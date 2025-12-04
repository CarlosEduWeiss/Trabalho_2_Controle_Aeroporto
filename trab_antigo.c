/*

                                               TRABALHO DE Linguagem de prog 1
                                               CONTROLE DE AREONAVES E ROTAS

                alunos: Arthur Fogliato e Carlos Eduardo Weiss
                semestre: Primeiro semestre
                ano: 2025
                professor: Anderson
                curso: Eng.Computacao



*/
//Bibliotecas utilizadas para o codigo
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//aqui temos algumas definicoes de tamanaho e  criacao do tipo String
#define TAMANHO 100
#define QTD_MAX_TRIPULACAO 20
typedef char string[TAMANHO];
#define QTD_MAX_AERONAVES  50
#define QTD_MAX_ROTAS      20

//Criamos o tipo Stuct Aeronaves, onde ira armazenar as infoermacoes necessarias
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
    string nome_piloto;
    string nome_comissario[QTD_MAX_TRIPULACAO];//
    string nome_copiloto;
    
    Aeronaves_t *prox;
    

}Aeronaves_t;

int qtd_comissario;
//temos aqui a criacao do tipo Struct Rotas para armazenar rotas
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
    
    Rotas_t *prox;
 

}Rotas_t;
//funcoes de menu
int menuPrincipal();
void menu_aeronaves();
void menu_rotas();

//funcoes de interesse de aeronaves
void inserir_aeronave_pelo_incicio(Aeronaves_t **lista, Aeronaves_t *nova_equipe);
void inserir_aeronave_pelo_fim(Aeronaves_t **lista, Aeronaves_t *nova_equipe);
Aeronaves_t* localizar_fim_lista(Aeronaves_t *lista);
Aeronaves_t* localizar_fim_lista(Aeronaves_t id_aeronave, Aeronaves_t *lista);
Rotas_t* localizar_fim_lista(Rotas_t *lista);
Rotas_t* localizar_fim_lista(Rotas_t id_aeronave, Rotas_t *lista);
Aeronaves_t CadastroDeAeronaves();
void relatorioDeAeronaves(Aeronaves_t aviao);
int busca_por_prefixo(string prefixo);
void lista_por_fabricante(Aeronaves_t *lista);
void lista_por_modelo(Aeronaves_t *lista);
void lista_por_ano(Aeronaves_t *lista);
void lista_por_situacao(Aeronaves_t *lista);
void qtd_aeronava_manuntencao();
//funcoes de interesse de rotas
Rotas_t CadastroDeRotas();
void consultar_por_data();
void lista_por_destino(Rotas_t *lista);
void lista_por_origem(Rotas_t *lista);
void percentual_voo_intervalo();
void pecentual_voo_aeronave();
void consumo_por_data();
void lista_Maior_passageiros(Rotas_t *lista);
void lista_Menor_passageiros(Rotas_t *lista);

//funcoes auxiliares/ ajudam a implementar o codigo
void remover_enter(string str);
int data_em_dias(int dia, int mes, int ano);
void limpar_tela();
void mostrar_msg();


//chama o menu principal e realiza as questoes de ordem do MenuPincipal
int main()
{
    Aeronaves_t *lista_aeronaves = NULL, aux* = NULL;
    Rotas_t *lista_rotas = NULL, aux* = NULL;
    int MenuPrincipal;
    do{
        
        MenuPrincipal = menuPrincipal();

        switch (MenuPrincipal){
            case 1:
            if (qtd_aeronaves_cadastradas < QTD_MAX_AERONAVES) {
                bases_aeronaves[qtd_aeronaves_cadastradas] = CadastroDeAeronaves();
                qtd_aeronaves_cadastradas++;
                
                mostrar_msg("Aeronave Cadastrada Com Sucesso!");
            } else {
                printf("Limite máximo de aeronaves atingido!\n");
            }
           
            break;
            case 2:
                if (qtd_rotas_cadastradas < QTD_MAX_ROTAS) {
                    bases_rotas[qtd_rotas_cadastradas] = CadastroDeRotas();
                    qtd_rotas_cadastradas++;
                    
                    mostrar_msg("Rota Cadastrada Com Sucesso!");
                } else {
                    printf("Limite máximo de rotas atingido!\n");
                }
                break;
            case 3:
                menu_aeronaves();
                break;
            case 4:
                menu_rotas();
                break;
            case 0:
                printf("saindo do programa...\n");
        }
    }while(MenuPrincipal != 0);

    return 0;
}
//Menu principal e suas respectivas opcoes para chamada de funcao
int menuPrincipal(void){
    
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
}
//menu de aeronaves, realiza as funcoes de intesse sobre aeronaves
void menu_aeronaves(void){
    int opc;
    

    do {
    printf("-----MENU DE AERONAVES-----\n");
    printf("1 buscar aeronave por prefixo\n");
    printf("2 listagem por fabricante\n");
    printf("3 listagem por modelo\n");
    printf("4 listagem por ano\n");
    printf("5 listagem por situacao\n");
    printf("0 para voltar\n");
    printf("::::");
    scanf("%i", &opc);
    
    switch(opc){
        case 1: {
            int resposta;
            string consulta;
            getchar();
            printf("digite o prefixo da aeronave");
            fgets(consulta, TAMANHO, stdin);
            remover_enter(consulta);
            resposta = busca_por_prefixo(consulta);
            if(resposta >= 0){
                printf("Aeronave encontrada!");
                relatorioDeAeronaves(bases_aeronaves[resposta]);
            }else{
                printf("Aeronave nao encontrada;");
            }
            break;
        }
        
        case 2:
            lista_por_fabricante();
            break;

        case 3:
            lista_por_modelo();
            break;
        
        case 4:
            lista_por_ano();
            break;

        case 5:
            lista_por_situacao();
            break;
    }
    } while (opc != 0);

    
}
//realiza as funcoes de interesse de rotas
void menu_rotas(void){
    
    int opc;

    do{
        
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


    
        switch(opc){
            case 1:
            consultar_por_data();
                break;
            case 2:
            lista_por_destino();
                break;
            case 3:
            lista_por_origem();
                break;
            case 4:
            percentual_voo_intervalo();
                break;
            case 5:
            pecentual_voo_aeronave();
                break;
            case 6:
            consumo_por_data();
                break;
            case 7:
            lista_Maior_passageiros();
                break;
            case 8:
            lista_Menor_passageiros();
                break;
            case 0:
            printf("voltando ao menu principal...");
                break;

        }
    }while(opc != 0);
    
}
//faz o cadastro de aeronaves
Aeronaves_t CadastroDeAeronaves()
{
    Aeronaves_t aviao;
    Rotas_t rotas;

    printf("Digite a identificacao da aeronave.\n");
    getchar();
    fgets(aviao.indentificacao,TAMANHO,stdin);
    remover_enter(aviao.indentificacao);
    //todo fgets do codigo tera um remover enter no codigo/ para que nao deixe nenhum /n perdido
    

    printf("Digite o modelo da aeronave\n");
    fgets(aviao.modelo, TAMANHO, stdin);
    remover_enter(aviao.modelo);

    

    printf("Fabricante da aeronave\n");
    fgets(aviao.fabricante, TAMANHO, stdin);
    remover_enter(aviao.fabricante);


    printf("Matricula da aeronave\n");
    fgets(aviao.matricula, TAMANHO, stdin);
    remover_enter(aviao.matricula);

    

    printf("Ano de fabricacao\n");
    scanf("%i", &aviao.ano_de_fabricacao);
    getchar();

    

    printf("Digite (p) para aeronave do tipo passageiro/ digite (c) para aeronave de carga\n");
    scanf("%c", &aviao.tipo);
    getchar();


    printf("Digite a situacao da aeronave, digite (o) para operante e (m) para manuntencao\n");
    scanf("%c", &aviao.situacao);
    getchar();

    printf("Digite quantos da tripulacao tem: comecando por piloto/co-piloto\n");
    scanf("%i %i %i", &aviao.tripulacao.piloto, &aviao.tripulacao.copiloto, &aviao.tripulacao.comissaria);
    getchar();

    int qtd_comissario = aviao.tripulacao.comissaria;

    printf("Nome do piloto\n");
    fgets(aviao.nome_piloto, TAMANHO, stdin);
    remover_enter(aviao.nome_piloto);

    printf("nome do copiloto\n");
    fgets(aviao.nome_copiloto, TAMANHO, stdin);
    remover_enter(aviao.nome_copiloto);
    //Laco de repeticao para que preencha todos os nomes de comissarios
    printf("nome dos comissarios\n");
    for(i = 0; i < qtd_comissario; i++){
        fgets(aviao.nome_comissario[i], TAMANHO, stdin);
        remover_enter(aviao.nome_comissario[i]);
    }


    

   
    

    return aviao;
    
}
Rotas_t CadastroDeRotas()
{
    Aeronaves_t aviao;
    Rotas_t rotas;

    printf("Digite o codigo da rota.\n");
    scanf("%i", &rotas.codigo);
    getchar();

    printf("Digite a data da rota, comecando por dia, depois mes e depois ano\n");
    scanf("%i", &rotas.data.dia);
    getchar();

    printf("Digite a data da rota, comecando por dia, depois mes e depois ano\n");
    scanf("%i", &rotas.data.mes);
    getchar();

    printf("Digite a data da rota, comecando por dia, depois mes e depois ano\n");
    scanf("%i", &rotas.data.ano);
    getchar();

    printf("digite a hora da rota, comecando por horas e depois minutos.\n");
    scanf("%i %i", &rotas.hora.horas, &rotas.hora.minutos);
    getchar();

    printf("Origem da rota\n");
    fgets(rotas.localDePartida, TAMANHO, stdin);
    remover_enter(rotas.localDePartida);

    printf("Destino da rota\n");
    fgets(rotas.localDeDestino, TAMANHO, stdin);
    remover_enter(rotas.localDeDestino);

    printf("Combustivel necessario para percorrer a rota em LITROS.\n");
    scanf("%f", &rotas.combustivel_necessario);
    getchar();

    printf("Digite a quantidade de passageiros.\n");
    scanf("%i", &rotas.qtd_passageiros);
    getchar();

    printf("Digite a quantidade de carga em KG.\n");
    scanf("%i", &rotas.qtd_cargas);
    getchar();

    printf("Digite o codigo da aeronave designada para a rota.\n");
    scanf("%i", &rotas.Aeronave_alocada);
    getchar();

    return rotas;

}
void relatorioDeAeronaves(Aeronaves_t aviao)
{
    printf("A indentificacao da aeronave eh........: %s.\n", aviao.indentificacao);   
    printf("O modelo da aeronave eh.........: %s\n", aviao.modelo);    
    printf("Fabricante da aeronave eh.........:%s\n", aviao.fabricante);  
    printf("Matricula da aeronave eh.........:%s\n", aviao.matricula);
    printf("Ano de fabricacao eh........:%i\n", aviao.ano_de_fabricacao); 
    printf("O tipo de aeronave eh, lembrando (p) para aeronave do tipo passageiro/(c) para aeronave de carga........:%c\n", aviao.tipo);
    printf("A situacao da aeronave eh, lembrando (o) para operante e (m) para manuntencao.......%c:\n", aviao.situacao);
    printf("O numero de pilotos eh: %i, O numero de co-piloto(s) eh: %i, o numero de comissarios(as) eh: %i\n", aviao.tripulacao.piloto, aviao.tripulacao.copiloto, aviao.tripulacao.comissaria);
    printf("Nome do piloto: %s\n", aviao.nome_piloto);
    printf("Nome do co-piloto: %s\n", aviao.nome_copiloto);
    for(i = 0; i < aviao.tripulacao.comissaria; i++){
        printf("Nome dos comissarios: %s\n", aviao.nome_comissario[i]);
    }


}
void relatorioDeRotas(Rotas_t rotas){

    printf("O Codigo da rota eh %i.\n", rotas.codigo);   
    printf("A data de fabricacao %i/%i/%i \n", rotas.data.dia,rotas.data.mes,rotas.data.ano);    
    printf("A hora da rota eh |%i:%i|\n", rotas.hora.horas, rotas.hora.minutos);  
    printf("Local de partida:%s\n", rotas.localDePartida);
    printf("Ano de fabricacao eh........:%s\n", rotas.localDeDestino); 
    printf("O combustivel necessario para realizar a rota eh: %f\n", rotas.combustivel_necessario);
    printf("Diga a quantidade de passageiros que irao para a rota: %iL\n", rotas.qtd_passageiros);
    printf("Diga a quantidade de carga no voo %i kg\n ", rotas.qtd_cargas);



}
//busca aeronave por indentificacao
int busca_por_prefixo(string prefixo) {
    int i;
    for(i = 0;i<QTD_MAX_AERONAVES;i++ ){
        if(strcmp(bases_aeronaves[i].indentificacao, prefixo)== 0){
            return i;
        }
    }

    return -1;
}
//remove o enter do fgets
void remover_enter(string str){
    for(size_t i = 0; i < strlen(str); i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
}
void lista_por_fabricante(void) {
    int qtd_fabricante = 0;
    string fabricante;

    printf("Fabricante: ");
    getchar(); // limpa buffer do scanf anterior
    fgets(fabricante, TAMANHO, stdin);
    remover_enter(fabricante);

    for (int i = 0; i < qtd_aeronaves_cadastradas; i++) {
        if (strcmp(fabricante, bases_aeronaves[i].fabricante) == 0) {
            printf("\n--- Aeronave %d ---\n", i + 1);
            relatorioDeAeronaves(bases_aeronaves[i]);
            qtd_fabricante++;
        }
    }

    if (qtd_fabricante == 0)
        printf("Nenhuma aeronave encontrada com esse fabricante.\n");
    else
        printf("\nEstão cadastrados %i aviões desse fabricante.\n", qtd_fabricante);
}
void lista_por_modelo(void) {
    string modelo;
    int qtd_modelo = 0;
    printf("modelo: ");
    getchar();
    fgets(modelo, TAMANHO, stdin);
    remover_enter(modelo);

    //strcspn...
    for(int i=0; i<QTD_MAX_AERONAVES; i++){
        if(strcmp(modelo, bases_aeronaves[i].modelo) == 0){
            printf("%s", bases_aeronaves[i].modelo);
            relatorioDeAeronaves(bases_aeronaves[i]);
            qtd_modelo++;
        }
    }
    printf("estão cadastrados %i aviões deste modelo\n", qtd_modelo);
}
void lista_por_ano(void) {    
    int ano, qtd_ano =0;
    getchar();
    printf("ano de fabricacao (4 digitos): \n");
    scanf("%i", &ano);
    getchar();

    for(int i=0;i<QTD_MAX_AERONAVES;i++){
        if(ano == bases_aeronaves[i].ano_de_fabricacao){
            printf("%i.\n", i);
            relatorioDeAeronaves(bases_aeronaves[i]);
            qtd_ano++;  
        }
    }
    printf("há %i avioes fabricados no ano %i\n", qtd_ano, ano);

}
void lista_por_situacao(void) {
    char busca;
    int qtd_situacao=0;
    getchar();
    printf("buscar por manutencao(m) ou operante(o): \n");
    scanf("%c", &busca);
    getchar();

    for(int i=0;i<QTD_MAX_AERONAVES;i++){
        if(busca==bases_aeronaves[i].situacao){
            printf("%i.\n", i);
            relatorioDeAeronaves(bases_aeronaves[i]);
            qtd_situacao++;
        }
    }

    if(busca=='o'){
        printf("no momento, %i avioes estao operantes\n", qtd_situacao);}
        else{printf("no momento, %i avioes estao em manutencao\n", qtd_situacao);}
}
void consultar_por_data(void) {
    unsigned dia, mes, ano; 
    int qtd_consultar_por_data=0;
 
    printf("dd/mm/aaaa: ");
    scanf("%d", &dia);
    getchar();

    printf("dd/mm/aaaa: ");
    scanf("%d", &mes);
    getchar();

    printf("dd/mm/aaaa: ");
    scanf("%d",&ano);
    getchar();
 
    
    for(int i=0; i<qtd_rotas_cadastradas; i++){
        if(dia==bases_rotas[i].data.dia && mes==bases_rotas[i].data.mes && ano==bases_rotas[i].data.ano){
        relatorioDeRotas(bases_rotas[i]);
        qtd_consultar_por_data++;
    }
    }
    printf("houveram %i rotas nesta data\n", qtd_consultar_por_data);

}
void lista_por_destino(void) {
    int repetido;
    string escolha;
    
    printf("----TODOS OS DESTINOS----\n");
    for (int i = 0; i < qtd_rotas_cadastradas; i++) {
        repetido = 0;
        for (int j = 0; j < i; j++) {
        
            if (strcmp(bases_rotas[i].localDeDestino, bases_rotas[j].localDeDestino) == 0) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            printf("%i. %s\n", i + 1, bases_rotas[i].localDeDestino);
        }
    }
    
    printf("Digite o nome exato do destino:\n");
    fgets(escolha, TAMANHO, stdin);
    remover_enter(escolha);
    
    for (int k = 0; k < qtd_rotas_cadastradas; k++) {
 
        if (strcmp(escolha, bases_rotas[k].localDeDestino) == 0) {
            relatorioDeRotas(bases_rotas[k]);
        }
    }
}
void lista_por_origem(void) {
    int repetido;
    string escolha;
    
    printf("----TODOS OS DESTINOS----\n");
    for (int i = 0; i < qtd_rotas_cadastradas; i++) {
        repetido = 0;
        for (int j = 0; j < i; j++) {
        
            if (strcmp(bases_rotas[i].localDePartida, bases_rotas[j].localDePartida) == 0) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            printf("%i. %s\n", i + 1, bases_rotas[i].localDePartida);
        }
    }
    
    printf("Digite o nome exato da origem:\n");
    fgets(escolha, TAMANHO, stdin);
    remover_enter(escolha);
    
    for (int k = 0; k < qtd_rotas_cadastradas; k++) {
 
        if (strcmp(escolha, bases_rotas[k].localDePartida) == 0) {
            relatorioDeRotas(bases_rotas[k]);
        }
    }

}
void percentual_voo_intervalo(void) {
    int data_inicial, data_final;
    int dia_inical,mes_inicial,ano_incial;
    int dia_final, mes_final, ano_final;
    int data_voo;
    int total_destino_intervalo = 0;
    int total_intervalo = 0;
    string destino;
    int i;
    double porcentagem;

    printf("----Vamos calcular a porcentagem de voos de um determinado destinado em um determinado intervalo de datas ----\n");
    printf("Digite a data inicial!\n");
    scanf("%i %i %i", &dia_inical, &mes_inicial, &ano_incial);
    getchar();

    printf("Agora digite a data final!\n");
    scanf("%i %i %i", &dia_final, &mes_final, &ano_final);
    getchar();

    printf("Agora digite o destino\n");
    if (fgets(destino, TAMANHO, stdin) == NULL) {
        printf("Entrada invalida para o destino.\n");
        return;
    }
    remover_enter(destino);

    data_inicial = data_em_dias(dia_inical, mes_inicial, ano_incial);
    data_final = data_em_dias(dia_final, mes_final, ano_final);

    for(i = 0; i < qtd_rotas_cadastradas; i++){
        data_voo = data_em_dias(bases_rotas[i].data.dia, bases_rotas[i].data.mes, bases_rotas[i].data.ano);
        if(data_voo >= data_inicial && data_voo <= data_final){
            total_intervalo++;
            if(strcmp(destino, bases_rotas[i].localDeDestino) == 0){
                total_destino_intervalo++;
            }
        }
    }

    if(total_intervalo == 0){
        printf("Nao ha voos no intervalo informado.\n");
        return;
    }

    porcentagem = (total_destino_intervalo * 100.0) / (double)total_intervalo;
    printf("A porcentagem eh: %.2f%%\n", porcentagem);

    /*Pegar o dia mes e data desejado e colocar em uma variavel, depois comparar com a variavel 
    dar info de data incial, data final , destino */

}
void pecentual_voo_aeronave(void) {
    int total_voos = qtd_rotas_cadastradas;
	if (total_voos == 0) {
		printf("Nao ha voos cadastrados.\n");
		return;
	}

	for (int j = 0; j < qtd_aeronaves_cadastradas; j++) {
		int cont = 0;
		for (int i = 0; i < qtd_rotas_cadastradas; i++) {
			if (bases_rotas[i].Aeronave_alocada == j) {
				cont++;
			}
		}
		double perc = (cont * 100.0) / (double) total_voos;
		printf("- %s: %.2f%% (%d de %d)\n", bases_aeronaves[j].indentificacao, perc, cont, total_voos);
	}

}
void consumo_por_data(void) {
    
        unsigned int qtd_total_combustivel = 0;
        int dia1, mes1, ano1, dia2, mes2, ano2, dia_rota, mes_rota, ano_rota;
        int data_inicial, data_final, data_rota;
    
        printf("inicio do periodo: ");
        scanf("%d%d%d", &dia1, &mes1, &ano1);
        getchar();
    
        printf("fim do periodo: ");
        scanf("%d%d%d", &dia2, &mes2, &ano2);
        getchar();

        data_inicial = data_em_dias(dia1, mes1, ano1);
        data_final = data_em_dias(dia2, mes2, ano2);
    
        for(int i=0; i<qtd_rotas_cadastradas; i++){
            dia_rota = bases_rotas[i].data.dia;
            mes_rota = bases_rotas[i].data.mes;
            ano_rota = bases_rotas[i].data.ano;
    
            data_rota = data_em_dias(dia_rota, mes_rota, ano_rota);
    
            if(data_rota >= data_inicial && data_rota <= data_final){
                qtd_total_combustivel += bases_rotas[i].combustivel_necessario;
            }
        }
    
        printf("o combustivel total consumido por todas as rotas que ocorreram dentro do periodo de %d/%d/%d a %d/%d/%d foi %u\n", dia1, mes1, ano1, dia2, mes2, ano2, qtd_total_combustivel);
        
    /*
    
    primeiro ele compara ano mes e dia da data final ver se é maior que a inicial, 
    depois ele for percorre começando na data inicial até a final
    se tiver dentro do intervalo ele += qtd total combustivel
    
    */
    
    
}
void lista_Maior_passageiros(void) {
    
        Rotas_t temp[QTD_MAX_ROTAS];
        Rotas_t auxiliar;
    
        for(int i=0;i<qtd_rotas_cadastradas;i++){
            temp[i] = bases_rotas[i];
        }
    
        printf("lista de rotas do MAIOR ao MENOR numero de passageiros\n");
        
        for(int i=0;i<qtd_rotas_cadastradas; i++){
            for(int j=0; j<qtd_rotas_cadastradas;j++){
                if(temp[j].qtd_passageiros<temp[i].qtd_passageiros){
                auxiliar = temp[i];
                temp[i] = temp[j];
                temp[j] = auxiliar;
            }
           }
        }
        
        for(int k=0;k<qtd_rotas_cadastradas;k++){
            printf("rota de %s a %s, com %d passageiros\n", temp[k].localDePartida, temp[k].localDeDestino, temp[k].qtd_passageiros);
        }
    
    

}
void lista_Menor_passageiros(void) {
    
    Rotas_t temp[QTD_MAX_ROTAS];
    Rotas_t auxiliar;
    
    for(int i=0;i<QTD_MAX_ROTAS;i++){
        temp[i] = bases_rotas[i];
    }

    printf("lista de rotas do MENOR ao MAIOR numero de passageiros\n");
    
    for(int i=0;i<qtd_rotas_cadastradas; i++){
       for(int j=0; j<qtd_rotas_cadastradas;j++){
           if(temp[j].qtd_passageiros>temp[i].qtd_passageiros){
               auxiliar = temp[i];
            temp[i] = temp[j];
            temp[j] = auxiliar;
        }
    }
    }
    
    for(int k=0;k<qtd_rotas_cadastradas;k++){
        printf("rota de %s a %s, com %d passageiros\n", temp[k].localDePartida, temp[k].localDeDestino, temp[k].qtd_passageiros);
    }

    

}
//transforma data em dias
int data_em_dias(int dia, int mes, int ano)
{
    int soma;
    ano = ano * 365;
    mes = mes * 30;
    soma = dia + mes + ano;

    return soma;
}   
//funcao para limpar a tela do menu
void limpar_tela()
{
    system("clear");
}
void mostrar_msg(char *msg)
{
    printf("**************************** CONTROLE DE AERONAVES E ROTAS ******************************\n");
    printf("%s\n", msg);
    printf("De um ENTER para continuar!!\n");
    printf("*************************************************************************\n");
    getchar();
}