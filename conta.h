#ifndef CONTA_H_
#define CONTA_H_

#include "transacao.h"

/*Define uma estrutura do tipo opaco ListaConta*/
typedef struct listaconta ListaConta;

/*Define uma estrutura do tipo opaco Conta*/
typedef struct conta Conta;

/* Cria uma lista de contas
 * input: não tem
 * output: uma lista de contas vazia
 * pré-condição: a lista não existe
 * pós-condição: a lista existe e é vazia */
ListaConta* criaListaConta();

/* Inicializa uma conta 
 * input: o numero da conta
 * output: um ponteiro pra conta criada
 * pré-condição: não tem
 * pós-condição: a conta existe e foi inicializada */
Conta* criaConta(int conta);

/* Cria uma conta conjunta
 * input: o numero da conta
 * output: um ponteiro pra conta criada
 * pré-condição: não tem
 * pós-condição: a conta existe */
Conta* criaContaConjunta(int conta);

/* Busca uma conta numa lista de contas
 * input: o numero da conta
 * output: um ponteiro pra conta encontrada
 * pré-condição: lista de contas existe
 * pós-condição: não tem */
Conta* buscaConta(ListaConta* l, int conta);

/* Insere uma conta na lista de contas
 * input: uma lista de contas e um ponteiro pra conta
 * output: 0 caso não insira a conta por algum motivo, 1 quando há inserção 
 * pré-condição: a lista e a conta existem
 * pós-condição: a lista existe e contém a conta inserida */
int insereConta(ListaConta* l, Conta* c);

/* Libera o espaço de uma conta
 * input: um ponteiro pra conta
 * output: não tem
 * pré-condição: a conta existe
 * pós-condição: o espaço alocado para conta foi liberado */
void liberaConta(Conta* c);

/* Libera o espaço reservado pela lista
 * input: a lista de contas
 * output: não tem
 * pré-condição: a lista existe
 * pós-condição: o espaço alocado para a lista foi liberado */
void liberaListaConta(ListaConta* l);

/* Pega o saldo de uma determinada conta
 * input: um ponteiro pra conta
 * output: o saldo da conta
 * pré-condição: a conta existe
 * pós-condição: a conta permanece inalterada */
int getSaldo(Conta* c);

/* Atualiza o saldo de uma determinada conta
 * input: um ponteiro pra conta e uma quantia
 * output: não tem
 * pré-condição: a conta existe
 * pós-condição: a conta tem sem saldo alterado */
void setSaldo(Conta* c,int i);

/* Pega o número de uma determinada conta
 * input: um ponteiro pra conta
 * output: o número da conta
 * pré-condição: a conta existe
 * pós-condição: a conta permanece inalterada */
int getNumero(Conta* c);

/* Pega uma lista de transações de uma determinada conta
 * input: um ponteiro pra conta
 * output: a lista de transações da conta
 * pré-condição: a conta existe
 * pós-condição: a conta permanece inalterada */
ListaTransacao* getTransacao(Conta* c);

/* Exclui uma conta da lista de contas
 * input: a lista de contas, e o numero da conta
 * output: o inteiro 1 quando a conta é encontrada e excluída, e 0 quando não é encontrada
 * pré-condição: lista de contas existe e não é vazia, e a conta pertece à lista
 * pós-condição: a lista existe e a conta foi excluída */
int excluiConta(ListaConta* l, int conta);

/* Imprime as informações de uma conta
 * input: um ponteiro pra uma conta
 * output: não tem
 * pré-condição: a conta existe
 * pós-condição: as informações da conta permanecem inalteradas  */
void imprimeConta(Conta* c);

/* Imprime uma lista de contas
 * input: a lista de contas
 * output: não tem
 * pré-condição: a lista existe
 * pós-condição:  a lista permanece inalterada */
void imprimeListaConta(ListaConta* l);

#endif /*CONTA_H_*/