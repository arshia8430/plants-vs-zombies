#ifndef TOOLS
#define TOOLS
#include "header.h"
vector<FloatRect> generate_rect();
int randint(int min,int max);
bool is_point_in_rect(Vector2f point,FloatRect rect);
bool is_rect_in_rect(FloatRect rect1,FloatRect rect2);
//void tick_all(vector<auto>& vect);
vector <FloatRect> generate_rect();
void make_textures(Textures& textures);
void draw_everthing(RenderWindow& window,const vector<Sprite*>& sprites);
void draw_window(RenderWindow& window,const vector<Sprite>& sprites);
//void delete_from_vector(vector<auto>& vect,const auto obj);
#endif
