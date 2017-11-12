/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:53:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 18:53:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

Monitor::Monitor() : width(0), height(0), modules(), display() {}

Monitor::Monitor(Monitor const &) {}

// * DESTRUCTORS ************************************************************ //

Monitor::~Monitor() {
	IMonitorModule *module;
	iterator end = modules.end();

	for (Modules::iterator it = modules.begin(); it != end; ++it) {
		module = *it;
		delete (module);
	}
	modules.clear();
	delete (display);
}

// * OPERATORS ************************************************************** //

Monitor &Monitor::operator=(Monitor const &assign) {
	if (this != &assign) {

	}
	return (*this);
}

// * GETTERS **************************************************************** //

IMonitorDisplay *Monitor::getDisplay() const {
	return display;
}

int Monitor::getWidth() const {
	return width;
}

int Monitor::getHeight() const {
	return height;
}

// * SETTERS **************************************************************** //

void Monitor::setDisplay(IMonitorDisplay *display) {
	this->display = display;
}

void Monitor::addModule(IMonitorModule *module) {
	modules.push_back(module);
	height += module->getHeight();
}

// * MEMBER FUNCTIONS / METHODS ********************************************* //

void Monitor::draw() {
	IMonitorModule *module;
	iterator end = modules.end();

	for (iterator it = modules.begin(); it != end; ++it) {
		module = *it;
		module->draw(display);
	}
	display->draw();
}

void Monitor::refreshAll() {
	IMonitorModule *module;
	iterator end = modules.end();

	for (iterator it = modules.begin(); it != end; ++it) {
		module = *it;
		module->refresh();
	}
}

void Monitor::loop() {
	while (isOpen()) {
		refreshAll();
		draw();
		display->process_input();
	}
}

bool Monitor::isOpen() {
	return display->isOpen();
}

// * NESTED_CLASSES ********************************************************* //
