//JDV-GIPV - Projeto Domino - Etapa 1
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

#include "JDV-GIPV-Controller.h"
#include "JDV-GIPV-View.h"


void jogar(){


    void perguntaTamanho();

    do{
       void exibirMundo(int tamanho);

       void modificarCelula();
    }while(true);

}

void modificarCelula(){

	int erro;
	int linha,coluna;

	int escolherCelulaParaModificar(int linha, int coluna);
	
	
	if(mundo[linha][coluna] == 'O')
	{		
		do
		{
            char celulaInvalidaO();

			erro = 0;
			if(celulaInvalidaO() == 's')
			{
				mundo[linha][coluna] = '.';
			}
			else if(celulaInvalidaO() != 'n')
			{
				void caracterInvalido();
				erro = 1;
			}
		}while(erro == 1);	
	}
	else
	{
		mundo[linha][coluna] = 'O';
	}
	
}