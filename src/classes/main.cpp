/*
 Projet: snake
 Auteur: Sylvain Guilbert
*/
#include <iostream>
#include "Point.h"
#include "Board.h"


using namespace std;

int main()
{

    // pointeurs sur l'unique instance de la classe UniqueObject
    Board *fenetre;
    // initialisation des pointeurs
    fenetre = Board::getInstance ();

    Point p(10,4); // placement du point p
    p.drawPoint(); // affichage du point p
    Point p2(10,5);// placement du point p2
    p2.drawPoint();// affichage du point p2
    //cout << "press any key to quit" << endl;
    getchar();
    fenetre->kill();// permet de fermer proprement
    return 0;
}
