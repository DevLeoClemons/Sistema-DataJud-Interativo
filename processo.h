#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 2529658

#define buffer 1000

typedef struct {
    
    int id_processo;
    char numero_sigilo[buffer];
    char sigla_grau[buffer];
    char procedimento[buffer];
    char ramo_justica[buffer];
    char sigla_tribunal[buffer];   
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char dt_recebimento[buffer];
    int id_ultima_classe;
    bool flag_violencia_domestica;
    bool flag_feminicidio;
    bool flag_ambiental;
    bool flag_quilombolas;
    bool flag_indigenas;
    bool flag_infancia;
    char decisao[buffer];
    char dt_resolvido[buffer];
    int cnm1;
    int primeiras_sent_m1;
    int baix_m1;
    int decm1;
    int mpu_m1;
    int julgado_m1;
    int des_m1;
    int sus_m1;

} Processo;

typedef struct {
    
    int ano, mes, dia;

} Date;

void contar_linhas(char *Arquivo);

Processo * LerDados(char *Arquivo);

void ex2_busca_ultimo_oj(Processo *x);

void ex3_busca_dt_recebimento_mais_antigo(Processo * x);

void ex4_qtd_proc_violencia_domestica(Processo * x);

void ex5_qtd_proc_feminicidio(Processo * x);

void ex6_qtd_proc_causas_ambientais(Processo * x);

void ex7_qtd_proc_causas_quilombolas(Processo * x);

void ex8_qtd_proc_causas_indigenas(Processo * x);

void ex9_qtd_proc_infancia_juventude(Processo * x);

Date stringToDate(char * c);

void ex10_duracao_processo(Processo * x);

int ehAnoBissexto(int ano);

int calc_qtd_dias_mes(int ano, int mes);

long calc_dias_da_data(Date d);

void ex11_calc_perc_meta1(Processo * x);

void ex12_csv_julgadom1(Processo * x);

void limpar();

void mostrar_opcoes();

void ler_opcao(int * opcao, Processo * x);

void ler_opcao(int * opcao, Processo *);

int deseja_continuar(int * continuar);





