/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

//#include "Defines.h"
#include "Spriter.h"

void Spriter::setSprite(const string sprite){
	vector<string> path;

	path.push_back(sprite + "_past");
	path.push_back(sprite);
	path.push_back(sprite + "_future");
	
}
