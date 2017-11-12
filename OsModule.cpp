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

OsModule::OsModule(int height, Monitor &monitor) : AModule("Os") {
	int w, h;
	IMonitorDisplay *display;

	lines.push_back(new Line("Type:", Kernel::getKernelInfo("kern.ostype")));
	lines.push_back(
			new Line("Release:", Kernel::getKernelInfo("kern.osrelease")));
	this->height = static_cast<int>(lines.size() + 1);
	this->refresh();
	display = monitor.getDisplay();
	display->getMaxYX(h, w);
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

void OsModule::refresh() {}

// * NESTED_CLASSES ********************************************************* //
