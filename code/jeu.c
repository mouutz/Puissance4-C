#include "jeu.h"

void red() {printf("\033[1;31m");}
void blue() {printf("\033[0;34m");}
void blue2() {printf("\033[1;34m");}
void green() {printf("\033[1;32m");}
void Resett() {printf("\033[0m");}


char     board[7][7]= {' ',' ',' ',' ',' ',' ',' '};
int     joueurs = 1;
int     usrInput;

int is_nbr(char c)
{
	return(c > 47 & c < 58);
}

void PrintBoard(void)
{
	printf("_____________________\n");
	for(int i = 0; i < 7; i++)
	{
	    for(int j = 0; j < 7; j++)
		{
			printf("|");
			printf("%c|", board[i][j]);
	    }
	    printf("\n");
	}
	printf("_____________________\n");
	blue();
	printf("|1||2||3||4||5||6||7|\n\n");
}

int ChekWin(void)
{
	int counter = 0;
	for(int i = 6; i >= 0; i--){
	    for(int j = 0; j < 7; j++){
		if(board[i][j] != 0){
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i - k][j]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i][j + k]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i - k][j - k]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i - k][j + k]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		}
	    }
	}
}
    
void changePlayer()
{
	if(joueurs == 1)
	{
	    joueurs++;
	}
	else
	{
	    joueurs--;
	}
}

void turn()
{	
	blue2();
	printf("Joueur %d , selectionnez une colonne pour placer votre jeton: ", joueurs);
	Resett();
	LOOP:scanf("%d", &usrInput);
	if((usrInput < 0 || usrInput > 7))
	{
		printf("Veuillez saisir un nombre entre 1 et 7: ");
		goto LOOP;
	}
	usrInput -= 1;
	if(board[0][usrInput] != 0)
	{
		printf("Colonne pleine, veuillez en sélectionner une autre");
		goto LOOP;
		}
	for(int k = 0; k < 8; k++)
	{
		if(board[k][usrInput] != 0)
		{
			board[k - 1][usrInput] = joueurs;
			break;
		}
		else
		{
			if(k == 6)
			{
				board[k][usrInput] = joueurs;
			}
		}
	}
	changePlayer();
}



