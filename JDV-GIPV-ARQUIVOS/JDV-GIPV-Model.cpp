//JDV-GIPV - Projeto Jogo da Vida - Etapa 3
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

char mundo[60][60];
int tamanho;

void inicializarMundo()
{
	for(int i = 0;i < 60;i++)
	{
		for(int k = 0; k < 60;k++)
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
			if(mundo[i][j] == '.' || mundo[i][j] == '+');
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
			}
		}
	}
}



