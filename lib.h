#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct lista {
    int info;
    struct lista *prox;
} TLista;

TLista *inicializa(void);
TLista *ins_ini(TLista *l, int elem);
void imprime(TLista *l);
void libera(TLista *l);
void imprimeComEspacamento(TLista *l);
TLista * busca (TLista *l, int elem);
TLista * retira(TLista *l, int elem);
TLista * ins_ult (TLista *l, int elem);
TLista * ins_ord(TLista * l, int elem);

TLista * inverte (TLista* l);

int tamanhoListaEncadeada(TLista*l);

TLista * adicao(TLista * primeiro, TLista * segundo);
TLista * subtracao(TLista * primeiro, TLista * segundo);
TLista * multiplicacao(TLista * primeiro, TLista * segundo);

TLista * divisao(TLista * primeiro, long int segundo);

TLista * retirazero(TLista *l);

TLista * verificaModManual(TLista * primeiro, TLista * segundo, int quociente);

int compara(TLista * primeiro, TLista * segundo);

