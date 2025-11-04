//JDV-GIPV - Projeto Jogo da Vida - Etapa 4
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

//Matriz mundo
extern char **mundo;

//Matriz auxiliar
extern char **proxGen;

//Tamanho da matriz mundo
extern int tamanho;

//Total Vivos, Mortos Vizinhos de Vivos e vivos da proxima geração
extern int totvivo, totmorto, totvivoprox;

//Inicializa o mundo com '.'
void inicializarMundo();

//Matriz auxiliar
//extern char proxGen[60][60];

//Calcula vizinhas de uma celula
int calcVizinha(int linha,int coluna);
