#include "header.h"
#include "Zombie.h"
#include "Plant.h"
#include "Game.h"
Zombie::Zombie(Game* _game,int _x,int _y,float _health,const vector<Texture>& _attack_images,const vector<Texture>& _die_images,const vector<Texture>& _walk_images,int _v,int _damage,int _countdown){
	x=_x;
	y=_y;
	time_t timer=std::time(nullptr);
	countdown=_countdown;
	game=_game;
	damage=_damage;
	health=_health;
	attack_images=_attack_images;
	die_images=_die_images;
	walk_images=_walk_images;
	v=_v;
	sprite.setPosition(x,y);
	sprite.setScale(Vector2f(0.6,0.6));
}
void Zombie::tick(){
	if(health <=0 && is_die==false){
		is_walk=false;
		is_die=true;
		image_number=0;
	}
	if(is_v_damage){
		time_t now=std::time(nullptr);
		if(now-damage_timer>=v_damage_time){
			v=save_v;
			is_v_damage=false;
		}
	}
	if(is_walk){
		sprite.move(-v,0);
		x+=v;
		image_number++;
		sprite.setTexture(walk_images[image_number]);
		if(image_number>=walk_images.size()-1)
			image_number=0;
	}
	if(x< -10)
		game->delete_zombie(this);
	FloatRect rect=sprite.getGlobalBounds();
	if(game->check_plant(rect)!= NULL && !is_die){
		if(is_walk){
			image_number=0;
			is_walk=false;
		}
		sprite.setTexture(attack_images[image_number]);
		image_number++;
		if(image_number>=attack_images.size())
			image_number=0;
		(game->check_plant(rect)->get_damage(damage/attack_images.size()));
	}
	else if(!is_die && !is_walk){
		image_number=0;
		is_walk=true;
	}
	if(is_die){
		sprite.setTexture(die_images[image_number]);
		image_number++;
		if(image_number>=die_images.size())
			game->delete_zombie(this);
	}
}
void Zombie::get_damage(float d,float v_damage,int _v_damage_time){
	if(&health==nullptr)
		return;
	health-=d;
	if(v_damage!=0){
		save_v=v;
		v=v-v_damage;
		if(v<0)
			v=0;
		v_damage_time=_v_damage_time;
		damage_timer=std::time(nullptr);
		v_damage_time=_v_damage_time;
		is_v_damage=true;
	}
}
