/*
 Projet: snake
 Auteur: Houdi
*/
#include <iostream>
#include "Point.h"
#include "Board.h"
#include "snake.h"
#include <unistd.h>

int usleep(useconds_t usec);

using namespace std;


#define  TOUCHE_KEY_UP 1 // sert a définir les touche de mouvement
#define  TOUCHE_KEY_DOWN 2
#define  TOUCHE_KEY_LEFT 3
#define  TOUCHE_KEY_RIGHT 4

int kbhit(void)    // Cette fonction retourne si une touche est appuyé par l'utilisateur
{
	int ch, r;


	nodelay(stdscr, TRUE);



	ch = getch();
	if( ch == ERR)
		r = FALSE;
	else
	{
		r = TRUE;
		ungetch(ch);
	}


	echo();
	nodelay(stdscr, FALSE);
	return(r);
}

int main()
{
	int derniereDir=TOUCHE_KEY_UP;

    // pointeurs sur l'unique instance de la classe Unique Object
	Board *fenetre;
    // initialisation des pointeurs
	fenetre = Board::getInstance ();

	snake serpent(10,10);




	keypad (stdscr,true);
	curs_set(0);
	

	
	
	while (!(serpent.checkColisionWithBoard()))
	{

		if(kbhit()) {
			switch (getch()){
				case 259:
				derniereDir = TOUCHE_KEY_UP;
				serpent.move(TOUCHE_KEY_UP);
				break;
				case 260:
				derniereDir = TOUCHE_KEY_LEFT;
				serpent.move(TOUCHE_KEY_LEFT);
				break;
				case 258:
				derniereDir = TOUCHE_KEY_DOWN;
				serpent.move(TOUCHE_KEY_DOWN);
				break;
				case 261:
				derniereDir = TOUCHE_KEY_RIGHT;
				serpent.move(TOUCHE_KEY_RIGHT);
				break;
			}

			serpent.move(derniereDir);

		}else{
			serpent.move(derniereDir);

		}

		serpent.affichSerpent();
		usleep (100000);
	}
	
    	clear();
	fenetre->kill();
	return 0;
};
