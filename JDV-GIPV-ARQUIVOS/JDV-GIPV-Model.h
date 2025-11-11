 //JDV-GIPV - Projeto Jogo da Vida - Etapa 5
//11/11/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

#ifndef JDV-GIPV-MODEL.H
#define JDV-GIPV-MODEL.H

typedef struct cel
{
	int lin,col;
	struct cel *next;
}TipoCel;

//Matriz mundo
extern char **mundo;

//Matriz auxiliar
extern char **proxGen;

//Tamanho da matriz mundo
extern int tamanho;

extern TipoCel *pvivo, *pmorto, *pvivoprox;

//Total Vivos, Mortos Vizinhos de Vivos e vivos da proxima geração
extern int totvivo, totmorto, totvivoprox;

void inicializarMundo();

void simulacao();

int calcVizinha(int linha, int coluna);

void carregaVivo(int ii, int jj);

void excluiLVivo(int ii,int jj);

void carregaMorto(int ii, int jj);

void excluiLMorto(int ii,int jj);

void carregaVivoprox(int ii, int jj);

void excluiLVivoprox(int ii,int jj);

void liberaLista(TipoCel **lista);

void salvarArquivo(const char *nomeArquivo, int numGeracao);

int carregarArquivo(const char *nomeArquivo);
#endif
