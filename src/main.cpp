#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
int main() {
  sf::Window window(sf::VideoMode(800, 600), "game");
  window.setVerticalSyncEnabled(true);
  sf::Music music;
  if (!music.openFromFile("music.ogg")) {
    std::cerr << "music error" << std::endl;
    return 1;
  }
  music.play();
  sf::Image image;
  if (!image.loadFromFile("image.png")) {
    std::cerr << "load image error!" << std::endl;
    return 1;
  }
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) 
        window.close();
    window.clear(sf::Color::Black);
    window.display();
  }
  music.stop();
  return 0;
}
