/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

#ifndef _Player_h
#define _Player_h

    
class Player {
	public:
	    bool setName(char* sName);

	private:
		bool isMoving;
		int posX;
		int posY;

		void move();
};

#endif
