#include <stdio.h>  
#include <stdlib.h> 

typedef struct node{ //aqui é daclarado uma variavel do tipo
    int nota;
    struct node *nxt;
} Node;//aqui é o nome do tipo

Node *criar();
Node *push(Node*fila, int nota);
Node *pop(Node*fila);
Node *peak(Node*fila);
void liberar_fila (Node *fila);
void exibirFila(Node *fila);

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
        printf("\n******push: erro de alocacao***********");
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

Node *pop(Node*fila) //desenfilar ou dque
{
    if(fila ==NULL)
    {
        printf("\n******pop: lista vazia*****\n");
        //vazia e sair
    }
    Node *temp = fila;//no[] temporario recebe o conteudo da fila posta
    fila = fila->nxt;//fila recebe o endereço do proximo, sendo assim o pontiero fila apont agora pra o proximo
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
    Node *temp=fila;//lembrar de inicializar
    while(temp!=NULL)
    {
        printf("%d -> ", temp->nota);
        temp=temp->nxt;
    }
    printf("NULL \n");
}

//main--------------------------
int main(int argc, char *argv[])
{
    Node *fila=criar();
    peak(fila);
    fila=push(fila,30);
    peak(fila);
    fila=push(fila,301);
    fila=push(fila,79);
    printf("\nimprimir fila:\n");
    exibirFila(fila);
    liberar_fila(fila);
        

return 0;
}