#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "genetica.h"

// cria uma instancia de matriz
void nova_matriz(matriz* mat, int tam) {
	// inicia o atributo 'dados' como uma matriz n por 2
	mat->dados = (int **)malloc(tam*sizeof(int*));
	for (int i = 0; i < tam; i++)
		mat->dados[i] = (int *)malloc(2*sizeof(int));
	
	// dá ao atributo 'tamanho' o seu valor
	mat->tamanho = tam;
}

// limpa a memoria ocupada pela matriz
void destruir_matriz(matriz* mat) {
	free(mat -> dados);
	mat -> tamanho = 0;
}

// gera uma matriz aleatoriamente para realizacao de teste
matriz matriz_aleatoria(int tam) {
	matriz mat;
	nova_matriz(&mat, tam);
	
	// seleciona a seed dos numeros pseudoaleatorios
	srand(time(0));

	for (int i = 0; i < tam; i++) {
		mat.dados[i][0] = rand()%21;
		mat.dados[i][1] = rand()%21;
	}

	return mat;
}

// mostra os dados contidos no atributo 'dados' da matriz
void print_matriz(matriz mat) {
	for (int i = 0; i < mat.tamanho; i++)
		printf("{%d,%d}\n", mat.dados[i][0], mat.dados[i][1]);
}

// converte um arquivo .csv formatado para matriz
matriz txt2matriz(FILE *arquivo) {
	int	qtd_linhas = quantas_linhas(arquivo);	

	// inicia matriz
	matriz mat;
	nova_matriz(&mat, qtd_linhas);

	// le arquivo em matriz
	for (int i = 0; i < mat.tamanho; i++) {
		fscanf(arquivo, "%d,%d\n", &mat.dados[i][0], &mat.dados[i][1]);
	}

	return mat;
}

// sobrescreve arquivo com conteudos de uma matriz
void matriz2txt(matriz mat, FILE *arquivo, char *filepath) {
	// apaga conteudo original do arquivo
	if (freopen(filepath, "w", arquivo) == 0) {
		printf("O arquivo nao pode ser sobrescrito");
		return;
	}

	for (int i = 0; i < mat.tamanho; i++) {
		fprintf(arquivo, "%d,%d\n", mat.dados[i][0], mat.dados[i][1]);
	}
}

// ordena numeros em relacao a um digito especifico
void OrdenaDigitos(matriz A, int posicao) {
	// inicia B com zeros
	int* B = (int *)calloc(19, sizeof(int));
	int digito, i;
	
	// conta a frequencia de digitos de 0 a 9
	for (i = 0; i < A.tamanho; i++) {
		digito = A.dados[i][0] / posicao;
		digito %= 10;
		digito += 9;
		B[digito]++;
	}
	for (i = 1; i < 19; i++) {
		B[i] += B[i - 1];
	}

	matriz C;
	nova_matriz(&C, A.tamanho);

	for (i = A.tamanho-1; i >= 0; i--) {
		digito = A.dados[i][0] / posicao;
		digito %= 10;
		digito += 9;
		B[digito]--;
		C.dados[B[digito]][0] = A.dados[i][0];
		C.dados[B[digito]][1] = A.dados[i][1];
	}
	for (i = 0; i < A.tamanho; i++) {
		A.dados[i][0] = C.dados[i][0];
		A.dados[i][1] = C.dados[i][1];
	}

	free(B); 
}

// ordena numeros digito a digito
void OrdenaNumeros(matriz A) {
	int maior = 0, posicao = 1;

	// acha o maior inteiro em A[i][0]
	for (int i = 0; i < A.tamanho; i++) {
		if (A.dados[i][0] > maior)
			maior = A.dados[i][0];
	}

	// ordena digito a digito os numeros em A[i][0]
	while (maior / posicao > 0) {
		OrdenaDigitos(A,posicao);
		posicao *= 10;
	}
}
