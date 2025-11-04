//JDV-GIPV - Projeto Jogo da Vida - Etapa 4
//28/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

//Bibliotecas 
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include "JDV-GIPV-Model.h"

char **mundo = NULL;
char **proxGen = NULL;
int tamanho;

void inicializarMundo()
{
    //Aloca memória para as linhas conforme o tamanho 
    mundo = (char**)malloc(tamanho * sizeof(char*));
    proxGen = (char**)malloc(tamanho * sizeof(char*));
    
    //Aloca memória para as colunas de cada linha
    for(int i = 0; i < tamanho; i++)
    {
        mundo[i] = (char*)malloc(tamanho * sizeof(char));
        proxGen[i] = (char*)malloc(tamanho * sizeof(char));
    }
    
    // Inicializar com '.'
    for(int i = 0; i < tamanho; i++)
    {
        for(int k = 0; k < tamanho; k++)
        {
            mundo[i][k] = '.';
        }
    }
}

void simulacao()
{
	int numViz;
	//fazer a proxima geracao e armazenar na matriz proxGen
	for(int i = 0; i < tamanho; i++)
	{
		for(int j = 0; j < tamanho; j++)
		{
			numViz = calcVizinha(i,j);
			if(mundo[i][j] == '.' || mundo[i][j] == '+')
			{
				if(numViz == 3)
				{
					proxGen[i][j] = 'O';
				}
				else
				{
					proxGen[i][j] = '.';
				}
			}
			else
			{
				if(numViz <= 1)
				{
					//morte por solidao
					proxGen[i][j] = '.';
				}
				else if(numViz >= 4)
				{
					//morte por competicao
					proxGen[i][j] = '.';
				}
				else
				{
					//sobrevive
					proxGen[i][j] = 'O';
				}
			}
		}
	}

	//copiar proxgen de volta pro mundo
	for(int i = 0; i < tamanho; i++)
	{
		for(int j = 0; j < tamanho; j++)
		{
			mundo[i][j] = proxGen[i][j];
		}
	}
}

int calcVizinha(int linha, int coluna){
    int contviz = 0;
    
    for(int i = linha - 1; i <= linha + 1; i++){
        for(int j = coluna - 1; j <= coluna + 1; j++){
            if(i != linha || j != coluna){
				if(i >= 0 && i < tamanho && j >= 0 && j < tamanho){
					if(mundo[i][j] == 'O'){
						contviz++;
					}
        		}
			}
            
           
   		}
    
   
	}
	 return contviz;
}

