#ifndef SFMLDISPLAY_HPP
# define SFMLDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "SFML/Graphics.hpp"

class sfmlDisplay : public IMonitorDisplay
{
public:

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

private:
	const sf::ContextSettings settings;

	int windowCount;

	Windows windows;

	sf::RenderWindow window;

	sfmlDisplay(sfmlDisplay const &s);
	sfmlDisplay &operator=(sfmlDisplay const &s);
	
};

#endif // SFMLDISPLAY_HPP