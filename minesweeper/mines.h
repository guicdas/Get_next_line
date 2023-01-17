#ifndef _mines_H
#define _mines_H

char *atribuirVAL(char * V, int V1, int V2, int V3);
void matrizZero(char *V, int **l);
int contagem(int k);
void putBombs(int line, int col, char *linha);
void calcBombs(int line, int col, char *linha);
void printLines(int line, int col,char *linha);
int transformVal(char VAL);
void pedirCL(char * m, char * nome);
void jogada(char * linha, int coluna, int row, int col, int line, int bomb);

#endif	