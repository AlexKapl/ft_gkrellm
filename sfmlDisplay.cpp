#include "sfmlDisplay.hpp"

sfmlDisplay::sfmlDisplay() : settings(0, 0, 4),
		viewCount(0), views(),
		window(new sf::RenderWindow(sf::VideoMode(500, 2000),
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
		// if (event.type != sf::Event::KeyPressed)
		// 	continue ;
		// if (event.key.code == sf::Keyboard::Q) {
		// 	chosenView = (chosenView == -1) ? 0 : -1;
		// }
		// if (event.key.code == sf::Keyboard::Up) {
		// 	if (!moveMode) {
		// 		chosenView--;
		// 		if (chosenView == -1)
		// 			chosenView = views.size() - 1;
		// 	}
		// 	else {
		// 		if (chosenView == 0) {
		// 			continue ;
		// 		}
		// 		else {
		// 			sf::View *view = views[chosenView], *swapView = views[chosenView - 1];

		// 			sf::FloatRect	viewViewport = view->getViewport(),
		// 							swapViewViewport = swapView->getViewport(),
		// 							tmpViewport = view->getViewport();

		// 			sf::Vector2f viewCenter = view->getCenter(), swapViewCenter = swapView->getCenter();
		// 			sf::Vector2f viewSize = view->getSize(), swapViewSize = swapView->getSize();
		// 			// int viewX = viewCenter.x - viewSize.x / 2, viewY = viewCenter.y - viewSize.y / 2;
		// 			int swapViewX = swapViewCenter.x - swapViewSize.x / 2, swapViewY = swapViewCenter.y - swapViewSize.y / 2;

		// 			sf::FloatRect	viewRect(swapViewX, swapViewY, viewSize.x, viewSize.y),
		// 							swapViewRect(swapViewX + viewSize.x, swapViewY + viewSize.y, swapViewSize.x, swapViewSize.y);
		// 			tmpViewport = viewViewport;
		// 			viewViewport.top = swapViewViewport.top;
		// 			swapViewViewport.top += viewViewport.height;

		// 			view->setViewport(viewViewport);
		// 			swapView->setViewport(swapViewViewport);

		// 			view->reset(viewRect);
		// 			swapView->reset(swapViewRect);

		// 			// views[chosenView] = swapView;
		// 			// views[chosenView - 1] = view;
		// 			int tmp = chosenView;
		// 			chosenView = nums[chosenView - 1];
		// 			nums[chosenView - 1] = tmp;
		// 			chosenView--;
		// 		}
		// 	}
		// }
		// if (event.key.code == sf::Keyboard::Down) {
		// 	if (!moveMode) {
		// 		chosenView++;
		// 		if (chosenView == views.size())
		// 			chosenView = 0;
		// 	}
		// 	else {
		// 		if (chosenView == views.size() - 1) {
		// 			continue ;
		// 		}
		// 		else {
		// 			sf::View *view = views[chosenView], *swapView = views[chosenView + 1];

		// 			sf::FloatRect	viewViewport = view->getViewport(),
		// 							swapViewViewport = swapView->getViewport(),
		// 							tmpViewport;

		// 			sf::Vector2f viewCenter = view->getCenter(), swapViewCenter = swapView->getCenter();
		// 			sf::Vector2f viewSize = view->getSize(), swapViewSize = swapView->getSize();
		// 			int viewX = viewCenter.x - viewSize.x / 2, viewY = viewCenter.y - viewSize.y / 2;
		// 			// int swapViewX = swapViewCenter.x - swapViewSize.x / 2, swapViewY = swapViewCenter.y - swapViewSize.y / 2;

		// 			sf::FloatRect	viewRect(viewX + swapViewSize.x, viewY + swapViewSize.y, viewSize.x, viewSize.y),
		// 							swapViewRect(viewX, viewY, swapViewSize.x, swapViewSize.y);
		// 			tmpViewport = viewViewport;
		// 			swapViewViewport.top = viewViewport.top;
		// 			viewViewport.top += swapViewViewport.height;

		// 			swapView->setViewport(viewViewport);
		// 			view->setViewport(swapViewViewport);

		// 			swapView->reset(viewRect);
		// 			view->reset(swapViewRect);

		// 			// views[chosenView] = swapView;
		// 			// views[chosenView + 1] = view;
		// 			int tmp = chosenView;
		// 			chosenView = nums[chosenView + 1];
		// 			nums[chosenView + 1] = tmp;
		// 			chosenView++;
		// 		}
		// 	}
		// }
		// if (event.key.code == sf::Keyboard::M) {
		// 	moveMode = (moveMode) ? false : true;
		// }
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

	leftSide.setFillColor(sf::Color(192, 192, 192));
	rightSide.setFillColor(sf::Color(192, 192, 192));
	// if (chosenView == num)
	// {
	// 	if (!moveMode)
	// 		upSide.setFillColor(sf::Color(108, 255, 108));
	// 	else
	// 		upSide.setFillColor(sf::Color(108, 108, 255));
	// }
	// else
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
	x = 500 / 2;
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