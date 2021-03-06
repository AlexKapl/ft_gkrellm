/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:02:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 19:02:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

CpuModule::CpuModule(int height, Monitor &monitor) : AModule("CPU") {
	int w, h;
	IMonitorDisplay *display;
	std::string str;
	unsigned long pos;

	str =  Kernel::getKernelInfo("machdep.cpu.brand_string");
	pos = str.find("CPU") - 1;
	lines.push_back(new Line("CPU:", str.substr(0, pos)));
	lines.push_back(new Line("Speed:", str.substr(str.find('@') + 1)));
	lines.push_back(new Line("Cores:", Kernel::getKernelInfoInt(
			"machdep.cpu.core_count")));
	lines.push_back(new Line("User:", ""));
	lines.push_back(new Line("System:", ""));
	this->height = static_cast<int>(lines.size() + 1);
	this->refresh();
	display = monitor.getDisplay();
	display->getMaxYX(h, w);
	if (w > width)
		width = w;
	win = display->getWindowNum(this->height, this->width, height, 0);
}


// * DESTRUCTORS ************************************************************ //

CpuModule::~CpuModule() {}

// * OPERATORS ************************************************************** //

CpuModule &CpuModule::operator=(CpuModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void CpuModule::refresh() {
	static double seconds = -1, start = clock();
	double secondsPassed;

	secondsPassed = (clock() - start) / CLOCKS_PER_SEC;
	if ((secondsPassed - seconds) > 0.3) {
		seconds = secondsPassed;

		int s1, s2;
		std::string top =
				Kernel::getTopInfo("\"CPU\" | awk '{print $3\"|\"$5\"?\"}'");
		unsigned long delim = top.find('|');

		lines[User]->setValue(top.substr(0, delim));
		s1 = lines[User]->getSize();
		lines[System]->setValue(top.substr(delim + 1,
										   top.find('?') - delim - 1));
		s2 = lines[System]->getSize();
		s1 = s1 > s2 ? s1 : s2;
		if (width < s1)
			width = s1;

	}
}

// * NESTED_CLASSES ********************************************************* //
