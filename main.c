#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "genetica.h"

int main () {
	FILE *A = fopen("arquivos/A.txt", "r");
	FILE *B = fopen("arquivos/B.txt", "r");
	FILE *out1 = fopen("arquivos/out1.txt", "w");
	FILE *out2 = fopen("arquivos/out2.txt", "w");
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
	CtrlF(texto, trecho, out1);

	// teste -- quantas_linhas (CERTO)
	printf("\nlinhas A:%d -- linhas B:%d\n", nA, nB);

	// teste - OrdenaNumeros (CERTO)
	matriz c;
	nova_matriz(&c, 5);
	c.dados[0][0] = 16;
	c.dados[0][1] = 22;
	c.dados[1][0] = 4;
	c.dados[1][1] = 9;
	c.dados[2][0] = 17;
	c.dados[2][1] = 20;
	c.dados[3][0] = -8;
	c.dados[3][1] = -1;
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
	OrdenaNumeros(a);
	print_matriz(a);
	printf("\n");
	OrdenaNumeros(b);
	print_matriz(b);

	// teste -- ContagemIntersecoes (CERTO)
	ContagemIntersecoes(A, B, nA, nB, out2);



	fclose(A); fclose(B); fclose(out1); fclose(out2); fclose(texto); fclose(trecho);

	return 0;
}
