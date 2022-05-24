#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "genetica.h"

int main () {

	/* IDENTIFICAÇÃO DE GENE MAIS ATIVO */

	// inicialização de variáveis
	FILE *genoma = fopen("arquivo/genoma_grande.txt", "r");
	FILE *pos_genes = fopen("arquivo/pos_genes_grande.csv", "r");
	FILE *fragmentos = fopen("arquivo/fragmentos_grande.txt", "r");
	FILE *pos_fragmentos = fopen("arquivo/pos_fragmentos_grande.txt", "rw");
	FILE *saida = fopen("arquivo/saida/atividade_genica_grande.txt", "w");
	int n_genes = quantas_linhas(pos_genes); // causando segfault
	int n_fragmentos = quantas_linhas(fragmentos); // causando segfault

	// aplica o algoritmo para verificar atividade gênica
	ContagemLeituras(genoma, pos_genes, fragmentos, pos_fragmentos, n_genes, n_fragmentos, saida);

	// fecha os arquivos após processá-los
	fclose(genoma); 
	fclose(pos_genes); 
	fclose(fragmentos); 
	fclose(pos_fragmentos);
	fclose(saida);


	/* ANÁLISE EMPÍRICA DE COMPLEXIDADE */

	return 0;
}
