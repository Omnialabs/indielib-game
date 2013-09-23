/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

//#include "Defines.h"
#include "Player.h"

Player::Player(){
	setSpriter("samus");
}

/*Player::Player(const string sprite){
	setSpriter(sprite);
}*/

void Player::setSpriter(const string sprite){
	spriter(sprite);
}

void Player::setName(const string sName){
	name = sName;
}

/*Player::Player(const string sprite):
   Spriter(sprite) {
}*/

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