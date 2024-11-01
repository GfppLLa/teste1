/*
### Problema 1: Troca de Valores Usando Ponteiros
1. Leia dois valores inteiros X e Y.
2. Utilize ponteiros para trocar os valores de X e Y.
3. Exiba os valores antes e depois da troca em duas linhas.
   - Exemplo de saída:  
     ```
     5 10
     10 5
     ```
*/
#include <stdlib.h>
#include <stdio.h>
void troca(int **um, int **dois);
void troca (int **um, int **dois)
{
    int *aux1=*um;
    *um=*dois;
    *dois=aux1;
    //not the best option
}
int main(int argc, char*argv[])
{

    int a=0, b=0;

    int *ptra=&a;
    int *ptrb=&b;
    int **varUm=&ptra;//=(int*)calloc(1, sizeof(int));
    int **varDois=&ptrb;//=(int*)calloc(1, sizeof(int));


    printf("\nn1: ");
    scanf("%d", &a);
    
    printf("\nn2: ");
    scanf("%d", &b);
    printf("\nvalor inical: %d e %d ", **varUm, **varDois);
    troca(&varUm, &varDois);//envia para função os endereços dos ponteiros 
    printf("\nvalor final: %d e %d ", **varUm, **varDois);
return 0;
}