#ifndef TRANSACAO_H_
#define TRANSACAO_H_

/*Define uma estrutura do tipo opaco ListaTransacao*/
typedef struct listatransacao ListaTransacao;

/*Define uma estrutura do tipo opaco Transacao*/
typedef struct transacao Transacao;

/* Cria uma lista de transações
 * input: não tem
 * output: uma lista de transacao vazia
 * pré-condição: a lista não existe
 * pós-condição: a lista existe e é vazia */
ListaTransacao* criaListaTransacao();

/* Inicializa uma transação de depósito 
 * input: a quantia a ser depositada
 * output: a uma transação de depósito
 * pré-condição: não tem
 * pós-condição: a transação existe e foi inicializada como um depósito */
Transacao* deposito(int quantia);

/* Cria uma transação de saque
 * input: a quantia a ser sacada
 * output: uma transação de saque
 * pré-condição: não tem
 * pós-condição: a transação existe e foi inicializada como um saque */
Transacao* saque(int quantia);

/* Insere uma transação na lista de transações
 * input: uma lista de transações e uma transação
 * output: não tem
 * pré-condição: a lista e a transação tem que existir
 * pós-condição: a lista existe e contém a transação inserida */
void insereTransacao(ListaTransacao* l, Transacao* t);

/* Imprime uma transação
 * input: a transação
 * output: não tem
 * pré-condição: a transação existe
 * pós-condição: as informações da transação permanecem inalteradas */
void imprimeTransacao(Transacao* t);

/* Imprime a lista de transações
 * input: a lista de transações da conta
 * output: não tem
 * pré-condição: a lista existe e não é vazia
 * pós-condição: a lista permanece inalterada */
void imprimeListaTransacao(ListaTransacao* l);

/* Libera o espaço de uma transação
 * input: a transação
 * output: não tem
 * pré-condição: a transação existe
 * pós-condição: o espaço alocado para transação foi liberado */
void liberaTransacao(Transacao* t);

/* Libera o espaço reservado pela lista
 * input: a lista de transações
 * output: não tem
 * pré-condição: a lista existe
 * pós-condição: o espaço alocado para a lista foi liberado */
void liberaListaTransacao(ListaTransacao* l);

#endif /*TRANSACAO_H_*/