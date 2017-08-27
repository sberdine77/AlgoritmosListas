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


void insere(node *ultimo, node *FILA){
    int inElement;
    node *novo = (node *) malloc(sizeof(node));
    scanf("%d", &inElement);
    
    novo->valor = inElement;
    novo->proximo = NULL;
    
    if(filaVazia(FILA)){
        FILA->proximo = novo;
        ultimo = novo;
    }
    else{
        ultimo->proximo = novo;
        ultimo = novo;
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
    if(filaVazia(FILA)){
        return NULL;
    }
    else{
        node *temp = FILA->proximo;
        FILA->proximo = temp->proximo;
        return temp;
    }
}

int main(){
    
    node *FILA = (node *) malloc(sizeof(node));
    FILA->proximo = NULL;
    
    node *ultimo = (node *) malloc(sizeof(node));
    ultimo->proximo = NULL;
    
    int nEntradas, i, opcao;
    
    scanf("%d", &nEntradas);
    for(i = 0; i < nEntradas; i++){
        scanf("%d", &opcao);
        if(opcao == 1){
            insere(ultimo, FILA);
        }
        else if(opcao == 2){
            node *tmp = retira(FILA);
            if(tmp != NULL){
                free(tmp);
            }
        }
        else if(opcao == 3){
            exibePrimeiro(FILA);
        }
    }
    free(FILA);
    free(ultimo);
    return 0;
}












