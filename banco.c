#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

#define TMAX 10

/*DEFINIÇÃO DAS ESTRUTURAS */
struct listabanco{
	Banco* prim;
	Banco* ult;
};

struct banco{
  char* nome;
  ListaConta* contas;
  ListaCliente* clientes;
  struct banco* prox;
};


/* FUNÇÕES DE CRIAÇÃO E INICIALIZAÇÃO */
ListaBanco* criaListaBanco(){
  ListaBanco* lb = (ListaBanco*)malloc(sizeof(ListaBanco));
  lb->prim = NULL;
  lb->ult = NULL;
  return lb;
}

Banco* criaBanco(char* nome){
  Banco* b = (Banco*)malloc(sizeof(Banco));
  b->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
  b->nome = strcpy(b->nome, nome);
  b->contas = criaListaConta();
  b->clientes = criaListaCliente();
  b->prox = NULL;
  return b;
}


/* FUNÇÃO DE BUSCA */
Banco* buscaBanco(ListaBanco* l, char* nome){
  Banco* aux;	
  for(aux = l->prim; aux!=NULL; aux=aux->prox){
    if(strcmp(aux->nome,nome)==0){
      return aux;
    }
  }
  return NULL;
}


/* FUNÇÕES AUXILIARES */
ListaCliente* getClientes(Banco* b){
  return b->clientes;
}

ListaConta* getContas(Banco* b){
  return b->contas;
}

/* FUNÇÕES DE INSERÇÃO */
void insereBanco(ListaBanco* l, Banco* b){
  if(l->prim == NULL){
    l->prim = b;
    l->ult = b;
    return;
  }
  l->ult->prox = b;
  l->ult = b;
}

void insereClienteBanco(ListaBanco* l, char* cliente, char* banco){
  Banco* b = buscaBanco(l,banco);
  if(b==NULL){
    printf("ERRO: %s nao existe\n", banco);
    return;
  }else{
    int i;
    Cliente* c = criaCliente(cliente);
    i = insereCliente(getClientes(b), c);
    if(i==0){
      printf("no %s\n", banco);
    }
  }
}
  
void insereContaBanco(int num, char* nomeCliente, ListaBanco* l, char* nomeBanco){
  Banco* b = buscaBanco(l, nomeBanco);
  if(b==NULL){
    printf("ERRO: %s não existe\n", nomeBanco);
    return;
  }
  Cliente* c = buscaCliente(b->clientes, nomeCliente);
  if(c==NULL){
    printf("ERRO: Cliente %s não existe no %s\n", nomeCliente, nomeBanco);
    return;
  }
  if(verificaNMax(c)<TMAX){
    Conta* conta = criaConta(num);
    if(insereConta(b->contas,conta)!=0){      
      addConta(c,conta);
    }else{
      printf("no %s\n", nomeBanco);
      free (conta);
      return;
    }
  }else{
    printf("ERRO: Cliente %s já possui numero máximo de contas!\n", nomeCliente);
  }
}

void insereContaConjuntaBanco(int num, char* cliente1, char* cliente2, ListaBanco* l, char* nomeBanco){
  Banco* b = buscaBanco(l, nomeBanco);
  if(b==NULL){
    printf("ERRO: %s não existe\n", nomeBanco);
    return;
  }
  Cliente* c1 = buscaCliente(b->clientes, cliente1);
  Cliente* c2 = buscaCliente(b->clientes, cliente2);
  if(c1==NULL){
    printf("ERRO: Cliente %s não existe no %s\n", cliente1, nomeBanco);
    return;
  }
  if(c2==NULL){
    printf("ERRO: Cliente %s não existe no %s\n", cliente2, nomeBanco);
    return;
  }
  Conta* conta = criaContaConjunta(num);
  if(insereConta(b->contas,conta)!=0){      
    addConta(c1,conta);
    addConta(c2,conta);
  }else{
    liberaConta(conta);
    return;
  }
}


/* FUNÇÕES DE MOVIMENTAÇÕES DA CONTA */
void deposita(ListaBanco* l, char* nome, int conta, int quantia){
  Banco* b = buscaBanco(l, nome);
  if(b!=NULL){
    Conta* c = buscaConta(b->contas, conta);
    if(c!=NULL){
      Transacao* t = deposito(quantia);
      setSaldo(c, getSaldo(c)+quantia);
      insereTransacao(getTransacao(c), t);
      return;
    }else{
      printf("ERRO: não existe conta %d no %s\n", conta, nome);
      return;
    }
  }else{
    printf("ERRO: %s nao existe\n", nome);
    return;
  }
}

