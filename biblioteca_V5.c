#include <stdio.h>

#define MAX_LIVROS 3
#define MAX_USUARIOS 3
#define TAM_TEXTO 120

typedef struct
{
    int codigo;
    char descricao[TAM_TEXTO];
    int estoque;
} Livro;

typedef struct
{
    int codigo;
    char dados[TAM_TEXTO];
    int codigoLivroEmprestado;
} Usuario;

Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];


int respostaParaUmaPergunta(char pergunta[])
{
    char resposta;

    while (1)
    {
        printf("%s (S/N): ", pergunta);
        scanf(" %c", &resposta);

        if (resposta == 'S' || resposta == 's')
        {
            return 1;
        }
        else if (resposta == 'N' || resposta == 'n')
        {
            return 0;
        }
        else
        {
            printf("Resposta invalida! Digite S ou N.\n");
        }
    }
}


int cadastrarTitulo(Livro livros[], int qtdLivros)
{
    int repetidos;

    while (qtdLivros < MAX_LIVROS)
    {
        printf("\n--- CADASTRE UM LIVRO ---\n");

        repetidos = 0;

        printf("Digite o codigo do livro que deseja cadastrar: ");
        scanf("%d", &livros[qtdLivros].codigo);

        for (int i = 0; i < qtdLivros; i++)
        {
            if (livros[qtdLivros].codigo == livros[i].codigo)
            {
                repetidos = 1;
            }
        }

        while (livros[qtdLivros].codigo < 0 || repetidos == 1)
        {
            printf("Codigo invalido ou repetido!\n");
            printf("Por favor, insira um novo codigo: ");

            scanf("%d", &livros[qtdLivros].codigo);

            repetidos = 0;

            for (int i = 0; i < qtdLivros; i++)
            {
                if (livros[qtdLivros].codigo == livros[i].codigo)
                {
                    repetidos = 1;
                }
            }
        }

        getchar();

        printf("Digite a descricao para esse livro: ");
        fgets(livros[qtdLivros].descricao, TAM_TEXTO, stdin);

        printf("Digite a quantidade em estoque desse livro: ");
        scanf("%d", &livros[qtdLivros].estoque);

        while (livros[qtdLivros].estoque < 0)
        {
            printf("O estoque nao pode ser menor que 0!\n");
            printf("Tente novamente: ");

            scanf("%d", &livros[qtdLivros].estoque);
        }

        qtdLivros++;

        printf("Livro cadastrado com sucesso!\n");
    }

    return qtdLivros;
}


int cadastrarUsuarios(Usuario usuarios[], int qtdUsuarios)
{
    int repetidos;

    while (qtdUsuarios < MAX_USUARIOS)
    {
        printf("\n--- CADASTRE UM USUARIO ---\n");

        repetidos = 0;

        printf("Digite o codigo desse usuario: ");
        scanf("%d", &usuarios[qtdUsuarios].codigo);

        for (int i = 0; i < qtdUsuarios; i++)
        {
            if (usuarios[qtdUsuarios].codigo == usuarios[i].codigo)
            {
                repetidos = 1;
            }
        }

        while (usuarios[qtdUsuarios].codigo < 0 || repetidos == 1)
        {
            printf("Codigo invalido ou repetido!\n");
            printf("Por favor, insira um novo codigo: ");

            scanf("%d", &usuarios[qtdUsuarios].codigo);

            repetidos = 0;

            for (int i = 0; i < qtdUsuarios; i++)
            {
                if (usuarios[qtdUsuarios].codigo == usuarios[i].codigo)
                {
                    repetidos = 1;
                }
            }
        }

        getchar();

        printf("Digite os dados do usuario (Nome, CPF etc): ");
        fgets(usuarios[qtdUsuarios].dados, TAM_TEXTO, stdin);

        usuarios[qtdUsuarios].codigoLivroEmprestado = -1;

        qtdUsuarios++;

        printf("Usuario cadastrado com sucesso!\n");
    }

    return qtdUsuarios;
}


