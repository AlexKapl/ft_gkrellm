/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:19:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 12:19:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesDisplay.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

NcursesDisplay::NcursesDisplay() : windowCount(0), windows() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	start_color();
	init_color(COLOR_MAGENTA, 441, 453, 455);
	init_color(COLOR_BLUE, 188, 194, 200);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(TEXT, COLOR_WHITE, COLOR_BLUE);
	init_pair(BORDER, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(TITLE, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_GREEN);
	init_pair(9, COLOR_BLACK, COLOR_RED);
	init_pair(10, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
	refresh();
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &) {}

// * DESTRUCTORS ************************************************************ //

NcursesDisplay::~NcursesDisplay() {

}

// * OPERATORS ************************************************************** //

NcursesDisplay &NcursesDisplay::operator=(NcursesDisplay const &assign) {
	if (this != &assign) {

	}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void NcursesDisplay::draw() {
	WINDOW *win;
	iterator end = windows.end();

	for (iterator it = windows.begin(); it != end; ++it) {
		win = *it;
		wrefresh(win);
	}
}

int NcursesDisplay::getWindowNum(int h, int w, int y, int x) {
	windows.push_back(newwin(h, w, y, x));
	drawBorder(windowCount);
	return (windowCount++);
}

void NcursesDisplay::getMaxYX(int &h, int &w) {
	getmaxyx(stdscr, h, w);
}

void NcursesDisplay::drawBorder(int num) {
	WINDOW *win = windows[num];

	wattron(win, COLOR_PAIR(BORDER));
	wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(win, COLOR_PAIR(BORDER));
	wrefresh(win);
}

void NcursesDisplay::drawLine(int num, int y, int x, Line *line) {
	WINDOW *win = windows[num];

	wattron(win, COLOR_PAIR(TEXT));
	this->cleanLine(win, y);
	mvwprintw(win, y, 1, "%s", line->getName().c_str());
	x = ((getmaxx(win) / 2) - line->getSize() / 2);
	mvwprintw(win, y, x, "%s", line->getValue().c_str());
	wattroff(win, COLOR_PAIR(TEXT));
}

void NcursesDisplay::drawTitle(int num, int x, Line *line) {
	WINDOW *win = windows[num];

	wattron(win, COLOR_PAIR(TITLE));
	this->cleanLine(win, 0);
	x = ((getmaxx(win) / 2) - line->getSize() / 2);
	mvwprintw(win, 0, x, "%s", line->getValue().c_str());
	wattroff(win, COLOR_PAIR(TITLE));

}

void NcursesDisplay::cleanLine(WINDOW *win, int y) {
	mvwhline(win, y, 1, ' ', getmaxx(win) - 2);
}

// * NESTED_CLASSES ********************************************************* //
