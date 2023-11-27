/* ------------  Funcionalidades  ------------ */

short mostrarArvoreSimplificada(Nodo *nodo, short altura);

short mostrarArvoreDetalhada(Nodo *nodo, short altura);

/* ------------------------------------------- */

// mostrarArvoreSimplificada: Implime a árvore ao usuário mostrando os nodos e seus fatores.

short mostrarArvoreSimplificada(Nodo *nodo, short altura)
{

    if (nodo == NULL)
    {

        int linhas = pow(2, altura);
        linhas = (linhas + (linhas - 2)) / 2;

        for (int i = 0; i < linhas; i++)
        {
            printf("\n\n");
        }
    }
    else
    {

        mostrarArvoreSimplificada(nodo->filhoDireita, (altura - 1));

        for (int i = 0; i < nodo->nivelNodo; i++)
        {
            printf("          ");
        }

        printf(" (%5d)%2hd\n\n", nodo->numeroNodo, nodo->fatorBalanceamento);

        mostrarArvoreSimplificada(nodo->filhoEsquerda, (altura - 1));
    }

    return 0;
}

// mostrarArvoreDetalhada: Implime a árvore em barras mostrando os dados dos nodos.

short mostrarArvoreDetalhada(Nodo *nodo, short altura)
{

    if (nodo != NULL)
    {

        printf("|  %5d |   %2hd  |   %2hd   |   %hd  |   %2hd  |     %hd    |    %hd    | ", nodo->numeroNodo, nodo->nivelNodo, nodo->alturaNodo, nodo->grauNodo, nodo->fatorBalanceamento, nodo->alturaEsquerda, nodo->alturaDireita);

        for (int i = 1; i < nodo->nivelNodo; i++)
        {
            printf("      ");
        }

        printf("%5d ", nodo->numeroNodo);

        for (short i = nodo->nivelNodo; i < altura; i++)
        {
            printf("------");
        }
        printf("|\n");

        printf("                                                                ");
        for (int i = 1; i < (altura + 1); i++)
        {
            printf("      ");
        }
        printf("|\n");

        mostrarArvoreDetalhada(nodo->filhoEsquerda, altura);
        mostrarArvoreDetalhada(nodo->filhoDireita, altura);
    }

    return 0;
}