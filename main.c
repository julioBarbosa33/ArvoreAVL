/* ------------ Include / Import ------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#include "struct.h"
#include "adicionais.c"

//#include "insercao/"
//#include "fatorBalanceamento/"
//#include "balanceandoEsquerda/rotacaoSimples"
//#include "balanceandoDireita/rotacaoSimples"
//#include "balanceandoEsquerda/rotacaoDupla"
//#include "balanceandoDireita/rotacaoDupla"
//#include "remocao/"
//#include "visitacao/"
#include "apresentacao/apresentacao.c"

/* -------------------------------------------- */

/* ------------ Funcionalidades ------------- */

int main();

short verificarArvoreVazia(Nodo *nodo);

Nodo *alocarNodo();

Nodo *verificarExistenciaNodo(Nodo *nodo, int alvo);

void construirNodo(Nodo **pRaiz, Nodo *nodo);

void alterarDadosNodo(Nodo *nodo, short nivel);

void buscarNodoDesbalanceado(Nodo **alvo, short *rotacao, Nodo *nodo);

void encontrarPaiNodo(Nodo **pai, short *lado, int numero, Nodo *nodo);

void balancearArvore(Nodo **pRaiz);

void removerNodo(Nodo **pRaiz);

/* -------------------------------------------- */

// main: Função principal.

int main()
{

    setlocale(LC_ALL, "Portuguese");

    short opcao = -1;
    Nodo *pRaiz = NULL;
    Nodo *novoNodo = NULL;

    while (opcao != 0)
    {

        menu(&opcao);

        switch (opcao)
        {

        case 1:

            if (!confirmacao())
                continue;

            printf(" </> Alocando nodo.\n");
            novoNodo = alocarNodo();

            if (novoNodo)
            {
                printf(" </> Nodo alocado.\n");
                printf(" </> Construindo nodo.\n\n");
                construirNodo(&pRaiz, novoNodo);
                printf(" </> Nodo construido.\n");
                printf(" </> Alterando dados do(s) nodo(s).\n");
                alterarDadosNodo(pRaiz, 1);
                printf(" </> Dados alterados.\n");
                printf(" </> Verificando balanceamento.\n");
                balancearArvore(&pRaiz);
                printf(" </> Verificação/balancemaneto concluído.\n");
            }
            else
                printf(" </> Não há espaço de memória disponível!\n");

            break;

        case 2:

            if (verificarArvoreVazia(pRaiz))
                printf(" </> A árvore está vazia!\n");
            else
            {
                if (!confirmacao())
                    continue;

                removerNodo(&pRaiz);

                if (!verificarArvoreVazia(pRaiz))
                {
                    printf(" </> Alterando dados do(s) nodo(s).\n");
                    alterarDadosNodo(pRaiz, 1);
                    printf(" </> Dados alterados.\n");
                    printf(" </> Verificando balanceamento.\n");
                    balancearArvore(&pRaiz);
                    printf(" </> Verificação/balancemaneto concluído.\n");
                }
            }

            break;

        case 3:

            if (verificarArvoreVazia(pRaiz))
                printf(" </> A árvore está vazia!\n");
            else
            {
                /* Função VISITCAO */ /* Função VISITCAO */ /* Função VISITCAO */ /* Função VISITCAO */ /* Função VISITCAO */
                printf(" </> Pré-ordem: ");
                preOrdem(pRaiz);
                printf("\n");

                printf(" </> Em-ordem.: ");
                emOrdem(pRaiz);
                printf("\n");

                printf(" </> Pós-ordem: ");
                posOrdem(pRaiz);
                printf("\n\n\n");
            }

            break;

        case 5:

            if (verificarArvoreVazia(pRaiz))
                printf(" </> A árvore está vazia!\n");
            else
                mostrarArvoreSimplificada(pRaiz, pRaiz->alturaNodo);

            break;

        case 6:

            if (verificarArvoreVazia(pRaiz))

                printf(" </> A árvore está vazia!\n");

            else
            {

                printf("----------------------------------------------------------------");
                for (int i = 1; i < (pRaiz->alturaNodo + 2); i++)
                    printf("------");
                printf("-\n");

                printf("| Número | Nível | Altura | Grau | Fator | Esquerda | Direita |\n");

                printf("                                                                ");
                for (int i = 1; i < (pRaiz->alturaNodo + 2); i++)
                    printf("      ");
                printf("|\n");

                mostrarArvoreDetalhada(pRaiz, (pRaiz->alturaNodo + 1));
                printf("\n");

                printf("----------------------------------------------------------------");
                for (int i = 1; i < (pRaiz->alturaNodo + 2); i++)
                    printf("------");
                printf("-\n\n\n");
            }

            break;

        case 0:

            if (pRaiz)
            {
                printf(" </> Liberando espaço de memória preenchido.\n");
                limparMemoria(pRaiz);
                printf(" </> Espaço liberado.\n");
            }
            encerrarPrograma();

            break;
        }
    }

    return 0;
}

