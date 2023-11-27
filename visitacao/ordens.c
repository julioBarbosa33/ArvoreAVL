void preOrdem (nodo *endNodo){
if (nodo != NULL)
{
    printf("%d", endNodo->numeroNodo);
    preOrdem(endNodo->filhoEsquerda);
    preOrdem(endNodo->filhoDireita);
}
}

void emOrdem (nodo *endNodo){
if (nodo != NULL)
{
    emOrdem(endNodo->filhoEsquerda);
    printf("%d", endNodo->numeroNodo);
    emOrdem(endNodo->filhoDireita);
}    
}

void posOrdem (nodo *endNodo){
if (nodo != NULL)
{
    posOrdem(endNodo->filhoEsquerda);
    posOrdem(endNodo->filhoDireita);
    printf("%d", endNodo->numeroNodo);
}    
}

//colocar dentro da int main

    printf("Pre-Ordem: ");
    preOrdem(endNodo);
    printf("\n");

    printf("Em Ordem: ");
    emOrdem(endNodo);
    printf("\n");

    printf("Pos-Ordem: ");
    posOrdem(endNodo);
    printf("\n");