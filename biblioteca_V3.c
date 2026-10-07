#include <stdio.h>
#define MAX_TITULOS 3
#define TAM_TEXTO 120

int cadastrarTitulo( int codigos[], int estoques[], char descricao1[], char descricao2[], char descricao3[], int qtdTitulos
){
    int repetidos;
    while (qtdTitulos < MAX_TITULOS)
    {
        printf("\n -- CADASTRE UM LIVRO -- \n");

        repetidos = 0;

        printf("Digite o codigo do livro: ");
        scanf("%d", &codigos[qtdTitulos]);
        getchar();

        if (qtdTitulos == 0) {
            printf("Digite a primeira descricao: ");
            fgets(descricao1, TAM_TEXTO, stdin);
        }
        else if (qtdTitulos == 1) {
            printf("Digite a segunda descricao: ");
            fgets(descricao2, TAM_TEXTO, stdin);
        }
        else {
            printf("Digite a terceira descricao: ");
            fgets(descricao3, TAM_TEXTO, stdin);
        }
        
        
        for (int i = 0; i < qtdTitulos; i++) {
            if (codigos[qtdTitulos] == codigos[i]) {
                repetidos = 1;
            }
        }

        while (codigos[qtdTitulos] < 0 || repetidos == 1)
        {
            printf("Codigo invalido ou repetido \n");
            printf("Por favor insira um novo codigo: \n");
            scanf("%d", &codigos[qtdTitulos]);

            repetidos = 0;

            for (int i = 0; i < qtdTitulos; i++) {
                if (codigos[qtdTitulos] == codigos[i]) {
                    repetidos = 1;
                }
            }
        }

       printf("Digite a quantidade em estoque: ");
       scanf("%d", &estoques[qtdTitulos]);

       while (estoques[qtdTitulos] < 0)
       {
        printf("O estoque nao pode ser negativo! Tente novamente: \n");
        scanf("%d", &estoques[qtdTitulos]);
       }
       qtdTitulos++;

       printf("Livro cadastrado com sucesso! \n");

    }
    return qtdTitulos;
}
 
void listarTitulos(
    int codigos[],
    int estoques[],
    char descricao1[],
    char descricao2[],
    char descricao3[],
    int qtdTitulos
){
    for (int i = 0; i < qtdTitulos; i++)
    {
        printf("\n--- TITULO %d ---\n", i + 1);
        printf("Codigo: %d\n", codigos[i]);

        if (i == 0)
        {
            printf("Descricao: %s", descricao1);
        }
        else if (i == 1)
        {
            printf("Descricao: %s", descricao2);
        }
        else
        {
            printf("Descricao: %s", descricao3);
        }

        printf("Estoque: %d\n", estoques[i]);
    }
} 
 
int buscarTitulo(int codigos[],int estoques[],int qtdTitulos,int codigoBuscado
){

    for (int i = 0; i < qtdTitulos; i++) {
        if (codigoBuscado == codigos[i]) {
            return i;
        }
    }

    return -1;
}
 
int calcularQtdExemplares(int estoques[], int qtdTitulos){
    int total = 0;

    for(int i = 0; i < qtdTitulos; i++){
        total += estoques[i];
    }

    return total;
}


int disponibilidadeTitulo(int qtdEstoque ){
    if (qtdEstoque > 0){
        return 1;
    } else {
        return 0;
    }
}

int respostaParaUmaPergunta(char pergunta[]) {
    char resposta;

    while (1) {
        printf("%s (S/N): ", pergunta);
        scanf(" %c", &resposta);

        if (resposta == 'S' || resposta == 's') {
            return 1;
        }
        else if (resposta == 'N' || resposta == 'n') {
            return 0;
        }
        else {
            printf("Resposta invalida! Digite S ou N.\n");
        }
    }
}

int main (){
    int codigos[MAX_TITULOS] = {0};
    int estoques[MAX_TITULOS] = {0};

    char descricao1[TAM_TEXTO];
    char descricao2[TAM_TEXTO];
    char descricao3[TAM_TEXTO];

    int qtdTitulos = 0;

    qtdTitulos = cadastrarTitulo(codigos,estoques,descricao1,descricao2,descricao3,qtdTitulos);

    int totalEstoque = calcularQtdExemplares(estoques, qtdTitulos);

    printf("\n Quantidade de titulos cadastrados: %d \n", qtdTitulos);
    printf("\n Total de livros em estoque: %d \n", totalEstoque);

    int codigoBuscado; int encontrado = 0; int posicao;

    printf("\n --- BUSCAR TITULOS --- \n");

    int desejapesquisar = respostaParaUmaPergunta(
        "Deseja pesquisar um titulo?"
    );

    if (desejapesquisar == 1)
    {
         while (encontrado == 0)
    {
        printf("Digite o codigo do titulo que deseja buscar: \n");
        scanf("%d", &codigoBuscado);

        posicao = buscarTitulo(codigos, estoques, qtdTitulos, codigoBuscado);

        if (posicao != -1)
        {
            printf("Codigo: %d\n", codigos[posicao]);
            printf("Estoque: %d\n", estoques[posicao]);

            encontrado = 1;
        }
        else
        {
            printf("Livro nao encontrado para o codigo fornecido!\n");
            printf("Por favor, tente novamente.\n");
        }
    }

    int disponivel = disponibilidadeTitulo(estoques[posicao]);

    if (disponivel == 1)
    {
       printf("Livro disponivel em nosso estoque! \n");
    } else {
       printf("Livro indisponivel em nosso estoque! \n");
    }

    } else {
        printf("Programa encerrado! \n ");
        return 0;
    }

    printf("\n --- LISTAR TODOS OS TITULOS --- \n");
    int desejaListar = respostaParaUmaPergunta(
        "Deseja listar todos os titulos ?"
    ); 

    if (desejaListar == 1)
    {
        listarTitulos(
            codigos,
            estoques,
            descricao1,
            descricao2,
            descricao3,
            qtdTitulos
        );
    } else {
        printf("Nenhum livro listado. \n");
    }
    

    return 0;
}