#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Tipo matriz (tipo opaco)

struct matriz {
    int numColumns, numLines;
    data_type **matriz;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz *m = (Matriz *)calloc(1, sizeof(Matriz));
    m->numLines = nlinhas;
    m->numColumns = ncolunas;
    m->matriz = (data_type **)calloc(nlinhas, sizeof(data_type *));

    for (int i = 0; i < nlinhas; i++) {
        m->matriz[i] = (data_type*)calloc(ncolunas, sizeof(data_type));
    }

    return m;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    if (mat ==NULL || linha >=mat->numLines || coluna >=mat->numColumns){
        exit(0);
    }

    mat->matriz[linha][coluna]=elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
 * pos-condicao: mat não é modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    if (mat ==NULL || linha >=mat->numLines || coluna >=mat->numColumns){
        exit(0);
    }
    return mat->matriz[linha][coluna];
}

/*Retorna o número de colunas da matriz mat
 * inputs: a matriz
 * output: o número de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada
 */
int recuperaNColunas (Matriz* mat)
{ 
    if (mat==NULL){
        exit(0);
    }
    return mat->numColumns;
}

/*Retorna o número de linhas da matriz mat
 * inputs: a matriz
 * output: o número de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada
 */
int recuperaNLinhas (Matriz* mat)
{
    if (mat==NULL){
        exit(0);
    }
    return mat->numLines;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat)
{
    Matriz * mTransposta=inicializaMatriz(mat->numColumns, mat->numLines);
    for (int j=0; j<mat->numLines; j++){
        for (int i =0; i<mat->numColumns; i++){
            printf("%d ", mat->matriz[j][i]);
        }
        printf("\n");
    }
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicação
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 não são modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2);

/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat)
{
    for (int j=0; j<mat->numLines; j++){
        for (int i =0; i<mat->numColumns; i++){
            printf("%d ", mat->matriz[j][i]);
        }
        printf("\n");
    }
}


/*Libera memória alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: toda a memória alocada para matriz foi liberada
 */
void destroiMatriz(Matriz* mat)
{
    for (int i = 0; i < mat->numLines; i++) {
        free(mat->matriz[i]);
    }
    free(mat->matriz);
    free(mat);
}
