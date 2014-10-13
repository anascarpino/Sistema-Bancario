#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"


#define CONJUNTA 0
#define INDIVIDUAL 1

/* DEFINIÇÃO DAS ESTRUTURAS */
struct listaconta{
  Conta* prim;
  Conta* ult;
};

struct conta{
  int num;
  int saldo;
  int info; //se é conjunta ou não
  ListaTransacao* transacao;
  struct conta* prox;
};


/* FUNÇÕES DE CRIAÇÃO E INICIALIZAÇÃO */
Conta* criaConta(int conta){
  Conta* c = (Conta*)malloc(sizeof(Conta));
  c->num = conta;
  c->saldo = 0;
  c->info = INDIVIDUAL;
  c->transacao = criaListaTransacao();
  c->prox = NULL;
  return c;
}

Conta* criaContaConjunta(int conta){
  Conta* c = (Conta*)malloc(sizeof(Conta));
  c->num = conta;
  c->saldo = 0;
  c->info = CONJUNTA;
  c->transacao = criaListaTransacao();
  c->prox = NULL;
  return c;
}

ListaConta* criaListaConta(){
  ListaConta* l = (ListaConta*)malloc(sizeof(ListaConta));
  l->prim = NULL;
  l->ult = NULL;
  return l;
}


/* FUNÇÃO DE BUSCA */
Conta* buscaConta(ListaConta* l, int conta){
  Conta* aux;	
  for(aux = l->prim; aux!=NULL; aux=aux->prox){
    if(aux->num == conta){
      return aux;
    }
  }
  return NULL;
}


/* FUNÇÃO DE INSERÇÃO */
int insereConta(ListaConta* l, Conta* c){
  if(l->prim == NULL){
    l->prim = c;
    l->ult = c;
    return 1;
  }
  Conta* aux = buscaConta(l, c->num);
  if(aux==NULL){
    l->ult->prox = c;
    l->ult = c;
    return 1;
  }else{
    printf("ERRO: Conta %d já existe ", c->num);
    return 0;
  }
}


/* FUNÇÕES DE LIBERAÇÃO DE MEMÓRIA */
void liberaConta(Conta* c){
  liberaListaTransacao(c->transacao);
  free(c);
}

void liberaListaConta(ListaConta* l){
  Conta* aux;	
  for(aux=l->prim;aux!=NULL;aux=aux->prox){
    liberaConta(aux);
  }
  free(l);	
}


/* FUNÇÕES AUXILIARES */
int getNumero(Conta* c){
  return c->num;
}

int getSaldo(Conta* c){
  return c->saldo;
}

void setSaldo(Conta* c,int i){
 c->saldo = i; 
}

ListaTransacao* getTransacao(Conta* c){
  return c->transacao;
}


/* FUNÇÃO DE EXCLUSÃO */
int excluiConta(ListaConta* l, int conta){
  Conta* ant = NULL;
  Conta* aux = l->prim;

  if(aux==NULL){ //testa se a lista está vazia
    printf("ERRO: não existe conta %d ", conta);
    return 0;
  }

  while(aux!=NULL && getNumero(aux)!=conta){
    ant = aux;
    aux = aux->prox;
  }

  if(ant==NULL){ //testa se é o primeiro elemento
   l->prim = aux->prox;
   if(aux->prox==NULL){
    l->ult = NULL;
   }
   liberaConta(aux);
   return 1;
  }
  if(aux!=NULL){ //caso o cliente exista
   ant->prox = aux->prox;
   if(aux->prox==NULL){ // testa se é o ultimo elemento
    l->ult = ant;	
   }
   liberaConta(aux);
   return 1;
  }else{
    printf("ERRO: não existe conta %d ", conta);
    return 0;
  }
}


/* FUNÇÕES DE IMPRESSÃO */
void imprimeConta(Conta* c){
  printf("    CONTA %d\n", c->num);
}

void imprimeListaConta(ListaConta* l){
  if(l->prim==NULL){
    printf("   Nenhuma conta\n");
    return;
  }
  Conta* aux;
  for(aux=l->prim; aux!=NULL; aux=aux->prox){
    imprimeConta(aux);
  }
}
