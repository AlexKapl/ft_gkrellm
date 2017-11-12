#include "sfmlDisplay.hpp"
#include "Monitor.hpp"

sfmlDisplay::sfmlDisplay() : themeNum(0), settings(0, 0, 4),
		viewCount(0), views(),
		window(new sf::RenderWindow(sf::VideoMode(500, 2000),
			   "ft_gkrellm",
			   sf::Style::Default & (~(1 << 1)),
			   settings))
{
	themes.push_back(theme(sf::Color(441/3.92, 453/3.92, 455/3.92), sf::Color(291/3.92, 293/3.92, 295/3.92), sf::Color(188/3.92, 194/3.92, 200/3.92)));
	themes.push_back(theme(sf::Color(99/3.92,  92/3.92,  60/3.92),  sf::Color(230/3.92, 223/3.92, 165/3.92), sf::Color(226/3.92, 143/3.92, 179/3.92)));
	themes.push_back(theme(sf::Color(36/3.92,  36/3.92,  36/3.92),  sf::Color(220/3.92, 64/3.92,  53/3.92),  sf::Color(78/3.92,  78/3.92,  82/3.92)));
}

sfmlDisplay::sfmlDisplay(int) {}

sfmlDisplay::sfmlDisplay(sfmlDisplay const &) {}
sfmlDisplay::~sfmlDisplay() {}
sfmlDisplay &sfmlDisplay::operator=(sfmlDisplay const &) { return *this; }

void sfmlDisplay::clear() { window->clear(sfmlDisplay::themes[themeNum].backColor); }
bool sfmlDisplay::isOpen() { return window->isOpen(); }

sf::RectangleShape sfmlDisplay::createLine(int w, int h, int x, int y, int rotate) {
	sf::RectangleShape rectangle;

	rectangle.setSize(sf::Vector2f(w, h));
	rectangle.setPosition(x, y);
	rectangle.setRotation(rotate);

	return rectangle;
}

void sfmlDisplay::colorTheme() {
	if (++themeNum > THEMES_NUM - 1)
		themeNum = 0;
}

void sfmlDisplay::draw() {
	window->display();
}

void sfmlDisplay::processInput() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
		   (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			window->close();
		if (event.type != sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
		{
			window->close();
			Monitor::swap = 1;
		}
		if (event.type != sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab)
			colorTheme();
	}
}

void sfmlDisplay::drawBorder(int num) {
	window->setView(*views[num]);

	sf::Vector2f size = views[num]->getSize();

	sf::Vector2f center = views[num]->getCenter();
	int dx = center.x - size.x / 2;
	int dy = center.y - size.y / 2;

	sf::RectangleShape 	leftSide  = createLine(10, size.y, dx, dy, 0),
						rightSide = createLine(10, size.y, size.x - 10 + dx, dy, 0),

						upSide    = createLine(40, size.x, dx, 40 + dy, -90),
						upSide1	  = createLine(10, size.x, dx, 50 + dy, -90),
						downSide  = createLine(10, size.x, dx, size.y + dy, -90);

	leftSide.setFillColor(sfmlDisplay::themes[themeNum].borderColor);
	rightSide.setFillColor(sfmlDisplay::themes[themeNum].borderColor);
	upSide.setFillColor(sfmlDisplay::themes[themeNum].titleColor);
	upSide1.setFillColor(sfmlDisplay::themes[themeNum].borderColor);
	downSide.setFillColor(sfmlDisplay::themes[themeNum].borderColor);

	window->draw(leftSide);
	window->draw(rightSide);
	window->draw(upSide);
	window->draw(upSide1);
	window->draw(downSide);
}

void sfmlDisplay::drawTitle(int num, int x, Line * line) {
	window->setView(*views[num]);

	sf::Vector2f size = views[num]->getSize();
	sf::Vector2f center = views[num]->getCenter();
	int dx = center.x - size.x / 2;
	int dy = center.y - size.y / 2;

	sf::Font font;
	font.loadFromFile("OpenSans.ttf");
	sf::Text title;
	title.setFont(font);
	title.setString(line->getValue());
	title.setColor(sf::Color(112, 147, 219));
	x = (500 - line->getValue().size() * title.getCharacterSize() / 2) / 2;
	title.setPosition(x + dx, dy);

	window->draw(title);
}

void sfmlDisplay::drawLine(int num, int y, int x, Line * line) {
	window->setView(*views[num]);

	sf::Font font;
	font.loadFromFile("OpenSans.ttf");

	sf::Vector2f size = views[num]->getSize();
	sf::Vector2f center = views[num]->getCenter();
	int dx = center.x - size.x / 2;
	int dy = center.y - size.y / 2;

	sf::Text key, value;
	key.setString(line->getName());
	value.setString(line->getValue());
	key.setFont(font);
	value.setFont(font);
	key.setColor(sf::Color(255, 255, 224));
	value.setColor(sf::Color(255, 255, 153));
	key.setPosition(x + 10 + dx, y * 32 + dy);
	value.setPosition(250 / 2 + dx, y * 32 + dy);

	window->draw(key);
	window->draw(value);
}

void sfmlDisplay::drawPony(int num, AnimatedSprite &animatedSprite) {
	window->setView(*views[num]);
	window->draw(animatedSprite);
}

void sfmlDisplay::getMaxYX(int &h, int &w) {
	h = 2000;
	w = 500;
}

int sfmlDisplay::getWindowNum(int h, int w, int y, int x) {
	y *= 32;
	h *= 32;
	sf::View *view = new sf::View(sf::FloatRect(x, y,
												static_cast<float>(w),
												static_cast<float>(h)));
	// std::cout << h << " " << w << " " << y << " " << x << std::endl;
	float xf = static_cast<float>(x) / 500;
	float yf = static_cast<float>(y) / 2000;
	view->setViewport(sf::FloatRect(xf, yf,
												static_cast<float>(w) / 500,
												static_cast<float>(h) / 2000));
	views.push_back(view);
	// std::cout << h << " " << w << " " << yf << " " << xf << std::endl;
	return (viewCount++);
}


sfmlDisplay::theme::theme(sf::Color c1, sf::Color c2, sf::Color c3) : titleColor(c1), borderColor(c2), backColor(c3) {}
sfmlDisplay::theme &sfmlDisplay::theme::operator=(theme const &t) {
	this->titleColor = t.titleColor;
	this->borderColor = t.borderColor;
	this->backColor = t.backColor;
	return *this;
}
sfmlDisplay::theme::~theme() {}
sfmlDisplay::theme::theme(theme const &t) {
	*this = t;
}
