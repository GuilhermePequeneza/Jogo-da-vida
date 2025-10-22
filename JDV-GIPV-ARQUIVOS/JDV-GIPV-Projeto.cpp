 //JDV-GIPV - Projeto Jogo da Vida - Etapa 1
//08/10/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

#include "JDV-GIPV-Model.cpp"
#include "JDV-GIPV-Controller.cpp"


int main(){
    /*inicializarMundo();
    tamanho = perguntaTamanho();
    jogar();

    return 0; */
    char op = menuGeral();
    if(op == '1' ){
		inicializarMundo();
	   	jogar();
		}

}
