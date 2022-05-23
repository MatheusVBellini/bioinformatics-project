#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "genetica.h"

int main () {
	FILE *A = fopen("arquivos/A.txt", "r");
	FILE *B = fopen("arquivos/B.txt", "r");
	FILE *out = fopen("arquivos/out.txt", "w");
	FILE *texto = fopen("arquivos/texto.txt", "r");
	FILE *trecho = fopen("arquivos/trecho.txt", "r");
	int nA = quantas_linhas(A);
	int nB = quantas_linhas(B);
	
	// teste -- cond_txt2string (CERTO)
	char *str = NULL;
	printf("\n");
	for (int i = 0; i < 10; i++) {
		str = cond_txt2string(trecho,'\n');
		printf("%s\n", str);
	}

	// teste -- CrtlF (CERTO)
	CtrlF(texto, trecho, out);

	// teste -- quantas_linhas (CERTO)
	printf("\nlinhas A:%d -- linhas B:%d\n", nA, nB);

	// teste - OrdenaNumeros (NAO FUNCIONA COM NEGATIVOS) *************************
	matriz c;
	nova_matriz(&c, 5);
	c.dados[0][0] = 16;
	c.dados[0][1] = 22;
	c.dados[1][0] = 4;
	c.dados[1][1] = 9;
	c.dados[2][0] = 17;
	c.dados[2][1] = 20;
	c.dados[3][0] = 8;
	c.dados[3][1] = 1;
	c.dados[4][0] = 15;
	c.dados[4][1] = 23;
	OrdenaNumeros(c);
	print_matriz(c);

	// teste - txt2string (CERTO)
	char *text = txt2string(texto);
	printf("\n%s\n", text);

	// teste -- txt2matrix (CERTO)
	matriz a = txt2matriz(A);
	matriz b = txt2matriz(B);
	printf("\ntamanho: %d\n", a.tamanho);
	print_matriz(a);
	printf("\n");
	print_matriz(b);

	// teste -- ContagemIntersecoes (ainda n da pra testar) **********************************
	// ContagemIntersecoes(A, B, nA, nB, out);



	fclose(A); fclose(B); fclose(out); fclose(texto); fclose(trecho);

	return 0;
}
