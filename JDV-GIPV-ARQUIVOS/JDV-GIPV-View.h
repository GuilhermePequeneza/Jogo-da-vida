//JDV-GIPV - Projeto Jogo da Vida - Etapa 1
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

//Pergunta o tamanho da matriz mundo
int perguntaTamanho();

//Exibi a matriz mundo
void exibirMundo(int tamanho);

//Escolher uma célula para ser modificada
void escolherCelulaParaModificar(int *linha, int *coluna);

//Limpa a tela
void limpaTela();

//Aponta uma caractér inválido
void caracterInvalido();

//Aponta que a célula escolhida ja é 'O'
char celulaInvalidaO();

//Limpa o buffer
void fclear();

//Pegunta se quer ou nao quer vizinhos mortos aparecerem
char perguntaVizinhosMortos();

//Menu geral
char menuGeral();
