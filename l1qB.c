#include <stdio.h>
#include <stdlib.h>

struct Node{
	long int valor;
	struct Node *proximo;
};
typedef struct Node node;


int pilhaVazia(node *PILHA){
	if(PILHA->proximo == NULL){
		return 1;
	}
	else{
		return 0;
	}
}


void insere(node *PILHA){
	long int inElement;
	node *novo = (node *) malloc(sizeof(node));
	scanf("%ld", &inElement);

	novo->valor = inElement;
	novo->proximo = NULL;

	if(pilhaVazia(PILHA)){
		PILHA->proximo = novo;
	}
	else{
		node *temp = PILHA->proximo;
		while(temp->proximo != NULL){
			temp = temp->proximo;
		}
		temp->proximo = novo;
	}
}

void exibePrimeiro(node *PILHA){
	if(pilhaVazia(PILHA)){
		printf("Empty!\n");
	}
	else{
		node *temp = PILHA->proximo;
		while(temp->proximo != NULL){
			temp = temp->proximo;
		}
		printf("%ld\n", temp->valor);
	}
}

node *retira(node *PILHA){
	node *temp = PILHA->proximo;
	node *penultimo = PILHA;
	while(temp->proximo != NULL){
		penultimo = temp;
		temp = temp->proximo;
	}
	penultimo->proximo = NULL;
	return temp;
}

int main(){

	node *PILHA = (node *) malloc(sizeof(node));
	
	PILHA->proximo = NULL;

	long int i, nEntradas;
	int opcao;

	scanf("%ld", &nEntradas);
	for(i = 0; i < nEntradas; i++){
		scanf("%d", &opcao);
		if(opcao == 1){
			insere(PILHA);
		}
		else if(opcao == 2){
			node *tmp = retira(PILHA);
			free(tmp);
		}
		else{
			exibePrimeiro(PILHA);
		}
	}
	free(PILHA);
	return 0;
}