
#include <stdio.h>

#define MAX_LIVROS 3
#define TAM_TEXTO 120

int main() {

    int codigos[MAX_LIVROS] = {0};
    int codigoPesquisado;
    int estoques[MAX_LIVROS] = {0};
    int qtdLivros = 0;
    int novoCodigo;
    int repetidos;

    char descricao1[TAM_TEXTO];
    char descricao2[TAM_TEXTO];
    char descricao3[TAM_TEXTO];

    // Cadastro dos livros
    while (qtdLivros < MAX_LIVROS) {

        repetidos = 0;

        printf("Digite o codigo do livro:\n");
        scanf("%d", &novoCodigo);

        getchar();

        if (qtdLivros == 0) {
            printf("Digite a primeira descricao: ");
            fgets(descricao1, TAM_TEXTO, stdin);
        }
        else if (qtdLivros == 1) {
            printf("Digite a segunda descricao: ");
            fgets(descricao2, TAM_TEXTO, stdin);
        }
        else {
            printf("Digite a terceira descricao: ");
            fgets(descricao3, TAM_TEXTO, stdin);
        }

        for (int i = 0; i < qtdLivros; i++) {
            if (novoCodigo == codigos[i]) {
                repetidos = 1;
            }
        }

        while (novoCodigo < 0 || repetidos == 1) {

            printf("Codigo invalido ou ja cadastrado!\n");
            printf("Digite outro codigo:\n");
            scanf("%d", &novoCodigo);

            repetidos = 0;

            for (int i = 0; i < qtdLivros; i++) {
                if (novoCodigo == codigos[i]) {
                    repetidos = 1;
                }
            }
        }

        codigos[qtdLivros] = novoCodigo;

        // Validação do estoque
        printf("Digite a quantidade em estoque:\n");
        scanf("%d", &estoques[qtdLivros]);

        while (estoques[qtdLivros] < 0) {
            printf("Estoque nao pode ser negativo!\n");
            printf("Digite novamente:\n");
            scanf("%d", &estoques[qtdLivros]);
        }

        qtdLivros++;

        printf("Livro cadastrado com sucesso!\n");
    }

    printf("\n--- LIVROS CADASTRADOS ---\n");

    for (int i = 0; i < qtdLivros; i++) {
        printf("Codigo: %d | Estoque: %d\n",
           codigos[i], estoques[i]);

        if (i == 0) {
            printf("Descricao: %s", descricao1);
        }
        else if (i == 1) {
            printf("Descricao: %s", descricao2);
        }
        else if (i == 2) {
            printf("Descricao: %s", descricao3);
        }
    }

    int i = 0;
    int quantidadeCadastrada = qtdLivros;
    qtdLivros = 0;

    while (i < quantidadeCadastrada) {
        qtdLivros += estoques[i];
        i++;
    }

    printf("\nTotal de exemplares da biblioteca: %d\n", qtdLivros);


    printf("\nInforme o codigo do livro que deseja pesquisar:\n");
    scanf("%d", &codigoPesquisado);

    while (codigoPesquisado <= 0) {
        printf("Codigo invalido! Digite novamente:\n");
        scanf("%d", &codigoPesquisado);
    }

    int encontrado = 0;

    for (int i = 0; i < quantidadeCadastrada; i++) {

        if (codigoPesquisado == codigos[i]) {

            encontrado = 1;

            printf("\n--- RESULTADO DA BUSCA ---\n");
            printf("Codigo: %d\n", codigos[i]);
            printf("Estoque: %d\n", estoques[i]);

            if (i == 0) {
                printf("Descricao: %s", descricao1);
            }
            else if (i == 1) {
                printf("Descricao: %s", descricao2);
            }
            else if (i == 2) {
                printf("Descricao: %s", descricao3);
            }

            if (estoques[i] > 0) {
                printf("Existem exemplares disponiveis!\n");
            } else {
                printf("Nao existem exemplares disponiveis.\n");
            }

            break;
        }
    }

    if (encontrado == 0) {
        printf("Livro nao encontrado no sistema!\n");
    }
    

    return 0;
}