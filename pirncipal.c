/*
receber dois ints
armazenar em structs
array de structs
receber int e comparar se dentro do intervalo  de algumas das structs

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//receber e imprimir erros
void logErro(const char *mensagem) {
    FILE *arquivo = fopen("log_erro.txt", "a");  // abre o arquivo em modo append
    if (arquivo == NULL) {
        perror("erro ao abrir o arquivo de log");
        return;
    }

    // obtém a hora atual
    time_t agora;
    time(&agora);
    char *data_hora = ctime(&agora);  // converte para string

    // remove a nova linha do final da string
    data_hora[strcspn(data_hora, "\n")] = '\0';

    // escreve no arquivo de log
    fprintf(arquivo, "[%s] erro: %s\n", data_hora, mensagem);

    fclose(arquivo);  // fecha o arquivo
}

//função de ler do teclado
void lerDo(int *toLer, int *valor)
{
    int lacoOut=0;
    do{
        printf("\n--insina numero: ");//
        char *ler;
        ler =(char*)calloc(100,(sizeof(char)));
        if(ler==NULL)
        {
            printf("\n--memoria na lcoada--");
            exit(1);
        }
        int i=0;
        fgets(ler, 100, stdin); //ler com fgets
        ler[strcspn(ler, "\n")]= '\0'; //troca o caracter de enter por fim de linha
        while(ler[i]!='\0')
        {
            char temp = ler[i];
            int tempN = isdigit(temp);
            if(tempN==0)
            {
                printf("\n--inserir apenas numeros--");//se n for numero tempn é 0
                break;
            }else{
                continue;//continuar para verificar os demais
            }

        i++;
        }
        if(ler[i]=='\n') //se rodou tuodo do array e se o ultimo indice é o fim de linha
        {
            lacoOut=1;
            int varTemp=atoi(ler);
            valor=varTemp;
        }
        free(ler);
    }while(lacoOut==0);


}
//função que recebe o resultado e imprime em tela
void escrever(int opt, )
{

}
//função sair

void menuTeste()
{
    int valorTeste=0;
    while(1)
    {
        /* code */
        while(1){
        printf("\n******operacoes******\n1- inserir um novo intervalo\n2- verificar ponto\n3- sair\n-------------");
        char temp=' ';
            while(1){  //while((temp=getchar())!= EOF)
                temp=getchar();
                if(temp ==EOF)
                {
                    break;
                }
            }
            if(temp =='1'||temp =='2' || temp =='3' )
            {
                int temp1 = temp;
                op(1, temp1);
            }else{
                    continue;
            }
        }


    } 
    
}

void op(int mind, int aux)
{
    if(mind ==0)
    {
        menuTeste();
    }else{
        if(mind ==1)
        {
            switch (aux)
            {
            case 1: //inserir intervalo
                                         //chamar função no arquivo c auxiliar
                                         //receber valor boolenao se a inserção deu certo
                                         //chamar funçãoa uxiliar que ler e volta valor
                                         //chamar função axuliar que imprime em tela
                        int * interA;
                        int * interB;
                        interA = (int*) calloc(1, (sizeof(int)));
                        interB = (int*) calloc(1,(sizeof(int)));
                        printf("\n***inserir intervalos***\n***insira inicio: ***");
                        lerDo(1, interA); //ler para o valor A
                        printf("\n***inserir fim do intervalo***");
                        lerDo(1, interB); //ler para valor B
                        int teste=adicionaIntervalos(interA, interB);
                        free(interA);
                        free(interB);         
                break;
            case 2: //verificar intervalo
                                        //chamar função no arquivo c auxiliar
                                        //receber valor booleano se a operação deu certo e valor de operação
                                        //chamar funçãoa uxiliar que ler e volta valor
                                         //chamar função axuliar que imprime em tela
                        int *interC;
                        interC=(int*)calloc(1, (sizeof(int)));
                        //todo terminar a implementação e o que fazer com o resultado recebido

                break;
            
            case 3: //sair

                break;
            }
        }
    }

}

int main(int argc, char *argv[])
{
    op();

return 0;
}

/*
notas da versão, 
terminar funções
:
-escrever()
-op()

implementar:--em outro arquivo--
-implementaponto()
-verificaPonto()


*/