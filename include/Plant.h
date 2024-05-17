#ifndef PLANTS
#define PLANTS
#include "header.h"
#include "Game.h"
class Plant : public Obj{
	private:
		vector<Texture> images;
		int countdown2;
		string name;
		float health_save;
		time_t timer;
		time_t timer2;
	public:
		void tick();
		Plant(Game* _game,int _x,int _y,float _health,const vector<Texture>& _images,int _countdown,int _countdown2,string name);
		void get_damage(double damage);
};
#endif
