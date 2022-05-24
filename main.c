#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "genetica.h"

int main () {

	/* IDENTIFICAÇÃO DE GENE MAIS ATIVO */

	// inicialização de variáveis
	FILE *genoma = fopen("arquivos/genoma_pequeno.txt", "r");
	FILE *pos_genes = fopen("arquivos/pos_genes_pequeno.csv", "r");
	FILE *fragmentos = fopen("arquivos/fragmentos_pequeno.txt", "r");
	FILE *pos_fragmentos = fopen("arquivos/saida/pos_fragmentos_pequeno.txt", "w");
	FILE *saida = fopen("arquivos/saida/atividade_genica_pequeno.txt", "w");
	int n_genes = quantas_linhas(pos_genes); 
	int n_fragmentos = quantas_linhas(fragmentos); 

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
