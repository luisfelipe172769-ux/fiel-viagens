#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTOS 100

// ==========================================
// ESTRUTURAS DE DADOS (MODELO RELACIONAL)
// ==========================================

typedef struct {
    int id_cliente; // Chave Primaria (PK)
    char nome[50];
    char documento[20];
    char telefone[20];
    char email[50];
} Cliente;

typedef struct {
    int id_pet; // Chave Primaria (PK)
    int fk_cliente; // Chave Estrangeira (FK) -> id_cliente
    char nome_pet[30];
    char especie[30];
} Pet;

typedef struct {
    int id_destino; // Chave Primaria (PK)
    char cidade[50];
} Destino;

typedef struct {
    int id_registro; // Chave Primaria (PK)
    int fk_cliente; // Chave Estrangeira (FK)
    int fk_pet; // Chave Estrangeira (FK)
    int fk_destino; // Chave Estrangeira (FK)
    int dias_viagem;
} RegistroViagem;

// ==========================================
// BANCO DE DADOS EM MEMÓRIA (VETORES)
// ==========================================

Cliente tabela_clientes[MAX_ELEMENTOS];
int total_clientes = 0;

Pet tabela_pets[MAX_ELEMENTOS];
int total_pets = 0;

Destino tabela_destinos[MAX_ELEMENTOS];
int total_destinos = 0;

RegistroViagem tabela_registros[MAX_ELEMENTOS];
int total_registros = 0;

// ==========================================
// FUNÇÃO AUXILIAR DE LIMPEZA DE BUFFER
// ==========================================

void pausar_e_limpar() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================

int main() {
    int opcao;

    do {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printf("\n=== Sistema Interno FielViagens ===\n");
        printf("1. Cadastrar Cliente (Dono)\n");
        printf("2. Cadastrar Pet (Vinculado a um Dono)\n");
        printf("3. Cadastrar Destino Disponivel\n");
        printf("4. Registrar Nova Viagem (Associativa)\n");
        printf("5. Listar Todos os Registros de Viagens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            printf("\n--- Cadastro de Cliente ---\n");

            tabela_clientes[total_clientes].id_cliente = total_clientes + 1;

            printf("Nome do Cliente: ");
            scanf(" %[^\n]s", tabela_clientes[total_clientes].nome);

            printf("Documento (CPF/RG): ");
            scanf(" %[^\n]s", tabela_clientes[total_clientes].documento);

            printf("Telefone: ");
            scanf(" %[^\n]s", tabela_clientes[total_clientes].telefone);

            printf("Email: ");
            scanf(" %[^\n]s", tabela_clientes[total_clientes].email);

            printf("Cliente cadastrado com ID: %d\n", tabela_clientes[total_clientes].id_cliente);
            total_clientes++;
            pausar_e_limpar();

        } else if (opcao == 2) {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            printf("\n--- Cadastro de Pet ---\n");

            if (total_clientes == 0) {
                printf("Erro: Cadastre pelo menos um cliente antes de adicionar um pet.\n");
            } else {
                tabela_pets[total_pets].id_pet = total_pets + 1;

                printf("Digite o ID do Cliente (Dono): ");
                scanf("%d", &tabela_pets[total_pets].fk_cliente);

                printf("Nome do Pet: ");
                scanf(" %[^\n]s", tabela_pets[total_pets].nome_pet);

                printf("Especie do Pet: ");
                scanf(" %[^\n]s", tabela_pets[total_pets].especie);

                printf("Pet cadastrado com sucesso e vinculado ao Cliente ID %d!\n", tabela_pets[total_pets].fk_cliente);
                total_pets++;
            }
            pausar_e_limpar();

        } else if (opcao == 3) {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            printf("\n--- Cadastro de Destino ---\n");

            tabela_destinos[total_destinos].id_destino = total_destinos + 1;

            printf("Nome da Cidade de Destino: ");
            scanf(" %[^\n]s", tabela_destinos[total_destinos].cidade);

            printf("Destino cadastrado com ID: %d\n", tabela_destinos[total_destinos].id_destino);
            total_destinos++;
            pausar_e_limpar();

        } else if (opcao == 4) {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            printf("\n--- Registrar Nova Viagem ---\n");

            if (total_clientes == 0 || total_pets == 0 || total_destinos == 0) {
                printf("Erro: Garanta que existam Clientes, Pets e Destinos cadastrados para criar um registro.\n");
            } else {
                tabela_registros[total_registros].id_registro = total_registros + 1;

                printf("ID do Cliente: ");
                scanf("%d", &tabela_registros[total_registros].fk_cliente);

                printf("ID do Pet: ");
                scanf("%d", &tabela_registros[total_registros].fk_pet);

                printf("ID do Destino: ");
                scanf("%d", &tabela_registros[total_registros].fk_destino);

                printf("Quantidade de Dias da Viagem: ");
                scanf("%d", &tabela_registros[total_registros].dias_viagem);

                printf("Viagem registrada com Sucesso! ID do Registro: %d\n", tabela_registros[total_registros].id_registro);
                total_registros++;
            }
            pausar_e_limpar();

        } else if (opcao == 5) {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            printf("\n--- Relatorio Geral de Viagens Ativas ---\n");

            if (total_registros == 0) {
                printf("Nenhum registro de viagem cadastrado ainda.\n");
            } else {
                for (int i = 0; i < total_registros; i++) {
                    int cli_idx = tabela_registros[i].fk_cliente - 1;
                    int pet_idx = tabela_registros[i].fk_pet - 1;
                    int dest_idx = tabela_registros[i].fk_destino - 1;

                    printf("==========================================\n");
                    printf("REGISTRO VIAGEM ID: %d\n", tabela_registros[i].id_registro);
                    printf("Cliente: %s (Doc: %s | Tel: %s)\n",
                           tabela_clientes[cli_idx].nome,
                           tabela_clientes[cli_idx].documento,
                           tabela_clientes[cli_idx].telefone);
                    printf("Pet Assistido: %s (%s)\n",
                           tabela_pets[pet_idx].nome_pet,
                           tabela_pets[pet_idx].especie);
                    printf("Destino: %s | Duracao: %d dias\n",
                           tabela_destinos[dest_idx].cidade,
                           tabela_registros[i].dias_viagem);
                }
                printf("==========================================\n");
            }
            pausar_e_limpar();
        }

    } while (opcao != 0);

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    printf("Sistema encerrado.\n");
    return 0;
}
