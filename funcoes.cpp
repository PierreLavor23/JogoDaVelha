#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>


using namespace std;


char matrix[3][3];
int termino=0, jogada=0;
char venceu=' ';
//criando funções
//
void iniciaPrograma();

void mostrarJogoDaVelha();

void preencherPosicao();

void movimentacaoTabuleiro();
//
//multiplayer 
void movimento();
void jogo2();

//
void placar();
void jogo();

void fimDoJogo();
void testando();
//

char jogador1[20], jogador2[20];

//contadores 
int contadorVitoriasX = 0;
int contadorVitoriasO = 0;
int contadorEmpates = 0;
//


	//cria a matriz 3x3
	 void iniciaPrograma()
	{
		//percoree a matriz	 e preencher com o vazio ' '	
	    for(int x=0;x < 3;x++)
	    for(int y=0;y < 3;y++)
	    matrix[x][y]=' ';
	}
	//mostra na tela a matriz em formato de jogo da velha
	void mostrarJogoDaVelha()
	{
		system("cls"); //limpando a tela
	    cout<<" "<<  matrix[0][0]  <<" | "<< matrix[0][1] <<"| "<< matrix[0][2] <<"\n"
	    <<" --|--|--\n"
	    << " "<< matrix[1][0] <<" | "<<  matrix[1][1]  <<"| "<<  matrix[1][2]<<"\n"
	    <<" --|--|--\n"
	    << " "<< matrix[2][0] <<" | "<<  matrix[2][1]  <<"| "<<  matrix[2][2]<<"\n"<<endl;
	}
	void preencherPosicao()
	{
		int x=0,y=0;
	    cout<<"\n=====Entre com a Posicao X(linhas) e Y(coluna)====="<<"\nJogador 1: "<<jogador1<<"\n\nPosicao X(linha):";
	    cin>>x;
	    cout<<"Posicao Y(coluna):";
	  	cin>>y;         
 		if((x <= 3 )&&(x > 0)&&(y <= 3)&&(y > 0)&&(matrix[x-1][y-1] == ' ')) 
	    {
	        matrix[x-1][y-1]='X'; //caso o usuario digite com 1, corrigi o valor e continua funcionando
	    }else
	    {
	        cout<<"\n ====POR FAVOR DIGITE UMA POSIÇÃO VALIDA!====";
	        preencherPosicao();
	    }           
	}
	void movimentacaoTabuleiro()
	 {
		int condicao = 0;
		if (condicao == 0)
		 {
		 	if(jogada==0)
		 	{
		          if((matrix[0][0]==' ')&&(matrix[0][2]==' ')&&(matrix[2][0]==' ')&&(matrix[2][2]==' '))
		          {
		              if(matrix[1][1]==' ')
		                   {
		                       matrix[0][0]='O';
		                    	condicao = 1;            
		                   }else{
		                      matrix[1][0]='O';
		                       condicao = 1;
		                   }
		        }else
		         {
		            matrix[1][1]='O';
		            condicao = 1;            
		        }
		             
			}
  			else
 			{
             
           if((matrix[0][0]=='O')&&(matrix[0][2]=='O')&&(matrix[0][1]==' '))
            {
                matrix[0][1]='O';
                condicao = 1;            
            }else  if((matrix[0][0]=='O')&&(matrix[0][1]=='O')&&(matrix[0][2]==' '))
           {
              	matrix[0][2]='O';
           	 	condicao = 1;
            }else if((matrix[0][2]=='O')&&(matrix[0][1]=='O')&&(matrix[0][0]==' '))
            {
                matrix[0][0]='O';
                condicao = 1;
            }else if((matrix[0][0]=='O')&&(matrix[2][0]=='O')&&(matrix[1][0]==' '))
    		{
           	    matrix[1][0]='O';
                condicao = 1;
			}else if((matrix[0][0]=='O')&&(matrix[1][0]=='O')&&(matrix[2][0]==' '))
            {
                matrix[2][0]='O';
                condicao = 1;
           }else if((matrix[1][0]=='O')&&(matrix[2][0]=='O')&&(matrix[0][0]==' '))
            {
                matrix[0][0]='O';
                condicao = 1;
			}else if((matrix[2][0]=='O')&&(matrix[2][2]=='O')&&(matrix[2][1]==' '))
            {
               matrix[2][1]='O';
               condicao = 1;
			}else if((matrix[2][0]=='O')&&(matrix[2][1]=='O')&&(matrix[2][2]==' '))
           	{
               matrix[2][2]='O';
              	condicao = 1;
             }else if((matrix[2][1]=='O')&&(matrix[2][2]=='O')&&(matrix[2][0]==' '))
 			{
                matrix[2][0]='O';
                condicao = 1;
 			 }else if((matrix[2][2]=='O')&&(matrix[0][2]=='O')&&(matrix[1][2]==' '))
            {
                matrix[1][2]='O';
                condicao = 1;
             }else if((matrix[2][2]=='O')&&(matrix[1][2]=='O')&&(matrix[0][2]==' '))
             {
                matrix[0][2]='O';
                condicao = 1;
             }else if((matrix[1][2]=='O')&&(matrix[0][2]=='O')&&(matrix[2][2]==' '))
             {
                matrix[2][2]='O';
                condicao = 1;
             }else if((matrix[0][1]=='O')&&(matrix[2][1]=='O')&&(matrix[1][1]==' '))
             {
                matrix[1][1]='O';
                condicao = 1;
             }else if((matrix[0][1]=='O')&&(matrix[1][1]=='O')&&(matrix[2][1]==' '))
            {
                matrix[2][1]='O';
                condicao = 1;
           }else if((matrix[1][1]=='O')&&(matrix[2][1]=='O')&&(matrix[0][1]==' '))
           {
                matrix[0][1]='O';
               	condicao = 1;
 			}else if((matrix[0][0]=='X')&&(matrix[2][2]=='X')&&(matrix[1][1]==' '))
            {
                matrix[1][1]='O';
                condicao = 1;
             }else if((matrix[0][0]=='O')&&(matrix[1][1]=='O')&&(matrix[2][2]==' '))
            {
            matrix[2][2]='O';
               condicao = 1;
            }else  if((matrix[1][1]=='O')&&(matrix[2][2]=='O')&&(matrix[0][0]==' '))
            {
               matrix[0][0]='O';
               condicao = 1;
            }else  if((matrix[0][2]=='O')&&(matrix[2][0]=='O')&&(matrix[1][1]==' '))
            {
                 matrix[1][1]='O';
                 condicao = 1;
            }else if((matrix[0][2]=='O')&&(matrix[1][1]=='O')&&(matrix[2][0]==' '))
            {
               	 matrix[2][0]='O';
                 condicao = 1;
            }else if((matrix[2][0]=='O')&&(matrix[1][1]=='O')&&(matrix[0][2]==' '))
            {
                matrix[0][2]='O';
                condicao = 1;
			//para atrapalhar o oponente a ganhar
           }else  if((matrix[0][0]=='X')&&(matrix[0][2]=='X')&&(matrix[0][1]==' '))
           {
                matrix[0][1]='O';
                condicao = 1;            
           }else if((matrix[0][0]=='X')&&(matrix[0][1]=='X')&&(matrix[0][2]==' '))
           {
                matrix[0][2]='O';
                condicao = 1;
           }else if((matrix[0][2]=='X')&&(matrix[0][1]=='X')&&(matrix[0][0]==' '))
          {
                matrix[0][0]='O';
                condicao = 1;
          }else if((matrix[0][0]=='X')&&(matrix[2][0]=='X')&&(matrix[1][0]==' '))
          {
                matrix[1][0]='O';
                condicao = 1;
          }else if((matrix[0][0]=='X')&&(matrix[1][0]=='X')&&(matrix[2][0]==' '))
            {
               matrix[2][0]='O';
            	condicao =1;
           }else if((matrix[1][0]=='X')&&(matrix[2][0]=='X')&&(matrix[0][0]==' '))
           {
                matrix[0][0]='O';
                condicao = 1;
            }else  if((matrix[2][0]=='X')&&(matrix[2][2]=='X')&&(matrix[2][1]==' '))
            {
                   matrix[2][1]='O';
                   condicao = 1;
            }else  if((matrix[2][0]=='X')&&(matrix[2][1]=='X')&&(matrix[2][2]==' '))
            {
                matrix[2][2]='O';
                condicao = 1;
           }else if((matrix[2][1]=='X')&&(matrix[2][2]=='X')&&(matrix[2][0]==' '))
           {
               matrix[2][0]='O';
               condicao = 1;
			}else if((matrix[2][2]=='X')&&(matrix[0][2]=='X')&&(matrix[1][2]==' '))
            {
                matrix[1][2]='O';
                condicao = 1;
             }else  if((matrix[2][2]=='X')&&(matrix[1][2]=='X')&&(matrix[0][2]==' '))
            {
               	matrix[0][2]='O';
               	condicao = 1;
           }else if((matrix[1][2]=='X')&&(matrix[0][2]=='X')&&(matrix[2][2]==' '))
           {
                 matrix[2][2]='O';
                 condicao = 1;
           }else if((matrix[0][1]=='X')&&(matrix[2][1]=='X')&&(matrix[1][1]==' '))
            {
                matrix[1][1]='O';
                condicao = 1;
			}else if((matrix[0][1]=='X')&&(matrix[1][1]=='X')&&(matrix[2][1]==' '))
            {
                 matrix[2][1]='O';
                 condicao = 1;
            }else if((matrix[1][1]=='X')&&(matrix[2][1]=='X')&&(matrix[0][1]==' '))
           {
               matrix[0][1]='O';
               condicao = 1;
            }else  if((matrix[0][0]=='X')&&(matrix[2][2]=='X')&&(matrix[1][1]==' '))
            {
                 matrix[1][1]='O';
                 condicao = 1;
            }else if((matrix[0][0]=='X')&&(matrix[1][1]=='X')&&(matrix[2][2]==' '))
            {
                   matrix[2][2]='0';
                   condicao = 1;
            }else if((matrix[1][1]=='X')&&(matrix[2][2]=='X')&&(matrix[0][0]==' '))
           {
                matrix[0][0]='O';
                condicao = 1;
           }else if((matrix[0][2]=='X')&&(matrix[2][0]=='X')&&(matrix[1][1]==' '))
            {
                matrix[1][1]='O';
               	condicao = 1;
           }else if((matrix[0][2]=='X')&&(matrix[1][1]=='X')&&(matrix[2][0]==' '))
            {
                matrix[2][0]='O';
                condicao = 1;
           }else if((matrix[2][0]=='X')&&(matrix[1][1]=='X')&&(matrix[0][2]==' '))
            {
                matrix[0][2]='O';
                condicao = 1;
            }
                                             
            else{
                   for (int x=0;x<3;x++)
                           for (int y=0;y<3;y++)
                             {
                                if((condicao == 0)&&(matrix[x][y]==' '))
                                   {
                                       matrix[x][y]='O';
                                       condicao = 1;
                                    }                                          
                             }
                                               }            
 			}
				}


 }
