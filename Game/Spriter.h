/*****************************************************************************************
 * Desc: Utility methods for working paths setup
 *****************************************************************************************/

#ifndef _Spriter_h
#define _Spriter_h

#include <string>
#include <vector>

using namespace std;
    
class Spriter {
	vector<string> path;

	public:
		Spriter();
		Spriter(const string sprite);
		vector<string> getPath();
		//std::vector<char> getSprite();	
};

#endif
