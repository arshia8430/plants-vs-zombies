#ifndef GAME
#define GAME
#include "header.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Plant.h"
#include "Sun.h"
#define MAX_HEALTH 100
#define SUN_INTERVAL 3
#define ZOMBIE_INTERVAL 3
#define SUN_SPEED 1
class Game{
	private:
		RenderWindow window;
		Sprite choose_sprite;
		bool is_game_end=false;
		bool first_choose;
		bool choosing_mode=false;
		int suns_count=0;
		int sun_interval=SUN_INTERVAL;
		int zombie_interval=ZOMBIE_INTERVAL;
		int zombie_health=MAX_HEALTH;
		int sun_speed=SUN_SPEED;
		int zombie_speed=1;
		time_t sun_timer=time(nullptr);
		time_t zombie_timer=time(nullptr);
		vector<time_t> last_choose{4,time(nullptr)};
		vector<FloatRect> card_rect;
		vector<Sun*> suns;
		vector<Sun*> suns_delete;
		vector<Zombie*> zombies;
		vector<Zombie*> zombies_delete;
		vector<Plant*> plants;
		vector<Plant*> plants_delete;
		vector<Bullet*> bullets;
		vector<Bullet*> bullets_delete;
		Textures textures;
		vector<FloatRect> check_list;
		vector <Sprite*> sprites;
		vector <Sprite> window_sprites;
		vector <FloatRect> cards_rects;
		vector <FloatRect> rects;
		vector <Text> texts{5};
		Card card;
		Text text;
		void setup_window();
		Font font;
		void check_end();
		void draw();
		void add_sun();
		void add_zombie();
		void add_plant(int x,int y);
		template <typename U>
		void update(vector<U*>&objects,vector<U*>&objects_delete);
		void check_event(Event& event);
		template <typename T>
		void tick_all(vector<T*>& vect);
		void handle_event(RenderWindow& w);
	public:
		void sun_plus();
		void start();
		Plant* check_plant(FloatRect rect);
		void delete_sun(Sun* sun);
		void delete_zombie(Zombie* zombie);
		void delete_bullet(Bullet* bullet);
		void delete_plant(Plant* plant);
		void new_bullet(int x,int y,int mode);
		Zombie* check_bullet(FloatRect input);
};
#endif
