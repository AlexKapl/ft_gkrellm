/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:25:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 21:57:41 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AModule.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //


AModule::AModule(const std::string &title) :
		win(0), width(0), height(), lines() {
	lines.push_back(new Line("", title));
	lines.push_back(new Line("", ""));
}

// * DESTRUCTORS ************************************************************ //

AModule::~AModule() {
	Line * line;
	Line::iterator end = lines.end();

	for (Line::iterator it = lines.begin(); it != end; ++it) {
		line = *it;
		delete(line);
	}
	lines.clear();
//	delwin(win);
}

// * OPERATORS ************************************************************** //

AModule &AModule::operator=(AModule const &assign) {
	if (this != &assign) {
	}
	return (*this);
}

// * GETTERS **************************************************************** //

int AModule::getWidth() const {
	return width;
}

int AModule::getHeight() const {
	return height;
}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void AModule::draw(IMonitorDisplay *display) {
	display->drawBorder(win);
	display->drawTitle(win, 0, lines[0]);
	for (unsigned i = 1; i < lines.size(); i++) {
		display->drawLine(win, i, 0, lines[i]);
	}
}

// * NESTED_CLASSES ********************************************************* //