void listarTitulos(Livro livros[], int qtdLivros)
{
    int desejaListar;

    desejaListar = respostaParaUmaPergunta(
        "Deseja listar os livros?"
    );

    if (desejaListar == 0)
    {
        return;
    }

    printf("\n--- LISTAR LIVROS ---\n");

    for (int i = 0; i < qtdLivros; i++)
    {
        printf("\nLivro %d\n", i + 1);
        printf("Codigo: %d\n", livros[i].codigo);
        printf("Descricao: %s", livros[i].descricao);
        printf("Estoque: %d\n", livros[i].estoque);
    }
}


void buscarLivro(Livro livros[], int qtdLivros)
{
    int desejaPesquisar;
    int codigoBuscado;
    int posicao;

    desejaPesquisar = respostaParaUmaPergunta(
        "\nDeseja pesquisar um livro?\n"
    );

    if (desejaPesquisar == 0)
    {
        return;
    }

    printf("\n--- BUSCAR LIVRO ---\n");

    printf("Digite o codigo do livro que deseja buscar: ");
    scanf("%d", &codigoBuscado);

    posicao = -1;

    for (int i = 0; i < qtdLivros; i++)
    {
        if (livros[i].codigo == codigoBuscado)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        printf("\nLivro encontrado!\n");
        printf("Codigo: %d\n", livros[posicao].codigo);
        printf("Descricao: %s", livros[posicao].descricao);
        printf("Estoque: %d\n", livros[posicao].estoque);
    }
    else
    {
        printf("\nLivro nao encontrado!\n");
    }
}


int calcularQtdExemplares(Livro livros[], int qtdLivros)
{
    int total = 0;

    for (int i = 0; i < qtdLivros; i++)
    {
        total += livros[i].estoque;
    }

    return total;
}


void listarUsuarios(Usuario usuarios[], int qtdUsuarios)
{
    int desejaListar;

    desejaListar = respostaParaUmaPergunta(
        "\nDeseja listar os usuarios?\n"
    );

    if (desejaListar == 0)
    {
        return;
    }

    printf("\n--- LISTAR USUARIOS ---\n");

    for (int i = 0; i < qtdUsuarios; i++)
    {
        printf("\nUsuario %d\n", i + 1);
        printf("Codigo: %d\n", usuarios[i].codigo);
        printf("Dados: %s", usuarios[i].dados);
        printf(
            "Codigo do livro emprestado: %d\n",
            usuarios[i].codigoLivroEmprestado
        );
    }
}

void alterarEstoque(Livro *livro, int valor){
    livro->estoque = valor;
}

void registrarEmprestimo(Usuario *usuario, int codigoLivro){
    usuario->codigoLivroEmprestado = codigoLivro;
}

void encerrarEmprestimo(Usuario *usuario){

}

int main()
{
    int qtdLivros = 0;
    int qtdUsuarios = 0;
    qtdLivros = cadastrarTitulo(livros, qtdLivros);
    qtdUsuarios = cadastrarUsuarios(usuarios, qtdUsuarios);
    listarTitulos(livros, qtdLivros);
    buscarLivro(livros, qtdLivros);
    listarUsuarios(usuarios, qtdUsuarios);
    printf("\nQuantidade total de exemplares: %d\n",calcularQtdExemplares(livros, qtdLivros));
    alterarEstoque(&livros[0], 1);
    printf("\nEstoque do primeiro livro: %d\n",livros[0].estoque);
    registrarEmprestimo(&usuarios[0], 101);
    printf("Livro emprestado pelo primeiro usuario: %d\n",usuarios[0].codigoLivroEmprestado);
    encerrarEmprestimo(&usuarios[0]);
    printf("Livro emprestado pelo primeiro usuario apos devolucao: %d\n",usuarios[0].codigoLivroEmprestado);
    return 0;
}
