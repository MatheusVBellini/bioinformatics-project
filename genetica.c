#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matriz.h"
#include "genetica.h"

// conta a quantidade de linhas no arquivo
int quantas_linhas(FILE *arquivo) {
	int qtd_linhas = 0;
	char chr;
	rewind(arquivo);
	do {
		chr = fgetc(arquivo);
		if (chr == '\n')
			qtd_linhas++;
	} while(chr != EOF);
	rewind(arquivo);

	return qtd_linhas;
}

// conta a quantidade de intersecções dos intervalos de B nos de A
void ContagemIntersecoes(FILE *A, FILE *B, int nA, int nB, FILE *out) {
	// inicia contagem com zeros
	int *contagens = (int *)calloc(nA, sizeof(int));

	// inicia matrizes a e b
	matriz a = txt2matriz(A);
	matriz b = txt2matriz(B);

	// ordena as matrizes
	OrdenaNumeros(a);
	OrdenaNumeros(b);

	// ???
	int primeiro_iB = 0;
	for (int i = 0; i < nA; i++)
		for (int j = primeiro_iB; j < nB; j++) {
			if ( (a.dados[i][1] < b.dados[j][0]) || (a.dados[i][0] > b.dados[j][1]) ) {
				if (contagens[i] == 0)
					primeiro_iB = j;
			}
			else
				contagens[i] += 1;
		}
	
	for (int i = 0; i < nA; i++)
		fprintf(out, "%d\n", contagens[i]);

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
		string[i++] = chr;
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
	// se EOF for a primeiro caracter lido, retorna uma string EOF para sinalizar final
	if (chr == EOF)
		return "EOF";
	while (chr != condicao) {
		string[i++] = chr;
		string = (char *)realloc(string, (++tam)*sizeof(char)); // aumenta o tamanho da string para novos caracteres
		chr = fgetc(arquivo);
		// se EOF for encontrado antes da condicao de parada, retorna string ate ele
		if (chr == EOF) {
			string[tam-1] = '\0';
			return string;
		}
	}
	
	// coloca token de finalizacao na string
	string[tam-1] = '\0';

	return string;
}

// informa a posicao dos trechos estao no texto de entrada
void CtrlF(FILE *arq_texto, FILE *arq_trechos, FILE *out) {
	rewind(arq_texto); rewind(arq_trechos);

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

void ContagemLeituras(FILE *arquivo_genoma, FILE *arquivo_pos_genes, FILE *arquivo_fragmentos, FILE *arquivo_pos_fragmentos, int n_genes, int n_fragmentos, FILE *arquivo_saida) {
	
	// encontra a posição dos fragmentos para checar interseções com os genes
	CtrlF(arquivo_genoma, arquivo_fragmentos, arquivo_pos_fragmentos);

	// conta a quantidade de interseções entre os fragmentos e os genes
	ContagemIntersecoes (arquivo_pos_genes, arquivo_pos_fragmentos, n_genes, n_fragmentos, arquivo_saida);
}
