/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

#ifndef _Player_h
#define _Player_h

#include <string>
#include "Spriter.h"

    
class Player {
	public:
		Player();
		Player(const string sprite);
		void setName(const string sName);
		void setSpriter(const string sprite);
		//void move();

	private:
		Spriter spriter (const string sprite);
		string name;
		/*bool isMoving;
		int posX;
		int posY;*/

		
};

#endif