// verificarArvoreVazia: Verifica se a árvore está vazia.

short verificarArvoreVazia(Nodo *nodo)
{

    if (nodo != NULL)
        return 0;

    else
        return 1;
};

// alocarNodo: Verifica se há espaço de memória e aloca um nodo.

Nodo *alocarNodo()
{

    Nodo *ponteiroNovo = (Nodo *)malloc(sizeof(Nodo));

    return ponteiroNovo;
};

// verificarExistenciaNodo: Verifica se existe um nó com o valor passado pela variável alvo.

Nodo *verificarExistenciaNodo(Nodo *nodo, int alvo)
{

    if (nodo == NULL)
        return 0;

    else
    {

        if (nodo->numeroNodo == alvo)
            return nodo;

        else if (nodo->numeroNodo > alvo)
            return verificarExistenciaNodo(nodo->filhoEsquerda, alvo);

        else
            return verificarExistenciaNodo(nodo->filhoDireita, alvo);
    }
};

// construirNodo: Constrói o nodo colocando dados dentro do mesmo.

void construirNodo(Nodo **pRaiz, Nodo *nodo)
{

    while (1)
    {
        printf(" </> Informe um número de até 4 dígitos para o nodo: ");
        scanf("%d", &nodo->numeroNodo);
        printf("\n");

        if (verificarExistenciaNodo(*pRaiz, nodo->numeroNodo))
            printf(" </> Já existe um nodo com este número!\n\n");
        else
            break;
    }

    printf(" </> Inserindo nodo na árvore.\n");
    nodo->nivelNodo = /* Função INSERCAO */ /* Função INSERCAO */ /* Função INSERCAO */ /* Função INSERCAO */ /* Função INSERCAO */ + 1;
    printf(" </> Nodo inserido.\n");

    nodo->grauNodo = 0;

    nodo->alturaNodo = 1;

    nodo->filhoDireita = NULL;

    nodo->alturaDireita = 0;

    nodo->filhoEsquerda = NULL;

    nodo->alturaEsquerda = 0;

    nodo->fatorBalanceamento = 0;

    return;
};

// alterarDadosNodo: Irá alterar os dados de cada nodo.

void alterarDadosNodo(Nodo *nodo, short nivel)
{

    if (nodo != NULL)
    {

        nodo->nivelNodo = nivel;

        if (nodo->filhoEsquerda != NULL && nodo->filhoDireita != NULL)
            nodo->grauNodo = 2;

        else if (nodo->filhoEsquerda != NULL || nodo->filhoDireita != NULL)
            nodo->grauNodo = 1;

        else
            nodo->grauNodo = 0;

        printf(" </> Calculando fator de balanceamento.\n");
        nodo->fatorBalanceamento = /* Função FATORBALANCEAMENTO */ /* Função FATORBALANCEAMENTO */ /* Função FATORBALANCEAMENTO */ /* Função FATORBALANCEAMENTO */ /* Função FATORBALANCEAMENTO */
        printf(" </> Fator calculado.\n");

        nodo->alturaNodo = max(nodo->alturaEsquerda, nodo->alturaDireita) + 1;

        alterarDadosNodo(nodo->filhoEsquerda, (nivel + 1));
        alterarDadosNodo(nodo->filhoDireita, (nivel + 1));
    }

    return;
};

