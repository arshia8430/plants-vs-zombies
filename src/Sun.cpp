#include "header.h"
#include "Sun.h"
#include "Game.h"

Sun::Sun(Game* g, int X, int Y,const vector<Texture>& t,int V){
	game=g;
	x=X;
	y=Y;
	textures=t;
	v=V;
	sprite.setPosition(x,y);
	sprite.setScale(Vector2f(0.5,0.5));
}
void Sun::tick(){
	sprite.move(0,v);
	y+=v;
	sprite.setTexture(textures[image_number]);
	image_number++;
	if(image_number>=textures.size())
		image_number=0;
	if(y>610)
		game->delete_sun(this);
}