void saca(ListaBanco* l, char* nome, int conta, int quantia){
  Banco* b = buscaBanco(l, nome);
  if(b!=NULL){
    Conta* c = buscaConta(b->contas, conta);
    if(c!=NULL){
      if(getSaldo(c) >= quantia){
	Transacao* t = saque(quantia);
	setSaldo(c, getSaldo(c)-quantia);
	insereTransacao(getTransacao(c), t);
	return;
      }else{
	printf("ERRO: não foi possível sacar %d da conta %d – saldo insuficiente\n", quantia, conta);
	return;
      }
    }else{
      printf("ERRO: não existe conta %d no %s\n", conta, nome);
      return;
    }
  }else{
    printf("ERRO: %s nao existe\n", nome);
    return;
  }
}

void transfere(ListaBanco* l, char* bOrigem, int contaOrigem, char* bDestino, int contaDestino, int quantia){
  Banco* b1 = buscaBanco(l, bOrigem);
  Banco* b2 = buscaBanco(l, bDestino);
  if(b1 == NULL || b2 == NULL){
    printf("ERRO: não foi possivel realizar a transferencia - banco nao encontrado\n");
    return;
  }
  Conta* c1 = buscaConta(b1->contas, contaOrigem);
  Conta* c2 = buscaConta(b2->contas, contaDestino);
  if(c1 == NULL || c2 == NULL){
    printf("ERRO: uma das contas não existe\n");
    return;
  }
  if(getSaldo(c1)<quantia){
    printf("ERRO: não foi possível sacar %d da conta %d – saldo insuficiente\n", quantia, contaOrigem);
    return;
  }else{
    Transacao* t1 = saque(quantia);
    Transacao* t2 = deposito(quantia);
    saca(l, bOrigem, contaOrigem, quantia);
    deposita(l, bDestino, contaDestino, quantia);
  }
}


/* FUNÇÕES DE LIBERAÇÃO DE MEMÓRIA */
void liberaBanco(Banco* b){
  liberaListaConta(b->contas);
  liberaListaCliente(b->clientes);
  free(b->nome);
  free(b);
}

void liberaListaBanco(ListaBanco* l){
  Banco* aux;	
  for(aux=l->prim;aux!=NULL;aux=aux->prox){
    liberaBanco(aux);
  }
  free(l);	
}


/* FUNÇÃO DE EXCLUSÃO */
void excluiBanco(ListaBanco* l, char* nome){
  Banco* ant = NULL;
  Banco* aux = l->prim;

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
   liberaBanco(aux);
   return;
  }
  if(aux!=NULL){ //caso o cliente exista
   ant->prox = aux->prox;
   if(aux->prox==NULL){ // testa se é o ultimo elemento
    l->ult = ant;	
   }
   liberaBanco(aux);
   return;
  }else{
    printf("ERRO: Banco %s nao existe\n", nome);
    return;
  }
}


/* FUNÇÕES DE IMPRESSÃO */
void imprimeBanco(Banco* b){
  printf("BANCO %s\n", b->nome);
  imprimeListaCliente(b->clientes);
  printf("\n");
}

void imprimeListaBanco(ListaBanco* l){
  if(l->prim==NULL){
    printf("Nenhum banco\n");
    return;
  }
  Banco* aux;
  for(aux=l->prim; aux!=NULL; aux=aux->prox){
    imprimeBanco(aux);
  }
}

void imprimeSaldo(ListaBanco* l, char* nome, int conta){
  Banco* b = buscaBanco(l, nome);
  if(b==NULL){
   printf("ERRO: Banco %s nao existe\n", nome);
    return;
  }else{
    Conta* c = buscaConta(b->contas, conta);
    if(c==NULL){
      printf("ERRO: não existe conta %d no banco %s\n", conta, nome);
      return;
    }else{
      printf("SALDO %s – conta %d: %d\n", b->nome, getNumero(c), getSaldo(c));
      return;
    }
  }
}

void imprimeExtrato(ListaBanco* l, char* nome, int conta){
  Banco* b = buscaBanco(l, nome);
  if(b==NULL){
    printf("ERRO: %s nao existe\n", nome);
    return;
  }else{
    Conta* c = buscaConta(b->contas, conta);
    if(c==NULL){
      printf("ERRO: não existe conta %d no %s\n", conta, nome);
      return;
    }else{
      printf("EXTRATO %s – conta %d\n", b->nome, getNumero(c));
      imprimeListaTransacao(getTransacao(c));
      return;
    }
  }
}
