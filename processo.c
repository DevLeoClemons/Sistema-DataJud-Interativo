#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "processo.h"

void contar_linhas(char *Arquivo){
    
// primeiro a se fazer é saber quantas linhas nosso csv tem.

    printf("\nAguarde, contando as linhas...\n");

    int linhas = 0;
    char c;
    FILE * fp = fopen(Arquivo, "r");

    if(fp == NULL){
        
        printf("Erro ao abrir o arquivo!");

    }

    while ((c = fgetc(fp)) != EOF){

        if(c == '\n'){
            linhas++;
        }

    }

    fclose(fp);

    printf("\nO arquivo tem %d linhas!\n\n", linhas+1);

}

Processo * LerDados(char *Arquivo){

    printf("\nAguarde, estamos lendo os dados...\n");

    Processo * x = malloc(TAMANHO * sizeof(Processo));
    
    if(x == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    
    FILE * fp = fopen(Arquivo, "r");

    if(fp == NULL) {
        printf("Arquivo não pode ser aberto!\n");
        exit(1);
    }

    // Lendo o cabeçalho e ignorando

    char linha[2000];
    
    fgets(linha, sizeof(linha), fp);

    int i = 0;

    while(fgets(linha, sizeof(linha), fp)){

        linha[strcspn(linha, "\n")] = '\0';

        char * ptr = linha; // percorre a linha atual
        char * campo; // aponta o campo atual
        int col = 0;

        while(1){

            campo = ptr; // inicio do campo 

            while(*ptr && *ptr != ';'){
                ptr++;
            }

            if(*ptr == ';'){
                
                *ptr = '\0';
                ptr++;
            }

            switch (col) {
                case 0: x[i].id_processo = campo[0] ? atoi(campo) : 0; break;
                case 1: strcpy(x[i].numero_sigilo, campo[0] ? campo : "NULL"); break;
                case 2: strcpy(x[i].sigla_grau, campo[0] ? campo : "NULL"); break;
                case 3: strcpy(x[i].procedimento, campo[0] ? campo : "NULL"); break;
                case 4: strcpy(x[i].ramo_justica, campo[0] ? campo : "NULL"); break;
                case 5: strcpy(x[i].sigla_tribunal, campo[0] ? campo : "NULL"); break;
                case 6: x[i].id_tribunal = campo[0] ? atoi(campo) : 0; break;
                case 7: x[i].recurso = campo[0] ? atoi(campo) : 0; break;
                case 8: x[i].id_ultimo_oj = campo[0] ? atoi(campo) : 0; break;
                case 9: strcpy(x[i].dt_recebimento, campo[0] ? campo : "NULL"); break;
                case 10: x[i].id_ultima_classe = campo[0] ? atoi(campo) : 0; break;
                case 11: x[i].flag_violencia_domestica = campo[0] ? atoi(campo) : 0; break;
                case 12: x[i].flag_feminicidio = campo[0] ? atoi(campo) : 0; break;
                case 13: x[i].flag_ambiental = campo[0] ? atoi(campo) : 0; break;
                case 14: x[i].flag_quilombolas = campo[0] ? atoi(campo) : 0; break;
                case 15: x[i].flag_indigenas = campo[0] ? atoi(campo) : 0; break;
                case 16: x[i].flag_infancia = campo[0] ? atoi(campo) : 0; break;
                case 17: strcpy(x[i].decisao, campo[0] ? campo : "NULL"); break;
                case 18: strcpy(x[i].dt_resolvido, campo[0] ? campo : "NULL"); break;
                case 19: x[i].cnm1 = campo[0] ? atoi(campo) : 0; break;
                case 20: x[i].primeiras_sent_m1 = campo[0] ? atoi(campo) : 0; break;
                case 21: x[i].baix_m1 = campo[0] ? atoi(campo) : 0; break;
                case 22: x[i].decm1 = campo[0] ? atoi(campo) : 0; break;
                case 23: x[i].mpu_m1 = campo[0] ? atoi(campo) : 0; break;
                case 24: x[i].julgado_m1 = campo[0] ? atoi(campo) : 0; break;
                case 25: x[i].des_m1 = campo[0] ? atoi(campo) : 0; break;
                case 26: x[i].sus_m1 = campo[0] ? atoi(campo) : 0; break;
            }

            col++;
            if(*ptr == '\0') break;

        }

        i++;

    }

    fclose(fp);
    return x;
}

void ex2_busca_ultimo_oj(Processo *x){
    
    int id_processo;

    printf("\nDigite o id do processo que deseja buscar: ");
    scanf("%d", &id_processo);

    printf("\nAguarde, buscando Último Órgão Julgador...\n");

    for(int i = 0; i < TAMANHO; i++){
        if(x[i].id_processo == id_processo){
            printf("\nID Último Orgão Julgador: %d\n", x[i].id_ultimo_oj);
        }
    }

}

int busca_id_processo(Processo *x, char * dt_recebimento){

    int id_processo;

    for(int i = 0; i < TAMANHO; i++){
        if(strcmp(x[i].dt_recebimento, dt_recebimento) == 0){
            
            return x[i].id_processo;
        }
    }

    return -1;
}

void ex3_busca_dt_recebimento_mais_antigo(Processo * x){

    char id_proc_dt_rec_mais_ant[20];

    strcpy(id_proc_dt_rec_mais_ant, x[0].dt_recebimento);

    printf("\nAguarde, procurando a data de recebimento mais antiga...\n");

    for(int i = 1; i < TAMANHO; i++){

        if(strcmp(x[i].dt_recebimento, "NULL") == 0){
            continue;
        }

        if(strcmp(id_proc_dt_rec_mais_ant, x[i].dt_recebimento) > 0){

            strcpy(id_proc_dt_rec_mais_ant, x[i].dt_recebimento);

        }
        
    }

    printf("\nO processo com Data de Recebimento mais antiga possui o ID: %d e Data: %s\n",busca_id_processo(x, id_proc_dt_rec_mais_ant), id_proc_dt_rec_mais_ant);

}

void ex4_qtd_proc_violencia_domestica(Processo * x){

    int qtd = 0;

    printf("\nAguarde, filtrando processos envolvendo Viol. Doméstica...\n");

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].flag_violencia_domestica == 1){
            qtd++;
        }

    }

    printf("\nQuantidade de processos com a flag Violência Doméstica: %d\n", qtd);

}

