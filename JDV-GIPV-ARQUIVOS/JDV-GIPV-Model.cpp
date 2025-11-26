//JDV-GIPV - Projeto Jogo da Vida - Etapa 6
//25/11/2025 - Grupo: GIPV
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
#include <stdio.h> 
#include "JDV-GIPV-Model.h"

char **mundo = NULL;
//char **proxGen = NULL;
int tamanho;

TipoCel *pvivo, *pmorto, *pvivoprox;

int totvivo, totmorto, totvivoprox;

void inicializarMundo()
{
    //Aloca memória para as linhas conforme o tamanho 
    mundo = (char**)malloc(tamanho * sizeof(char*));
    //proxGen = (char**)malloc(tamanho * sizeof(char*));
    
    //Aloca memória para as colunas de cada linha
    for(int i = 0; i < tamanho; i++)
    {
        mundo[i] = (char*)malloc(tamanho * sizeof(char));
        //proxGen[i] = (char*)malloc(tamanho * sizeof(char));
    }
    
    // Inicializar com '.'
    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < tamanho; j++)
        {
            mundo[i][j] = '.';
        }
    }

	int i, j;
	if(totvivo > 0)
	{
		TipoCel *aux = pvivo;
		while(aux != NULL)
		{
			i = aux->lin;
			j = aux->col;
			if(i >= 0 && j >= 0)
				mundo[i][j] = 'O';
			aux = aux->next;
		}
	}
}

void simulacao()
{
	int numViz, i, j;
	TipoCel *aux;
	aux = pvivo;
	

	liberaLista(&pvivoprox);
	totvivoprox = 0;

	
	while(aux != NULL)
	{
		i = aux->lin;
		j = aux->col;

		numViz = calcVizinha(i,j);
		
		if(numViz == 2 || numViz == 3){			
			carregaVivoprox(i,j);		
		}

		aux = aux->next;
	}
	
	aux = pmorto;	
	while(aux != NULL)
	{
		i = aux->lin;
		j = aux->col;

		numViz = calcVizinha(i,j);
		
		if(numViz == 3){			
			carregaVivoprox(i,j);		
		}

		aux = aux->next;
	}

	//copiar proxgen de volta pro mundo	
	liberaLista(&pvivo);
    pvivo = pvivoprox;
    totvivo = totvivoprox;
    pvivoprox = NULL;
    totvivoprox = 0;


	/*for(int i = 0; i < tamanho; i++)
	{
		for(int j = 0; j < tamanho; j++)
		{
			mundo[i][j] = proxGen[i][j];
		}
	}*/
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

void carregaVivo(int ii, int jj)
{
	TipoCel *aux = (TipoCel *) malloc(sizeof(TipoCel)); //Define ponteiro e o aloca

	if(aux == NULL)
	{
		//apresentaMensagem("Sem espaço na memoria para inclusao de celula viva\n");
		//printf("ERROERROERRO");
		return;
	}
	aux->lin = ii;
	aux->col = jj;

	if(totvivo == 0)
	{
		pvivo = aux;
		pvivo->next = NULL;
	}
	else
	{
		aux->next = pvivo;
		pvivo = aux;
	}
	totvivo++;
}

void excluiLVivo(int ii,int jj)
{
	TipoCel *aux,*aux2;

	aux = pvivo;
	aux2 = aux;
	if(totvivo > 0)
	{
		while (aux->lin != ii || aux->col != jj)
		{
			aux2 = aux;
			aux = aux->next;
		}
		if(aux->lin == ii && aux->col == jj)
		{
			if(aux2 == aux)
				pvivo = aux->next;
			else
				aux2->next = aux->next;
			free(aux);
		}
		totvivo--;
	}
}

void carregaMorto(int ii, int jj)
{
	TipoCel *aux = (TipoCel *) malloc(sizeof(TipoCel)); //Define ponteiro e o aloca

	if(aux == NULL)
	{
		//apresentaMensagem("Sem espaço na memoria para inclusao de celula morta\n");
		return;
	}
	aux->lin = ii;
	aux->col = jj;

	if(totmorto == 0)
	{
		pmorto = aux;
		pmorto->next = NULL;
	}
	else
	{
		aux->next = pmorto;
		pmorto = aux;
	}
	totmorto++;
}

void excluiLMorto(int ii,int jj)
{
	TipoCel *aux,*aux2;

	aux = pmorto;
	aux2 = aux;
	if(totmorto > 0)
	{
		while (aux->lin != ii || aux->col != jj)
		{
			aux2 = aux;
			aux = aux->next;
		}
		if(aux->lin == ii && aux->col == jj)
		{
			if(aux2 == aux)
				pmorto = aux->next;
			else
				aux2->next = aux->next;
			free(aux);
		}
		totmorto--;
	}
}

void carregaVivoprox(int ii, int jj)
{
	if(ii > 0 && jj > 0)
	{
		TipoCel *aux = (TipoCel *) malloc(sizeof(TipoCel)); //Define ponteiro e o aloca

		if(aux == NULL)
		{
			//apresentaMensagem("Sem espaço na memoria para inclusao de celula viva proxima\n");
			return;
		}
		aux->lin = ii;
		aux->col = jj;

		if(totvivoprox == 0)
		{
			pvivoprox = aux;
			pvivoprox->next = NULL;
		}
		else
		{
			aux->next = pvivoprox;
			pvivoprox = aux;
		}
		totvivoprox++;
	}
}

void excluiLVivoprox(int ii,int jj)
{
	TipoCel *aux,*aux2;

	aux = pvivoprox;
	aux2 = aux;
	if(totvivoprox > 0)
	{
		while (aux->lin != ii || aux->col != jj)
		{
			aux2 = aux;
			aux = aux->next;
		}
		if(aux->lin == ii && aux->col == jj)
		{
			if(aux2 == aux)
				pvivoprox = aux->next;
			else
				aux2->next = aux->next;
			free(aux);
		}
		totvivoprox--;
	}
}

void liberaLista(TipoCel **lista)
{
    TipoCel *atual = *lista;
    TipoCel *proximo;
    
    while(atual != NULL)
    {
        proximo = atual->next;  // Guarda o próximo antes de liberar
        free(atual);            // Libera a célula atual
        atual = proximo;        // Avança para a próxima
    }
    
    *lista = NULL;  // Zera o ponteiro da lista
}

void salvarArquivo(const char *nomeArquivo, int numGeracao)
{
    FILE *arquivo = fopen(nomeArquivo, "a"); 
    
    if(arquivo == NULL)
    {
        return;
    }
    
    TipoCel *aux = pvivo;
    while(aux != NULL)
    {
        fprintf(arquivo, "%d,%d\n", aux->lin, aux->col);
        aux = aux->next;
    }
    
    fprintf(arquivo, "\n"); 
    fclose(arquivo);
}

int carregarArquivo(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    
    if(arquivo == NULL)
    {
        return 0;
    }
    liberaLista(&pvivo);
    totvivo = 0;
    
    char linha[100];
    int lin, col;
    
    // Lê coordenadas
    while(fscanf(arquivo, "%d,%d", &lin, &col) == 2)
    {
        carregaVivo(lin, col);
    }
    
    fclose(arquivo);
    return 1;
}
