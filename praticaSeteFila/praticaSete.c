#include <stdio.h>
#include <stdlib.h>
#include "pratica.h"
/*


   1.  leia um número inteiro n, que representa a quantidade de casos de teste.

    2. para cada caso de teste:
        leia um número inteiro m, que indica o número de alunos.
        leia m inteiros, representando as notas dos alunos na ordem de chegada.

    3. reordene a lista de notas de forma decrescente.

    4. compare a lista original com a lista reordenada.

    5. conte quantos alunos permanecem nas mesmas posições após a reordenação.

    6. para cada caso de teste, imprima um número inteiro representando a quantidade de alunos que não trocaram de lugar.
*/
int escolhePivo(int tamanho)
{
int retorno= rand()%tamanho;

return retorno;
}
void reordena(int *vetorUm, int *vetorDois, int *tamanho){//reordenar fila com base nos ints dos valores, recebe o original e o novo
    //usar 
    int *numMenor;
    int *numMaior;
    numMaior=(int*)calloc(*tamanho, sizeof(int));
    numMenor=(int*)calloc(*tamanho,sizeof(int));
    int menor=0, maior=0, pivo=0;
    pivo=escolhePivo(*tamanho);
        //laço mais externo
        for( int i=0; i<*tamanho; i++)
        {
            if(vetorUm[i]==vetorUm[pivo])
            {
                continue;
            }
            if(vetorUm[i]<vetorUm[pivo])//menor que o pivo
            {
                numMenor[menor]=vetorUm[i];
                menor++;
            }
            if(vetorUm[i]>vetorUm[pivo])
            {
                numMaior[maior]=vetorUm[i];
                maior++;
            }
        }
    for(int i=tamanho; i>0;i--)
    {
        if(maior!=0) //fazer dentro de cada if uma iteraçao pra verificar todos os numeros e pegar o maior e retirar ele do vetor numMaior
        {   
            int temp=0, temp2=0;
            for (int k=0; k<maior;k++)
            {
                if(numMaior[k]>temp)
                {
                temp=numMaior[k];
                temp2=k;
                }
            }
            vetorDois[i]=numMaior[temp2];
            numMaior[temp2]=numMaior[maior-1];
            maior--;
            continue;
        }
        if(maior ==0)
        {
        vetorDois[i]=vetorUm[pivo];
        }
        if(menor!=0)
        {
            int temp=10000, temp2=0;
            for (int k=0; k<menor;k++) 
            {
                if(numMenor[k]<temp)
                {
                temp=numMenor[k];
                temp2=k;
                }
            }
            vetorDois[i]=numMenor[temp2];
            numMenor[temp2]=numMenor[menor-1];
            menor--;
        }
        
    }

    
}
void lerNums(int *num) //verificar se num no intervalo
{
    int temp;
    while(1)
    {
        temp=0;
        printf("\nlernums: insira numero: ");
        scanf("%d",&temp);
        if(temp>1&&temp<100)
        {
            *num=temp;
            break;
        }
        fflush(stdin);

    }
}
void counterOP(Node *fila, int *vetor) //recebe a fila e transforma em array e o retorna 
{
    int i=0;
    /*
    while(fila!=NULL)
    {
        vetor[i]=(*fila).nota;
        fila=(*fila).nxt; //// 'fila' é atualizado para o próximo nó da lista encadeada, usando desreferenciação explícita para acessar o campo 'nxt'
        i++;
    }*/
    while (fila!=NULL)
    {
        /*  // Forma divertida
        int *temp;
        temp=(int*)calloc(1, sizeof(int));
        if(temp==NULL)
        {
        exit(1);
        }
        pop(fila, temp);
        *vetor[i]=*temp; 
        free(temp);
        i++
         */
        pop(fila, vetor[i]);//forma eficiente
        i++;

    }
    
    
}
void oP()
{
    
    int *numNotas;
    numNotas=(int*)calloc(1,sizeof(int));
    printf("\ninserir numero de testes: ");
    lerNums(numNotas); 
    int *tempT;
    tempT=(int*)calloc(1,sizeof(int));
    for(int i =0; i<*numNotas;i++)
    {
        Node *filaProv = criar();//criar uma lista 1
        //Node *filaCtr = criar();//criar uma lista 2
        while(1) //toda iteração de ordenar push e comparar listas tem que ser aqui
        {  
            int *qtdNotas; //inserir quantas notas 
            qtdNotas=(int*)calloc(1,sizeof(int));
            printf("\n***oP: *****\ninserir nuemro de notas do aluno %d\n",i); //ler numero de notas a serem inseridas
            lerNums(qtdNotas);
                for(int k=0; k<qtdNotas;k++)
                {
                lerNums(tempT);//ler nota do aluno index i
                filaProv=push(filaProv,tempT);//push nota
                *tempT=0;
                }   
            int* tempN;        //criar array de ints 
            tempN=(int*)calloc(qtdNotas,(sizeof(int)));    //aloca arrays de int
            counterOP(filaProv,tempN); //preenche o array de ints com a fila
            int *tempM; //vetor ordenado
            tempM=(int*)calloc(qtdNotas,(sizeof(int)));
            reordena(tempN, tempM, qtdNotas); //recebe o array desordenado e o ordena



            //todo: função que recebe a prov e retorna a ctr
        }           
                     
        liberar_fila(filaProv);

    }
    //preencher lista um

    free(numNotas);
    free(tempT);//liberar 

}
int main(int argc, char *argv[])
{
    srand(time(NULL));
   int numT;
    for(int i =0; i<numT; i++)
    {
        oP;
    }

return 0;
}