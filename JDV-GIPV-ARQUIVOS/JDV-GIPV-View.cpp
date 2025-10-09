//JDV-GIPV - Projeto Jogo da Vida - Etapa 1
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

//Bibliotecas 
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include "JDV-GIPV-Model.h"
#include "JDV-GIPV-View.h"

int perguntaTamanho(){
    int tam;
    printf("Insira o tamanho do mundo(minimo:10 - maximo:60):  ");
    scanf("%d", &tam);
    fclear();
    return tam;
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

void escolherCelulaParaModificar(int *linha, int *coluna){
    printf("Numero da linha que deseja modificar: ");
	scanf("%d", linha);
	fclear();
	printf("Numero da coluna que deseja modificar: ");
	scanf("%d", coluna);
	fclear();
}

void caracterInvalido(){
    printf("Caracter invalido\n");
}

char celulaInvalidaO(){
    char op;
    printf("Ja existe uma celula viva nessa coordenada deseja deleta-la? (S/N): ");
    scanf(" %c", &op);
    fclear();
    op = tolower(op);
    return op;
}

void fclear(){
	char carac;
	while( (carac = fgetc(stdin)) != EOF && carac != '\n'){}
}

void limpaTela(){
    system("cls");
}