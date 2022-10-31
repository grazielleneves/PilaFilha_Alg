#include "pila_filha.h"
#include <stdio.h>
#include <stdlib.h>

///////////////////
//////FILA/////////
///////////////////

void criar_f(t_conjunto *conjunto) {

	conjunto->primeiro = NULL;
	conjunto->ultimo = NULL;
}

int enfileirar(t_conjunto *conjunto, t_elemento elemento) {

	t_apontador novo;
    novo = (t_apontador) malloc(sizeof(t_no));

	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = NULL;
	
	if (vazia_f(conjunto)) {
		conjunto->primeiro = novo;
	} 
    else {
		conjunto->ultimo->proximo = novo;
	}
	conjunto->ultimo = novo;

	return 0;
}


int desenfileirar(t_conjunto *conjunto, t_elemento elemento) {
    //Função para remover elementos da fila (FIFO)


	if (vazia_f(conjunto)){
		return 1;
    }
	if (conjunto->primeiro->elemento.chave != elemento.chave) {//elemento não existe
    	return 1;
  	}
	if (conjunto->primeiro == conjunto->ultimo){ // unitaria
		conjunto->ultimo = NULL;
    }

	t_apontador aux = conjunto->primeiro;
	conjunto->primeiro = conjunto->primeiro->proximo;
	free(aux);

	return 0;

}
int vazia_f(t_conjunto *conjunto) {
	if(conjunto->primeiro == NULL && conjunto->ultimo == NULL){
		return 1;
    }
	else{
		return 0;
    }
}
///////////////////
//////PILHA////////
///////////////////
void criar_p(t_conjunto *conjunto) {
	conjunto->topo = NULL;
}

int empilhar(t_conjunto *conjunto, t_elemento elemento) {

	t_apontador novo;
    novo = (t_apontador) malloc(sizeof(t_no));

	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = conjunto->topo;
	conjunto->topo = novo;
	
	//num_nos++;

	return 0;

}


int desempilhar(t_conjunto *conjunto, t_elemento elemento) {

	if (vazia_p(conjunto)){
		return 1;
    }
    if(conjunto->topo->elemento.chave != elemento.chave){
        return 1;
    }

	t_apontador aux = conjunto->topo;
	conjunto->topo = conjunto->topo->proximo;
	free(aux);
	return 0;
}

int vazia_p(t_conjunto *conjunto) {
	if(conjunto->topo == NULL)
		return 1;
	else
		return 0;
}
void libera_f(t_conjunto *conjunto) {//liberando fila
  t_apontador P = conjunto->primeiro;
  while (P != NULL) {
    conjunto->primeiro = P->proximo;
	free(P);
    P = conjunto->primeiro;
  }
}
void libera_p(t_conjunto *conjunto) {//liberando pilha
  t_apontador P = conjunto->topo;
  while (P != NULL) {
    conjunto->topo = P->proximo;
    free(P);
    P = conjunto->topo;
  }
}