// buscarNodoDesbalanceado: Procura nodos desbalanceados.

void buscarNodoDesbalanceado(Nodo **alvo, short *rotacao, Nodo *nodo)
{

    if (nodo)
    {
        if (nodo->fatorBalanceamento == -2)
        {

            if (nodo->filhoEsquerda->fatorBalanceamento == -2 || nodo->filhoEsquerda->fatorBalanceamento == 2)
                buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoEsquerda);
            else
            {
                (*alvo) = nodo;
                if (nodo->filhoEsquerda->fatorBalanceamento == -1)
                    *rotacao = 1;
                else
                    *rotacao = 2;

                return;
            }
        }
        else if (nodo->fatorBalanceamento == 2)
        {

            if (nodo->filhoDireita->fatorBalanceamento == -2 || nodo->filhoDireita->fatorBalanceamento == 2)
                buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoDireita);
            else
            {
                (*alvo) = nodo;
                if (nodo->filhoDireita->fatorBalanceamento == -1)
                    *rotacao = -2;
                else
                    *rotacao = -1;

                return;
            }
        }
        else
        {
            buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoEsquerda);
            buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoDireita);
        }
    }

    return;
};

// encontrarPaiNodo: Encontra o pai do nodo.

void encontrarPaiNodo(Nodo **pai, short *lado, int numero, Nodo *nodo)
{

    if (nodo->numeroNodo != numero)
    {

        if (nodo->filhoEsquerda->numeroNodo == numero)
        {

            (*pai) = nodo;
            *lado = -1;
            return;
        }
        else if (nodo->filhoDireita->numeroNodo == numero)
        {

            (*pai) = nodo;
            *lado = 1;
            return;
        }
        else
        {

            if (nodo->numeroNodo > numero)
                return encontrarPaiNodo(pai, lado, numero, nodo->filhoEsquerda);
            else
                return encontrarPaiNodo(pai, lado, numero, nodo->filhoDireita);
        }
    }
    else
    {
        (*pai) = NULL;
        *lado = 0;
        return;
    }
};

// balancearArvore: Irá chamar a rotação para balancear a árvore.

