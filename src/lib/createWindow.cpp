#include <createWindow.h>

void createWindow(RenderWindow &window, int WIDTH, int HEIGHT, String NAME_GAME) {

    window.create(sf::VideoMode(WIDTH, HEIGHT), NAME_GAME);
    window.setFramerateLimit(60);

}