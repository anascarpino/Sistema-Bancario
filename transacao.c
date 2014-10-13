#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transacao.h"

/* DEFINIÇÃO DAS ESTRUTURAS */
struct listatransacao{
  Transacao* prim;
  Transacao* ult;
};

struct transacao{
  char* nome;
  int quantia;
  struct transacao* prox;
};

/* FUNÇÕES DE CRIAÇÃO E INICIALIZAÇÃO*/
ListaTransacao* criaListaTransacao(){
  ListaTransacao* l = (ListaTransacao*)malloc(sizeof(ListaTransacao));
  l->prim = NULL;
  l->ult = NULL;
  return l;
}

Transacao* deposito(int quantia){
  Transacao* nova = (Transacao*)malloc(sizeof(Transacao));
  nova->nome = "DEPOSITO";
  nova->quantia = quantia;
  nova->prox = NULL;
  return nova;
}

Transacao* saque(int quantia){
  Transacao* nova = (Transacao*)malloc(sizeof(Transacao));
  nova->nome = "RETIRADA";
  nova->quantia = quantia;
  nova->prox = NULL;
  return nova;
}

/* FUNÇÃO DE INSERÇÃO */
void insereTransacao(ListaTransacao* l, Transacao* t){
  if(l->prim == NULL){
    l->prim = t;
    l->ult = t;
    return;
  }
  l->ult->prox = t;
  l->ult = t;
}

/* FUNÇÕES DE IMPRESSÃO */
void imprimeTransacao(Transacao* t){
  printf("      %s %d\n", t->nome, t->quantia);
}

void imprimeListaTransacao(ListaTransacao* l){
  Transacao* aux;
  if(l->prim==NULL){
    printf("      Nenhuma movimentacao\n");
    return;
  }
  for(aux=l->prim; aux!=NULL; aux=aux->prox){
    imprimeTransacao(aux);
  }
}

/* FUNÇÕES DE LIBERAÇÃO DE MEMÓRIA */
void liberaTransacao(Transacao* t){
  free(t);
}

void liberaListaTransacao(ListaTransacao* l){
  Transacao* aux;	
  for(aux=l->prim;aux!=NULL;aux=aux->prox){
    liberaTransacao(aux);
  }
  free(l);
}