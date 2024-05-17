#include "header.h"
#include "Plant.h"
#include "Game.h"
//#include "Game.hpp"
Plant::Plant(Game* _game,int _x,int _y,float _health,const vector<Texture>& _images,int _countdown,int _countdown2,string _name){
	game=_game;
	x=_x;
	y=_y;
	timer=std::time(nullptr);
	timer2=std::time(nullptr);
	health=_health;
	health_save=health;
	images=_images;
	name=_name;
	countdown=_countdown;
	countdown2=_countdown2;
	sprite.setPosition(x,y);
	sprite.setTexture(images[image_number]);
	sprite.setScale(Vector2f(0.6,0.6));
}
void Plant::tick(){
	time_t now = std::time(nullptr);
	timer=now;
	if(name=="sun" && now-timer2>=countdown2){
		game->sun_plus();
		timer2=now;
	}
	
	image_number++;
	float xp=health/health_save;
	if(name=="wallnut"){
		if(image_number==16 && xp==1)
			image_number=0;
		if(xp!=1)
			image_number=int(15+(1-xp)*12);
	}
	else if(image_number>images.size()-1){
		image_number=0;
		if(name=="normal"){
			game->new_bullet(x+23,y+5,1);
		}
		if(name=="snow")
			game->new_bullet(x+23,y+5,2);
	}
	if(health<=0){
		game->delete_plant(this);
	}
	sprite.setTexture(images[image_number]);

}
void Plant::get_damage(double damage){
	if(this==nullptr){
		cout<<"............"<<endl;
		return;
	}
	cout<<"ojjjjjjjjjj"<<endl;health-=damage;cout<<"whatlllllll"<<endl;}