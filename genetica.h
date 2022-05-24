#ifndef GENETICA_H
#define GENETICA_H

int quantas_linhas(FILE *arquivo);
void ContagemIntersecoes(FILE *A, FILE *B, int nA, int nB, FILE *out);
char *txt2string(FILE *arquivo);
char *cond_txt2string(FILE *arquivo, char condicao);
void CtrlF(FILE *arq_texto, FILE *arq_trechos, FILE *out);
void ContagemLeituras(FILE *arquivo_genoma, FILE *arquivo_pos_genes, FILE *arquivo_fragmentos, FILE *arquivo_pos_fragmentos, int n_genes, int n_fragmentos, FILE *arquivo_saida);

#endif 
