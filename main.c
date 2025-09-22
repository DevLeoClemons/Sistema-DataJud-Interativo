#include "processo.h"

int main(){

    limpar();

    Processo * x = LerDados("data/TJDFT_filtrado.csv"); // Lendo o CSV

    limpar();

    printf("\nSeja bem vindo ao DataJud do TJDFT interativo!\n");

    int opcao=0, continuar=0;

    while(true){

        mostrar_opcoes();

        ler_opcao(&opcao, x);

        if (deseja_continuar(&continuar) == 2){
            break;
        }

        limpar();
        
    }

}