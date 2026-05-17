#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

typedef struct{
    Territorio *TerrAtual; // Vetor de Territorios
    int quantidade;
} DadosAtuais;

// Funcao para cadastro de territorios
void cadastrarTerritorio(DadosAtuais **terr_atual, char nome_ter[], char cor_terr[], int tropas_terr, int indice){
    strcpy((*terr_atual) -> TerrAtual[indice].nome, nome_ter);
    strcpy((*terr_atual) -> TerrAtual[indice].cor, cor_terr);

    (*terr_atual) -> TerrAtual[indice].tropas = tropas_terr;
}

// Funca para exibir informaçoes de territorios
void exibirInformacoes(DadosAtuais *p, int quantidade){
    printf("\nMAPA DO MUNDO - ESTADO ATUAL\n\n");

    for (int i=0; i < quantidade; i++){
        printf("%d. %s (Exercito %s, Tropas: %d)\n", i + 1, p -> TerrAtual[i].nome, p -> TerrAtual[i].cor, p -> TerrAtual[i].tropas);
    };
}

// Funcao para alocaçao dinamica de memoria
void numTerritorio(DadosAtuais **ptr, int quantidade){
    *ptr = calloc(1, sizeof(DadosAtuais));

    if (*ptr == NULL){
        printf("\n[ERRO] A alocaçao dinamica de memoria para Dados de Territorio falhou");
    } else {
        printf("\nA alocacao dinamica para Dados de Territorio foi um sucesso\n");
    }

    (*ptr) -> TerrAtual = calloc(quantidade, sizeof(Territorio));

    if ((*ptr) -> TerrAtual == NULL){
        printf("[ERRO] Alocacao dinamica de memoria para Territorios falhou");
    } else {
        printf("A alocacao dinamica de memoria para territorio foi um sucesso\n");
    }
};

// Funcao de ataque de defensor e atacante
void atack(int quantidade){
    int num_atacante=0, num_defensor=0;
    int atacante=0, defensor=0;

    DadosAtuais *infos = NULL;

    srand(time(NULL)); // Inicializa a semente com o horario atual do pc

    do {
        num_atacante = (rand() % 6) + 1; // gera um valor inteiro aleatorio de 1 a 6
        num_defensor = (rand() % 6) + 1;

        printf("\n-- FASE DE ATAQUE --\n");
        printf("Escolha o territorio atacante (1 a %d, ou 0 para sair): ", quantidade);

        scanf("%d", &atacante);
        getchar();

        if (atacante == 0){
            break;
        } else {
            printf("Escolha o territorio defensor (1 a %d): ", quantidade);
            scanf("%d", &defensor);
            getchar();
            
            printf("\n-- RESULTADO DA BATALHA --\n");

            printf("O atacante %s rolou um dado e tirou: %d\n", infos -> TerrAtual[atacante].nome, num_atacante);
            printf("O defensor %s rolou um dado e tirou: %d\n", infos -> TerrAtual[defensor].nome, num_defensor);
        };
    } while ((atacante != 0));
};

// Funcao para liberar alocacao dinamica de memoria
void liberarMemoria(DadosAtuais **ptr){
    free((*ptr) -> TerrAtual);
    (*ptr) -> TerrAtual = NULL;

    printf("\nA alocacao de memoria reservada foi liberada com sucesso!");
};

int main(){

    int qts_territorios, tropas;
    char nome[30], cor[10];

    DadosAtuais *Terr;

    printf("Qual e o numero de territorios: ");

    scanf("%d", &qts_territorios); 
    getchar();   

    numTerritorio(&Terr, qts_territorios);
    
    for (int i=0; i < qts_territorios; i++){
        printf("\n -- Cadastrando Territorio %d --\n", i + 1);

        printf("• Nome do Territorio: ");

        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("• Cor do Exercito: ");

        fgets(cor, sizeof(cor), stdin);
        cor[strcspn(cor, "\n")] = '\0';

        printf("• Numero de Tropas: ");
        scanf("%d", &tropas);

        getchar();
        cadastrarTerritorio(&Terr, nome, cor, tropas, i);
    };
    atack(qts_territorios);
    
    liberarMemoria(&Terr);

    return 0;
}