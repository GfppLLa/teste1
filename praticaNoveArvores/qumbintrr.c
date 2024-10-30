/*
ler numero de execuções
ler numero de elementos a serem inseridos
interios para os da arvore
ler valor a ser pesquisado

arvores:
No* criarNo(valor); 
No* inserirNo (No* raiz, int valor);
No* buscarNo(No* raiz, int conteudo);
void encontrarFilhos(No* raiz, int conteudo);
void exibirArvore(No* raiz);
void liberarMemoria(No* raiz);



lerN();//
oP();//
main()//
*/
#include <stdio.h>
#include<stdlib.h>

typedef struct No
{
    int conteudo;
    struct No *esquerda;
    struct No *direita;
    
} No;
 
  No* criarNo(int valor);
 No* inserirNo(No* raiz, int valor);
 No* buscarNo(No* raiz, int valor);
 void encontrarFilhos(No* raiz, int valor);
 void exibirArvore(No* raiz);
 void liberarArvore(No* raiz);
void opPreencher(No** raiz, int num_testes);
int lerDoTeclado();

 No* criarNo(int valor)
 {
    No* novoNo;//criacao
    novoNo=(No*)calloc(1, sizeof(No)); //alocacao
    if(novoNo!=NULL){
        (*novoNo).conteudo=valor;
        (*novoNo).esquerda=NULL;
        (*novoNo).direita=NULL;
    }
    return novoNo;
 }
No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    No* atual = raiz;
    No* pai = NULL;
    No* novoNo = criarNo(valor);

    while (atual != NULL) {
        pai = atual;
        if (valor < atual->conteudo) {
            atual = atual->esquerda;
        } else if (valor > atual->conteudo) {
            atual = atual->direita;
        } else {
            printf("\nValor já existe na árvore: %d", valor);
            free(novoNo);
            return raiz;
        }
    }

    if (valor < pai->conteudo) {
        pai->esquerda = novoNo;
    } else {
        pai->direita = novoNo;
    }

    return raiz;
}

No* buscarNo(No* raiz, int valor)
{
   No* atual=raiz;//

   while(atual != NULL)
   {
        if((*atual).conteudo==valor)
        {
            return atual;
        }else{
            if(valor <(*atual).conteudo)
            {
                atual=(*atual).esquerda;
            }else{
                atual=(*atual).direita;
            }
        }

   }
   return NULL;
}

void encontrarFilhos(No* raiz, int valor)
{
    No* noLocal=buscarNo(raiz, valor);
    if(noLocal==NULL)
    {
        printf("\nvalor nao encontrado");
        return;
    }
    if(noLocal->esquerda==NULL && noLocal->direita==NULL)
    {
        printf("\nnao ha filhos");
    }else{
        if(noLocal->esquerda!=NULL)
        {
            printf("\nfilho esquerdo: ");
            printf("%d \n",noLocal->esquerda->conteudo);
        }
        if(noLocal->direita!=NULL)
        {   
            printf("\nfilho direito: ");
            printf("%d \n", noLocal->direita->conteudo);
        }
        printf("\n");
    }
}



void opPreencher(No** raiz, int num_testes)//nao faz sentido, mas funcionou
{
    printf("\n**preencher\n");
    for (int i=0; i<num_testes; i++)
    {
        int aux;
        printf("\ninserir caso numero %d: ->", i);
        scanf("%d",&aux);
        if (aux<1 || aux>100)
        {
            continue;
            i--;
        }else{
            *raiz=inserirNo(*raiz, aux); //a lgum problema com a merda da passgaem de endereço e de conteudo, 
            //free(aux);
            continue;
        }
        //free(aux);
        
    }
}
void exibirArvore(No* raiz)
{
    
    if(raiz!=NULL)
    {
        printf("\n%d\n",raiz->conteudo);
        exibirArvore(raiz->esquerda);
        exibirArvore(raiz->direita);
    }
}
void liberarArvore(No* raiz)
{
    if(raiz!=NULL)
    {
        liberarArvore((*raiz).esquerda);
        liberarArvore((*raiz).direita);
        free(raiz);
    }
}

int lerDoTeclado()
{
    while(1){
        printf("\ninserir: ");
        int aux;
        scanf("%d",&aux);
        if(aux<1|| aux>100)
        {
            continue;       
        }else{
            return aux;
            break;
        }
    }
}
void waiting()
{
   
    printf("\npressione qualquer tecla para imprimir arvore");
    getchar();
    getchar();
     system("clear");
}
int main(int argc, char*argv[])
{   
    No* raiz=NULL;
    int num_casos;
    //num_casos=(int*)calloc(1, sizeof(int));//ler numero de casos
    int num_testes;
    //num_testes=(int*)calloc(1, sizeof(int));//ler numero de elementos a serem inseridos  (por caso)
    int num_filho;
    //num_filho=(int*)calloc(1, sizeof(int));
    printf("\n*****inserir numero de casos***** ");
    num_casos=lerDoTeclado();
    for(int i=0; i<num_casos;i++){
        printf("\n----operacao de numero %d-----", i);
        printf("\n*****inserir numero de elementos***** ");
        num_testes=lerDoTeclado();
        
        
        opPreencher(&raiz, num_testes);
        printf("\n***filho a ser buscado***");
        num_filho=lerDoTeclado();
        system("clear");
        encontrarFilhos(raiz, num_filho);
        waiting();
        printf("\n***exibir arvore: *****\n");
        exibirArvore(raiz);
        liberarArvore(raiz);
    }
return 0;
}