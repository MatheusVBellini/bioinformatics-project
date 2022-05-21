#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matriz.h"
#include "genetica.h"

void ContagemIntersecoes(FILE *A, FILE *B, int nA, int nB, FILE *out) {
	// inicia contagem com zeros
	int *contagens = (int *)calloc(nA, sizeof(int));
	
	// inicia matrizes a e b
	matriz a, b;
	nova_matriz(&a, nA);
	nova_matriz(&b, nB);
	
	// le texto em a e b
	a = txt2matriz(A);
	b = txt2matriz(B);

	// ordena as matrizes
	OrdenaNumeros(a);
	OrdenaNumeros(b);

	// ???
	int primeiro_iB = 0;
	for (int i = 0; i < nA; i++)
		for (int j = primeiro_iB; j < nB; j++) {
			if (a.dados[i][1] < b.dados[j][0] || a.dados[i][0] > b.dados[j][1]) {
				if (contagens[i] == 0)
					primeiro_iB = j;
			}
			else
				contagens[i] += 1;
		}
	
	for (int i = 0; i <= nA; i++)
		fprintf(out, "%d, ", contagens[i]);

}

// converte o conteudo de um arquivo em uma string
char *txt2string(FILE *arquivo) {
	rewind(arquivo);
	int tam = 1, i = 0;
	// inicia a string
	char *string = (char *)malloc(tam*sizeof(char));

	// esreve o arquivo na string
	char chr = fgetc(arquivo);
	while (chr != EOF)	{
		string[0] = chr;
		string = (char *)realloc(string, (++tam)*sizeof(char)); // aumenta o tamanho da string para novos caracteres
		chr = fgetc(arquivo);
	}
	
	// coloca token de finalizacao na string
	string[tam-1] = '\0';

	return string;
}

// le um arquivo ate a condicao de parada passada e transforma em string
char *cond_txt2string(FILE *arquivo, char condicao) {
	int tam = 1, i = 0;
	// inicia a string
	char *string = (char *)malloc(tam*sizeof(char));

	// esreve o arquivo na string
	char chr = fgetc(arquivo);
	if (chr == EOF)
		goto end_of_file_no_string;
	while (chr != condicao) {
		string[0] = chr;
		string = (char *)realloc(string, (++tam)*sizeof(char)); // aumenta o tamanho da string para novos caracteres
		chr = fgetc(arquivo);
		if (chr == EOF)
			goto end_of_file_with_string;
	}
	
	// coloca token de finalizacao na string
	string[tam-1] = '\0';

	return string;
	
	// se EOF for encontrado antes da condicao de parada, retorna string ate ele
	end_of_file_with_string:
	string[tam-1] = '\0';
	return string;
	
	// se EOF for a primeiro caracter lido, retorna uma string EOF para sinalizar final
	end_of_file_no_string:
	return "EOF";
}

// informa a posicao dos trechos estao no texto de entrada
void CtrlF(FILE *arq_texto, FILE *arq_trechos, FILE *out) {
	
	// inicia string texto baseada no arquivo texto de entrada
	char *texto = txt2string(arq_texto);
	
	// inicia laço de procura de trechos no texto
	int i, j;
	char *trecho = cond_txt2string(arq_trechos, '\n'); 
	while (strcmp(trecho,"EOF")) {
		for (i = 0; texto[i] != '\0'; i++) {
			for (j = 0; (trecho[j] != '\0') && (texto[i + j] == trecho[j]); j++);
			if (trecho[j] == '\0') {
				fprintf(out, "%d,%d\n", i, i+j-1);
				break;
			}
		}
		trecho = cond_txt2string(arq_trechos, '\n');
	}
}
