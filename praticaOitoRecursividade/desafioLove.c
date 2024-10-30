#include <stdio.h>
#include <string.h>


int pFCRR(const char* string, const char* substring, int tamanhoString, int tSub) {

    if (tamanhoString == 0) {
        return 1;
    }

    if (tamanhoString < tSub || tamanhoString % tSub != 0) {
        return 0;
    }

    if (strncmp(string, substring, tSub) == 0) {
        return pFCRR(string + tSub, substring, tSub - tSub, tSub);
    }
    
    return 0; 
}

int encontrarMSC(char* s1, char* s2, int tamanho1, int tamanho2) {
    for (int tSub = 1; tSub <= tamanho1 && tSub <= tamanho2; tSub++) {
        for (int i = 0; i <= tamanho1 - tSub; i++) {
            char substring[31];
            strncpy(substring, s1 + i, tSub);
            substring[tSub] = '\0'; 

            int podeFormarS1 = pFCRR(s1, substring, tamanho1, tSub);
            int podeFormarS2 = pFCRR(s2, substring, tamanho2, tSub);
            
            if (podeFormarS1 && podeFormarS2) {
                return 1; 
            }
        }
    }
    
    return 0; 
}

int main() {
    int numeroDeCasos;
    printf("\ninserir numero de casos: ");
    scanf("%d", &numeroDeCasos); 
    
    for (int numeroPar = 1; numeroPar <= numeroDeCasos; numeroPar++) {
        char stringBinaria1[31];
        char stringBinaria2[31];
        printf("\n------opercao: %d-----",numeroPar);
        printf("\ninserir string um: ");
        scanf("%s", stringBinaria1);
        printf("\ninserir string dois: ");
        scanf("%s", stringBinaria2);
        printf("\n");
        
        printf("Pair #%d: ", numeroPar);
        
        int tamanhoS1 = strlen(stringBinaria1);
        int tamanhoS2 = strlen(stringBinaria2);
        
        int resultado = encontrarMSC(stringBinaria1, stringBinaria2, tamanhoS1, tamanhoS2);
        
        if (resultado) {
            printf("All you need is love!\n");
        } else {
            printf("Love is not all you need!\n");
        }
    }
    
    return 0;
}
