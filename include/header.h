#ifndef HEADER
#define HEADER
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
class Game;
class Bullet;
class Zombie;
class Plant;
class Sun;
class Obj{
        protected:
                int x;
                int image_number=0;
                int v;
                int y;
                Game* game;
                int countdown=0;
                Sprite sprite;
                bool is_alive;
                int time;

        public:
				float health=0;
                //Obj(Game* game,int X,int Y,vector<Texture>textures,int health=0,bool is_alive=false);
                Sprite* get_sprite(){return &sprite;}

};


struct Card{
	int index;
	string name;
	vector<Texture> textures;
	float health;
	int countdown;
};
struct Textures{
	vector<Texture> walk_normal_zombie{22};
	vector<Texture> dead_normal_zombie{10};
	vector<Texture> attack_normal_zombie{21};
	vector<Texture> normal_flower{13};
	vector<Texture> snow_flower{15};
	vector<Texture> sun_flower{18};
	//vector<Texture> walking_big_zombie;
	//vector<Texture> dead_big_zombie;
	//vector<Texture> attack_big_zombie;
	vector<Texture> wallnut{27};
	Texture flower_card;
	Texture aaa;
	Texture snowflower_card;
	Texture sunflower_card;
	Texture wallnut_card;
	Texture wallpaper;
	vector<Texture> sun{22};
	Texture count_sun;
	vector <Texture> normal_bullet{2};
	vector<Texture>snow_bullet{2};
	Texture game_over;
};

/*
class Obj{
	protected:
		int x;
		int y;
		Game game;
		int health;
		int countdown=0;
		Image image;
		bool is_alive=true;
		int time;	public:
		void move(int  dx,int dy);
		void change_image(Image i);

};

class Sun : public Obj{
	public:
		void tick();
};
class Zombie : public Obj{
	private:
		bool is_attack;
		Flower target;
	public:
		zombie(int X,int Y,Game g,Image i,int t,int h=0);
		void attack();
		void tick();
		void damage(int d);
};
class Flower : public Obj{
	public:
		void tick();
		flower(int X,int Y,Game g,Image i,int t,int h=0);
};
class Tir : public Obj{
	public:
		Tir(int X,int Y,Game g,Image i,int t,int d=0,int h=0);
		void tick();	

};

class Game{
	private:
		bool is_game_end;
		Sprite wallpaper
		vector<Flower> flowers;
		vector<Bullet> bullets;
		vector<Sun> suns;
		vector<Zombie> zombies;
		vector<Flower> flowers_delete;
		vector<Bullet> bullets_delete;
		vector<Sun> suns_delete;
		vector<Zombie> zombies_delete;
		Textures textures;
		vector <Sprite> sprites;
	public:
		Game(RenderWindow w);
};
*/	
//Sprite make_sprite(Texture texture,Vector2f vect,Vector2f scale=Vector2f(0.7,0.7));
#endif
