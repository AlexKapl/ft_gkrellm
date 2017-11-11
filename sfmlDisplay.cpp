#include "sfmlDisplay.hpp"

sfmlDisplay::sfmlDisplay() : settings(0, 0, 4),
		windowCount(0), windows(),
		window(sf::VideoMode(1600, 1600),
			   "ft_gkrellm",
			   sf::Style::Default & (~(1 << 1)),
			   settings)
{
	window.setActive(false);
	window.clear();
}

sfmlDisplay::sfmlDisplay(sfmlDisplay const &) {}
sfmlDisplay::~sfmlDisplay() {}
sfmlDisplay &sfmlDisplay::operator=(sfmlDisplay const &) {}

void sfmlDisplay::clear() { window.clear(); }
bool sfmlDisplay::isOpen() { return window.isOpen(); }

void sfmlDisplay::draw() {
	window.display();
}

void sfmlDisplay::processInput() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
		   (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			window.close();
	}
}

void sfmlDisplay::drawBorder(int num) {

}

void sfmlDisplay::drawTitle(int num, int x, Line * line) {

}

void sfmlDisplay::drawLine(int num, int y, int x, Line * line) {

}

void sfmlDisplay::getMaxYX(int &h, int &w) {

}

int sfmlDisplay::getWindowNum(int h, int w, int y, int x) {
	
}