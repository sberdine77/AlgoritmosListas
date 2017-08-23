#include <stdio.h>
#include <stdlib.h>

struct Node{
	int valor;
	struct Node *proximo;
};
typedef struct Node node;


int filaVazia(node *FILA){
	if(FILA->proximo == NULL){
		return 1;
	}
	else{
		return 0;
	}
}


void insere(node *FILA){
	int inElement;
	node *novo = (node *) malloc(sizeof(node));
	scanf("%d", &inElement);

	novo->valor = inElement;
	novo->proximo = NULL;

	if(filaVazia(FILA)){
		FILA->proximo = novo;
	}
	else{
		node *temp = FILA->proximo;
		while(temp->proximo != NULL){
			temp = temp->proximo;
		}
		temp->proximo = novo;
	}
}

void exibePrimeiro(node *FILA){
	if(filaVazia(FILA)){
		printf("Empty!\n");
	}
	else{
		node *temp = FILA->proximo;
		printf("%d\n", temp->valor);
	}
}

node *retira(node *FILA){
	node *temp = FILA->proximo;
	FILA->proximo = temp->proximo;
	return temp;
}

int main(){

	node *FILA = (node *) malloc(sizeof(node));
	
	FILA->proximo = NULL;

	int nEntradas, i, opcao;

	scanf("%d", &nEntradas);
	for(i = 0; i < nEntradas; i++){
		scanf("%d", &opcao);
		if(opcao == 1){
			insere(FILA);
		}
		else if(opcao == 2){
			node *tmp = retira(FILA);
			free(tmp);
		}
		else{
			exibePrimeiro(FILA);
		}
	}
	free(FILA);
	return 0;
}











