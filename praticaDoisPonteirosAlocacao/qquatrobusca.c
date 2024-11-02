/*
### Problema 4: Busca de Valores em Sequência
1. Leia um valor N (tamanho da sequência) e uma sequência de N inteiros.
2. Leia um valor B (número de buscas) e os valores que deseja buscar na sequência.
3. Para cada valor buscado, exiba a posição da primeira ocorrência (iniciando de 1). Se o valor não estiver presente, exiba "NAO".
   - Exemplo de saída:  
     ```
     3
     NAO
     2
     ```
ler o temanho de um array
preencher o array
buscar um nunero e dizer qual a primeira aparição dele
*/
int main(int argc, char*argv[])
{
    int numBusca;
    printf("\ninsira o numero a ser buscado: ");
    scanf("%d", &numBusca);
    int *vetor;
    vetor=(int*)calloc(argc, sizeof(int));
    for(int i=1; i<argc; i++)
    {
        vetor[i-1]=atoi(argv[i]);
    }
    printf("\nexibibicao: \n");
    for(int i=0; i<argc-1; i++)
    {   
        if(numBusca==vetor[i])
        {
            printf(" 1º ");
            break;
        }
        printf("  ");
    }
    printf("\n");
    for(int i=0; i<argc-1; i++)
    {   
        if(numBusca==vetor[i])
        {
            printf(" [%d]", vetor[i]);
            continue;
        }
        printf(" %d", vetor[i]);
    }
    printf("\n");

return 0;
}
