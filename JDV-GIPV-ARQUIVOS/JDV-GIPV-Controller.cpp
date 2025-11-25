//JDV-GIPV - Projeto Jogo da Vida - Etapa 6
//25/11/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

#include "JDV-GIPV-Model.h"
#include "JDV-GIPV-View.cpp"
#include "JDV-GIPV-Controller.h"
#include <windows.h>

void jogar(){
	char op;
	tamanho = perguntaTamanho();
	inicializarMundo();

	do
	{

		op = menuGeral();
		if(op == '1'){
			executarSim();
		}
		else if(op == '2'){
			exibirMundo(tamanho);
		}
		else if(op == '3'){
			modificarCelula();
		}
		else if(op == '4'){
			mostrarVizinhosMortos();
		}
		 else if(op == '5'){  
            gerenciarArquivos();
        }

	}while(op != '0');

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
				excluiLVivo(linha,coluna);						
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
		carregaVivo(linha,coluna);		
	}	
}

void mostrarVizinhosMortos(){
    int erro;
    do{
        erro = 0;
        char opcao = perguntaVizinhosMortos();
        if(opcao == 's'){
            
        }
        else if(opcao == 'n'){
            
        }
        else{
            erro = 1;
        }		
    }while(erro == 1);
}

void acharMortosVizinhos()
{
	int i, j;

	TipoCel *aux = pvivo;

	liberaLista(&pmorto);

	while(aux != NULL)
	{
		i = aux->lin;
		j = aux->col;

		//superiores
		if(mundo[i-1][j-1] == '.' )		
			carregaMorto(i-1,j-1);
		
		if(mundo[i-1][j] == '.')		
			carregaMorto(i-1,j);
		
		if(mundo[i-1][j+1] == '.')
			carregaMorto(i-1,j+1);


		//Laterais
		if(mundo[i][j-1] == '.')
			carregaMorto(i,j-1);
		if(mundo[i][j+1] == '.')
			carregaMorto(i,j+1);


		//Inferiores
		if(mundo[i+1][j-1] == '.' )		
			carregaMorto(i+1,j-1);
		
		if(mundo[i+1][j] == '.')		
			carregaMorto(i+1,j);
		
		if(mundo[i+1][j+1] == '.')
			carregaMorto(i+1,j+1);

		aux = aux->next;
	}
}



void executarSim()
{
	int quant = quantSim();
	int velocidade = velSim();

	printf("Total de vivos inicial: %d\n", totvivo);
    TipoCel *teste = pvivo;
    while(teste != NULL) {
        printf("Vivo em: %d,%d\n", teste->lin, teste->col);
        teste = teste->next;
    }

	//loop pra cada geração
	for(int geracao = 1; geracao <= quant; geracao++)
	{
		limpaTela();

		printf("Geracao: %d/%d\n", geracao, quant); 		

		acharMortosVizinhos();
				
		simulacao();

		inicializarMundo();

		exibirMundo(tamanho);


		if(velocidade == 0)
		{
			system("pause");
		}
		else
		{
			Sleep(velocidade * 1000);
		}

	}
	
	printf("\n Fim da Simulacao!\n"); 
	system("pause");	
}

void gerenciarArquivos()
{
    char op = menuArquivo();
    
    if(op == '1')
    {
        salvarArquivo("savegame.dat", 0); // 0 indica estado atual
        printf("Geracao salva com sucesso em %s!\n", "savegame.dat");
        system("pause");
    }
    else if(op == '2')
    {
        if(carregarArquivo("savegame.dat"))
        {
            printf("Geracao carregada com sucesso!\n");
            inicializarMundo();
        }
        else
        {
            printf("Falha ao carregar arquivo!\n");
        }
        system("pause");
    }
}
