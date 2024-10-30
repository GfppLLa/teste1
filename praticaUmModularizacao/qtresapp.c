/*
### Exercício 3: Aproximação de π
1. Leia um valor inteiro n.
2. Implemente a função `aproxPi` que:
   - Se n for menor que 1, exiba "Número de termos inválido. Deve ser maior ou igual a 1."
   - Caso contrário, use a fórmula de Leibniz para calcular a aproximação de π e exiba o valor com 5 casas decimais:
   \[
   \pi \approx 4 \times \left(1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \cdots \right)
   \]

*/
void outPi(int *termos, long double *pii)
{
    printf("\n-->pi<--\nnumero de termos--> %d\npi-->%.30LF\n",*termos,*pii);
}
long double aproxPi(int i, int *termos, long double *pii) //recursividade
{
    if(i>= *termos)
    {
        return *pii;

    }else{
        int sinal=0;
        if(i % 2 == 0)
        {
         sinal =1; //par
        }
        else{ 
                 sinal =-1;//impa
            }

        *pii=*pii+(sinal*((4.0/(2*i+1))));
        
        printf("\ndebud: i:%d \n",i);

        return aproxPi(i+1, termos, pii);
    }   

}
void obterTermos(int *termos)
{
    printf("\n***inserir termo***");
    int aux;
        while(1){
        printf("\n-->");
        scanf("%d",&aux);
            if(aux>0)
            {
                *termos=aux;
                break;
            }
        }
}
int main (int argc, char *argv[])
{
    int *termos;
    termos=(int*)calloc(1,(sizeof(int)));
    long double *pii;
    pii=(long double*)calloc(1,sizeof(long double));
    obterTermos(termos);
        *pii = 0.0;
    aproxPi(0, termos,pii);
    
    outPi(termos, pii);

return 0;
}