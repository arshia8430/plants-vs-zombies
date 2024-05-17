#ifndef BULLET
#define BULLET
#include "header.h"
#include "Game.h"
class Bullet : public Obj{
	public:
		int flag=0;
		float m=0.03;
		float op=0;
		int check=0;
		bool fflag=true;
		vector<Texture> images;
		int v_damage=0;
		int v_damage_time=0;
		int damage;
		Bullet(Game* _game,int _x,int _y,vector<Texture> &_image,int _damage,int _v,int _v_damage,int _v_damage_time);
		void tick();


};
#endif
