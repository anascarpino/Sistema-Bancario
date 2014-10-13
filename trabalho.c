#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

#define TAM 30

int main(int argc,char* argv[]){
  if(argc==2){
    freopen(argv[1],"r", stdin);
    freopen("saida.txt","w", stdout);

    if(!freopen(argv[1], "r", stdin) || !freopen("saida.txt", "w", stdout)){
      printf("ERRO: erro na abertura dos arquivos!\n");
      exit(1);
    }
    
    ListaBanco* lb = criaListaBanco();
    Banco* b;
    char funcao[TAM];
    int quantia;
    int conta1;
    int conta2;
    char banco1[TAM];
    char banco2[TAM];
    char cliente1[TAM];
    char cliente2[TAM];
  
    scanf("%s", funcao);
    while(strcmp(funcao, "FIM")!=0){
      if(strcmp(funcao, "CRIABANCO")==0){
	scanf("%s", banco1);
	b = criaBanco(banco1);
	insereBanco(lb, b);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "INSERECLIENTE")==0){
	scanf("%s %s", cliente1, banco1);
	insereClienteBanco(lb, cliente1, banco1);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "INSERECONTA")==0){
	scanf("%d %s %s", &conta1, cliente1, banco1);
	insereContaBanco(conta1, cliente1, lb, banco1);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "INSERECONTACONJUNTA")==0){
	scanf("%d %s %s %s", &conta1, cliente1, cliente2, banco1);
	insereContaConjuntaBanco(conta1,cliente1,cliente2,lb,banco1);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "DEPOSITA")==0){
	scanf("%s %d %d", banco1, &conta1, &quantia);
	deposita(lb, banco1, conta1, quantia);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "SACA")==0){
	scanf("%s %d %d", banco1, &conta1, &quantia);
	saca(lb, banco1, conta1, quantia);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "TRANSFERE")==0){
	scanf("%s %d %s %d %d", banco1, &conta1, banco2, &conta2, &quantia);
	transfere(lb, banco1, conta1, banco2, conta2, quantia);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "SALDO")==0){
	scanf("%s %d", banco1, &conta1);
	imprimeSaldo(lb, banco1, conta1);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "EXTRATO")==0){
	scanf("%s %d", banco1, &conta1);
	imprimeExtrato(lb, banco1, conta1);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "EXCLUICONTA")==0){
	scanf("%s %d", banco1, &conta1);
	b = buscaBanco(lb, banco1);
	if(b!=NULL){
	  excluiContaCliente(getClientes(b), conta1);
	  if(!excluiConta(getContas(b), conta1)){
	    printf("no %s\n", banco1);
	  }
	}
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "EXCLUICLIENTE")==0){
	scanf("%s %s", banco1, cliente1);
	b = buscaBanco(lb, banco1);
	if(b!=NULL){
	  excluiCliente(getClientes(b), cliente1);
	}
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "EXCLUIBANCO")==0){
	scanf("%s", banco1);
	excluiBanco(lb, banco1);
	scanf("%s", funcao);
      }
      if(strcmp(funcao, "IMPRIMETUDO")==0){
	printf("\n");
	imprimeListaBanco(lb);
	scanf("%s", funcao);
      }
    }
    liberaListaBanco(lb);
    fclose(stdin);
    fclose(stdout);
  }
  return 0;
}