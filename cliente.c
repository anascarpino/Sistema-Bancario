#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

#define TMAX 10

/* DEFINIÇÃO DAS ESTRUTURAS */
struct listacliente{
  Cliente* prim;
  Cliente* ult;
};

struct cliente{
  char* nome;
  Conta* vet[TMAX];
  int num;
  struct cliente* prox;
};


/* FUNÇÕES DE CRIAÇÃO E INICIALIZAÇÃO */
ListaCliente* criaListaCliente(){
  ListaCliente* l = (ListaCliente*)malloc(sizeof(ListaCliente));
  l->prim = NULL;
  l->ult = NULL;
  return l;
}

Cliente* criaCliente(char* nome){
  Cliente* cl = (Cliente*)malloc(sizeof(Cliente));
  int i;
  cl->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
  cl->nome = strcpy(cl->nome, nome);
  cl->prox = NULL;
  cl->num = 0;
  for(i=0; i<TMAX; i++){
    cl->vet[i] = NULL;
  }
  return cl;
}


/* FUNÇÃO DE BUSCA */
Cliente* buscaCliente(ListaCliente* l, char* nome){
  Cliente* aux;	
  for(aux = l->prim; aux!=NULL; aux=aux->prox){
    if(strcmp(aux->nome,nome)==0){
      return aux;
    }
  }
  return NULL;
}


/* FUNÇÃO DE INSERÇÃO */
int insereCliente(ListaCliente* l, Cliente* cl){
  if(l->prim == NULL){
    l->prim = cl;
    l->ult = cl;
    return 1;
  }
  Cliente* aux = buscaCliente(l, cl->nome);
  if(aux==NULL){
    l->ult->prox = cl;
    l->ult = cl;
    return 1;
  }else{
    printf("ERRO: Cliente %s já existe ", cl->nome);
    return 0;
  }
}


/* FUNÇÃO DE LIBERAÇÃO DE MEMÓRIA */
void liberaCliente(Cliente* cl){
  free(cl->nome);
  free(cl);
}

void liberaListaCliente(ListaCliente* l){
  Cliente* aux;	
  for(aux=l->prim;aux!=NULL;aux=aux->prox){
    liberaCliente(aux);
  }
  free(l);	
}


/* FUNÇÕES DE EXCLUSÃO */
void excluiCliente(ListaCliente* l, char* nome){
  Cliente* ant = NULL;
  Cliente* aux = l->prim;

  if(aux==NULL){ //testa se a lista está vazia
    return;
  }

  while(aux!=NULL && strcmp(aux->nome,nome)){
    ant = aux;
    aux = aux->prox;
  }

  if(ant==NULL){ //testa se é o primeiro elemento
   l->prim = aux->prox;
   if(aux->prox==NULL){
    l->ult = NULL;
   }
   liberaCliente(aux);
   return;
  }
  if(aux!=NULL){ //caso o cliente exista
   ant->prox = aux->prox;
   if(aux->prox==NULL){ // testa se é o ultimo elemento
    l->ult = ant;	
   }
   liberaCliente(aux);
   return;
  }else{
    printf("ERRO: Cliente %s não existe\n", nome);
    return;
  }
}

void excluiContaCliente(ListaCliente* l, int conta){
  Cliente* aux;
  for(aux = l->prim; aux!=NULL; aux = aux->prox){   
    int i;
    for(i=0; i<TMAX; i++){
      if(aux->vet[i]==NULL){
	break;
      }
      if(getNumero(aux->vet[i]) == conta){
	int j;
	for(j=i; j<TMAX-1; j++){
	  aux->vet[j]=aux->vet[j+1];
	}
	aux->vet[TMAX-1] = NULL;
      }
    }
  }
}  


/* FUNÇÕES DE IMPRESSÃO */
void imprimeCliente(Cliente* cl){
  printf("CLIENTE %s\n", cl->nome);
  int i=0;
  while(cl->vet[i]!=NULL){
    imprimeConta(cl->vet[i]);
    i++;
  }
}

void imprimeListaCliente(ListaCliente* l){
  if(l->prim==NULL){
    printf("Nenhum cliente\n");
    return;
  }
  Cliente* aux;
  for(aux=l->prim; aux!=NULL; aux=aux->prox){
    imprimeCliente(aux);
  }
}


/* FUNÇÃO AUXILIAR */
void addConta(Cliente* cl, Conta* c){
  int i;
  for(i=0; i<TMAX; i++){
    if(cl->vet[i] == NULL){
      cl->vet[i] = c;
      cl->num++;
      return;
    }
  }
  printf("ERRO: Cliente %s já possui o número máximo de contas\n", cl->nome);
}

int verificaNMax(Cliente* c){
  return c->num;
}
    