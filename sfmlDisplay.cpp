#include "sfmlDisplay.hpp"

sfmlDisplay::sfmlDisplay() : settings(0, 0, 4),
		viewCount(0), views(),
		window(new sf::RenderWindow(sf::VideoMode(1600, 1600),
			   "ft_gkrellm",
			   sf::Style::Default & (~(1 << 1)),
			   settings))
{}

sfmlDisplay::sfmlDisplay(sfmlDisplay const &) {}
sfmlDisplay::~sfmlDisplay() {}
sfmlDisplay &sfmlDisplay::operator=(sfmlDisplay const &) { return *this; }

void sfmlDisplay::clear() { window->clear(); }
bool sfmlDisplay::isOpen() { return window->isOpen(); }

sf::RectangleShape sfmlDisplay::createLine(int w, int h, int x, int y, int rotate) {
	sf::RectangleShape rectangle;

	rectangle.setSize(sf::Vector2f(w, h));
	rectangle.setPosition(x, y);
	rectangle.setRotation(rotate);

	return rectangle;
}

void sfmlDisplay::draw() {
	// window->setView(*views[0]);
	// sf::CircleShape shape(100.f);
	// shape.setFillColor(sf::Color::Green);
	// window->draw(shape);
	window->display();
}

void sfmlDisplay::processInput() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
		   (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			window->close();
	}
}

void sfmlDisplay::drawBorder(int num) {
	window->setView(*views[num]);

	sf::Vector2f size = views[num]->getSize();
	sf::RectangleShape 	leftSide  = createLine(10, size.y, 0, 0, 0),
						rightSide = createLine(10, size.y, size.x - 10, 0, 0),

						upSide    = createLine(40, size.x, 0, 40, -90),
						upSide1	  = createLine(10, size.x, 0, 50, -90),
						downSide  = createLine(10, size.x, 0, size.y, -90);

	leftSide.setFillColor(sf::Color(192, 192, 192));
	rightSide.setFillColor(sf::Color(192, 192, 192));
	upSide.setFillColor(sf::Color(108, 108, 108));
	upSide1.setFillColor(sf::Color(192, 192, 192));
	downSide.setFillColor(sf::Color(192, 192, 192));

	window->draw(leftSide);
	window->draw(rightSide);
	window->draw(upSide);
	window->draw(upSide1);
	window->draw(downSide);
}

void sfmlDisplay::drawTitle(int num, int x, Line * line) {
	window->setView(*views[num]);

	sf::Font font;
	font.loadFromFile("OpenSans.ttf");
	sf::Text title;
	title.setFont(font);
	title.setString(line->getValue());
	title.setColor(sf::Color(112, 147, 219));
	x = 1600 / 2;
	title.setPosition(x, 0);

	window->draw(title);
}

void sfmlDisplay::drawLine(int num, int y, int x, Line * line) {
	window->setView(*views[num]);

	sf::Font font;
	font.loadFromFile("OpenSans.ttf");

	sf::Text key, value;
	key.setString(line->getName());
	value.setString(line->getValue());
	key.setFont(font);
	value.setFont(font);
	key.setColor(sf::Color(255, 255, 224));
	value.setColor(sf::Color(255, 255, 153));
	key.setPosition(x + 10, y * 32);
	value.setPosition(1600 / 2, y * 32);

	window->draw(key);
	window->draw(value);
}

void sfmlDisplay::getMaxYX(int &h, int &w) {
	h = 1600;
	w = 1600;
}

int sfmlDisplay::getWindowNum(int h, int w, int y, int x) {
	x++; y++; w++;h++;
	sf::View *view = new sf::View(sf::FloatRect(0, 0,
												static_cast<float>(w),
												static_cast<float>(h * 24)));
	view->setViewport(sf::FloatRect(static_cast<float>(x / 1600),
												static_cast<float>(0 / 1600),
												static_cast<float>(w / 1600),
												static_cast<float>(h * 24) / 1600));
	views.push_back(view);
	std::cout << h * 32 << " " << w << " " << y << " " << x << std::endl;
	return (viewCount++);
}