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

	int windowCount;

	Windows windows;

	Panels panels;

	change changes;

	void swapWindows(int lhs, int rhs);

	void drawBorder(WINDOW *win);

	void cleanLine(WINDOW *win, int y);

	NcursesDisplay(NcursesDisplay const &copy);

	NcursesDisplay &operator=(NcursesDisplay const &assign);

};


#endif
