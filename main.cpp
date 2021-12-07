#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "funcoes.cpp"
using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");
	int aux = 0;
    while(aux == 0){
    int opcao;
    venceu=' ';
    termino=0;
    jogada=0;
    
     
     cout<<"\n\n\n ===================\n";
     cout<<" ===================\n";
     cout<<" ===================\n";
     cout<<" ===================\n";
     cout<<"       JOGO DA VELHA     \n";
     cout<<"       1- ONE PLAYER       \n";
     cout<<"       2- MULTIPLAYER       \n";
     cout<<"       3- PLACAR         \n";
     cout<<"       4- Sair           \n";
     cout<<" ===================\n";
     cout<<" ===================\n";
     cout<<" ===================\n";
     cout<<" ===================\n\n\n\n";
    
     cin>>opcao;
     switch(opcao){
     	case 1:
     		system("cls");
     		cout<<" ===================\n";
     		cout<<" ===================\n";
     		cout<<"Digite o nome do player 1: \n";
     		cin>>jogador1;
     		while ((jogada<=9)&&(termino!=1)){        
	    		jogo();
	    		jogada++;	
			}
     		break;
     	case 2:
     		system("cls");
     		cout<<" ===================\n";
     		cout<<" ===================\n";
     		cout<<"Digite o nome do player 1: \n";
     		cin>>jogador1;
     		cout<<"Digite o nome do player 2: \n";
     		cin>>jogador2;
     		while ((jogada<=9)&&(termino!=1)){        
	    		jogo2();
	    		jogada++;
			}
     		break;
     	case 3:
     		placar();
     		break;
     	case 4:
		 	cout<<"GAME ENCERRADO";	
     		aux = 1;
	 }
	}
    return 0;
}

