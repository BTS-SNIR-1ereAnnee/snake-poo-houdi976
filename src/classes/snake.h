#include <iostream>
#include "Point.h"
#include "Board.h"

class snake
{ 
public:
	void ajouterPoint(Point p);
	void afficher();

private:
	Point serpent[20];
	int m_index;
};

#endif 
