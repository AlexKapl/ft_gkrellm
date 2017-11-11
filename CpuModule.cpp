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

	lines.push_back(new Line("CPU:", Kernel::getKernelInfo(
			"machdep.cpu.brand_string")));
	lines.push_back(new Line("Cores:", Kernel::getKernelInfoInt(
			"machdep.cpu.core_count")));
	lines.push_back(new Line("", ""));
	lines.push_back(new Line("", ""));
	lines.push_back(new Line("", ""));
	lines.push_back(new Line("", ""));
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
	int size;

	for (int i = 4; i < 8; i++) {
		lines[i]->setValue(Kernel::getCoreInfo(i - 4));
		size = lines[i]->getSize();
		if (width < size)
			width = size;
	}
}

// * NESTED_CLASSES ********************************************************* //
