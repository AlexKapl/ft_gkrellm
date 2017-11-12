/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:19:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 15:12:02 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

# include "IMonitorDisplay.hpp"


class NcursesDisplay : public IMonitorDisplay {

private:

	struct Panel {
		PANEL * panel;
		int		h;
		int		y;

		Panel(PANEL *panel, int h, int y);
	};

public:
	typedef std::vector<WINDOW *> Windows;
	typedef std::vector<Panel *> Panels;
	typedef Windows::iterator iterator;

	NcursesDisplay();

	~NcursesDisplay();

	void process_input();

	void draw();

	void drawTitle(int num, int x, Line *line);

	void drawLine(int num, int y, int x, Line *line);

	void getMaxYX(int &h, int &w);

	int getWindowNum(int h, int w, int y, int x);

private:

	struct change {
		bool chooseMode;
		bool changeMode;
		int panel;
		WINDOW *win;

		change();

		void highlight(NcursesDisplay * display);

		void normal();

		void up(NcursesDisplay * display);

		void down(NcursesDisplay * display);
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

	int windowCount;

	Windows windows;

	Panels panels;

	change changes;

	static void colorTheme();

	void swapWindows(int lhs, int rhs);

	void drawBorder(WINDOW *win);

	void cleanLine(WINDOW *win, int y);

	NcursesDisplay(NcursesDisplay const &copy);

	NcursesDisplay &operator=(NcursesDisplay const &assign);

};


#endif
