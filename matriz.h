#ifndef MATRIZ_H
#define MATRIZ_H

// matriz n por 2
typedef struct {
	int** dados; // valores da matriz
	int tamanho; // numero de pares de valor 
}matriz;

void nova_matriz(matriz* mat, int tam);
void destruir_matriz(matriz* mat);
void print_matriz(matriz mat);
matriz txt2matriz(FILE *arquivo);
void matriz2txt(matriz mat, FILE *arquivo, char *filepath);
void OrdenaDigitos(matriz A, int posicao);
void OrdenaNumeros(matriz A);

#endif

