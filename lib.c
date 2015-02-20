#include "lib.h"

TLista * inicializa(void){
	return NULL;
}

TLista *ins_ini(TLista *l, int elem){
	TLista* novo = (TLista*) malloc (sizeof(TLista));
	novo->info=elem;
	novo->prox=l;
	return novo;
}

void imprime(TLista *l){
	TLista *p = l;
	while(p){
		printf("%d",p->info);
		p=p->prox;
	}
	printf("\n");
}

void imprimeComEspacamento(TLista *l){
	TLista *p = l;
	while(p){
		printf("%d  ",p->info);
		p=p->prox;
	}
	printf("\n");
}

void libera(TLista* l){
	TLista *p=l;
	while(p){
		TLista *q = p;
		p=p->prox;
		free(q);
	}
}

TLista* busca(TLista*l,int elem){
	TLista* p = l;
	while((p)&&(p->info!=elem))
		p = p->prox;
	return p;
}

//retira zero a esquerda

TLista * retirazero(TLista *lista) {
    TLista *pCopia, *p, *q;

    if (lista == NULL) return NULL;
    else {
        p = lista;
        while (p!=NULL && p->info == 0) p = p->prox;

        if (p == NULL) return NULL;
        q = lista;
        while (q != p) {
            pCopia = q;
            q = q->prox;
            free(pCopia);
        }
        return q;
    }
}

//insere na utlima posicao
TLista * ins_ult (TLista *l, int elem) {
    if (!l) {
        return ins_ini(l, elem);
    }
    TLista *novo = (TLista *) malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL;
    TLista *p = l;  //ponteiro p aponta para inicio lista l

    //enquanto for diferente de nulo eu vou andar com eele
    while (p->prox) {
        p = p->prox;
    }
    //encontrou o lugar correto e aponta para o novo
    p->prox = novo;
    return l;
}

TLista * ins_ord(TLista * l, int elem) {
    TLista * p = l, *ant = NULL;

    //enquanto  existir
    while((p) && (p->info < elem)) {
        ant = p;
        p = p->prox;
    }
    if (!ant) {
     return ins_ini(l, elem);
    } else {
        TLista * novo = (TLista *) malloc(sizeof(TLista));
        novo->info = elem;
        novo->prox = p;
        ant->prox = novo;
        return l;
    }

}

TLista * inverte (TLista* l) {
    TLista *nova = inicializa();

    while (l != NULL) {
        // Remove o elemento da lista antiga.
        TLista *elemento = l;
        l = l->prox;

        // Insere o elemento na nova lista.
        elemento->prox = nova;
        nova = elemento;
    }

    return nova;

}

int tamanhoListaEncadeada(TLista*l){
	int contador = 0;
	TLista* p = l;
	while(p != NULL) {
        p = p->prox;
        contador++;
	}
    return contador;
}

/*
	A função compara os dígitos de duas listas.
	Retorna:
	-1 se a primeira lista é menor que a segunda;
	 0 se as listas são iguais
	 1 se a primeira lista é maior que a segunda;
 */


int compara(TLista * primeiro, TLista * segundo) {
	int n;

	if (primeiro!=NULL && segundo!=NULL){
		n = compara(primeiro->prox, segundo->prox);
		if (n==0) {
			if (primeiro->info < segundo->info) {
                n=-1;
			} else if (primeiro->info > segundo->info) {
                n = 1;
			} else {
                n = 0;
			}
        }
		return n;
        } else if (primeiro == NULL && segundo !=NULL) {
            return -1;
        } else if(primeiro != NULL && segundo == NULL) {
            return 1;
        } else {
            return 0;
        }
}

/**
Esta função recebe duas listas de inteiros encadeadas e faz a soma entre eles.
Entrada: 2 listas encadeadas
Saída: 1 lista contendo a soma entre eles;

Exemplo:
primeiro = 12346    = 1 -> 2 -> 3 -> 4 -> 6
segundo = 25        = 2 -> 5
____________________________________________
resultado = 12371   = 1 -> 2 -> 3 -> 7 -> 1

*/
TLista * adicao(TLista * primeiro, TLista * segundo) {
  TLista *resultado = inicializa();

  TLista * p = primeiro;
  TLista * s = segundo;

  int numeroPrimeiro = 0;
  int numeroSegundo = 0;
  int vaiUm = 0;
  int resultadoSoma;

  while ((p != NULL) || (s != NULL)) {

    if (p != NULL) {
        numeroPrimeiro = p->info;
        p = p->prox;
    } else {
        numeroPrimeiro = 0;
    }

    if (s != NULL) {
        numeroSegundo = s->info;
        s = s->prox;
    } else {
        numeroSegundo = 0;
    }

    resultadoSoma = (numeroPrimeiro + numeroSegundo + vaiUm) % 10;
    vaiUm = (numeroPrimeiro + numeroSegundo + vaiUm) / 10;
    //printf("\n\nO resultado da soma e %d. Numero primeiro: %d. Numero segundo: %d",resultadoSoma, numeroPrimeiro,numeroSegundo);
    resultado = ins_ini(resultado, resultadoSoma);
  }

//printf("\n\nVaim um: %d", vaiUm);
  if (vaiUm != 0) {
    resultado = ins_ini(resultado, vaiUm);
  }
  return resultado;
}

