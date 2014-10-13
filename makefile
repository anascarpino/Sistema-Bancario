simulador: 
	#compila arquivos
	gcc -c transacao.c conta.c cliente.c banco.c trabalho.c
	#gera o executavel sistemaBancario
	gcc -o sistemaBancario transacao.o conta.o cliente.o banco.o trabalho.o



