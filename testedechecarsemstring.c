#include<stdio.h>        
    
    int main() {
        char tipo1[] = "Residencial", tipo2[] = "Industrial", tipo3[] = "Comercial", instalationType[100];
        int valid = 0;
        int instalationTypesize = 0;
  
        
        while (valid == 0) {
        instalationTypesize = 0;
        int usage = 0;
        printf("\nDigite o tipo de sua localidade (com inicial maiúscula): "); 
        scanf("%99s", instalationType);

            for (int p = 0; instalationType[p]  != '\0'; p++)
            {
                instalationTypesize++;
            }
            
            usage = (instalationTypesize);
            printf("%d", instalationTypesize);

        //int lenght = sizeof(nome) / sizeof(nome[0]);

            if (instalationType[0] == tipo1[0]) {   
                for (int q = 0; q < usage; ) {
                    if (instalationType[q] == tipo1[q]) {
                        q++;
                        if (q == usage - 1) {
                            printf("\nVálidado");
                            valid = 1;
                        }
                    } else {
                            printf("Inválido, tente novamente.");
                            valid = 0;
                            break;
                    }
                } 
            } else if (instalationType[0] == tipo2[0]){
                for (int w = 0; w < usage; ) {
                    if (instalationType[w] == tipo2[w]) {
                        w++;
                        if (w == usage - 1) {
                            printf("\nVálidado");
                            valid = 1;
                        }
                    } else {
                        printf("Inválido, tente novamente.");
                        valid = 0;
                        break;
                    }
                }   
            } else if (instalationType[0] == tipo3[0]) {
                for (int e = 0; e < usage; ) {
                    if (instalationType[e] == tipo3[e]) {
                        e++;
                        if (e == usage - 1) {
                            printf("\nVálidado");
                            valid = 1;
                        }
                    } else {
                        printf("Inválido, tente novamente.");
                        valid = 0;
                        break;
                    }
                }
            } else {
                valid = 0;
                printf("Inválido.");
            }

        }
        
        printf("Pode prosseguir\n");
        return 0;
    }