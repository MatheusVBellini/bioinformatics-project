#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "genetica.h"

int main () {
	FILE *A = fopen("arquivos/A.txt", "r");
	FILE *B = fopen("arquivos/B.txt", "r");
	FILE *out = fopen("arquivos/out.txt", "w");
	int nA = quantas_linhas(A);
	int nB = quantas_linhas(B);

	// teste -- quantas_linhas
	printf("linhas A:%d -- linhas B:%d\n", nA, nB);

	// teste -- ContagemIntersecoes
	ContagemIntersecoes(A, B, nA, nB, out);

	fclose(A); fclose(B); fclose(out);

	return 0;
}