void ex5_qtd_proc_feminicidio(Processo * x){

    int qtd = 0;

    printf("\nAguarde, filtrando processos envolvendo Feminicídio...\n");

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].flag_feminicidio == 1){
            qtd++;
        }

    }

    printf("\nQuantidade de processos com a flag Feminicídio: %d\n", qtd);

}

void ex6_qtd_proc_causas_ambientais(Processo * x){

    printf("\nAguarde, filtrando processos envolvendo Causas Ambientais...\n");

    int qtd = 0;

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].flag_ambiental == 1){
            qtd++;
        }

    }

    printf("\nQuantidade de processos com a flag Causas Ambientais: %d\n", qtd);

}

void ex7_qtd_proc_causas_quilombolas(Processo * x){

    printf("\nAguarde, filtrando processos envolvendo Quilombolas...\n");
    
    int qtd = 0;

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].flag_quilombolas == 1){
            qtd++;
        }

    }

    printf("\nQuantidade de processos com a flag de Causas Quilombolas: %d\n", qtd);

}

void ex8_qtd_proc_causas_indigenas(Processo * x){

    printf("\nAguarde, filtrando processos envolvendo Indígenas...\n");
    
    int qtd = 0;

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].flag_indigenas == 1){
            qtd++;
        }

    }

    printf("\nQuantidade de processos com a flag Causas Indígenas: %d\n", qtd);

}

void ex9_qtd_proc_infancia_juventude(Processo * x){

    printf("\nAguarde, filtrando processos envolvendo Infância e Juventude...\n");
    
    int qtd = 0;

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].flag_infancia == 1){
            qtd++;
        }

    }

    printf("\nQuantidade de processos com a flag Infância e Juventude: %d\n", qtd);

}

Date stringToDate(char * c){

    Date d;

    sscanf(c, "%d-%d-%d", &d.ano, &d.mes, &d.dia);

    return d;
    
}

void ex10_duracao_processo(Processo * x){

    printf("\nAguarde, calculando duração do processo...\n");
    
    int id_processo;

    printf("\nDigite o ID do processo: ");
    scanf("%d", &id_processo);

    char dt_recebimento[20];
    char dt_resolvido[20];

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].id_processo == id_processo){

            if(x[i].dt_resolvido[0] != '\0'){

                strcpy(dt_recebimento, x[i].dt_recebimento);
                strcpy(dt_resolvido, x[i].dt_resolvido);
                break;
            }
            else{
                printf("\nProcesso ainda em andamento!\n");
                return;
            }

            
        }

    }

    // transformando as strings de datas para a struct "Date" criada

    Date date_receb = stringToDate(dt_recebimento);
    Date date_resol = stringToDate(dt_resolvido);

    long dias1 = calc_dias_da_data(date_resol);
    long dias2 = calc_dias_da_data(date_receb);

    long intervaloDias = dias1 - dias2;

    printf("\nO Processo durou %ld dias!\n", intervaloDias);

}

int ehAnoBissexto(int ano){
    return ((ano % 400 == 0)|| ((ano % 4 == 0)&&(ano % 100 != 0)));
}

int calc_qtd_dias_mes(int ano, int mes){
    switch (mes){
        case 2: return ehAnoBissexto(ano) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default: return 31;   
    }
}

long calc_dias_da_data(Date d){

    long dias = d.dia;

    for (int m = 1; m < d.mes; m++){

        dias += calc_qtd_dias_mes(d.ano, m);

    }

    for (int a = 1; a < d.ano; a++){

        dias += ehAnoBissexto(a) ? 366 : 365;

    }

    return dias;

}

