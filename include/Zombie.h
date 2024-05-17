#ifndef ZOMBIE
#define ZOMBIE
#include "header.h"
#include "Game.h"
class Zombie : public Obj{
	private:
		bool is_die=false;
		bool is_walk=true;
		vector<Texture> attack_images;
		vector<Texture> die_images;
		vector<Texture> walk_images;
		int save_v;
		time_t damage_timer;
		time_t timer;
		int v_damage_time;
		bool is_v_damage=false;
		float damage;
	public:
		Zombie(Game* _game,int _x,int _y,float _health,const vector<Texture>& _attack_images,const vector<Texture>& _die_images,const vector<Texture>& _walk_images,int _v,int _damage,int _countdown);
		void attack();
		void tick();
		void get_damage(float d,float v_damage=0,int _v_damage_time=0);
};
#endif
