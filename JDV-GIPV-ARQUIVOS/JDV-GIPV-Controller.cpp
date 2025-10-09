//JDV-GIPV - Projeto Jogo da Vida - Etapa 1
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

#include "JDV-GIPV-Model.h"
#include "JDV-GIPV-Controller.h"
#include "JDV-GIPV-View.h"


void jogar(){
    
    exibirMundo(tamanho);

    while(true){
       modificarCelula();
       exibirMundo(tamanho);
    }

}

void modificarCelula(){

	int erro;
	int linha, coluna;

	escolherCelulaParaModificar(&linha, &coluna);
	
	
	if(mundo[linha][coluna] == 'O')
	{		
		do
		{
            char opcao = celulaInvalidaO();

			erro = 0;
			if(opcao == 's')
			{
				mundo[linha][coluna] = '.';
			}
			else if(opcao != 'n')
			{
				caracterInvalido();
				erro = 1;
			}
		}while(erro == 1);	
	}
	else
	{
		mundo[linha][coluna] = 'O';
	}
	
}