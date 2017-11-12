/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:59:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 21:59:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

NetworkModule::NetworkModule(int height, Monitor &monitor) : AModule("Network") {
	int w, h;
	IMonitorDisplay *display;

	lines.push_back(new Line("In:", ""));
	lines.push_back(new Line("Out:", ""));
	this->height = static_cast<int>(lines.size() + 1);
	this->refresh();
	display = monitor.getDisplay();
	display->getMaxYX(h, w);
	if (w > width)
		width = w;
	win = display->getWindowNum(this->height, this->width, height, 0);
}


// * DESTRUCTORS ************************************************************ //

NetworkModule::~NetworkModule() {}

// * OPERATORS ************************************************************** //

NetworkModule &NetworkModule::operator=(NetworkModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void NetworkModule::refresh() {
	static double seconds = -1, start = clock();
	double secondsPassed;

	secondsPassed = (clock() - start) / CLOCKS_PER_SEC;
	if ((secondsPassed - seconds) > 0.3) {
		seconds = secondsPassed;

		unsigned long delim;
		std::stringstream ss;
		std::string top = Kernel::getTopInfo(
				"\"Net\" | awk '{print $3\"|\"$5\"}\"}'");

		delim = top.find('|');
		lines[In]->setValue(top.substr(0, delim));
		lines[Out]->setValue(top.substr(delim + 1, top.find('}') - delim - 1));
	}
}

// * NESTED_CLASSES ********************************************************* //
