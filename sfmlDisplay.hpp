#ifndef SFMLDISPLAY_HPP
# define SFMLDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "AnimatedSprite.hpp"
# include "SFML/Graphics.hpp"

class sfmlDisplay : public IMonitorDisplay
{
public:

	typedef std::vector<sf::View *> Views;
	typedef Views::iterator iterator;

	sfmlDisplay();
	~sfmlDisplay();

	void draw();

	void drawBorder(int num);

	void drawTitle(int num, int x, Line * line);

	void drawLine(int num, int y, int x, Line * line);

	void getMaxYX(int &h, int &w);

	int getWindowNum(int h, int w, int y, int x);

	void clear();

	bool isOpen();

	void processInput();

	void drawPony(int num, AnimatedSprite &animatedSprite);

private:
	sf::RectangleShape createLine(int w, int h, int x, int y, int rotate);

	const sf::ContextSettings settings;

	int viewCount;

	Views views;

	sf::RenderWindow *window;

	sfmlDisplay(sfmlDisplay const &s);
	sfmlDisplay &operator=(sfmlDisplay const &s);

	// int chosenView;
	// bool moveMode;
};

#endif // SFMLDISPLAY_HPP