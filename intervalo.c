/*
aplicar a implementação das funções

*/

#include <stdio.h>
#include "intervalo.h"

//variaveis para armazenar os intervalos e contador
Intervalos intervalos[MAX_INTERVALOS];
int contador =0;
int adicionaIntervalo(int *inicio, int *fim)//função aicionar intervalos
{
    int funcionou=0;
    if(contador<MAX_INTERVALOS) //se menor que o maximo executar
    {   
        intervalos[contador].inicio=*inicio;
        intervalos[contador].fim = *fim;
        contador++;
        funcionou =1;
    }else{
        printf("\nnumero maximo de variaveis atingidas");
    }
    
return funcionou;
}
int verificaPonto(int *ponto)//função verificar pontos
{
int funcionou=0;
    for(int i =0; i<contador; i++)
    {
        if(*ponto>= intervalos[i].inicio && *ponto<= intervalos[i].fim)
        {
            printf("\nnum: %d dentro do intervalo [%d a %d]\n", *ponto, intervalos[i].inicio, intervalos[i].fim);
        }else{
            printf("\nfora dos intervalos");
        }
    }
return funcionou;
}