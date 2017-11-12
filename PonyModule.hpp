#ifndef PONYMODULE_HPP
# define PONYMODULE_HPP

# include "AModule.hpp"
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

class PonyModule : public AModule
{
public:
	PonyModule(int height, Monitor &monitor);
	~PonyModule();
	void refresh();
	void draw(IMonitorDisplay *monitor);

private:
	PonyModule();
	PonyModule(PonyModule const &);
	PonyModule &operator=(PonyModule const &);

	AnimatedSprite animatedSprite;
	Animation animation;
	sf::Texture texture;
	bool textureIsLoad;
	sf::Clock frameClock;
};

#endif // PONYMODULE_HPP