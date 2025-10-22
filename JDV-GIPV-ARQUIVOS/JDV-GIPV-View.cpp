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
#include "JDV-GIPV-View.h"


 
	
	
	//salvando par caso nao funcione
int perguntaTamanho(){
	int tam;
    do{
    	printf("Insira o tamanho do mundo(minimo:10 - maximo:60): ");
    	scanf("%d", &tam);
   		fclear();
   		if(tam >= 10 && tam <= 60){
   			break;
		   }
		else{
			printf("Tamanho invalido. Tente novamente\n");
			system("pause");
			limpaTela();
		}
	}while(true);
	
    return tam;
}

void exibirMundo(int tamanho){
	
	printf("   ");
    for(int i = 0; i < tamanho; i++)
		printf(" %0.2d", i);
	
	printf("\n\n");
	
	for(int i = 0; i < tamanho; i++)
	{
		printf("%0.2d ", i);
		for(int k = 0; k < tamanho; k++)
		{
			printf(" %2c", mundo[i][k]);
		}	
		printf("\n");
	}
}

void escolherCelulaParaModificar(int *linha, int *coluna){
	do{
		limpaTela();
		exibirMundo(tamanho);
		
		printf("\nNumero da linha que deseja modificar: ");
		scanf("%d", linha);
		fclear();
		
		printf("Numero da coluna que deseja modificar: ");
		scanf("%d", coluna);
		fclear();
		
		if (*coluna <= tamanho && *linha <= tamanho && *coluna >= 0 && *linha >= 0){
			break;
		}
		else{
			limpaTela();
			printf("Numero de colunas e/ou linhas invalido. Tente novamente\n");
			system("pause");
			
		}
	} while (true);
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

char perguntaVizinhosMortos(){
	char op;
    printf("Voce quer que mostre vizinhos mortos? (S/N): ");
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

char menuGeral()
{
     char op;
     do{
        limpaTela();
    	printf("-------------------------\n");
    	printf("|Digite 0 para Sair:    |\n");
    	printf("|Digite 1 para Jogar:   |\n");
    	printf("-------------------------\n");
    	printf("Escolha: ");
    	
    	op = getchar();
    	fclear();
    	if(op == '0' || op == '1')
    	{
             return op;
            
              }
        
		else{
           	 
			printf("Opção inválida. Pressione Enter...\n");
            getchar();
			  
        }
	}while(op != '0' || op != '1');
}
