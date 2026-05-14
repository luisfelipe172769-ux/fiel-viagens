#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados do cliente no Protocolo Fiel
typedef struct {
    int id;
    char nome[50];
    char pet[30];
    int dias_viagem;
} ClienteFiel;

int main() {
    ClienteFiel clientes[100]; // Vetor de structs
    int totalClientes = 0;
    int opcao;

    do {
        printf("\n=== Sistema Interno FielViagens ===\n");
        printf("1. Cadastrar Cliente no Protocolo\n");
        printf("2. Listar Clientes Ativos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\n--- Novo Cadastro ---\n");
            clientes[totalClientes].id = totalClientes + 1;
            
            printf("Nome do Cliente: ");
            scanf(" %[^\n]s", clientes[totalClientes].nome); // Lê string com espaços
            
            printf("Nome do Pet / Cuidado: ");
            scanf(" %[^\n]s", clientes[totalClientes].pet);
            
            printf("Dias de Viagem: ");
            scanf("%d", &clientes[totalClientes].dias_viagem);
            
            totalClientes++;
            printf("Cadastro realizado com sucesso!\n");

        } else if (opcao == 2) {
            printf("\n--- Clientes Ativos no Protocolo ---\n");
            for (int i = 0; i < totalClientes; i++) {
                printf("ID: %d | Nome: %s | Pet/Alvo: %s | Dias: %d\n", 
                       clientes[i].id, clientes[i].nome, clientes[i].pet, clientes[i].dias_viagem);
            }
            if (totalClientes == 0) printf("Nenhum cliente cadastrado ainda.\n");
        }

    } while (opcao != 0);

    printf("Sistema encerrado.\n");
    return 0;
}