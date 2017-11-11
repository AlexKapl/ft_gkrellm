#include "UserModule.hpp"/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:05:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 19:05:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserModule.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

UserModule::UserModule(int height, Monitor & monitor) :
		win(0), width(0), height(WIN_H(2)), lines() {
	int		w, h;
	IMonitorDisplay *display;

	lines.push_back(new Line("", "User"));
	lines.push_back(new Line("", ""));
	lines.push_back(new Line("Host:", ""));
	lines.push_back(new Line("User:", ""));
	this->refresh();
	display = monitor.getDisplay();
	display->getMaxYX(w, h);
//	if ((h - height) < this->height) {
//		throw MyException("Can't fit data in window. Please increase height");
//	}
//	else if (w < width) {
//		throw MyException("Can't fit data in window. Please increase width");
//	}
	if (w > width)
		width = w;
	win = display->getWindowNum(this->height, width, height, 0);
	// display->drawBorder(win);
}


// * DESTRUCTORS ************************************************************ //

UserModule::~UserModule() {
	Line * line;
	Line::iterator end = lines.end();

	for (Line::iterator it = lines.begin(); it != end; ++it) {
		line = *it;
		delete(line);
	}
	lines.clear();
//	delwin(win);
}

// * OPERATORS ************************************************************** //

UserModule &UserModule::operator=(UserModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //

int UserModule::getWidth() const {
	return width;
}

int UserModule::getHeight() const {
	return height;
}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void UserModule::refresh() {
	unsigned long	s1, s2;

	lines[Host]->setValue(Kernel::getKernelInfoByName("kern.hostname"));
	s1 = lines[Host]->getValue().size();
	lines[User]->setValue(Kernel::getUserName());
	s2 = lines[User]->getValue().size();
	width = static_cast<int>(s1 > s2 ? s1 : s2);
}

void UserModule::draw(IMonitorDisplay *display) {
	display->drawBorder(win);
	display->drawTitle(win, 0, lines[Title]);
	for (int i = 1; i < 4; i++) {
		display->drawLine(win, i, 0, lines[i]);
	}
}

// * NESTED_CLASSES ********************************************************* //
