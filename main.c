#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main () {
	matriz A;
	nova_matriz(&A, 3);
	A.dados[0][0] = 6; 
	A.dados[0][1] = 7;
	A.dados[1][0] = 3;
	A.dados[1][1] = 1;
	A.dados[2][0] = 7;
	A.dados[2][1] = 4;

	OrdenaNumeros(A);
	print_matriz(A);

	return 0;
}
