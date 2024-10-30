/*
1. leia um número inteiro n, que representa a quantidade de casos de teste.

2. para cada caso de teste:

    leia um número inteiro m, que indica o número de alunos.
    leia m inteiros, representando as notas dos alunos na ordem de chegada.

3. reordene a lista de notas de forma decrescente.

4. compare a lista original com a lista reordenada.

5. conte quantos alunos permanecem nas mesmas posições após a reordenação.

6. para cada caso de teste, imprima um número inteiro representando a quantidade de alunos que não trocaram de lugar.

N numero de execuções 
M numero de alunos


*/

#include "pratica.h"


Node *criar()
{
//criar a fila
return NULL; //por algum motivo
}
Node *push(Node*fila, int nota)//add novo elemento no final da fila
{   
    Node *novo = (Node*)calloc(1,sizeof(Node));//aloca um novo Node
    if(novo ==NULL)
    {
        //erro de alocacao
    }
    novo->nota=nota;//imagino que seja como o this em java
    novo->nxt = NULL;//variavel nxt de node novo recebe null
        
    if(fila==NULL)//fila é um endereço de um node recebido
    {
        return novo;//se a fila tiver vazia o novo[] é primeiro
    }else{
        Node *temp=fila;//o no[] é recebido e posto em uma variavel temporaria
        while(temp->nxt != NULL)//enquanto a variavel next for diferente de vazia
        {
            temp=temp->nxt;//avança no proximo no[] até achar o ultimo
        }
        temp->nxt=novo;//um novo no[] é dado no fim da fila
        return fila;//fila sendo o no[] recebido no cabecario
    }

}

Node *pop(Node*fila, int *nota) //desenfilar ou dque
{
    if(fila ==NULL)
    {
        printf("\n******pop: lista vazia*****\n");
        //vazia e sair
    }
    *nota=(*fila).nota; //ponteiro de int recebe o valor do primeiro elemento 
    Node *temp = fila;//no[] temporario recebe o conteudo da fila posta
    fila = (*fila).nxt;//fila recebe o endereço do proximo, sendo assim o pontiero fila apont agora pra o proximo
    free (temp);
    return fila;//retorna fila sendo que fila é agora o endereço do proximo

}
Node *peak(Node*fila)//ver primeiro elemento
{
    if(fila ==NULL)
    {
        printf("\n***peak: fila vazia****\n");//fila vazia
        return NULL;
    }else{
        return fila;//se nao tiver vazia é só retornar o endereço do primeiro elemento
    }
}

void liberar_fila (Node *fila)
{
    Node *temp;
    while(fila!=NULL)
    {
        temp=fila;
        fila=fila->nxt;
        free(temp);
    }    
}

void exibirFila(Node *fila)
{
    Node *temp;
    while(temp!=NULL)
    {
        printf("%d -> ", temp->nota);
        temp=temp->nxt;
    }
    printf("NULL \n");
}

