#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "conta.h"

/*Define uma estrutura do tipo opaco ListaCliente*/
typedef struct listacliente ListaCliente;

/*Define uma estrutura do tipo opaco Cliente*/
typedef struct cliente Cliente;

/* Cria uma lista de clientes
 * input: não tem
 * output: uma lista de clientes vazia
 * pré-condição: a lista não existe
 * pós-condição: a lista existe e é vazia */
ListaCliente* criaListaCliente();

/* Inicializa um cliente
 * input: o nome do cliente
 * output: um ponteiro pro cliente criado
 * pré-condição: não tem
 * pós-condição: o cliente existe e foi inicializado */
Cliente* criaCliente(char* nome);

/* Busca um cliente numa lista de clientes
 * input: o nome do cliente
 * output: um ponteiro pro cliente encontrado
 * pré-condição: lista de clientes existe
 * pós-condição: não tem */
Cliente* buscaCliente(ListaCliente* l, char* nome);

/* Insere um cliente na lista de clientes
 * input: uma lista de clientes e um ponteiro pra um cliente
 * output: um inteiro 1 caso o cliente seja inserido, e 0 caso não 
 * pré-condição: a lista e o cliente existem
 * pós-condição: a lista existe e contém o cliente inserido */
int insereCliente(ListaCliente* l, Cliente* cl);

/* Libera o espaço de um cliente
 * input: um ponteiro pro cliente
 * output: não tem
 * pré-condição: o cliente existe
 * pós-condição: o espaço alocado para o cliente foi liberado */
void liberaCliente(Cliente* cl);

/* Libera o espaço reservado pela lista
 * input: a lista de clientes
 * output: não tem
 * pré-condição: a lista existe
 * pós-condição: o espaço alocado para a lista foi liberado */
void liberaListaCliente(ListaCliente* l);

/* Exclui um cliente da lista de clientes
 * input: a lista de clientes, e o nome do cliente
 * output: não tem
 * pré-condição: lista de clientes existe e não é vazia, e o cliente pertece à lista
 * pós-condição: a lista existe e o cliente foi excluído */
void excluiCliente(ListaCliente* l, char* nome);

/* Exclui uma conta de um determinado clientes ]
 * input: a lista de clientes e uma conta
 * output: não tem
 * pré-condição: a lista de clientes existe e não é vazia
 * pós-condição: a lista permanece inalterada, e as contas encontradas nos clientes foram excluídas */
void excluiContaCliente(ListaCliente* l, int conta);

/* Imprime as informações de um cliente
 * input: um ponteiro pra um cliente
 * output: não tem
 * pré-condição: o cliente existe
 * pós-condição: o cliente permanece inalterado */
void imprimeCliente(Cliente* cl);

/* Imprime uma lista de clientes
 * input: a lista de clientes
 * output: não tem
 * pré-condição: a lista existe
 * pós-condição: a lista permanece inalterada */
void imprimeListaCliente(ListaCliente* l);

/* Adiciona uma conta a um determinado cliente
 * input: um ponteiro pro cliente, e e o ponteiro pra conta a ser inserida
 * output: não tem
 * pré-condição: o cliente existe no banco
 * pós-condição: o cliente existe e a conta foi adicionada a ele */
void addConta(Cliente* cl, Conta* c);

/* Verifica quantas contas o cliente já tem
 * input: um ponteiro pro cliente
 * output: o numero de contas do cliente
 * pré-condição: o cliente existe
 * pós-condição: o cliente permanece inalterado */
int verificaNMax(Cliente* c);

#endif /*CLIENTE_H_*/