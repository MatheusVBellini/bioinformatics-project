#define TESTE 2

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matriz.h"
#include "genetica.h"

int main () {

	// inicialização de variáveis
	FILE *genoma_pequeno = fopen("arquivos/genoma_pequeno.txt", "r");
	FILE *genoma_medio = fopen("arquivos/genoma_medio.txt", "r");
	FILE *genoma_grande = fopen("arquivos/genoma_grande.txt", "r");

	FILE *pos_genes_pequeno = fopen("arquivos/pos_genes_pequeno.csv", "r");
	FILE *pos_genes_medio = fopen("arquivos/pos_genes_medio.csv", "r");
	FILE *pos_genes_grande = fopen("arquivos/pos_genes_grande.csv", "r");

	FILE *fragmentos_pequeno = fopen("arquivos/fragmentos_pequeno.txt", "r");
	FILE *fragmentos_medio = fopen("arquivos/fragmentos_medio.txt", "r");
	FILE *fragmentos_grande = fopen("arquivos/fragmentos_grande.txt", "r");

	FILE *pos_fragmentos_pequeno = fopen("arquivos/saida/pos_fragmentos_pequeno.txt", "w+");
	FILE *pos_fragmentos_medio = fopen("arquivos/saida/pos_fragmentos_medio.txt", "w+");
	FILE *pos_fragmentos_grande = fopen("arquivos/saida/pos_fragmentos_grande.txt", "w+");

	FILE *saida_1_1 = fopen("arquivos/saida/atividade_genica_1_1.txt", "w");
	FILE *saida_1_2 = fopen("arquivos/saida/atividade_genica_1_2.txt", "w");
	FILE *saida_1_3 = fopen("arquivos/saida/atividade_genica_1_3.txt", "w");
	FILE *saida_2_1 = fopen("arquivos/saida/atividade_genica_2_1.txt", "w");
	FILE *saida_2_2 = fopen("arquivos/saida/atividade_genica_2_2.txt", "w");
	FILE *saida_2_3 = fopen("arquivos/saida/atividade_genica_2_3.txt", "w");
	FILE *saida_3_1 = fopen("arquivos/saida/atividade_genica_3_1.txt", "w");
	FILE *saida_3_2 = fopen("arquivos/saida/atividade_genica_3_2.txt", "w");
	FILE *saida_3_3 = fopen("arquivos/saida/atividade_genica_3_3.txt", "w");

	int n_genes_pequeno = quantas_linhas(pos_genes_pequeno); 
	int n_genes_medio = quantas_linhas(pos_genes_medio); 
	int n_genes_grande = quantas_linhas(pos_genes_grande); 

	int n_fragmentos_pequeno = quantas_linhas(fragmentos_pequeno);
	int n_fragmentos_medio = quantas_linhas(fragmentos_medio);
	int n_fragmentos_grande = quantas_linhas(fragmentos_grande);

	/* GENE MAIS ATIVO */



	/* ANÁLISE EMPÍRICA DE COMPLEXIDADE */
	clock_t ciclos_init, ciclos_1, ciclos_2, ciclos_3;

	switch (TESTE) {
		case 1: // teste 1
			ciclos_init = clock();
			ContagemLeituras(genoma_grande, pos_genes_grande, fragmentos_pequeno, pos_fragmentos_pequeno, n_genes_grande, n_fragmentos_pequeno, saida_1_1);
			ciclos_1 = clock() - ciclos_init;
			ContagemLeituras(genoma_grande, pos_genes_grande, fragmentos_medio, pos_fragmentos_medio, n_genes_grande, n_fragmentos_medio, saida_1_2);
			ciclos_2 = clock() - ciclos_1 - ciclos_init;
			ContagemLeituras(genoma_grande, pos_genes_grande, fragmentos_grande, pos_fragmentos_grande, n_genes_grande, n_fragmentos_grande, saida_1_3);
			ciclos_3 = clock() - ciclos_2 - ciclos_1 - ciclos_init;
		break;
		case 2: // teste 2
			ciclos_init = clock();
			ContagemLeituras(genoma_grande, pos_genes_pequeno, fragmentos_grande, pos_fragmentos_grande, n_genes_pequeno, n_fragmentos_grande, saida_2_1);
			ciclos_1 = clock() - ciclos_init;
			ContagemLeituras(genoma_grande, pos_genes_medio, fragmentos_grande, pos_fragmentos_grande, n_genes_medio, n_fragmentos_grande, saida_2_2);
			ciclos_2 = clock() - ciclos_1 - ciclos_init;
			ContagemLeituras(genoma_grande, pos_genes_grande, fragmentos_grande, pos_fragmentos_grande, n_genes_grande, n_fragmentos_grande, saida_2_3);
			ciclos_3 = clock() - ciclos_2 - ciclos_1 - ciclos_init;
		break;
		case 3: // teste 3
			ciclos_init = clock();
			ContagemLeituras(genoma_pequeno, pos_genes_grande, fragmentos_grande, pos_fragmentos_grande, n_genes_grande, n_fragmentos_grande, saida_3_1);
			ciclos_1 = clock() - ciclos_init;
			ContagemLeituras(genoma_medio, pos_genes_grande, fragmentos_grande, pos_fragmentos_grande, n_genes_grande, n_fragmentos_grande, saida_3_2);
			ciclos_2 = clock() - ciclos_1 - ciclos_init;
			ContagemLeituras(genoma_grande, pos_genes_grande, fragmentos_grande, pos_fragmentos_grande, n_genes_grande, n_fragmentos_grande, saida_3_3);
			ciclos_3 = clock() - ciclos_2 - ciclos_1 - ciclos_init;
		break;
		default:
			printf("O teste selecionado e invalido!\n");
	}

	// output do teste
	printf("Pequeno: %lfs\n", (double)ciclos_1/CLOCKS_PER_SEC);
	printf("Medio: %lfs\n", (double)ciclos_2/CLOCKS_PER_SEC);
	printf("Grande: %lfs\n", (double)ciclos_3/CLOCKS_PER_SEC);

	// fecha os arquivos após processá-los
fecha_arquivos: 

	fclose(genoma_pequeno); 
	fclose(genoma_medio); 
	fclose(genoma_grande); 
	fclose(pos_genes_pequeno); 
	fclose(pos_genes_medio); 
	fclose(pos_genes_grande); 
	fclose(fragmentos_pequeno); 
	fclose(fragmentos_medio); 
	fclose(fragmentos_grande); 
	fclose(pos_fragmentos_pequeno);
	fclose(pos_fragmentos_medio);
	fclose(pos_fragmentos_grande);
	fclose(saida_1_1);
	fclose(saida_1_2);
	fclose(saida_1_3);
	fclose(saida_2_1);
	fclose(saida_2_2);
	fclose(saida_2_3);
	fclose(saida_3_1);
	fclose(saida_3_2);
	fclose(saida_3_3);

	return 0;
}
