/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

//#include "Defines.h"
#include "Player.h"

Player::Player(string sprite):spriter(sprite){
	setName("P1");
}

/*
Player:: Player(Type val1, Type val2): 
field1(val1),
field2(val2) {

}
*/

/*void Player:: setSpriter(const string param){
   spriter = Spriter(param);
}*/

void Player::setName(const string sName){
	name = sName;
}

string Player::getCurrentSprite(int era){
	return spriter.getPath()[era];	
}

//void Player::move() {
	/*if (mI->_input->isKeyPressed(IND_KEYRIGHT)){
		posX = 119;
		mhPos += mSpeed * mDelta;
		mMovingSamus->setAnimation(mAnimationSamus);
		bMovingSamus = true;
		if (mMovingSamus->getMirrorX()){
			mMovingSamus->setMirrorX(0);
		}
		mPosXCamera0 += mSpeedLayer0 * mDelta;
	}*/
//}