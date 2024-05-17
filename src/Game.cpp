#include "header.h"
#include "tools.h"
#include "Game.h"
#include "Bullet.h"
#include "Sun.h"
#include "Zombie.h"
#include "Plant.h"
bool check(FloatRect rect,vector<FloatRect> rects){
	for(FloatRect rec:rects)
		if(rec==rect)
			return true;
	return false;
}

void Game::setup_window()
{
	font.loadFromFile("files/Algerian.ttf");
		text.setFont(font);
		text.setString("END");
		text.setCharacterSize(250);
		text.setFillColor(Color::Red);
		text.setPosition(Vector2f(270,170));
	for (int i = 0; i < 5; i++)
	{
		texts[i].setFont(font);
		texts[i].setCharacterSize(25);
		texts[i].setFillColor(Color::Black);
	}
	texts[0].setPosition(Vector2f(20,100));
	texts[1].setString("0");
	texts[2].setString("0");
	texts[0].setString("0");
	texts[3].setString("0");
	texts[1].setPosition(Vector2f(25,160));
	texts[2].setPosition(Vector2f(25,270));
	texts[3].setPosition(Vector2f(25,390));
	texts[4].setPosition(Vector2f(720,55));
	make_textures(textures);
	Sprite wallpaper(textures.wallpaper);
	Sprite flower_card(textures.flower_card);
	Sprite snowflower_card(textures.snowflower_card);
	Sprite sunflower_card(textures.sunflower_card);
	Sprite wallnut_card(textures.wallnut_card);
	Sprite count_sun(textures.count_sun);
	count_sun.setPosition(700, 5);
	flower_card.setPosition(10, 30);
	sunflower_card.setPosition(10, 130);
	wallnut_card.setPosition(10, 230);
	snowflower_card.setPosition(10, 330);
	window_sprites.push_back(wallpaper);
	window_sprites.push_back(flower_card);
	window_sprites.push_back(snowflower_card);
	window_sprites.push_back(sunflower_card);
	window_sprites.push_back(count_sun);
	window_sprites.push_back(wallnut_card);
	rects = generate_rect();
	cards_rects.push_back(flower_card.getGlobalBounds());
	cards_rects.push_back(snowflower_card.getGlobalBounds());
	cards_rects.push_back(sunflower_card.getGlobalBounds());
	cards_rects.push_back(wallnut_card.getGlobalBounds());
}
template <typename T>
void Game::tick_all(vector<T *> &vect)
{
	for (int i = 0; i < vect.size(); i++)
		vect[i]->tick();
}
template <typename U>
void delete_from_vector(std::vector<U *> &vec, U* element)
{
	auto it = std::find(vec.begin(), vec.end(), element);
	if (it != vec.end())
	{
		vec.erase(it);
	}
	
}
void Game::add_sun()
{
	time_t now = time(nullptr);
	if (now - sun_timer < sun_interval)
		return;
	sun_timer = now;
	int x = randint(0, 790);
	Sun *sun = new Sun(this, x, 0, textures.sun, sun_speed);
	suns.push_back(sun);
	sprites.push_back(sun->get_sprite());
}
void Game::add_zombie()
{
	time_t now = time(nullptr);
	if (now - zombie_timer < zombie_interval)
		return;
	zombie_timer = now;
	vector<int> all_y = {85, 165, 285, 375, 465};
	int y = all_y[randint(0, 4)];
	Zombie *zombie = new Zombie(this, 800, y, zombie_health, textures.attack_normal_zombie, textures.dead_normal_zombie, textures.walk_normal_zombie, zombie_speed, 1,1);
	zombies.push_back(zombie);
	sprites.push_back(zombie->get_sprite());
}
void Game::start()
{
	RenderWindow window(VideoMode(800, 600), "Game");
	Music music;
	if(!music.openFromFile("files/pics/bg.ogg"))
	{
		return 1;
	}
	music.setLoop(true);
	music.play();
	while (true)
	{

	}

	window.setFramerateLimit(20);
	this->setup_window();

	while (window.isOpen())
	{
		texts[4].setString(to_string(suns_count));
		this->handle_event(window);
		this->update(bullets, bullets_delete);
		this->update(suns, suns_delete);
		this->update(zombies, zombies_delete);
		this->update(plants, plants_delete);
		window.clear();
		draw_window(window, window_sprites);
		draw_everthing(window, sprites);
		for(int i=0;i<5;i++)
			window.draw(texts[i]);
		if(!is_game_end){
			this->add_sun();
			this->add_zombie();		
			tick_all(plants);
			tick_all(suns);
			tick_all(zombies);
			tick_all(bullets);
			check_end();
		}
		if(is_game_end){
			window.draw(text);
		}
		window.display();

	}
}
void Game::delete_sun(Sun *sun)
{
	suns_delete.push_back(sun);
}
void Game::delete_zombie(Zombie *zombie)
{
	zombies_delete.push_back(zombie);
}
void Game::delete_plant(Plant *plant)
{
	plants_delete.push_back(plant);
}
void Game::delete_bullet(Bullet *bullet)
{
	bullets_delete.push_back(bullet);
}
template <typename V>



