/*
### Exercício 2: Ciclo Trigonométrico
1. Leia um valor real R representando o ângulo em graus.
2. Implemente uma função que:
   - Calcule o número de voltas inteiras que o ângulo completa (R dividido por 360).
   - Determine o quadrante em que o ângulo se encontra.
3. Exiba o quadrante e o número de voltas no formato:
   ```
   QUADRANTE: <quadrante>
   QUANTIDADE DE VOLTAS: <número de voltas
   
   Q1 = 0 a 90, Q2= 90 a 180, Q3= 180 a 270, Q4= 270 a 360
   funcoes:
            lerNumero();
            calcularVoltar();
            calcularQuadrante();
            outEmTela();

*/
void outEmTela(int * voltas, int *quadrante)
{
    printf("\n-->saida<--\n-->quadrante: %d <--\n-->quantidade de voltas: %d <--\n", *quadrante, *voltas);
}
void calcularQuadrante(float *entrada, int *quadrante)
{
    if(*entrada>360)
    {
        *entrada=*entrada-360;
        calcularQuadrante(entrada, quadrante);//recursividade kkk
    }else{
        if(*entrada>=0&&*entrada<90)//quadrante 1
        {
            *quadrante=1;
        }else{
            if(*entrada>=90&&*entrada<180)//quadrante 2
            {
                *quadrante=2;
            }else{
                if(*entrada>=180&&*entrada<270)//quadrante 3
                {
                    *quadrante=3;
                }else{
                    if(*entrada>=270)//quadrante 4
                    {
                        *quadrante=4;
                    }
                }
            }
        }
    }
}
void calcularVoltas(float* entrada, int *voltas)
{
    *voltas=(int)*entrada/360.0;
}
void lerNumero(float *entrada)
{
    printf("\n****lernumero****");
        while(1)
        {
        float temp;
        printf("\ninserir: ");
        scanf("%f",&temp);
        if(temp >0.1 && temp<=1000000.1)
        {
            *entrada=temp;
            break;
        }else{ continue;}
        }
}
int main(int argc, char *argv[])
{
    float *entrada;
    entrada=(float*)calloc(1, (sizeof(float)));
    int *voltas;
    voltas=(int*)calloc(1,(sizeof(int)));
    int *quadrante;
    quadrante=(int*)calloc(1,sizeof(int));
    lerNumero(entrada); 
    calcularVoltas(entrada, voltas);
    calcularQuadrante(entrada, quadrante);
    outEmTela(voltas, quadrante);

return 0;
}