/**
Esta função recebe duas listas de inteiros encadeadas e faz a subtração entre elas.
Entrada: 2 listas encadeadas
Saída: 1 lista contendo a diferença entre eles;

Exemplo:
primeiro = 12346    = 1 -> 2 -> 3 -> 4 -> 6
segundo = 25        = 2 -> 5
____________________________________________
resultado = 12321   = 1 -> 2 -> 3 -> 2 -> 1

*/

TLista * subtracao(TLista * primeiro, TLista * segundo) {
  TLista *resultado = inicializa();

  int numeroPrimeiro = 0;
  int numeroSegundo = 0;
  int vaiUm = 0;
  int resultadoDif;


    TLista * p = primeiro;
    TLista * s = segundo;


  //enquanto a primeira lista não for null
  while (p != NULL) {
    //p e diferente de NULL
    numeroPrimeiro = p->info;
    p = p->prox;

    if (s != NULL) {
        numeroSegundo = s->info;
        s = s->prox;
    } else {
        numeroSegundo = 0;
    }
    //printf("\n====>Primeiro numero: %d | Segundo Numero: %d | Vai um %d | ", numeroPrimeiro, numeroSegundo, vaiUm);
    resultadoDif = numeroPrimeiro - numeroSegundo - vaiUm;
    //printf("Resultado dif: %d", resultadoDif);
    if (resultadoDif < 0) {
        vaiUm = 1;
        resultadoDif += 10;
    } else{ vaiUm = 0;}
    //printf(" | Resultado dif FINAL: %d\n\n", resultadoDif);
    resultado = ins_ini(resultado, resultadoDif);
  }

  resultado = retirazero(resultado);


  return resultado;
}


TLista * multiplicacao(TLista * primeiro, TLista * segundo) {
   int numeroPrimeiro = 0;
    int numeroSegundo = 0;
    int vaiN = 0;
    int resultadoMult;

    int i, x;
    TLista * p = primeiro;
    TLista * s = segundo;

    //a lista menor que define o numero de elementos que serao armazenados para a soma posterior
    int tamanhoListaMenor = tamanhoListaEncadeada(segundo);
    //cria um array de TLista para armazenar os elementos intermediários

    TLista * resultadoTemp[tamanhoListaMenor];

  i = 0;
  //enquanto a primeira lista não for null
  while (s != NULL) {
    //p e diferente de NULL
    numeroPrimeiro = s->info;
    s = s->prox;

    resultadoTemp[i] = inicializa();

    if (i > 0) {
        for (x = 1; x <=i ; x++) {
            resultadoTemp[i]  = ins_ini(resultadoTemp[i], 0);
        }
    }


    while (p != NULL) {
        numeroSegundo = p->info;
        p = p->prox;


        resultadoMult = ((numeroPrimeiro * numeroSegundo) + vaiN ) % 10;
        vaiN  = ((numeroPrimeiro * numeroSegundo) + vaiN ) / 10;

        resultadoTemp[i]  = ins_ini(resultadoTemp[i], resultadoMult);

    }
//a cada iteração faz o ponteiro voltar ao início da lista
    if (vaiN != 0) {
        resultadoTemp[i]  = ins_ini(resultadoTemp[i], vaiN);
    }

//printf("Imprime resultadoTemp...");
//imprime(resultadoTemp[i]);

    vaiN = 0;
    p = primeiro;
    i++;
  }

   /*   for (x = 0; x < i; x++) {
        printf("\nImprime indice %d => ", x);
        imprime(resultadoTemp[x]);
      }*/

    TLista *resultado = NULL;
    if (tamanhoListaMenor == 1) {
            resultado = resultadoTemp[0];

            for (x = 1; x < i; x++) {
                resultado = (x == 1) ? resultado : inverte(resultado);
                resultado = adicao(resultado, inverte(resultadoTemp[x]));
            }
    } else {
            resultado = inverte(resultadoTemp[0]);

            for (x = 1; x < i; x++) {
                resultado = (x == 1) ? resultado : inverte(resultado);
                resultado = adicao(resultado, inverte(resultadoTemp[x]));
            }
    }
  return resultado;
}


/**

Esta função recebe duas listas de inteiros encadeadas e faz a divisao entre elas.
Entrada: 2 listas encadeadas
Saída: 1 lista contendo o quoeficiente entre eles;

Exemplo:
primeiro = 2825     = 2 -> 8 -> 2 -> 5
segundo  =   15     =           1 -> 5
____________________________________________
resultado = 188     = 1 -> 8 -> 8

*/

