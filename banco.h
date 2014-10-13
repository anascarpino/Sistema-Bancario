#ifndef BANCO_H_
#define BANCO_H_

#include "cliente.h"

/*Define uma estrutura do tipo opaco ListaBanco*/
typedef struct listabanco ListaBanco;

/*Define uma estrutura do tipo opaco Banco*/
typedef struct banco Banco;

/* Cria uma lista de bancos
 * input: não tem
 * output: uma lista de bancos vazia
 * pré-condição: a lista não existe
 * pós-condição: a lista existe e é vazia */
ListaBanco* criaListaBanco();

/* Inicializa um banco
 * input: o nome do banco
 * output: um ponteiro pro banco criado
 * pré-condição: não tem
 * pós-condição: o banco existe e foi inicializado */
Banco* criaBanco(char* nome);

/* Busca um banco numa lista de bancos
 * input: o nome do banco
 * output: um ponteiro pro banco encontrado
 * pré-condição: lista de bancos existe
 * pós-condição: não tem */
Banco* buscaBanco(ListaBanco* l, char* nome);

/* Pega uma lista de clientes de um determinado banco
 * input: um ponteiro pro cliente
 * output: a lista de clientes do banco
 * pré-condição: o banco existe
 * pós-condição: o banco permanece inalterado */
ListaCliente* getClientes(Banco* b);

/* Pega uma lista de contas de um determinado banco
 * input: um ponteiro pra conta
 * output: a lista de contas do banco
 * pré-condição: o banco existe
 * pós-condição: o banco permanece inalterado */
ListaConta* getContas(Banco* b);

/* Insere um banco na lista de bancos
 * input: uma lista de bancos e um ponteiro pra um banco
 * output: não tem 
 * pré-condição: a lista e o banco existem
 * pós-condição: a lista existe e contém o banco inserido */
void insereBanco(ListaBanco* l, Banco* b);

/* Insere uma conta em um determinado banco
 * input: o número da conta, o nome do cliente, a lista de bancos e o nome do banco
 * output: não tem 
 * pré-condição: o cliente existe no banco
 * pós-condição: a conta existe e foi inserida no banco, e no cliente */
void insereContaBanco(int num, char* nomeCliente, ListaBanco* l, char* nomeBanco);

/* Insere uma conta conjunta em um determinado banco
 * input: o número da conta, o nome dos clientes, a lista de bancos e o nome do banco
 * output: não tem 
 * pré-condição: os clientes existem no banco
 * pós-condição: a conta existe e foi inserida no banco, e nos clientes */
void insereContaConjuntaBanco(int num, char* cliente1, char* cliente2, ListaBanco* l, char* nomeBanco);

/* Insere um cliente em um determinado banco
 * input:, o nome do cliente, a lista de bancos e o nome do banco
 * output: não tem 
 * pré-condição: o banco existe na lista de bancos
 * pós-condição: o cliente existe no banco, e a lista de bancos permanece inalterada */
void insereClienteBanco(ListaBanco* l, char* cliente, char* banco);

/* Realiza um depósito em determinada conta
 * input: a lista de bancos, o nome do banco, o número da conta, e a quantia a ser depositada
 * output: não tem
 * pré-condição: o banco pertence à lista de bancos, e a conta pertence ao banco
 * pós-condição: a conta existe e teve seu saldo alterado */
void deposita(ListaBanco* l, char* nome, int conta, int quantia);

/* Realiza um saque de determinada conta
 * input: a lista de bancos, o nome do banco, o número da conta, e a quantia a ser sacada
 * output: não tem
 * pré-condição: o banco pertence à lista de bancos, a conta pertence ao banco, e possui saldo suficiente
 * pós-condição: a conta existe e teve seu saldo alterado */
void saca(ListaBanco* l, char* nome, int conta, int quantia);

/* Realiza uma transferência de determinada conta para outra
 * input: a lista de bancos, o nome do banco de origem, o número da conta de origem, o nome do banco de destino, o número da conta de destino, e a quantia a ser transferida
 * output: não tem
 * pré-condição: os bancos pertencem à lista de bancos, as contas pertencem aos seus respectivos bancos, e conta de origem possui saldo suficiente
 * pós-condição: as contas existem e tiveram seus saldos alterados */
void transfere(ListaBanco* l, char* bOrigem, int contaOrigem, char* bDestino, int contaDestino, int quantia);

/* Libera o espaço de um banco
 * input: um ponteiro pro banco
 * output: não tem
 * pré-condição: o banco existe
 * pós-condição: o espaço alocado para o banco foi liberado */
void liberaBanco(Banco* b);

/* Libera o espaço reservado pela lista
 * input: a lista de bancos
 * output: não tem
 * pré-condição: a lista existe
 * pós-condição: o espaço alocado para a lista foi liberado */
void liberaListaBanco(ListaBanco* l);

/* Exclui um banco da lista de bancos
 * input: a lista de bancos, e o nome do banco
 * output: não tem
 * pré-condição: lista de bancos existe e não é vazia, e o banco pertece à lista
 * pós-condição: a lista existe e o banco foi excluído */
void excluiBanco(ListaBanco* l, char* nome);

/* Imprime as informações de um banco
 * input: um ponteiro pra um banco
 * output: não tem
 * pré-condição: o banco existe
 * pós-condição: as informações do banco permanecem inalteradas */
void imprimeBanco(Banco* b);

/* Imprime uma lista de bancos
 * input: a lista de bancos
 * output: não tem
 * pré-condição: a lista existe
 * pós-condição: a lista permanece inalterada */
void imprimeListaBanco(ListaBanco* l);

/* Imprime o saldo de uma determinada conta
 * input: a lista de bancos, o nome de um banco, e o número da conta
 * output: não tem
 * pré-condição: o banco existe na lista de bancos, e a conta existe no banco
 * pós-condição: o saldo, o banco, e a conta permanecem inalterados */
void imprimeSaldo(ListaBanco* l, char* nome, int conta);

/* Imprime o extrato de uma determinada conta
 * input: a lista de bancos, o nome de um banco, e o número da conta
 * output: não tem
 * pré-condição: o banco existe na lista de bancos, e a conta existe no banco
 * pós-condição: o banco e a conta permanecem inalterados */
void imprimeExtrato(ListaBanco* l, char* nome, int conta);

#endif /*BANCO_H_*/
