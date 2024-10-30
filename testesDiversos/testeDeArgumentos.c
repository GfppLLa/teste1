#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]) //argc numero de argumentos, argv argumentos escritos, o primeiro é o nome do programa
{
    printf("\nARGC %i \nARGV:{",argc);
    for(int i=0; i<argc; i++)
    {
        printf("\"%s\", ",argv[i]);
    }
    printf("}\n");
return 0;
}