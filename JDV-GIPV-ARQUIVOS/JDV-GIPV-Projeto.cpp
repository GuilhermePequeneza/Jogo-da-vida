//JDV-GIPV - Projeto Jogo da Vida - Etapa 1
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

#include "JDV-GIPV-Model.cpp"
#include "JDV-GIPV-Controller.cpp"


int main(){
   
    int op;

	printf("_________________________");
	printf("|Digite 1 para Jogar: \n|");
	printf("|Digite 2 para :      \n|");
	printf("|Digite 2 para :      \n|");
	scanf("%d",&op);
	switch(op){
		
		case 1: 
			
			perguntaTamanho();
			exibirMundo(tamanho);
			modificarCelula();
		
		case 2:
			printf("caso 2 mano");
		
		case 3:
			printf("caso 3 mano");
		
		
		
		
	}
   
   
   
   
    /*inicializarMundo();

    tamanho = perguntaTamanho();

    jogar();
    
    return 0; */
}
