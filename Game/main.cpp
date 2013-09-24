/*****************************************************************************************
 * Desc: Tutorial a) 01 Installing
 *****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Animation.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"
#include "IND_Timer.h"
#include "IND_Camera2d.h"
#include "WorkingPath.h"
#include <vector>
#include <string.h>
#include "Player.h"
//#include "Spriter.h"

using namespace std;

/*
==================
Main
==================
*/
int IndieLib()		
{
	char sMsgString[128];
	char sFpsValue[15];

	Spriter s1 ("samus");
	Player p ("samus");


    //Sets the working path as the 'exe' directory. All resource paths are relative to this directory
	if (!WorkingPathSetup::setWorkingPathFromExe(NULL)) {
		cout<<"\nUnable to Set the working path !";
	}

	// ----- IndieLib intialization -----

	CIndieLib *mI = CIndieLib::instance();
	if (!mI->init()) return 0;	

	// ----- Surface loading -----

	//Loading the background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../../../resources/background.jpg", IND_OPAQUE, IND_32)) return 0;

	//Loading a sprite
	IND_Surface *mSurfaceSamus = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceSamus, "../../../resources/SamusStill.png", IND_ALPHA, IND_32, 0, 255, 0)) return 0;

	//Loading an animation
	IND_Animation *mAnimationSamus = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationSamus, "../../../resources/animations/samus.xml", IND_ALPHA, IND_32, 0, 255, 0)) return 0;

	// Font
	IND_Font *mFont = IND_Font::newFont();
	if (!mI->_fontManager->add(mFont, "../../../resources/fonts/font.png", "../../../resources/fonts/font.xml", IND_ALPHA, IND_32)) return 0;

	IND_Entity2d *mText = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(1,mText);
	mText->setFont(mFont);

	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);
	mBack->setSurface(mSurfaceBack);

	IND_Entity2d *mStillSamus = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(0,mStillSamus);
	mStillSamus->setHotSpot(0.5f,0.5f);
	mStillSamus->setSurface(mSurfaceSamus);
	mStillSamus->setPosition(500,100,0);
	mStillSamus->setBoundingAreas("../../../resources/SamusStillCollision.xml");

	IND_Entity2d *mMovingSamus = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mMovingSamus);
	mMovingSamus->setSurface(mSurfaceSamus);

	// ----- Cameras -----
	int mMiddleScreenX = mI->_window->getWidth() / 2;
	int mMiddleScreenY = mI->_window->getHeight() / 2;

	float mPosXCamera0 = (float) mMiddleScreenX;

	IND_Camera2d *mCamera0 = new IND_Camera2d((int) mPosXCamera0, mMiddleScreenY);

	int mSpeedLayer0 = 100;

	// --- Camera to show the text ---
	IND_Camera2d *mCameraText = new IND_Camera2d((int) mI->_window->getWidth() / 2, mI->_window->getHeight() / 2);

	float mhPos = 100;
	float mvPos = 400;
	float mvOriginalPos = 400;
	int mSpeed = 100;
	float mDelta;

	// Create and start the elapsed time timer;
	IND_Timer *mElapsedTimer = new IND_Timer();
	mElapsedTimer->start();

	// Create and start the jump timer;
	IND_Timer *mJumpTimer = new IND_Timer();

	int mX = 0;
	int mSecond;
	char mTimeString[128];
	mTimeString[0] = 0;
	char mTempTime[1024];
	bool bMovingSamus = false;

	// ----- Main Loop -----	

	while (!mI->_input->onKeyPress (IND_ESCAPE) && !mI->_input->quit())
	{
		bMovingSamus = false;

		// ----- Input Update ----

		mI->_input->update();

		// ----- Text ----

		strcpy(sMsgString, "Fps: ");
		mI->_render->getFpsString(sFpsValue);
		strcat(sMsgString, sFpsValue);
		strcat(sMsgString,"\nUse arrows to move L/R\nUse <space> to ''jump''\nUse <escape> to quit\nStarted Since: ");
		strcat(sMsgString,mTimeString);
		mText->setText(sMsgString);
		mText->setLineSpacing (12);
		mText->setPosition(10, 10, 1);
		mText->setAlign(IND_LEFT);
		mText->setTint(125, 0, 0);

		// ----- Input ----

		mDelta = mI->_render->getFrameTime() / 1000.0f;

		// Move entities when pressing right
		if (mI->_input->isKeyPressed(IND_KEYRIGHT)){
			mhPos += mSpeed * mDelta;
			mMovingSamus->setAnimation(mAnimationSamus);
			bMovingSamus = true;
			if (mMovingSamus->getMirrorX())
			{
				mMovingSamus->setMirrorX(0);
			}
			mPosXCamera0 += mSpeedLayer0 * mDelta;
		}

		// Move entities when pressing left
		if (mI->_input->isKeyPressed(IND_KEYLEFT)){
			mhPos -= mSpeed * mDelta;
			mMovingSamus->setAnimation(mAnimationSamus);
			bMovingSamus = true;
			if (!mMovingSamus->getMirrorX())
			{
				mMovingSamus->setMirrorX(1);
			}
			mPosXCamera0 -= mSpeedLayer0 * mDelta;
		}

		//Make the player "jump"
		if (mI->_input->isKeyPressed(IND_SPACE)){
			mMovingSamus->setAnimation(mAnimationSamus);
			bMovingSamus = true;
			if (!mJumpTimer->isStarted()){
				mJumpTimer->start();
			}
			if (mJumpTimer->getTicks() <= 600){
     			mvPos -= mSpeed * mJumpTimer->getTicks()/10000.0f; //mDelta;
			}
			else{
				mJumpTimer->stop();
			}
		}
		/*else
		{
			mvPos += 5;
		}*/

		if (!bMovingSamus)
			mMovingSamus->setSurface(mSurfaceSamus);

		mCamera0->setPosition((int) mPosXCamera0, mMiddleScreenY);

		// ----- Updating entities attribute ----
		mSecond = (int) (mElapsedTimer->getTicks() / 1000.0f);

		// Show the time passing in seconds
		mI->_math->itoa(mSecond,mTempTime);
		strcpy (mTimeString, mTempTime);

		//Jump timer
		//mSecond = (int) (mJumpTimer->getTicks() / 1000.0f);

		//Samus
		mMovingSamus->setPosition((float) mhPos, mvPos, 0);

		// ----- Check collisions -----
		if (mI->_entity2dManager->isCollision(mMovingSamus,"head",mStillSamus,"SamusStillHead")){
			mText->setText("Collision between Msamus head and Ssamus head");
		}

		if (mI->_entity2dManager->isCollision(mMovingSamus,"head",mStillSamus,"SamusStilllleg")){
			mText->setText("Collision between Msamus head and Ssamus left leg");
		}

		if (mI->_entity2dManager->isCollision(mMovingSamus,"head",mStillSamus,"SamusStillrleg")){
			mText->setText("Collision between Msamus head and Ssamus right leg");
		}

		// ----- Game Logic -----
		if (mI->_input->isKeyPressed(IND_LALT) && mI->_input->onKeyPress(IND_RETURN)) mI->_render->toggleFullScreen();

		// -------- Render -------

		mI->_render->beginScene();

		// Render map (Layer 0)
		mI->_render->setCamera2d(mCamera0);
		mI->_entity2dManager->renderEntities2d(0);

		// Render the text (Layer ?)
		mI->_render->setCamera2d(mCameraText);
		mI->_entity2dManager->renderEntities2d(1);

		mI->_entity2dManager->renderCollisionAreas(255, 0, 0, 255);
		mI->_render->endScene();
	}

	// ----- Indielib End -----

	mI->end();

	return 0;
}
