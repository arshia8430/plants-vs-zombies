#ifndef SUN
#define SUN
#include "header.h"
#include "Game.h"
class Sun : public Obj{
	public:
		vector<Texture>textures;
		Sun(Game* g,const int X,const int Y,const vector<Texture>& t,const int V);
		void tick();

};
#endif
