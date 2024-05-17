#include "header.h"
#include "Bullet.h"
#include "Game.h"
#include "Zombie.h"
Bullet::Bullet(Game* _game,int _x,int _y,vector<Texture> &_image,int _damage,int _v,int _v_damage,int _v_damage_time){
	game=_game;
	x=_x;
	y=_y;
	
	images=_image;
	v_damage=_v_damage;
	v_damage_time=_v_damage_time;
	damage=_damage;
	v=_v;
	sprite.setTexture(_image[0]);
	sprite.setPosition(x,y);
	sprite.setScale(Vector2f(0.5,0.5));
	if(x>=810)
		game->delete_bullet(this);
	FloatRect rect=sprite.getGlobalBounds();
	if(game->check_bullet(rect)!=NULL){
		(game->check_bullet(sprite.getGlobalBounds()))->get_damage(damage,v_damage,v_damage_time);
		game->delete_bullet(this);
	}
}
void Bullet::tick(){
	check++;
	if(check==30){
		m=-m;
	}
	op+=m;
	if(op==0){
		m=0;
		op=0.5;
	}
	sprite.move(v,0);
	sprite.setScale(Vector2f(0.5+op,0.5+op));
	x+=v;
	if(flag!=0){
		if(flag!=1){
			flag++;
			return;
		}
		else
			game->delete_bullet(this);
	}
	FloatRect rect=sprite.getGlobalBounds();
	rect.left-=15;
	if(game->check_bullet(rect)!=NULL){
		(game->check_bullet(rect))->get_damage(damage,v_damage,v_damage_time);
		sprite.setTexture(images[1]);
		flag++;

		sprite.setScale(Vector2f(1.1,1.1));
	}
	if(x>=810)
		game->delete_bullet(this);
}
