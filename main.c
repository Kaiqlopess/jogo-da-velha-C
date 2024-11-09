#include <stdio.h>
#include <stdlib.h>


void limpar_entrada() {
 char c;
 while ((c = getchar()) != '\n' && c != EOF) {}
}



char diagonal(char jogo[3][3], char x, char o){

     if(jogo[0][0] == x && jogo[1][1] == x && jogo[2][2] == x){
            return x;
     }
     else if(jogo[0][0] == o && jogo[1][1] == o && jogo[2][2] == o){
            return o;
     }
     if(jogo[0][2] == x && jogo[1][1] == x && jogo[2][0] == x){
           return x;
     }
     else if(jogo[0][2] == o && jogo[1][1] == o && jogo[2][0] == o){
           return o;
     }

    return 'z';


}
char horizontal(char jogo[3][3], char x, char o){

    for(int i = 0; i < 3; i++){
         if(jogo[i][0] == x && jogo[i][1] == x && jogo[i][2] == x){
                return x;
         }
         else if(jogo[i][0] == o && jogo[i][1] == o && jogo[i][2] == o){
                return o;
         }
    }

    return 'z';
}

char vertical(char jogo[3][3], char x, char o){
      for(int i = 0; i < 3; i++){
         if(jogo[0][i] == x && jogo[1][i] == x && jogo[2][i] == x){
                return x;
         }
         else if(jogo[0][i] == o && jogo[1][i] == o && jogo[2][i] == o){
                return o;
         }
    }
    return 'z';
}

void regras(){
	printf("Ola jogadores, eu queria estabelcer as regras. O formato do jogo sera se 1 a 9\nem que cada posiçao sera uma casa para realizar a jogada, vai o exemplo:\n");
	printf("\n1 _ 2 _ 3 _\n");
	printf("4 _ 5 _ 6 _\n");
	printf("7 _ 8 _ 9 _\n");
	printf("\nPor favor nao utilizar de caracteres que nao forem os da\njogada, ou seja, so pode de 1 a 9!! ciente disso um otimo jogo\n");
}


int main()
{
    char x = 'x';
    char o = 'o';
    char jogadorwin;
    char jogadorVez;
    char repetidor = 's';

    int linha = 3;
    int coluna = 3;
    int jogada;
    int contador = 0;
    int px = 0;
    int po = 0;

    char jogo[3][3];

    regras();

    system("pause");
    system("cls");


    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
           jogo[i][j] = '_';
        }
    }

    while(repetidor == 's'){

            contador = 0;
            jogadorwin = 'z';

            for(int i = 0; i < linha; i++){
              for(int j = 0; j < coluna; j++){
                jogo[i][j] = '_';
              }
            }




        while(contador < 9 &&  jogadorwin != x && jogadorwin != o){

            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                   printf("%c ", jogo[i][j]);
                }
                printf("\n");
            }
            if(contador % 2 != 0){
                jogadorVez = o;
            }
            else{
                jogadorVez = x;
            }

            printf("Jogador %c jogue: ", jogadorVez);
            scanf("%d", &jogada);

            if(jogada < 1 || jogada > 9){
               printf("nao existe essa casa!\n");
               contador--;
            }
            else if(jogo[0][jogada - 1] != '_' && jogo[1][jogada - 4] != '_' && jogo[2][jogada - 7] != '_'){
                printf("essa essa casa ta ocupada!\n");
                contador--;
            }
            else{
              if(jogada >= 1 && jogada <= 3){
              jogo[0][jogada - 1] = jogadorVez;
                }
              else if(jogada >= 4 && jogada <= 6){
                  jogo[1][jogada - 4] = jogadorVez;
                }
              else if(jogada >= 7 && jogada <= 9){
                  jogo[2][jogada - 7] = jogadorVez;
                }
            }

           jogadorwin = diagonal(jogo, x, o);

           if (jogadorwin == 'z'){
            jogadorwin = vertical(jogo, x, o);
           }
           if(jogadorwin == 'z'){
            jogadorwin = horizontal(jogo, x, o);
           }



           system("pause");
           system("cls");

            contador++;
        }

         for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
               printf("%c ", jogo[i][j]);
            }
            printf("\n");
        }

        if(jogadorwin == 'z'){
        	printf("\n\n>>EMPATE<<\n");
		}
		else{
			printf("\n\nJogador vencedor: %c\n", jogadorwin);
		}


        if(jogadorwin == 'x'){
        	px = px+1;
		}
		else if(jogadorwin == 'o'){
			po = po+1;
		}
        printf("Placar\njogador x: %d\njogador o: %d ", px, po);
        limpar_entrada();
        printf("\nquer repetir a partida(s|n)? ");
        scanf("%c", &repetidor);

	   switch(repetidor)
	   {
	   	case 's':
	    case 'S':
	      repetidor = 's';
	   		break;
	   	case 'n':
	   	case 'N':
		   repetidor = 'n';
		   	printf("acabou o jogo!");
		   	break;
		default:
		 while(repetidor != 's' && repetidor != 'n'){
		 	printf("\nopcao invalida. Tente novamente, somente >>s<< ou >>n<<\n");
		 	limpar_entrada();
            printf("\nquer repetir a partida(s|n)? ");
            scanf("%c", &repetidor);
		 }

	   }

        system("pause");
        system("cls");

    }


    return 0;
}
