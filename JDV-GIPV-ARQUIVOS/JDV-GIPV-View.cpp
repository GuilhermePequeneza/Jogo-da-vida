//JDV-GIPV - Projeto Domino - Etapa 1
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

//Bibliotecas 
#include <stdio.h>
#include <iostream>
#include "JDV-GIPV-View.h"

void perguntaTamanho(){
    printf("Insira o tamanho do mundo(minimo:10 - maximo:60):  ");
}

void exibirMundo(int tamanho){
	
    for(int i = 0;i < tamanho; i++)
		printf("\t%2d",i);
	
	printf("\n\n");
	
	for(int i = 0; i < tamanho; i++)
	{
		printf("%d", i);
		for(int k = 0; k < tamanho;k++)
		{
			printf("\t%2c", mundo[i][k]);
		}	
		printf("\n");
	}
}

int escolherCelulaParaModificar(int linha, int coluna){
    printf("Numero da linha que deseja modificar: ");
	scanf("%d",&linha);
	fclear();
	printf("Numero da coluna que deseja modificar: ");
	scanf("%d",&coluna);
	fclear();
    return linha, coluna;
}

void caracterInvalido(){
    printf("Caracter invalido");
}

char celulaInvalidaO(){
    char op;
    printf("Ja existe uma celula viva nessa coordenada deseja deleta-la? (S/N): \n");
    scanf("%c", &op);
    op = tolower(getchar());
    return op;
}

void fclear(){
	char carac;
	while( (carac = fgetc(stdin)) != EOF && carac != '\n'){}
}

void limpaTela(){
    system("cls");
}