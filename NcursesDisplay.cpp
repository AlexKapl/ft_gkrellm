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

NcursesDisplay::NcursesDisplay() :
		windowCount(0), windows(), panels(), changes() {
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
	init_pair(HIGHLIGHT, COLOR_WHITE, COLOR_GREEN);
	refresh();
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &) {}

// * DESTRUCTORS ************************************************************ //

NcursesDisplay::~NcursesDisplay() {
	endwin();
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
	WINDOW *win = newwin(h, w, y, x);
	PANEL *panel = new_panel(win);

	drawBorder(win);
	windows.push_back(win);
	panels.push_back(new Panel(panel, h, y));
	set_panel_userptr(panel, win);
	return (windowCount++);
}

void NcursesDisplay::getMaxYX(int &h, int &w) {
	getmaxyx(stdscr, h, w);
}

void NcursesDisplay::drawBorder(WINDOW *win) {
	int color =
			(win != changes.win ? COLOR_PAIR(BORDER) : COLOR_PAIR(HIGHLIGHT));
	// check for highlighting window for change

	wattron(win, color);
	wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(win, color);
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

	drawBorder(win);
	wattron(win, COLOR_PAIR(TITLE));
//	this->cleanLine(win, 0);
	x = ((getmaxx(win) / 2) - line->getSize() / 2);
	mvwprintw(win, 0, x, "%s", line->getValue().c_str());
	wattroff(win, COLOR_PAIR(TITLE));

}

void NcursesDisplay::cleanLine(WINDOW *win, int y) {
	mvwhline(win, y, 1, ' ', getmaxx(win) - 2);
}

void NcursesDisplay::process_input() {
	int g = getch();

	switch (g) {
		case ENTER:
			changes.highlight(this);
			break;
		case BACKSPACE:
			changes.normal();
			break;
		case KEY_UP:
			changes.up(this);
			break;
		case KEY_DOWN:
			changes.down(this);
			break;
		default:
			break;
	}
}

void NcursesDisplay::swapWindows(int lhs, int rhs) {

	panels[rhs]->y = panels[lhs]->y;
	panels[lhs]->y = panels[lhs]->y + panels[rhs]->h;
	move_panel(panels[rhs]->panel, panels[rhs]->y, 0);
	move_panel(panels[lhs]->panel, panels[lhs]->y, 0);

	Panel * swap = panels[lhs];
	panels[lhs] = panels[rhs];
	panels[rhs] = swap;
}

// * NESTED_CLASSES ********************************************************* //

NcursesDisplay::change::change() :
		chooseMode(false), changeMode(false), panel(0), win() {}

void NcursesDisplay::change::highlight(NcursesDisplay *display) {
	if (!chooseMode) {
		chooseMode = true;
		win = display->windows[panel];
	}
	else changeMode = !changeMode;
}

void NcursesDisplay::change::up(NcursesDisplay *display) {
	if (chooseMode) {
		if (changeMode) {
			if (panel) {
				display->swapWindows(panel - 1, panel);
				--panel;
			}
		}
		else if (panel) {
			win = static_cast<WINDOW *>(panel_userptr(
					display->panels[--panel]->panel));
		}
	}
}

void NcursesDisplay::change::down(NcursesDisplay *display) {
	if (chooseMode) {
		if (changeMode) {
			if (panel + 1 < display->windowCount) {
				display->swapWindows(panel, panel + 1);
				++panel;
			}
		}
		else if (panel + 1 < display->windowCount) {
			win = static_cast<WINDOW *>(panel_userptr(
					display->panels[++panel]->panel));
		}
	}
}

void NcursesDisplay::change::normal() {
	chooseMode = false;
	changeMode = false;
	win = NULL;
}

NcursesDisplay::Panel::Panel(PANEL *panel, int h, int y) :
		panel(panel), h(h), y(y) {}
