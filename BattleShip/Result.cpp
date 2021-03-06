#include "Result.hpp"

using namespace sf;

Result::Result() {

}

Result::Result(State& state) {

    RenderWindow ResWindow(VideoMode(1280, 720), "Result");

    if (state == State::User) {
        ResTexture.loadFromFile("images\\Winner.jpg");
        music.openFromFile("sounds\\Ta_Da.wav");
    }
    else {
        ResTexture.loadFromFile("images\\Loser.jpg");
        music.openFromFile("sounds\\sea_gulls.wav");
    }      
    music.play();
    ResSprite.setTexture(ResTexture);
    ResSprite.setPosition(0, 0);

    ResWindow.clear();
    ResWindow.draw(ResSprite);
    ResWindow.display();

    while (ResWindow.isOpen())
    {
        while (ResWindow.pollEvent(ResEvent)) {
            if (ResEvent.type == Event::Closed) {
                ResWindow.close();
            }
        } 
    }
}