/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 17:01:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsModule.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

OsModule::OsModule(int height, Monitor &monitor) : AModule("Date") {
	int w, h;
	IMonitorDisplay *display;

	lines.push_back(new Line("Type:", ""));
	lines.push_back(new Line("Release:", ""));
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

OsModule::~OsModule() {}

// * OPERATORS ************************************************************** //

OsModule &OsModule::operator=(OsModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void OsModule::refresh() {
	int	s1, s2;

	lines[Type]->setValue(Kernel::getKernelInfo("kern.ostype"));
	s1 = lines[Type]->getSize();
	lines[Release]->setValue(Kernel::getKernelInfo("kern.osrelease"));
	s2 = lines[Release]->getSize();
	width = (s1 > s2 ? s1 : s2);
}

// * NESTED_CLASSES ********************************************************* //