bool check_in(V* object, vector<V*> objects){
	for(int i=0;i<objects.size();i++){
		if(object==objects[i])
			return true;
	}
	return false;
}
template <typename U>

void Game::update(vector<U *> &objects, vector<U *> &objects_delete)
{	
	for (int i = 0; i < objects_delete.size(); i++)
	{
		while(check_in(objects_delete[i]->get_sprite(),sprites)){
			delete_from_vector(sprites, objects_delete[i]->get_sprite());
		}
		while(check_in(objects_delete[i],objects)){
			delete_from_vector(objects, objects_delete[i]);
		}
		//delete_from_vector(sprites, a->get_sprite());
		
	}
	objects_delete.clear();
}

void Game::handle_event(RenderWindow &w)
{
	Event event;
	if (w.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (Mouse::isButtonPressed(Mouse::Button::Left))
		{
			Vector2i pos= Mouse::getPosition(w);
			Vector2f position = {pos.x,pos.y};
			if (choosing_mode){
				for (FloatRect rect : rects)
				{
					if (is_point_in_rect(position, rect) && !check(rect,check_list))
					{
						time_t now = time(nullptr);
						check_list.push_back(rect);
						this->add_plant(rect.left, rect.top);
						choosing_mode = false;
						first_choose = false;
						last_choose[card.index] = now;
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < suns.size(); i++)
				{
					if(is_point_in_rect(position,suns[i]->get_sprite()->getGlobalBounds())){
						sun_plus();
						this->delete_sun(suns[i]);
						return;
					}
				}
				
				time_t now = time(nullptr);
				if (is_point_in_rect(position, cards_rects[0]))
				{
					card.name = "normal";
					card.health = 100;
					card.index = 0;
					card.textures = textures.normal_flower;
					choose_sprite.setTexture(textures.flower_card);
					sprites.push_back(&choose_sprite);
					choosing_mode = true;
					cout<<choosing_mode<<endl;
					card.countdown = 1;
				}
				if (is_point_in_rect(position, cards_rects[1])) 
				{
					card.index = 1;
					card.name = "snow";
					card.health = 200;
					card.textures = textures.snow_flower;
					choose_sprite.setTexture(textures.snowflower_card);
					sprites.push_back(&choose_sprite);
					choosing_mode = true;
					card.countdown = 1;
				}
				if (is_point_in_rect(position, cards_rects[2])) 
				{
					card.index = 2;
					card.name = "sun";
					card.health = 200;
					card.countdown = 1;
					card.textures = textures.sun_flower;
					choose_sprite.setTexture(textures.sunflower_card);
					sprites.push_back(&choose_sprite);
					choosing_mode = true;
				}
				if (is_point_in_rect(position, cards_rects[3])) )
				{
					card.index = 3;
					card.health = 100;
					card.name = "wallnut";
					card.countdown = 1;
					card.textures = textures.wallnut;
					choose_sprite.setTexture(textures.wallnut_card);
					sprites.push_back(&choose_sprite);
					choosing_mode = true;
				}
			}
		}
		if (Mouse::isButtonPressed(Mouse::Button::Right) && choosing_mode)
		{
			delete_from_vector(sprites, &choose_sprite);
			choosing_mode = false;
		}
	}
}


void Game::new_bullet(int x, int y, int mode)
{
	Bullet *bullet;
	if (mode == 1)
	{
		bullet = new Bullet(this, x, y, textures.normal_bullet, 3, 10, 0, 0);
	}
	else
	{
		bullet = new Bullet(this, x, y, textures.snow_bullet, 3, 10, 3, 3);
	}
	bullets.push_back(bullet);
	sprites.push_back(bullet->get_sprite());
}

void Game::add_plant(int x, int y)
{
	Plant *plant = new Plant(this, x, y, card.health, card.textures, 10, card.countdown, card.name);
	plants.push_back(plant);
	sprites.push_back(plant->get_sprite());
}
Zombie *Game::check_bullet(FloatRect input)
{
	for (int i = 0; i < zombies.size(); i++)
	{
		FloatRect rect1 = (zombies[i]->get_sprite())->getGlobalBounds();
		if (is_rect_in_rect(input,rect1))
			return zombies[i];
	}
	return NULL;
}
Plant *Game::check_plant(FloatRect input)
{
	for (int i = 0; i < plants.size(); i++)
	{
		FloatRect rect1 = (plants[i]->get_sprite())->getGlobalBounds();
		if (is_rect_in_rect(rect1, input)){
			return plants[i];
		}
	}
	return NULL;
}
void Game::sun_plus() { suns_count++; }
void Game::check_end(){
	for (int i = 0; i < zombies.size(); i++)
	{
		if(zombies[i]->get_sprite()->getGlobalBounds().left<50){
			is_game_end=true;
			break;
		}
	}
	if(is_game_end){
		font.loadFromFile("files/Algerian.ttf");
		text.setFont(font);
		text.setString("END");
		text.setCharacterSize(250);
		text.setFillColor(Color::Red);
		text.setPosition(Vector2f(270,170));
		window.draw(text);
	}
}
