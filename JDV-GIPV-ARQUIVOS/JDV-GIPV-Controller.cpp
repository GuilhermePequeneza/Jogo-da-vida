//JDV-GIPV - Projeto Jogo da Vida - Etapa 4
//28/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida


#include "JDV-GIPV-Controller.h"
#include "JDV-GIPV-View.cpp"
#include "JDV-GIPV-Model.h"
#include <windows.h>

//FALTA: OPCAO DE MOSTRAR OU NAO MOSTRAR CELULAR MORTAS VIZINHAS

void jogar(){
	char op;
	tamanho = perguntaTamanho();
	inicializarMundo();

	do{
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
        if(opcao == 's'){
            for(int linha = 0; linha < tamanho; linha++){
                for(int coluna = 0; coluna < tamanho; coluna++){
                    if(mundo[linha][coluna] == 'O'){
                        for(int i = linha - 1; i <= linha+1; i++){
                            for(int j = coluna - 1; j <= coluna+1; j++){
                                if(i >= 0 && i < tamanho && j >= 0 && j < tamanho){
                                    if(mundo[i][j] == '.'){
                                        mundo[i][j] = '+';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(opcao == 'n'){
            for(int linha = 0; linha < tamanho; linha++){
                for(int coluna = 0; coluna < tamanho; coluna++){
                    if(mundo[linha][coluna] == '+'){
                        mundo[linha][coluna] = '.';
                    }
                }
            }
        }
        else{
            erro = 1;
        }		
    }while(erro == 1);
}




void executarSim()
{
	int quant = quantSim();
	int velocidade = velSim();

	//loop pra cada geração
	for(int geracao = 1; geracao <= quant; geracao++)
	{
		limpaTela();

		printf("Geracao: %d/%d\n", geracao, quant);
		simulacao();
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
	exit(0);
}
