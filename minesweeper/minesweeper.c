#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mines.h"

#define A 3

void escolha(char *V, char **argv);

int main(int argc, char **argv){
    
	(void)argc;      //fazer o argumento ao fzr o cmd e dps
    char V[A];
	int col, line;

    printf("\nNew game.\n\n");

    escolha(V, argv);
	printf("\n%d %d\n", V[0], V[1]);
	col=V[0];
	line=V[1];
	int linha[col][line];

    matrizZero(V, linha);
/*
	putBombs(line, col, linha);

	calcBombs(line, col, linha);

	primlinhaNums(line, col, linha);

	printLines(line, col, linha);

    printf("\ninterface\n\n");

	printPirmLinha(col, line, linha);

	printCadaLinha(col, line, linha);

    printf("\n\njogada: ");
    scanf("%d %d", &coluna, &row);
    printf("%d %d", coluna, row);

    jogada(linha, coluna, row, col, line, bomb);
*/

free(linha);
}

void escolha(char *V, char **argv){
	int i;
	char *esc = argv[1];

	printf("Escolher modo:\n\nEASY\n(9x9 10 Minas)\n\nMEDIUM\n(16x16 40 Minas)\n\nHARD\n(30x16 99 Minas)\n\nEXTREME\n(24x30 180 Minas)\n\nCUSTOM\n(9-30 Colunas e Linhas 10-270 minas)\n\nSAIR\n\n");

	for(i = 0 ; argv[i] ; i++){
		esc[i]=toupper(esc[i]);
	}

	if(strcmp(esc,"SAIR")==0){
		printf("Programa terminou\n");
		exit(1);
    }

	if(strcmp(esc, "EZ")==0){
		V = atribuirVAL(V, 9, 9, 10);
	}else{
		if(strcmp(esc, "MEDIUM")==0){
			V = atribuirVAL(V, 16, 16, 40);
    	}else{
			 if(strcmp(esc, "HARD")==0){
				V = atribuirVAL(V, 30, 16, 99);
			}else{
				if(strcmp(esc, "EXTREME")==0){
					V = atribuirVAL(V, 24, 30, 180);
				}else{
					printf("\nIsso não é uma escolha!!");
					exit(1);
				}
			}
        } 
    }/* else{
            if(strcmp(esc, "CUSTOM")==0){
                printf("\nColunas:");
                    pedirCL(c, "colunas");                                                                
                                printf("\nLinhas:");
                        pedirCL(l, "linhas");

                    alteracao(c, l);
                    printf("\n\n%s %s\n", c, l);
                printf("\nBombas:");
                    scanf(" %[^\n]", BO);
                 if(BO[0]==48 && BO[1]==48){
        printf("O mínimo são 10 bombas.\n");
                                chose();
                            }else if(BO[0]==50){
                                if(BO[1]>55){
                printf("O máximo são 270 bombas.\n");
                        chose();
                    }else if(BO[1]==55 && BO[2]>48){
                    printf("O máximo são 270 bombas.\n");
                    chose();
                        }
                }
                    strcpy(b, BO);
            printf("\n\n%s %s %s", c , l ,b);
                            
                    }
                }
            
            }*/
}