void jogo()
 {
    if (jogada==0){
    	iniciaPrograma();
	} 
    mostrarJogoDaVelha();
    preencherPosicao();

	movimentacaoTabuleiro();
	testando();        
 }                       
void fimDoJogo()
{
               system("cls");
               mostrarJogoDaVelha();
               cout<<"O jogador "<<venceu<<" Venceu\n ";
               if(venceu == 'X'){
               		contadorVitoriasX++;
			   }else{
			   		contadorVitoriasO++;
			   }
			    placar();
            	cout<<" \n=========DIGITE S PARA JOGAR NOVAMENTE=========\n";
		        char jogaDenovo;
                cin>>jogaDenovo;
               
               if(jogaDenovo == 'S' || jogaDenovo == 's')
               {
                	venceu=' ';
                    termino=0;
                    jogada=0;
                    jogo();
               }
             
}
void testando()
{
             
               //teste horizontal
               if((matrix[0][0]==matrix[0][1])&&(matrix[0][1]==matrix[0][2])&&(matrix[0][0]!=' '))
               {
                               termino=1;
                               venceu=matrix[0][0];
                               fimDoJogo();
               }
               if((matrix[1][0]==matrix[1][1])&&(matrix[1][1]==matrix[1][2])&&(matrix[1][0]!=' '))
               {
                               termino=1;
                               venceu=matrix[1][0];
                               fimDoJogo();
               }
               if((matrix[2][0]==matrix[2][1])&&(matrix[2][1]==matrix[2][2])&&(matrix[2][0]!=' '))
               {
                               termino=1;
                               venceu=matrix[2][0];
                               fimDoJogo();
               }
             
               //teste vertical
             
               if((matrix[0][0]==matrix[1][0])&&(matrix[1][0]==matrix[2][0])&&(matrix[0][0]!=' '))
               {
                               termino=1;
                               venceu=matrix[0][0];
                               fimDoJogo();          
               }
               if((matrix[0][1]==matrix[1][1])&&(matrix[1][1]==matrix[2][1])&&(matrix[0][1]!=' '))
               {
                               termino=1;
                               venceu=matrix[0][1];
                               fimDoJogo();
               }
               if((matrix[0][2]==matrix[1][2])&&(matrix[1][2]==matrix[2][2])&&(matrix[0][2]!=' '))
               {
                               termino=1;
                               venceu=matrix[0][2];
                               fimDoJogo();
               }
             
               //teste na digonal
             
               if((matrix[0][0]==matrix[1][1])&&(matrix[1][1]==matrix[2][2])&&(matrix[0][0]!=' '))
               {
                               termino=1;
                               venceu=matrix[0][0];
                               fimDoJogo();       
               }
               if((matrix[0][2]==matrix[1][1])&&(matrix[1][1]==matrix[2][0])&&(matrix[0][2]!=' '))
               {
                               termino=1;
                               venceu=matrix[0][2];
                               fimDoJogo();          
               }   
               // teste sedeu velha
               if ((jogada==4)&&(venceu==' '))
               {
               			system("cls");
		               mostrarJogoDaVelha();
		               cout<<"O JOGO FOI EMPATE!!\n";
		               if(venceu == ' '){
		               		contadorEmpates++;
					   }
		            	placar();
		            	cout<<" \n=========DIGITE S PARA JOGAR NOVAMENTE=========\n";
		                char jogaDenovo;
                		cin>>jogaDenovo;
		           
		               if(jogaDenovo == 'S' || jogaDenovo == 's')
		               {
		                	venceu=' ';
		                    termino=0;
		                    jogada=0;
		                    jogo();
		               }
               	
               }

}
void placar(){
				cout<<"\n ===================\n";
              	cout<<"     PLACAR FINAL      \n";
              	cout<<"     JOGADOR X= "<<contadorVitoriasX<<"        \n";
              	cout<<"     JOGADOR O= "<<contadorVitoriasO<<"        \n";
              	cout<<"     EMPATES= "<<contadorEmpates<<"        \n";
              	cout<<" ===================\n";
              	
              	
}
//multiplayer
void jogo2()
 {
    if (jogada==0){
    	iniciaPrograma();	
	} 
   	mostrarJogoDaVelha();
	preencherPosicao();
    movimento();
   	testando();  
             
 }  
void movimento()
 {
        int x=0,y=0;
	    cout<<"\n=====Entre com a Posicao X(linhas) e Y(coluna)====="<<"\nJogador 2: "<<jogador2<<"\n\nPosicao X(linha):";
	    cin>>x;
	    cout<<"Posicao Y(coluna):";
	  	cin>>y;         
 		if((x <= 3 )&&(x > 0)&&(y <= 3)&&(y > 0)&&(matrix[x-1][y-1] == ' ')) 
	    {
	        matrix[x-1][y-1]='O'; //caso o usuario digite com 1, corrigi o valor e continua funcionando
	    }else
	    {
	        cout<<"\n ====POR FAVOR DIGITE UMA POSIÇÃO VALIDA!====";
	        preencherPosicao();
	    }           

}


