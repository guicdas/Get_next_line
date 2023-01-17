#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mines.h"

char *atribuirVAL(char *V, int V1, int V2, int V3)
{
    V[0]=V1;
    V[1]=V2;
    V[2]=V3;

	return (V);
}

void matrizZero(char *V, int **l)
{
	int i=0, j=0, col=V[0], line=V[1];

	while (i < line)
	{
		j=0;
		while (j < col)
		{
			l[i][j] = 0;
			printf("\nasd\n%d %d %d %d", line, i, j , linha[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
/*

void putBombs(int line, int col, char *linha)
{
	int i, j, bombas=0, bomb=0;
	do{                                 //meter bombas
		for(i = 0 ; i < line ; i++)
		{
            for(j = 0 ; j < col ; j++)
			{
                if(bombas==bomb)
				{
                    if(linha[i][j]=='x')
					    linha[i][j]='x';
                    else
                        linha[i][j]='0';
                }
				else
				{
                    if(rand()%(7-1+1)+1==1){ 
                        linha[i][j]='x';
                        bombas++;
                    }else{linha[i][j]='o';
                    }
                }   
            }
        }
    }while(bombas!=bomb);
}

void calcBombs(int line, int col, char *linha)
{
	int i, j, n;
	for(i = 0; i < line ; i++)			//calcular numeros
	{                
		for(j = 0 ; j < col ; j++)
		{
			if(linha[i][j]=='x')
			{

			}
			else
			{
                n=0;
				n = contagem(linha[j-1][i-1]) + n;
				n = contagem(linha[j-1][i]) + n;
				n = contagem(linha[j-1][i+1]) + n;
				n = contagem(linha[j][i-1]) + n;
				n = contagem(linha[j][i+1]) + n;
                n = contagem(linha[j+1][i-1]) + n;
                n = contagem(linha[j+1][i]) + n;
                n = contagem(linha[j+1][i+1]) + n;
                linha[j][i]=n;
            }
        }
    }
}

void primlinhaNums(int line, int col, char *linha)//verif se é preciso
{
	int i, j;

	for(j = 0, i = 1 ; j < col*2+1 ; j++)
	{				//primeira linha dos numeros
		if(j % 2 == 0)
			printf("- ");
		else
		{
			if(i<10)
                printf(" %d ", i);
            else 
            	printf("%d ", i);
            i++;
        }
    }
    printf("\n");
}

void printLines(int line, int col, char *linha)
{
	int i, j;

	for(i = 0 ; i < line ; i++)
	{							//printf de cada linha
        if(j<9)
            printf("%d  ", i+1);
		else
		 	printf("%d ", i+1);

        for(i = 0 ; i < col ; i++)
		{
            printf("%d", linha[i][j]);
            printf(" |  ");
        }
        printf("\n");

        for(j = 0 ; j < col ; j++){
            printf("|----");
        }
        printf("|\n");
    }
}

void printPirmLinha(int col, int line, char *linha)
{
	int i, j;

    for(i=0, j=1;i<col*2+1;i++)
	{		//printf primeira linha
		if(j % 2 == 0)
			printf("- ");
		else{
            if(i < 10)
				printf(" %d ", i);
			else
            	printf("%d ", i);
			i++;
		}
	}
	printf("\n");
}

void printCadaLinha(int col, int line, char *linha) // ver printLines
{
	int i, j;

   for(i = 0 ; i < line ; i++){            //printf de cada linha
		if(i < 9)
			printf("%d  ", i+1);
		else
		 	printf("%d ", i+1);

		for(j = 0 ; j < col ; j++){
			printf("o");
			printf(" |  ");
		}
		printf("\n");
		for(j = 0 ; j < col ; j++){
			printf("|----");
		}
		printf("|\n");
	}
}

int transformVal(char VAL)
{
    int val=0;
    val=(VAL/100)*100+(VAL/10)*10+VAL%10;
    return val;
}

int contagem(int k)
{   
    if(k=='x'){
        return 1;
    }
    return 0;
}

void jogada(char * linha, int coluna, int row, int col, int line, int bomb)
{
    int i, j, n, bombas=0;

    for(j=0; j<line; j++){              //meter matriz a zeros
        for(i=0; i<col; i++){
            linha[i][j]=0;
            printf("%d ", linha[i][j]);  //ver qual é coluna, qual é linha
        }
        printf("\n");
    }

    do{                                 //meter bombas
        for(j=0;j<line;j++){
            for(i=0;i<col;i++){

                if(bombas==bomb){
                    if(linha[j][i]=='x'){
                        linha[j][i]='x';
                    }else{
                        linha[j][i]='0';
                    }
                }else{            
                    if(rand()%(7-1+1)+1==1){ 
                        linha[j][i]='x';
                        bombas++;
                    }else{linha[j][i]='o';
                    }
                }   
            }
        }
    }while(bombas!=bomb);
    

    for(j=0;j<line;j++){                //calcular numeros
        for(i=0;i<col;i++){
            if(linha[j][i]=='x'){
            }else{
                n=0;
                n = contagem(linha[j-1][i-1]) + n;
                n = contagem(linha[j-1][i]) + n;
                n = contagem(linha[j-1][i+1]) + n;
                n = contagem(linha[j][i-1]) + n;
                n = contagem(linha[j][i+1]) + n;
                n = contagem(linha[j+1][i-1]) + n;
                n = contagem(linha[j+1][i]) + n;
                n = contagem(linha[j+1][i+1]) + n;
                linha[j][i]=n;
            }
        }
    }


    for(i=0, j=1;i<col*2+1;i++){           //primeira linha dos numeros
        if(i%2==0){
            printf("- ");
        }else{
            if(j<10){
                printf(" %d ", j);
            }else{ 
            printf("%d ", j);
            }j++;
        }
    }
    printf("\n");

    for(j=0;j<line;j++){            //printf de cada linha
        if(j<9){
            printf("%d  ", j+1);
        }else printf("%d ", j+1);

        for(i=0;i<col;i++){
            printf("%d", linha[j][i]);
            printf(" |  ");
        }
        printf("\n");

        for(i=0;i<col;i++){
            printf("|----");
        }
        printf("|\n");
    }

    printf("\ninterface\n\n");

    if(linha[coluna][row]==120){
        printf("BURRO DA MERDA PERDESTE O JOGO ERA UMA BOMBA\\n\n");
    }

    for(i=0, j=1;i<col*2+1;i++){       //printf primeira linha
        if(i%2==0){
            printf("- ");
        }else{
            if(j<10){
                printf(" %d ", j);
            }else{
            printf("%d ", j);
            }j++;
        }
    }
    printf("\n");

    for(j=0;j<line;j++){            //printf de cada linha
        if(j<9){
            printf("%d  ", j+1);
        }else printf("%d ", j+1);

        for(i=0;i<col;i++){
            printf("o");
            printf(" |  ");
        }
        printf("\n");
        
        for(i=0;i<col;i++){
            printf("|----");
        }
        printf("|\n");
    }


void pedirCL(char * m, char * nome){
    char M[2];

    scanf(" %[^\n]", M);

    if(M[0]==48 && M[1]<57){  //tentar ver como fazer para nao ter de fazer "09"
        printf("O mínimo são 9 %s.\n", nome);
        pedirCL(m, nome);
    }else if(M[0]>51){
        printf("O máximo são 30 %s.\n", nome);
        pedirCL(m, nome);
    }else{
        retransformCL(M, m);
        printf("%s %s\n", m,M);
    }
}

void alteracao(char * c, char * l){

    printf("\n\n%s %s \nola\n\n\n\n", c, l);
    printf("%c %c %c %c", c[0], c[1], l[0], l[1]);
    c[2]=c[2]-48;
    printf("%c %c %c %c", c[0], c[1], l[0], l[1]);
    printf("\n\n%s\n\n\n\n\n", c);

}
*/