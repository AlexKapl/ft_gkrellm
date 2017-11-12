#include "PonyModule.hpp"

PonyModule::~PonyModule() {}
PonyModule::PonyModule(int height, Monitor &monitor) :
		AModule("Pony"), animatedSprite(sf::seconds(0.0548), true, false), textureIsLoad(false) {
	IMonitorDisplay *display;

	if (texture.loadFromFile("pony.png"))
	{
		textureIsLoad = true;
		animation.setSpriteSheet(texture);
	    int x = 0;
	    for (int i = 0; i < 27; i++) {
	        animation.addFrame(sf::IntRect(x, 0, 500, 500));
	        x += 600;
	    }
	    animatedSprite.setPosition(sf::Vector2f(0, height * 32 + 1));
	}
    this->height = 16;
    this->width = 500;

    display = monitor.getDisplay();
    win = display->getWindowNum(this->height, this->width, height, 0);
}

void PonyModule::draw(IMonitorDisplay *display) {
	if (textureIsLoad)
		display->drawPony(win, animatedSprite);
	display->drawBorder(win);
}

void PonyModule::refresh() {
	if (textureIsLoad) {
		sf::Time frameTime = frameClock.restart();
		animatedSprite.play(animation);
	    animatedSprite.update(frameTime);
	}
}