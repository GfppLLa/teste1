/*
receber a b e c
se a = 0 sair
calcular_raizes func()
a maior que 0 e menor que 10.0
b <= -1000.0
c <= 1000.0


*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void preencher(float *a, float *b, float *c)
{
    float temp=0.0;
    char var[] = {'A','B','C'};

    printf("\naquisicao de valores\n");
    for(int i=0; i<=2; i++)
    {
     printf("insira o valor de %c: ", var[i]);
     scanf("%f", &temp);
        if(i==0) //variavel a
        {  
            if(temp==0)
            {
                printf("\n*****nao pode ser 0******");
                temp=0.0;
                i--;
                continue;
            }
            *a=temp;
                
        }else{
            if(i>=1)
            {
                if(temp <-1000.0 || temp>1000.0)
                {   
                    printf("\n*****fora do intervalo******");//refazzer
                    i--;
                    continue;
                }
                if(i==1)
                {
                    *b=temp;
                }
                if(i==2)
                {
                    *c=temp;
                }
            }
        }
    }
}
float raiz_quadrada(float numero)
{
    float tolerancia = 0.0000001;
    float chute = numero/2.0;
    float proximo_chute;
    while(1)
    {
        proximo_chute =0.5*(chute+(numero/chute));
        if ((chute - proximo_chute) < tolerancia && (chute - proximo_chute) > -tolerancia)
        {
            break;
        }
        chute=proximo_chute;
    }
return chute;
}
float disciminante(float *a, float *b, float *c)
{
    float disc=0;
    disc=((pow(*b, 2))-(4* (*a * *c))); //necessario "*" na frente da variavel pra usar
    if(disc <0)
    {
     return -1;   //impossivel calcular e sair
    }
return disc;
}
void calcular_raizes (float *a, float *b, float *c, float *x1, float *x2)
{

    float discriminante = 0.0;
    if((discriminante =disciminante(a,b,c)) ==-1)
    {
        printf("\nimpossivel calcular ");
        exit(1);
    }else{
        float raiz_discriminante = raiz_quadrada(discriminante);
        *x1=(((-*b)+raiz_discriminante)/(2**a));
        *x2=(((-*b)-raiz_discriminante)/(2**a));
    }

}
int main(int argc, char *argv[] )
{

    float *a, *b, *c, *x1, *x2;
    a=(float*) calloc(1, (sizeof(float)));
    b = (float*)calloc (1,(sizeof(float)));
    c = (float*)calloc(1,(sizeof(float)));
    x1 = (float*) calloc(1,sizeof(float));
    x2=(float*)calloc(1,sizeof(float));

    preencher(a, b, c);
    calcular_raizes(a, b, c, x1, x2);
    printf("\nvalor de x1: %f \nvalor de x2: %f", *x1, *x2);

return 0;
}
/*
questao 1 modularização

*/