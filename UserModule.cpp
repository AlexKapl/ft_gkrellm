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

UserModule::UserModule(int height) :
		width(0), height(WIN_H(2)), title("User"), win(), lines() {
	int		w, h;

	lines.push_back(new Line("Host:", ""));
	lines.push_back(new Line("User:", ""));
	this->refresh();
	getmaxyx(stdscr, h, w);
	if ((h - height) < this->height) {
		throw MyException(MyException::Height);
	}
	else if (w < width) {
		throw MyException(MyException::Width);
	}
	win = newwin(this->height, width, height, 0);
	wattron(win, COLOR_PAIR(BORDER));
	wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(win, COLOR_PAIR(BORDER));
}


// * DESTRUCTORS ************************************************************ //

UserModule::~UserModule() {
	Line * line;
	Line::iterator end = lines.end();

	for (Line::iterator it = lines.begin(); it != end; ++it) {
		line = *it;
		delete(line);
	}
	lines.clear();
	delwin(win);
}

// * OPERATORS ************************************************************** //

UserModule &UserModule::operator=(UserModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void UserModule::refresh() {
	unsigned long	s1, s2;

	lines[Host]->setValue(Kernel::getKernelInfoByName("kern.hostname"));
	s1 = lines[Host]->getValue().size();
	lines[User]->setValue(Kernel::getUserName());
	s2 = lines[User]->getValue().size();
	width = static_cast<int>(s1 > s2 ? s1 : s2);
}

// * NESTED_CLASSES ********************************************************* //
