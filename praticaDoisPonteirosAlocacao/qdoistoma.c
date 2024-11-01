/*
### Problema 2: Soma Cruzada entre Sequências
1. Leia um valor N (tamanho das sequências) e duas sequências de N inteiros.
2. criar 2 vetor de 0 ate n, e preencher
2. Realize a soma cruzada: o primeiro elemento da primeira sequência com o último da segunda, o segundo com o penúltimo, e assim por diante.
3. Exiba a lista de somas resultante, separada por espaços.
   - Exemplo de saída:  
     ```
     6 6 6 6 6
     ```

*/
#include <stdlib.h>
#include<stdio.h>
void exibir(int** vetor, int num)
{
    int n=num-1;//de n ate 0
    int n2=0;//de 0 ate n
         while (n>=0)
        {
            //vetor[2][n2]=vetor[0][n2]+vetor[1][n];
            printf("\n soma de: %d e %d eh igual a : %d", vetor[0][n2],vetor[1][n], vetor[2][n2]);
            n2++;
            n--;
        }
}
void soma_cr(int** vetor, int num)
{
    //laço mais externo
    //for(int i=0; i<num; i++)
    //{
    int n=num-1;//de n ate 0
    int n2=0;//de 0 ate n
         while (n>0)
        {
            vetor[2][n2]=vetor[0][n2]+vetor[1][n];
            n2++;
            n--;
        }
        
    //}
}
void preencher(int**vetor, int num)
{
    printf("\n***preencher vetor***");
    for(int i=0; i<2; i++)
    {
        printf("\ninserir elementos da %d linha", i);
        for(int j=0; j<num; j++)
        {
            printf("\n%d elemento: ", j);
            scanf("%d", &vetor[i][j]);
        }
    }
}

int main(int argc, char*argv[])
{
    int num=0;
    printf("\ninserir n ");
    scanf("%d", &num);
    int**vetor;
    vetor=(int**)calloc(3, sizeof(int*));
    if(vetor==NULL)
    {
        printf("erro de alocacao");
        exit(1);
    }
    for(int i=0; i<num;i++)
    {
     vetor[i]=(int*)calloc(num,sizeof(int));
        if(vetor[i]==NULL)
        {
            printf("erro de alocacao");
            for(int j=0; j<i; j++)//tava i ao inves de num
            {
                free(vetor[j]);
            }
            exit(1);
        }
    }
    preencher(vetor, num);
    soma_cr(vetor, num);
    exibir(vetor, num);

}
