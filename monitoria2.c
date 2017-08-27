#include <stdio.h>
#include <stdlib.h>

typedef struct ntree {
	int conteudo;
	struct ntree *esq, *dir;
} node;

node *insere(node *tree, int value){
	if (tree == NULL){
		tree = (node *) malloc(sizeof(node));
		tree->conteudo = value;
		tree->esq = NULL;
		tree->dir = NULL;
		printf("AQUI\n");
	}
	else if(value < tree->conteudo){
		tree->esq = insere(tree->esq, value);
		printf("AQUI2\n");
	}
	else{
		tree->dir = insere(tree->dir, value);
		printf("AQUI3\n");
	}
	return tree;
}

void preordem(node *tree){
	if(tree != NULL){
		printf("%d ", tree->conteudo);
		preordem(tree->esq);
		preordem(tree->dir);
	}
}

void posordem(node *tree){
	if(tree != NULL){
		preordem(tree->esq);
		preordem(tree->dir);
		printf("%d ", tree->conteudo);
	}
}

void emordem(node *tree){
	if(tree != NULL){
		preordem(tree->esq);
		printf("%d ", tree->conteudo);
		preordem(tree->dir);
	}
}


int main(){

	int i, j, cases, nValues, value;

	node *tree = NULL;
	scanf("%d", &cases);
	for(i = 1; i <= cases; i++){
		scanf("%d", &nValues);
		for(j = 0; j < nValues; j++){
			scanf("%d", &value);
			insere(tree, value);
		}
		printf("Case %d:\n", i);
		printf("Pre. : ");
		preordem(tree);
		printf("\n");
		printf("In. . : ");
		emordem(tree);
		printf("\n");
		printf("Post: ");
		posordem(tree);
		printf("\n");
		printf("\n");
	}


}
