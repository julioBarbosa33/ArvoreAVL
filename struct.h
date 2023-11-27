/* -----------------  Nodo  ------------------- */

typedef struct Nodo
{

    int numeroNodo;

    short nivelNodo;

    short grauNodo;

    short alturaNodo;

    struct Nodo *filhoDireita;

    short alturaDireita;

    struct Nodo *filhoEsquerda;

    short alturaEsquerda;

    short fatorBalanceamento;

} Nodo;

/* -------------------------------------------- */