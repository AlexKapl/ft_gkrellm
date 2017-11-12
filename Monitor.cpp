/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:53:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 22:04:51 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.hpp"
#include "UserModule.hpp"
#include "NcursesDisplay.hpp"
#include "sfmlDisplay.hpp"
#include "OsModule.hpp"
#include "DateModule.hpp"
#include "CpuModule.hpp"
#include "PonyModule.hpp"
#include "RamModule.hpp"

// * STATICS **************************************************************** //

int Monitor::swap = 0;

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

	display->clear();
	display->processInput();

	for (Modules::iterator it = modules.begin(); it != end; ++it) {
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
		display->processInput();
		if (Monitor::swap) {
			IMonitorModule *module;
			iterator end = modules.end();

			for (Modules::iterator it = modules.begin(); it != end; ++it) {
				module = *it;
				delete (module);
			}
			modules.clear();

			IMonitorDisplay *oldDisplay = this->display;
			this->height = 0;
			NcursesDisplay test(10);
			if (typeid(*oldDisplay) == typeid(test))
			{
				delete oldDisplay;
				this->display = new sfmlDisplay();
				this->addModule(new PonyModule(this->getHeight(), *this));
			}
			else {
				delete oldDisplay;
				this->display = new NcursesDisplay();
			}
			this->addModule(new UserModule(this->getHeight(), *this));
			this->addModule(new OsModule(this->getHeight(), *this));
			this->addModule(new DateModule(this->getHeight(), *this));
			this->addModule(new CpuModule(this->getHeight(), *this));
			this->addModule(new RamModule(this->getHeight(), *this));
			Monitor::swap = 0;
		}
	}
}

bool Monitor::isOpen() {
	return display->isOpen();
}

// * NESTED_CLASSES ********************************************************* //
