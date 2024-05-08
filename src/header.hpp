#include <vector>

class Obj{
	proteted:
		int x;
		int y;
		Game game;
		int health;
		int countdown=0;
		Image image;
		bool is_alive=true;
		int time;
	public:
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
		vector<Flower> flowers;
		vector<Tir> tirs;
		vector<Sun> suns;
		vector<Zombie> zombies;
		delete_flower(Flower flower);
		delete_flower(Tir tir);
		delete_flower(Zombie zombie);
		delete_flower(Sun sun);
		vector<images> images_list;
	public:
		Game(vector<images> i);
		void start();
};	

