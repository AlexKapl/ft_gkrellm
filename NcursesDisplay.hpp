/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:19:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 12:19:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

# include "IMonitorDisplay.hpp"


class NcursesDisplay : public IMonitorDisplay {

private:

	struct Panel {
		PANEL *panel;
		int h;
		int y;

		Panel(PANEL *panel, int h, int y);
	};

public:
	typedef std::vector<WINDOW *> Windows;
	typedef std::vector<Panel *> Panels;
	typedef Windows::iterator iterator;

	NcursesDisplay();

	~NcursesDisplay();

	void process_input();

	bool isOpen();

	void hidePanel(int num);

	void draw();

	void drawTitle(int num, int x, Line *line);

	void drawBorder(int num);

	void drawLine(int num, int y, int x, Line *line);

	void getMaxYX(int &h, int &w);

	int getWindowNum(int h, int w, int y, int x);

private:

	enum modules {User, Os, Date, Cpu};

	struct change {
		bool chooseMode;
		bool changeMode;
		int panel;
		WINDOW *win;

		change();

		void highlight(NcursesDisplay *display);

		void normal();

		void up(NcursesDisplay *display);

		void down(NcursesDisplay *display);
	};

	struct colors {
		short r;
		short g;
		short b;
	};

	struct themes {
		colors title;
		colors borfer;
		colors back;
	};

	bool open;

	int windowCount;

	Windows windows;

	Panels panels;

	std::vector<bool> views;

	change changes;

	static void colorTheme();

	int getPanelIdByWin(WINDOW *win);

	int getWinIdByPanelId(int id);

	WINDOW * getWinByPanelId(int id);

	void swapWindows(int lhs, int rhs);

	void cleanLine(WINDOW *win, int y);

	NcursesDisplay(NcursesDisplay const &copy);

	NcursesDisplay &operator=(NcursesDisplay const &assign);

};


#endif
