//JDV-GIPV - Projeto Jogo da Vida - Etapa 3
//28/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida


#include "JDV-GIPV-Controller.h"
#include "JDV-GIPV-View.cpp"

//FALTA: OPCAO DE MOSTRAR OU NAO MOSTRAR CELULAR MORTAS VIZINHAS

void jogar(){
	char op;
	op = menuGeral();
	if(op == '1'){
		limpaTela();
		
		inicializarMundo();
		tamanho = perguntaTamanho();
    
    	exibirMundo(tamanho);

	    while(true){
	       modificarCelula();
	       mostrarVizinhosMortos();
	       exibirMundo(tamanho);
	    }
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

void mostrarVizinhosMortos(){
	
	int erro;
	do{
		erro = 0;
		char opcao = perguntaVizinhosMortos();
		if(opcao == 's')
		{
			for(int linha = 0;linha < tamanho;linha++)
			{
				for(int coluna = 0;coluna < tamanho;coluna++)
				{
					if(mundo[linha][coluna] == 'O')
					{
						for(int i = linha - 1;i <= linha+1;i++)
						{
							for(int j = coluna -1; j <= coluna+1;j++)
							{
								if(mundo[i][j] == '.')
								{									
									mundo[i][j] = '+';
								}
							}
						}
					}
				}
			}
		}
		else if(opcao == 'n')
		{
			for(int linha = 0;linha < tamanho;linha++){
				for(int coluna = 0;coluna < tamanho;coluna++){
					if(mundo[linha][coluna] == '+'){
						mundo[linha][coluna] = '.';
					}
				}
			}
		}
		else
		{
			erro = 1;
		}		
	}while(erro == 1);
	
}

int calcVizinha(int linha,int coluna){
	contviz = 0;
	
	//Contar vizinhos superiores
	if(mundo[linha+1][coluna-1] == 'O'){
		contviz++;
	}
	if(mundo[linha+1][coluna] == 'O'){
		contviz++;
	}
	if(mundo[linha+1][coluna+1] == 'O'){
		contviz++;
	}
	
	//Contar vizinhos laterais
	if(mundo[linha][coluna-1] == 'O'){
		contviz++;
	}
	if(mundo[linha][coluna+1] == 'O'){
		contviz++;
	}
	
	//Contar vizinhos inferiores
	if(mundo[linha-1][coluna-1] == 'O'){
		contviz++;
	}
	if(mundo[linha-1][coluna] == 'O'){
		contviz++;
	}
	if(mundo[linha-1][coluna+1] == 'O'){
		contviz++;
	}
	
	return contviz;
	
}