TLista * divisao(TLista * primeiro,long int segundo) {

  TLista *quociente = inicializa();
  TLista * p = primeiro;
  long int numeroDividendo,resto=0;//,x;
  //if (segundo==0) return p;
   while(p != NULL){
    numeroDividendo = p->info;
    p = p->prox;

    resto = resto*10 + numeroDividendo;

    if (resto < segundo){
            quociente=ins_ult(quociente,0);


    }else{

      quociente=ins_ult(quociente,(resto/segundo));
      resto = resto % segundo; //resto da divisao
    }
  }


  quociente = retirazero(quociente);

  return quociente;
}



/*
*
*
*   Tentativa que não deu certo
*
*

TLista * divisaoComListas(TLista * primeiro, TLista * segundo) {
  TLista *quociente = inicializa();

  TLista * temp = inicializa();
  temp = ins_ult(temp,0);

  TLista * dez = inicializa();
  dez = ins_ult(dez, 10);

  TLista * numeroDividendoTLista = inicializa();

  int numeroDividendo;
  int numeroSegundo = 0;
  int vaiUm = 0;
  int resultadoDif;
  int quocienteManual = 0;

  TLista * p = primeiro;
  TLista * s = segundo;

   while(p != NULL){
    numeroDividendo = p->info;
    p = p->prox;
    numeroDividendoTLista = ins_ult(numeroDividendoTLista, numeroDividendo);


//printf("\nImprimindo temp");
//imprime(temp);

    temp = multiplicacao(temp, dez);
//printf("\nImprimindo temp");
//imprime(temp);

    if (tamanhoListaEncadeada(temp) != 1) {
        temp = inverte(temp);
    }
    temp = adicao(temp, numeroDividendoTLista); //parece que nao esta inserindo o 8 adequdamente
//printf("\nImprimindo temp");
//imprime(temp);
//getch();

    if (compara(temp, segundo) == -1) {

//printf("\nA lista temp "); imprime(temp);
//printf("\nA lista segundo "); imprime(segundo);
//printf("Imprimindo quociente apos insercao de 0...");imprime(quociente);
        quociente=ins_ult(quociente,0);
//printf("Imprimindo quociente apos insercao de 0...");imprime(quociente);

    } else {
        segundo = inverte(segundo);
//printf("A lista maior "); imprime(temp);
//printf("A lista menor "); imprime(segundo);
//printf("Diferenca entre a maior (temp) - menor (segundo) ");imprime(subtracao(temp, segundo));
      quocienteManual = verificaQuocienteManual(temp,segundo);
printf("\nO valor do quocienteManual %d ", quocienteManual);
printf("\nO valor da lista quociente antes da insercao \n");imprime(quociente);
      quociente=ins_ult(quociente,quocienteManual);
printf("\nO valor da lista quociente depois da inserção do quocienteManual \n");imprime(quociente);

      temp = verificaModManual(temp,segundo, quocienteManual);

printf("\nO valor da lista temp ");imprime(temp);
    }

    numeroDividendoTLista = inicializa();
  }

  return quociente;
}

TLista * verificaModManual(TLista * primeiro, TLista * segundo, int quociente) {
printf("\n\nDentro do mod manual "); imprime(primeiro);imprime(segundo);
    TLista * p = primeiro;
    TLista * q = inicializa();
    q = ins_ini(q, quociente);

    TLista * temp = multiplicacao(segundo, quociente);
printf("\n\nDentro do mod manual valor da multiplicação"); imprime(temp);
    temp = subtracao(p,temp); //sempre positivo
    printf("\n\nDentro do mod manual valor da mod"); imprime(temp);
    return temp;
}

//exemplo 2825 com 15...primeiro caso 2, segundo caso 28....respo
int verificaQuocienteManual(TLista * primeiro, TLista * segundo) {
printf("\n\nDentro do quociente manual "); imprime(primeiro);imprime(segundo);
    int i = 1;
    TLista * temp = inicializa();

    TLista * s = segundo;
    TLista *p = primeiro;

    //primeira lista é maior que a segunda
    while(compara(p, s) == 1) {
        temp = ins_ini(temp, i);
printf("\n\nWHILE Quociente manual: BEFORE multiplicação s e temp "); imprime(s); imprime(temp);
        //s = inverte(s);
        s = multiplicacao(s, temp);
printf("\n\nWHILE Quociente manual: AFTER multiplicação s e temp "); imprime(s); imprime(temp);
        //s = inverte(s);
printf("\n\nWHILE Quociente manual: Imprime resultado multiplicacao "); imprime(s);
        temp = inicializa();
        i++;
    }
    return i - 1;
}*/

