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


