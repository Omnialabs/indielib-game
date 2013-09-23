/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

//#include "Defines.h"
#include "Spriter.h"

Spriter::Spriter(){
}

Spriter::Spriter(const string sprite){
	path.push_back(sprite + "_past");
	path.push_back(sprite);
	path.push_back(sprite + "_future");	
}