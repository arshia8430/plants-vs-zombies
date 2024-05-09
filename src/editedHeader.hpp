#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Obj {
protected:
    int x;
    int y;
    int health;
    int countdown = 0;
    bool is_alive = true;
    int time;
public:
    void move(int dx, int dy);
    void change_image(Texture& texture);
};

class Sun : public Obj {
public:
    void tick();
};
class Zombie : public Obj {
private:
    bool is_attack;
public:
    Zombie(int X, int Y, Game g, Texture& texture, int t, int h = 0);
    void attack();
    void tick();
    void damage(int d);
};
class Flower : public Obj {
public:
    void tick();
    Flower(int X, int Y, Game g, Texture& texture, int t, int h = 0);
};
class Tir : public Obj {
public:
    Tir(int X, int Y, Game g, Texture& texture, int t, int d = 0, int h = 0);
    void tick();
};

class Game {
private:
    vector<Flower> flowers;
    vector<Tir> tirs;
    vector<Sun> suns;
    vector<Zombie> zombies;
    void delete_flower(Flower& flower);
    void delete_flower(Tir& tir);
    void delete_flower(Zombie& zombie);
    void delete_flower(Sun& sun);
    vector<Texture> textures; 
public:
    Game(vector<Texture> textures);
    void start();
};
