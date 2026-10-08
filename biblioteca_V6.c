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

int menu(){
int escolha;
printf(
    "\n========== MENU ==========\n"
    "1 - Cadastrar livros\n"
    "2 - Cadastrar usuarios\n"
    "3 - Listar livros\n"
    "4 - Listar usuarios\n"
    "5 - Buscar livro\n"
    "6 - Buscar usuario\n"
    "7 - Alterar estoque\n"
    "8 - Registrar emprestimo\n"
    "9 - Encerrar emprestimo\n"
    "0 - Sair\n"
    "===========================\n"
);

    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
    
}

int cadastrarLivro(Livro livros[], int qtdLivros)
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
    printf("\n--- LISTAR LIVROS ---\n");

    if (qtdLivros == 0)
    {
        printf("Nenhum livro encontrado! Tente novamente mais tarde.\n");
        return;
    }

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
    int codigoBuscado;
    int posicao = -1;

    printf("\n--- BUSCAR LIVRO ---\n");

    if (qtdLivros == 0)
    {
        printf("Nenhum livro cadastrado!\n");
        printf("Cadastre um livro antes de realizar uma busca.\n");
        return;
    }

    printf("Digite o codigo do livro que deseja buscar: ");
    scanf("%d", &codigoBuscado);

    while (codigoBuscado < 0)
    {
        printf("Codigo invalido!\n");
        printf("Digite um codigo valido: ");
        scanf("%d", &codigoBuscado);
    }

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

void buscarUsuario(Usuario usuarios[], int qtdUsuarios){
    int codigoBuscado;
    int posicao = -1;

    printf("\n --- BUSCAR USUARIOS --- \n");

    if(qtdUsuarios == 0){
        printf("Nenhum usuario cadastrado! \n");
        printf("Cadastre um usuario antes de realizar uma busca \n");
    }

    printf("Digite o codigo do usuario que deseja buscar \n");
    scanf("%d", &codigoBuscado);

    while (codigoBuscado < 0)
    {
        printf("Codigo invalido!\n");
        printf("Digite um codigo valido: ");
        scanf("%d", &codigoBuscado);
    }

    for (int i = 0; i < qtdUsuarios; i++)
    {
        if (usuarios[i].codigo == codigoBuscado)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        printf("\nUsuario encontrado!\n");
        printf("Codigo: %d\n", usuarios[posicao].codigo);
        printf("Descricao: %s", usuarios[posicao].dados);
    }
    else
    {
        printf("\nUsuario nao encontrado!\n");
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
    printf("\n--- LISTAR USUARIOS ---\n");

    if (qtdUsuarios == 0)
    {
        printf("Nenhum usuario encontrado! Tente novamente mais tarde.\n");
        return;
    }
    
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
    int escolha;

    escolha = menu();

    while (escolha != 0)
    {
        if (escolha == 1)
        {
            qtdLivros = cadastrarLivro(livros, qtdLivros);
        }
        else if (escolha == 2)
        {
            qtdUsuarios = cadastrarUsuarios(usuarios, qtdUsuarios);
        }
        else if (escolha == 3)
        {
            listarTitulos(livros, qtdLivros);
        }
        else if (escolha == 4)
        {
            listarUsuarios(usuarios, qtdUsuarios);
        }
        else if (escolha == 5)
        {
            buscarLivro(livros, qtdLivros);
        }
        else if (escolha == 6)
        {
            buscarUsuario(usuarios, qtdUsuarios);
        }
        else if (escolha == 7)
        {
            
        }
        else if (escolha == 8)
        {
            
        }
        else if (escolha == 9)
        {
          
        }
        else
        {
            printf("Opcao invalida!\n");
            printf("Tente novamente.\n");
        }

        escolha = menu();
    }

    printf("Saindo do programa...\n");

    return 0;
}