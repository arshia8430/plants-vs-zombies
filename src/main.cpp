#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
using namespace sf;

Sprite draw_image(RenderWindow window,string name,int x=-1,int y=-1){
  Texture texture;
  texture.loadFromFile(string+".jpg");
  Sprite sprite;
  if(x!=-1 && y!= -1)
    sprite.setPostion(x,y);
  return sprite;
}
int main()
{
    RenderWindow window(VideoMode(800, 600), "Game");
    Texture texture;
    texture.loadFromFile("Background_0.jpg");
    Sprite wal(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.draw(draw_image(window,"card_wallnut",30,30));
        window.display();
    }

    return 0;
}
