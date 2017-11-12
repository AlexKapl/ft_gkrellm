/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:19:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 22:12:24 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesDisplay.hpp"
#include "Monitor.hpp"

// * STATICS **************************************************************** //

void NcursesDisplay::colorTheme() {
	static int i = 0;
	static themes theme[] = {
			{{441, 453, 455}, {291, 293, 295}, {188, 194, 200}},
			{{99,  92,  60},  {230, 223, 165}, {226, 143, 179}},
			{{36,  36,  36},  {220, 64,  53},  {78,  78,  82}}
	};
	init_color(COLOR_BORDER,
			   theme[i].border.r, theme[i].border.g, theme[i].border.b);
	init_color(COLOR_TITLE,
			   theme[i].title.r, theme[i].title.g, theme[i].title.b);
	init_color(COLOR_BACK, theme[i].back.r, theme[i].back.g, theme[i].back.b);
	if (++i > THEMES_NUM - 1)
		i = 0;
}

// * CONSTRUCTORS *********************************************************** //

NcursesDisplay::NcursesDisplay(int) : 
		open(true), windowCount(0), windows(), panels(), views(), changes(){}

NcursesDisplay::NcursesDisplay() :
		open(true), windowCount(0), windows(), panels(), views(), changes() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	start_color();
	NcursesDisplay::colorTheme();
	init_color(COLOR_GREEN, 0, 250, 0);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(BACK, COLOR_WHITE, COLOR_BACK);
	init_pair(BORDER, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(TITLE, COLOR_WHITE, COLOR_TITLE);
	init_pair(HIGHLIGHT, COLOR_WHITE, COLOR_GREEN);
	refresh();
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &) {}

// * DESTRUCTORS ************************************************************ //

NcursesDisplay::~NcursesDisplay() {
	clear();
	endwin();
}

// * OPERATORS ************************************************************** //

NcursesDisplay &NcursesDisplay::operator=(NcursesDisplay const &assign) {
	if (this != &assign) {

	}
	return (*this);
}

// * GETTERS **************************************************************** //

bool NcursesDisplay::isOpen() {
	return open;
}

void NcursesDisplay::getMaxYX(int &h, int &w) {
	getmaxyx(stdscr, h, w);
}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void NcursesDisplay::draw() {
	for (int i = 0; i < windowCount; i++) {
		if (views[i])
			wrefresh(windows[i]);
	}
}

int NcursesDisplay::getWindowNum(int h, int w, int y, int x) {
	WINDOW *win = newwin(h, w, y, x);
	PANEL *panel = new_panel(win);

	views.push_back(true);
	windows.push_back(win);
	panels.push_back(new Panel(panel, h, y));
	set_panel_userptr(panel, win);
	drawBorder(windowCount);
	return (windowCount++);
}

WINDOW *NcursesDisplay::getWinByPanelId(int id) {
	return (static_cast<WINDOW *>(panel_userptr(panels[id]->panel)));
}

int NcursesDisplay::getWinIdByPanelId(int id) {
	WINDOW *win = getWinByPanelId(id);

	for (int i = 0; i < windowCount; i++) {
		if (win == windows[i])
			return (i);
	}
	return 0;
}

int NcursesDisplay::getPanelIdByWin(WINDOW *win) {
	WINDOW *find;

	for (int i = 0; i < windowCount; i++) {
		find = getWinByPanelId(i);
		if (find == win)
			return (i);
	}
	return 0;
}

void NcursesDisplay::hidePanel(int num) {
	int i = getPanelIdByWin(windows[num]);

	changes.normal();
	changes.panel = 0;
	views[num] = !views[num];
	if (!views[num]) {
		hide_panel(panels[i]->panel);
		for (; i + 1 < windowCount; i++) {
			swapWindows(i, i + 1);
		}
	}
	else {
		show_panel(panels[i]->panel);
		for (; i; i--) {
			swapWindows(i - 1, i);
		}
	}
	update_panels();
	doupdate();
}


void NcursesDisplay::drawBorder(int num) {
	if (views[num]) {
		WINDOW *win = windows[num];
		int color =
				(win != changes.win ? COLOR_PAIR(BORDER) : COLOR_PAIR(
						HIGHLIGHT));
		// check for highlighting window for change

		wattron(win, color);
		wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
		wattroff(win, color);
	}
}

void NcursesDisplay::drawLine(int num, int y, int x, Line *line) {
	if (views[num]) {
		WINDOW *win = windows[num];

		wattron(win, COLOR_PAIR(BACK));
		this->cleanLine(win, y);
		mvwprintw(win, y, 1, "%s", line->getName().c_str());
		x = ((getmaxx(win) / 2) - line->getSize() / 2);
		mvwprintw(win, y, x, "%s", line->getValue().c_str());
		wattroff(win, COLOR_PAIR(BACK));
	}
}

void NcursesDisplay::drawTitle(int num, int x, Line *line) {
	if (views[num]) {
		WINDOW *win = windows[num];

		wattron(win, COLOR_PAIR(TITLE));
		this->cleanLine(win, 0);
		x = ((getmaxx(win) / 2) - line->getSize() / 2);
		mvwprintw(win, 0, x, "%s", line->getValue().c_str());
		wattroff(win, COLOR_PAIR(TITLE));
	}
}

void NcursesDisplay::cleanLine(WINDOW *win, int y) {
	mvwhline(win, y, 1, ' ', getmaxx(win) - 2);
}

void NcursesDisplay::processInput() {
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
		case TAB:
			NcursesDisplay::colorTheme();
			break;
		case 'u':
			hidePanel(User);
			break;
		case 'o':
			hidePanel(Os);
			break;
		case 'd':
			hidePanel(Date);
			break;
		case 'c':
			hidePanel(Cpu);
			break;
		case 'r':
			hidePanel(Ram);
			break;
		case 'n':
			hidePanel(Net);
			break;
		case 'q':
			open = false;
			break;
		case 'p':
			Monitor::swap = 1;
			open = false;
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

	Panel *swap = panels[lhs];
	panels[lhs] = panels[rhs];
	panels[rhs] = swap;
}

void NcursesDisplay::clean() {

}

// * NESTED_CLASSES ********************************************************* //

NcursesDisplay::change::change() :
		chooseMode(false), changeMode(false), panel(0), win() {}

void NcursesDisplay::change::highlight(NcursesDisplay *display) {
	if (!chooseMode) {
		chooseMode = true;
		if (display->views[panel]) {
			win = display->getWinByPanelId(panel);
		}
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
			win = display->getWinByPanelId(--panel);
		}
	}
}

void NcursesDisplay::change::down(NcursesDisplay *display) {
	if (chooseMode && panel + 1 < display->windowCount) {
		if (display->views[display->getWinIdByPanelId(panel + 1)]) {
			if (changeMode) {
				display->swapWindows(panel, panel + 1);
				++panel;
			}
			else {
				win = display->getWinByPanelId(++panel);
			}
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
