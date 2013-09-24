/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

#ifndef _Player_h
#define _Player_h

#include <string>
#include "Spriter.h"

    
class Player {
	Spriter spriter;
	string name;
	/*bool isMoving;
	int posX;
	int posY;*/

	public:
		Player();
		Player(const string sprite);
		void setName(const string sName);
		void setSpriter(const string sprite);
		string getCurrentSprite(int era);
		//void move();
};

#endif
