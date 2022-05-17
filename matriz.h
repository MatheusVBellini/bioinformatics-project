#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
	int** dados;
	int tamanho;
}matriz;

void nova_matriz(matriz* mat, int tam);
void destruir_matriz(matriz* mat);
void print_matriz(matriz mat);
void OrdenaDigitos(matriz A, int posicao);
void OrdenaNumeros(matriz A);

#endif

