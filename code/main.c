
#include "jeu.h"

int main()
{
    int joueurs = 1;


    while(ChekWin() != 1){
	system("clear");
	PrintBoard();
	turn();
    }
    system("clear");
    PrintBoard();
    changePlayer();
	if (joueurs == 1)
	{
		printf("le %der joueur a gagné.\n", joueurs);
	}else{
		printf("le %de joueur a gagné.\n", joueurs);
	}
	
	
    
}