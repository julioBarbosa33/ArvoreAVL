/* ------------ Funcionalidades ------------- */

void menu(short *opcao);

short confirmacao();

short max(short a, short b);

void opcaoInexistente();

void limparMemoria(Nodo *nodo);

void encerrarPrograma();

/* -------------------------------------------- */

// menu: Imprime as funcionalidades ao usuário.

void menu(short *opcao)
{

    while (1)
    {

        printf("\n-------------  MENU  -------------\n\n");
        printf("    [1] Inserir   Nodo\n");
        printf("    [2] Remover   Nodo\n");
        printf("    [3] Visitar   Árvore\n");
        printf("    [4] Mostrar   Árvore\n");
        printf("    [0] Encerrar  Software\n\n");
        printf("----------------------------------\n\n");

        printf(" </> Informe o número da opção: ");
        scanf("%hd", opcao);
        printf("\n");

        if (*opcao >= 0 && *opcao < 4)
            break;

        else if (*opcao == 4)
        {

            printf("----------------------------------\n\n");
            printf("    [5] Convencional  Simplificada\n");
            printf("    [6] Em Barras     Detalhada\n");
            printf("    [0] Voltar\n\n");
            printf("----------------------------------\n\n");

            printf(" </> Informe o número da opção: ");
            scanf("%hd", opcao);
            printf("\n");

            if (*opcao >= 5 && *opcao < 8)
                break;

            else if (*opcao == 0)
                continue;
        }

        opcaoInexistente();
    };

    return;
}

// confirmacao: Verifica se o usuário deseja proseguir com a ação que escolheu.

short confirmacao()
{
    short confirmacao;
    while (1)
    {

        printf("----------------------------------\n\n");
        printf(" </> Deseja realmente seguir com está ação?\n\n");
        printf("    [1] Sim\n");
        printf("    [0] Não\n\n");
        printf("----------------------------------\n\n");

        printf(" </> Informe o número da opção: ");
        scanf("%hd", &confirmacao);
        printf("\n");

        if (confirmacao > -1 && confirmacao < 2)
            break;

        opcaoInexistente();
    };

    return confirmacao;
}

// max: Encontra o maior valor passado por parametro.

short max(short a, short b)
{
    return (a > b) ? a : b;
}

// opcaoInexistente: Alerta que a opção informada não existe.

void opcaoInexistente()
{

    printf(" </> A opção informada não existe!\n\n\n");

    return;
};

// limparMemoria: Libera os espaços de memória reservados para os nodos da árvore.

void limparMemoria(Nodo *nodo)
{

    if (nodo != NULL)
    {
        limparMemoria(nodo->filhoEsquerda);
        limparMemoria(nodo->filhoDireita);
        free(nodo);
    }

    return;
};

// encerrarPrograma: Despedida.

void encerrarPrograma()
{

    printf(" </> Agradecemos por utilizar nosso software.\n\n\n");

    return;
};