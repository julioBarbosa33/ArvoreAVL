/* ------------ Funcionalidades ------------- */

void menu(short *opcao);

short confirmacao();

short max(short a, short b);

void opcaoInexistente();

void limparMemoria(Nodo *nodo);

void encerrarPrograma();

/* -------------------------------------------- */

// menu: Imprime as funcionalidades ao usu�rio.

void menu(short *opcao)
{

    while (1)
    {

        printf("\n-------------  MENU  -------------\n\n");
        printf("    [1] Inserir   Nodo\n");
        printf("    [2] Remover   Nodo\n");
        printf("    [3] Visitar   �rvore\n");
        printf("    [4] Mostrar   �rvore\n");
        printf("    [0] Encerrar  Software\n\n");
        printf("----------------------------------\n\n");

        printf(" </> Informe o n�mero da op��o: ");
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

            printf(" </> Informe o n�mero da op��o: ");
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

// confirmacao: Verifica se o usu�rio deseja proseguir com a a��o que escolheu.

short confirmacao()
{
    short confirmacao;
    while (1)
    {

        printf("----------------------------------\n\n");
        printf(" </> Deseja realmente seguir com est� a��o?\n\n");
        printf("    [1] Sim\n");
        printf("    [0] N�o\n\n");
        printf("----------------------------------\n\n");

        printf(" </> Informe o n�mero da op��o: ");
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

// opcaoInexistente: Alerta que a op��o informada n�o existe.

void opcaoInexistente()
{

    printf(" </> A op��o informada n�o existe!\n\n\n");

    return;
};

// limparMemoria: Libera os espa�os de mem�ria reservados para os nodos da �rvore.

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