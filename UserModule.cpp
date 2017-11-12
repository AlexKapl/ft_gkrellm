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

	lines.push_back(new Line("Host:", Kernel::getKernelInfo("kern.hostname")));
	lines.push_back(new Line("User:", Kernel::getUserName()));
	this->height = static_cast<int>(lines.size() + 1);
	this->refresh();
	display = monitor.getDisplay();
	display->getMaxYX(h, w);
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

void UserModule::refresh() {}

// * NESTED_CLASSES ********************************************************* //