void ex11_calc_perc_meta1(Processo * x){

    printf("\nAguarde, calculando percentual cumprido da meta 1...\n");
    
    int id_tribunal;

    float perc_m1=0, julgadom1=0, cnm1=0, desm1=0, susm1=0;

    printf("Digite o ID do tribunal: ");
    scanf("%d", &id_tribunal);

    for (int i = 0; i < TAMANHO; i++){

        if (x[i].id_tribunal == id_tribunal){

            julgadom1 += x[i].julgado_m1;
            cnm1 += x[i].cnm1;
            desm1 += x[i].des_m1;
            susm1 += x[i].sus_m1;

        }

    }
 
    perc_m1 = (((julgadom1) / (cnm1 + desm1 - susm1)) * 100);

    printf("\nPorcentagem de cumprimento da META 1: %.2f%%\n", perc_m1);

}

void ex12_csv_julgadom1(Processo * x){
    
    FILE * fp = fopen("ex12_julgado_m1.csv", "r");

    if (fp)
    {
        printf("\nO arquivo \"ex12_julgado_m1.csv\" já foi gerado!\n");
        return;
    }

    fp = fopen("ex12_julgado_m1.csv", "a");

    if(fp == NULL) {
        printf("Arquivo não pode ser criado!\n");
        exit(1);
    }

    printf("\nAguarde, gerando arquivo...\n");

    fprintf(fp, "id_processo;numero_sigilo;sigla_grau;procedimento;ramo_justica;sigla_tribunal;id_tribunal;recurso;id_ultimo_oj;dt_recebimento;id_ultima_classe;flag_violencia_domestica;flag_feminicidio;flag_ambiental;flag_quilombolas;flag_indigenas;flag_infancia;decisao;dt_resolvido;cnm1;primeirasentm1;baixm1;decm1;mpum1;julgadom1;desm1;susm1\n");

    for(int i = 0; i < TAMANHO; i++){

        if(x[i].julgado_m1 > 0){

            fprintf(fp, "%d;%s;%s;%s;%s;%s;%d;%d;%d;%s;%d;%d;%d;%d;%d;%d;%d;%s;%s;%d;%d;%d;%d;%d;%d;%d;%d\n", x[i].id_processo, x[i].numero_sigilo, x[i].sigla_grau, x[i].procedimento, x[i].ramo_justica, x[i].sigla_tribunal, x[i].id_tribunal, x[i].recurso, x[i].id_ultimo_oj, x[i].dt_recebimento, x[i].id_ultima_classe, x[i].flag_violencia_domestica, x[i].flag_feminicidio, x[i].flag_ambiental, x[i].flag_quilombolas, x[i].flag_indigenas, x[i].flag_infancia, x[i].decisao, x[i].dt_resolvido, x[i].cnm1, x[i].primeiras_sent_m1, x[i].baix_m1, x[i].decm1, x[i].mpu_m1, x[i].julgado_m1, x[i].des_m1, x[i].sus_m1);

        }

    }

    fclose(fp);

    limpar();

    printf("\nArquivo gerado com sucesso!\n");

}

void limpar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrar_opcoes(){

    printf("\n1- Contar linhas do csv\n2- Buscar Último Órgão Julgador\n3- Buscar Processo mais antigo\n4- Quantidade de proc. envolvendo Viol. Doméstica\n5- Quantidade de proc. envolvendo Feminicídio\n6- Quantidade de proc. envolvendo Causas Ambientais\n7- Quantidade de proc. envolvendo Quilombolas\n8- Quantidade de proc. envolvendo Indígenas\n9- Quantidade de proc. envolvendo Infância e Juventude\n10- Calcular duração do Processo\n11- Calcular percentual cumprido da META 1\n12- Gerar .csv com Processos julgados na Meta1\n\nDigite a opção que deseja: ");

}

void ler_opcao(int * opcao, Processo * x){

    scanf("%d", opcao);

        switch (*opcao)
        {
            case 1: limpar(); contar_linhas("data/TJDFT_filtrado.csv"); break;
            case 2: limpar(); ex2_busca_ultimo_oj(x); break;
            case 3: limpar(); ex3_busca_dt_recebimento_mais_antigo(x); break;
            case 4: limpar(); ex4_qtd_proc_violencia_domestica(x); break;
            case 5: limpar();printf("\nAcessando Banco de Dados...\n");ex5_qtd_proc_feminicidio(x); break;
            case 6: limpar(); ex6_qtd_proc_causas_ambientais(x); break;
            case 7: limpar(); ex7_qtd_proc_causas_quilombolas(x); break;
            case 8: limpar(); ex8_qtd_proc_causas_indigenas(x); break;
            case 9: limpar(); ex9_qtd_proc_infancia_juventude(x); break;
            case 10: limpar(); ex10_duracao_processo(x); break;
            case 11: limpar(); ex11_calc_perc_meta1(x); break;
            case 12: limpar(); ex12_csv_julgadom1(x); break;
            default: limpar(); printf("\nERRO: Digite uma opção válida!\n");
                
        }
    
}

int deseja_continuar(int * continuar){

    printf("\n1- Continuar\n2- Sair\n\nDigite a opção desejada: ");
        scanf("%d", continuar);
        if(*continuar == 2){
            printf("\nAté a próxima!\n");
            return 2;
        }
        return 0;
}