/*
declaração struct intervalo 
declarações funções
*/

#ifdef INTERVALO_H //verifica se a constante esta definida, se nao estivar ele segue
#define INTERVALO_H //define a costante 

typedef struct{ 
    int inicio;
    int fim;
} Intervalo;

#define MAX_INTERVALOS 100

int adicionaIntervalo(int inicio, int fim);
int verificaPonto(int ponto);

#endif