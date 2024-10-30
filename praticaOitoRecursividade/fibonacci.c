#include <stdio.h>

int chama = 0;

// Função recursiva para calcular Fibonacci e contar o número de chamadas
int fib(int n) {
    chama++; // Incrementa o contador de chamadas recursivas
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int N, X;
    
    printf("\ninserir numero testes: ");
    scanf("%d", &N);
    
    // Processamento de cada caso de teste
    for (int i = 0; i < N; i++) {
        printf("\n**inserir numero %d a ser testado: ", i);
        scanf("%d", &X); 
        chama = 0; 
        int result = fib(X); 
        printf("fib(%d) = %d calls = %d\n", X, chama - 1, result);
    }
    
    return 0;
}
