/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:29:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 19:29:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

RamModule::RamModule(int height, Monitor &monitor) : AModule("Ram") {
	IMonitorDisplay *display;

	lines.push_back(new Line("Total:", ""));
	lines.push_back(new Line("Used:", ""));
	lines.push_back(new Line("Wired:", ""));
	lines.push_back(new Line("Free:", ""));
	this->height = static_cast<int>(lines.size() + 1);
	this->refresh();
	display = monitor.getDisplay();
	win = display->getWindowNum(this->height, this->width, height, 0);
}


// * DESTRUCTORS ************************************************************ //

RamModule::~RamModule() {}

// * OPERATORS ************************************************************** //

RamModule &RamModule::operator=(RamModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void RamModule::refresh() {
	static double seconds = -1, start = clock();
	double secondsPassed;

	secondsPassed = (clock() - start) / CLOCKS_PER_SEC;
	if ((secondsPassed - seconds) > 0.3) {
		seconds = secondsPassed;

		unsigned long first, second;
		std::stringstream ss;
		std::string used, wired, free, top = Kernel::getTopInfo(
				"\"PhysMem\" | awk '{print $2$4\"|\"$6\"}\"}'");

		first = top.find('(');
		second = top.find('|');
		used = top.substr(0, first);
		wired = top.substr(first + 1, second - first - 1);
		free = top.substr(second + 1, top.find('}') - second - 1);
		ss << std::atoi(used.c_str()) + std::atoi(free.c_str()) << 'M';
		lines[Total]->setValue(ss.str());
		lines[Used]->setValue(used);
		lines[Wired]->setValue(wired);
		lines[Free]->setValue(free);
	}
}

// * NESTED_CLASSES ********************************************************* //
