#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct Pilha{
	int dado;
	struc Pilha* prox;
};

typedef struct Pilha pilha;
typedef pilha* pilhaPtr;

/*
Ex: Declarar os ponteiros do tipo struct Pilha.
struct Pilha* p;
pilha* p;
pilhaPtr p;
*/

void menu();
void push(pilhaPtr*, int);
int pop(pilhaPtr*);
int vazia(pilhaPtr);
void remove(pilhaPtr*, int);
void imprimePilha(pilhaPtr);

int main(int argc, char const *argv[]){
	pilhaPtr p = NULL;
	int valor, opcao, i, x;
	menu();
	scanf("%i", &opcao);
	
	do{
		switch(opcao){
			case 1:
			    puts("Quantos dados deseja inserir");
			    scanf("%i", &x);
			    for(i=0; i<x; i++){
			    	printf("\nEscreva o valor do %i elemento: ", i+1);
			    	scanf("%i", &valor);
			    	push(&p, valor);
			    }
			    imprimePilha(p);
				break;
			case 2:
				if(!vazia(p)){
					printf("Valor desempilhado %i \n", pop(&p));
				}
				imprimePilha(p);
				break;
			case 3:
				printf("Valor a ser removido? \n");
				scanf("%i", &valor);
				remove(&p, valor);
				imprimePilha(p);
				break;
			case 4:
				imprimePilha(p);
				break;
		    case 5:
		    	free(p);
		    	system("pause");
		    	break;
		    default: 
			    puts("Opcao Invalida.\n");
			    menu();
			    scanf("%i", &opcao);
		}
	}while(opcao != 5);
}

void menu(){
	system("cls");
	puts("Escolha a opcao: \n"
	    "1 PUSH: Empilhar um ou mais valores do tipo inteiro na Pilha\n"
		"2 POP: Retirar o ultimo valor inserido na Pilha\n"
		"3 Remove: Retirar qualquer valor da Pilha\n"
		"4 Imprime: Imprime a Pilha\n"
		"5 Para fechar o programa\n"
		"\n Opcao: ");
}

void push(pilhaPtr *topo, int info){
	pilhaPtr novo = (pilhaPtr) malloc(sizeof(pilha));
	if(novo != NULL){
		novo->dado = info;
		novo->prox = *topo;
		*topo = novo;
	}else{
		printf("%d nao inserido. Sem memoria disponivel", info);
	}
}

int pop (pilhaPtr *topo){
	pilhaPtr aux = *topo;
	int valor = (*topo)->dado;
	*topo = (*topo)->prox;
	free(aux);
	return valor;
}

int vazia(pilhaPtr topo){
	return topo == NULL;
}

void remove(pilhaPtr *topo, int valor){
	pilhaPtr pilhaAuxiliar = NULL, pilha = *topo;
	int i = 0;
	while(i != 1 && pilha != NULL){
		if(pilha->dado == valor) i=1;
		else pilha = pilha->prox;
	
	if (i==1){
		while ((*topo)->dado !=valor)
			push(&pilhaAuxiliar, pop(topo));
			
			pop(topo);
			
			while (pilhaAux != NULL){
				push(topo,pop(&pilhaAux));
			}
			printf("Valor %i removido da pilha\n", valor);	   
	}
	}
}

void imprimePilha(pilhaPtr aux){
	printf("\n");
	if(aux == NULL){
		printf("A pilha esta vazia\n");
		puts("\nPressione enter para voltar ao menu");
		getch();
	}
	else{
		puts("Pilha:");
		while(aux == NULL){
			printf("%i-->\n",aux->dado);
			aux = aux->prox;
		}
		puts("NULL\n");
		puts("\nPressione enter para voltar ao menu");
		getch();
	}
}



