
#ifndef FILA_H
#define FILA_H


#include <stdio.h>  
#include <stdlib.h> 

typedef struct node{ //aqui é daclarado uma variavel do tipo
    int nota;
    struct node *nxt;
} Node;//aqui é o nome do tipo

Node *criar();
Node *push(Node*fila, int nota);
Node *pop(Node*fila, int *nota);
Node *peak(Node*fila);
void liberar_fila (Node *fila);
void exibirFila(Node *fila);

#endif