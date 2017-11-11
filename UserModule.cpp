/* ************************************************************************** */
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

UserModule::UserModule(int height, Monitor &monitor) : AModule("User") {
	int w, h;
	IMonitorDisplay *display;

	lines.push_back(new Line("Host:", ""));
	lines.push_back(new Line("User:", ""));
	this->height = static_cast<int>(lines.size() + 1);
	this->refresh();
	display = monitor.getDisplay();
	display->getMaxYX(h, w);
//	if ((h - height) < this->height) {
//		throw MyException("Can't fit data in window. Please increase height");
//	}
//	else if (w < width) {
//		throw MyException("Can't fit data in window. Please increase width");
//	}
	if (w > width)
		width = w;
	win = display->getWindowNum(this->height, this->width, height, 0);
}


// * DESTRUCTORS ************************************************************ //

UserModule::~UserModule() {}

// * OPERATORS ************************************************************** //

UserModule &UserModule::operator=(UserModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void UserModule::refresh() {
	int s1, s2;

	lines[Host]->setValue(Kernel::getKernelInfoByName("kern.hostname"));
	s1 = lines[Host]->getSize();
	lines[User]->setValue(Kernel::getUserName());
	s2 = lines[User]->getSize();
	width = (s1 > s2 ? s1 : s2);
}

// * NESTED_CLASSES ********************************************************* //