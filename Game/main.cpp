/*****************************************************************************************
 * Desc: Tutorial a) 01 Installing
 *****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Animation.h"
#include "IND_Entity2d.h"
#include "WorkingPath.h"

/*
==================
Main
==================
*/
int IndieLib()		
{
    //Sets the working path as the 'exe' directory. All resource paths are relative to this directory
	if (!WorkingPathSetup::setWorkingPathFromExe(NULL)) {
		std::cout<<"\nUnable to Set the working path !";
	}

	// ----- IndieLib intialization -----

	CIndieLib *mI = CIndieLib::instance();
	if (!mI->init()) return 0;	

	// ----- Surface loading -----

	//Loading the background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../../../resources/background.jpg", IND_OPAQUE, IND_32)) return 0;

	//Loading a sprite
	/*IND_Surface *mSurfaceSamus = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceSamus, "../../../resources/SamusStill.png", IND_ALPHA, IND_32, 0, 255, 0)) return 0;*/

	/*IND_Animation *mAnimationSamus = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationSamus, "../../../resources/animations/samus.xml", IND_ALPHA, IND_32, 0, 255, 0)) return 0;*/


	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);
	mBack->setSurface(mSurfaceBack);

	/*IND_Entity2d *mStillSamus = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mStillSamus);
	mStillSamus->setSurface(mSurfaceSamus);
	mStillSamus->setPosition(500,100,0);*/

	/*IND_Entity2d *mMovingSamus = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mMovingSamus);
	mMovingSamus->setAnimation(mAnimationSamus);
	mMovingSamus->setSequence(0);*/

	// ----- Main Loop -----

	float mhPos = 100;
	float mvPos = 400;
	float mvOriginalPos = 400;
	int mSpeed = 150;
	float mDelta;

	while (!mI->_input->onKeyPress (IND_ESCAPE) && !mI->_input->quit())
	{
		// ----- Input Update ----

		mI->_input->update();

		// ----- Text ----

		// ----- Input ----

		mDelta = mI->_render->getFrameTime() / 1000.0f;

		//mDelta = mI->_render->getFrameTime() / 1000.0f;

		// Move entities when pressing right
		/*if (mI->_input->isKeyPressed(IND_KEYRIGHT)){
			mhPos += mSpeed * mDelta;
			if (mMovingSamus->getMirrorX())
			{
				mMovingSamus->setMirrorX(0);
			}
		}

		// Move entities when pressing left
		if (mI->_input->isKeyPressed(IND_KEYLEFT)){
			mhPos -= mSpeed * mDelta;
			if (!mMovingSamus->getMirrorX())
			{
				mMovingSamus->setMirrorX(1);
			}
		}*/

		//Make the player "jump"
		if (mI->_input->isKeyPressed(IND_SPACE)){
			mvPos -= mSpeed * mDelta;
		}
		else
		{
			if (mvPos < mvOriginalPos)
			{
				mvPos -= mSpeed * mDelta * -1;
			}
		}


		// ----- Updating entities attribute ----

		//Samus
		//mMovingSamus->setPosition((float) mhPos, mvPos, 0);

		// -------- Render -------

		mI->_render->beginScene();
		mI->_entity2dManager->renderEntities2d();
		mI->_render->endScene();
		////mI->_render->showFpsInWindowTitle();
	}

	// ----- Indielib End -----

	mI->end();

	return 0;
}