void balancearArvore(Nodo **pRaiz)
{
    Nodo *pai = NULL;
    Nodo *alvo = NULL;
    short lado;
    short rotacao;

    printf(" </> Buscando nodos desbalanceados.\n");
    buscarNodoDesbalanceado(&alvo, &rotacao, (*pRaiz));

    if (alvo)
    {
        printf(" </> Nodo encontrado.\n");
        printf(" </> Buscando pai do nodo.\n");
        encontrarPaiNodo(&pai, &lado, alvo->numeroNodo, (*pRaiz));

        if ((*pRaiz) != alvo)
        {
            printf(" </> Pai do nodo encontrado\n\n");
            printf(" </> Pai....: %d.\n", pai->numeroNodo);
            printf(" </> Alvo...: %d.\n", alvo->numeroNodo);
            printf(" </> Lado...: %hd.\n", lado);
            printf(" </> Rotação: %hd.\n", rotacao);

            if (lado == -1)
            {
                if (rotacao == -2)
                {
                    pai->filhoEsquerda = /* Função RDE */ /* Função RDE */ /* Função RDE */ /* Função RDE */ /* Função RDE */
                    printf(" </> RDE para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else if (rotacao == -1)
                {
                    pai->filhoEsquerda = /* Função RSE */ /* Função RSE */ /* Função RSE */ /* Função RSE */ /* Função RSE */ 
                    printf(" </> RSE para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }

                else if (rotacao == 1)
                {
                    pai->filhoEsquerda = /* Função RSD */ /* Função RSD */ /* Função RSD */ /* Função RSD */ /* Função RSD */ 
                    printf(" </> RSD para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else
                {
                    pai->filhoEsquerda = /* Função RDD */ /* Função RDD */ /* Função RDD */ /* Função RDD */ /* Função RDD */ 
                    printf(" </> RDD para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
            }
            else if (lado == 1)
            {
                if (rotacao == -2)
                {
                    pai->filhoDireita = /* Função RDE */ /* Função RDE */ /* Função RDE */ /* Função RDE */ /* Função RDE */
                    printf(" </> RDE para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else if (rotacao == -1)
                {
                    pai->filhoDireita = /* Função RSE */ /* Função RSE */ /* Função RSE */ /* Função RSE */ /* Função RSE */ 
                    printf(" </> RSE para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }

                else if (rotacao == 1)
                {
                    pai->filhoDireita = /* Função RSD */ /* Função RSD */ /* Função RSD */ /* Função RSD */ /* Função RSD */ 
                    printf(" </> RSD para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else
                {
                    pai->filhoDireita = /* Função RDD */ /* Função RDD */ /* Função RDD */ /* Função RDD */ /* Função RDD */ 
                    printf(" </> RDD para %d que é filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
            }
        }
        else
        {
            printf(" </> O nodo desbalanceado é a raiz.\n\n");
            printf(" </> Raiz...: %d.\n", alvo->numeroNodo);
            printf(" </> Rotação: %hd.\n", rotacao);

            if (rotacao == -2)
            {
                *pRaiz = /* Função RDE */ /* Função RDE */ /* Função RDE */ /* Função RDE */ /* Função RDE */
                printf(" </> RDE para %d que é a raiz.\n\n", alvo->numeroNodo);
            }
            else if (rotacao == -1)
            {
                *pRaiz = /* Função RSE */ /* Função RSE */ /* Função RSE */ /* Função RSE */ /* Função RSE */ 
                printf(" </> RSE para %d que é a raiz.\n\n", alvo->numeroNodo);
            }

            else if (rotacao == 1)
            {
                *pRaiz = /* Função RSD */ /* Função RSD */ /* Função RSD */ /* Função RSD */ /* Função RSD */ 
                printf(" </> RSD para %d que é a raiz.\n\n", alvo->numeroNodo);
            }
            else
            {
                *pRaiz = /* Função RDD */ /* Função RDD */ /* Função RDD */ /* Função RDD */ /* Função RDD */ 
                printf(" </> RDD para %d que é a raiz.\n\n", alvo->numeroNodo);
            }
        }

        printf(" </> Alterando dados do(s) nodo(s).\n");
        alterarDadosNodo((*pRaiz), 1);
        printf(" </> Dados alterados.\n\n\n");
    }
    else
        printf(" </> Não há nodo(s) desbalanceado(s).\n");
};

// removerNodo: Determina o nodo e a ser balanceado e seu efeito.

void removerNodo(Nodo **pRaiz)
{
    Nodo *alvo = NULL;
    int numero;
    while (1)
    {
        printf(" </> Informe o número do nodo: ");
        scanf("%d", &numero);
        printf("\n");
        printf(" </> Buscando nodo.\n");
        alvo = verificarExistenciaNodo((*pRaiz), numero);

        if (!alvo)
            printf(" </> Não existe um nodo com este número!\n\n");
        else
            printf(" </> Nodo encontrado.\n");
        break;
    }

    Nodo *pai = NULL;
    short lado;
    printf(" </> Buscando pai do nodo.\n");
    encontrarPaiNodo(&pai, &lado, alvo->numeroNodo, (*pRaiz));

    if (pai)
    {
        printf(" </> Pai do nodo encontrado.\n");
        if (lado == -1)
            pai->filhoEsquerda = /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */
        else
            pai->filhoDireita = /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */
    }
    else
        printf(" </> O nodo a ser removido é a raiz.\n");
    (*pRaiz) = /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */ /* Função REMOCAO */

    printf(" </> Remoção do nodo concluída.\n");

    return;
};