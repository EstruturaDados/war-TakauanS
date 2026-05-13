#include <stdio.h>

// Struct responsavel por criar territorio
typedef struct{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Strinc responsavel por armazenar todos os territorios
typedef struct{
    Territorio Atual[5];
    int quantidade_territorios;
} Dados_Territorios;

int main(){

    // Declaracao de variaveis de structs
    Dados_Territorios Terr_Atual = {.quantidade_territorios = 5};
    Territorio Terr;

    printf("=========================================================\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");

    // Laço de repetiçao responsavel por entradas do usuario
    for (int i=0; i < 5; i++){
        printf("\n -- Cadastrando Territorio %d --\n", i + 1);
        
        printf("• Nome do Territorio: ");
        fgets(Terr.nome, sizeof(Terr.nome), stdin);

        printf("• Cor do Exercito: (Ex: Azul, Verde): ");
        fgets(Terr.cor, sizeof(Terr.cor), stdin);

        printf("• Numero de tropas: ");
        scanf("%d", &Terr.tropas);

        getchar();

        Terr_Atual.Atual[i] = Terr;
    }

    // Laço responsavel por exibir os dados dos territorios
    for (int i=0; i < 5; i++){
        printf("\nTERRITORIO %d\n", i + 1);

        printf("  - Nome: %s", Terr_Atual.Atual[i].nome);
        printf("  - Cor: %s", Terr_Atual.Atual[i].cor);
        printf("  - Tropas: %d\n", Terr_Atual.Atual[i].tropas);
    }
    
    return 0;
}