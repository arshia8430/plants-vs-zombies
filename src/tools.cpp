#include "header.h"
vector<FloatRect> generate_rect(){
	vector<FloatRect> output;
	vector<int> points_y={100,200,300,400,490};

	for(int i=0;i<5;i++){
		int x=568;
		for(int j=0;j<9;j++){
			FloatRect rect(x,points_y[i],50,80);
			x-=54;
			output.push_back(rect);
		}
	}
	return output;
}
bool is_point_in_rect(Vector2f point,FloatRect rect){
	
	return (rect.left<=point.x&&point.x <=(rect.left+rect.width) &&(rect.top<=point.y && point.y<=(rect.top+rect.height)));
}
bool is_rect_in_rect(FloatRect rect1,FloatRect rect2){
	Vector2f point1(rect1.left,rect1.top);
	Vector2f point2(rect1.left+rect1.width,rect1.top);
	Vector2f point3(rect1.left,rect1.top+rect1.height);
	Vector2f point4(rect1.left+rect1.width,rect1.top+rect1.height);
	
	Vector2f point11(rect2.left,rect2.top);
	Vector2f point22(rect2.left+rect2.width,rect2.top);
	Vector2f point33(rect2.left,rect2.top+rect2.height);
	Vector2f point44(rect2.left+rect2.width,rect2.top+rect2.height);
	
	return ((is_point_in_rect(point1,rect2)||is_point_in_rect(point2,rect2)||is_point_in_rect(point3,rect2)||is_point_in_rect(point4,rect2)||is_point_in_rect(point11,rect1)||is_point_in_rect(point22,rect1)||is_point_in_rect(point33,rect1)||is_point_in_rect(point44,rect1))&&(point11.x-2>point1.x));

}

int randint(int min,int max){
	std::srand(std::time(nullptr));
	return std::rand() % (max - min + 1) + min;
}

void make_textures(Textures& textures){
    textures.flower_card.loadFromFile("files/pics/flower.png");
    textures.snowflower_card.loadFromFile("files/pics/snowflower.png");
    textures.sunflower_card.loadFromFile("files/pics/sunflower.png");
    textures.wallnut_card.loadFromFile("files/pics/wallnut.png");
    textures.wallpaper.loadFromFile("files/pics/Wallpaper.jpg");
	textures.game_over.loadFromFile("files/pics/game_over.png");
    textures.count_sun.loadFromFile("files/pics/count_sun.png");
	textures.normal_bullet[0].loadFromFile("files/pics/normal_bullet0.png");
	textures.normal_bullet[1].loadFromFile("files/pics/normal_bullet1.png");
	textures.snow_bullet[0].loadFromFile("files/pics/snow_bullet.png");
    for(int i=0;i<22;i++)
    	(textures.sun)[i].loadFromFile("files/pics/Sun_"+to_string(i)+".png");
    for(int i=0;i<22;i++)
        textures.walk_normal_zombie[i].loadFromFile("files/pics/Zombie_"+to_string(i)+".png");
    for(int i=0;i<10;i++)
        textures.dead_normal_zombie[i].loadFromFile("files/pics/ZombieDie_"+to_string(i)+".png");
    for(int i=0;i<21;i++)
        textures.attack_normal_zombie[i].loadFromFile("files/pics/ZombieAttack_"+to_string(i)+".png");
    for(int i=0;i<13;i++)
        textures.normal_flower[i].loadFromFile("files/pics/Peashooter_"+to_string(i)+".png");
    for(int i=0;i<15;i++)
        textures.snow_flower[i].loadFromFile("files/pics/SnowPea_"+to_string(i)+".png");
    for(int i=0;i<18;i++)
        textures.sun_flower[i].loadFromFile("files/pics/SunFlower_"+to_string(i)+".png");
    for(int i=0;i<27;i++)
        textures.wallnut[i].loadFromFile("files/pics/"+to_string(i)+".png");
}

void draw_everthing(RenderWindow& window,const vector<Sprite*>& sprites){
	for(int i=0;i<sprites.size();i++)
		window.draw(*sprites[i]);
}
void draw_window(RenderWindow& window,const vector<Sprite>& sprites){
	for(int i=0;i<sprites.size();i++)
		window.draw(sprites[i]);
}
