/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:19:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 16:37:42 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

# include "IMonitorDisplay.hpp"


class NcursesDisplay  : public IMonitorDisplay{

public:
	typedef std::vector<WINDOW *> Windows;
	typedef Windows::iterator iterator;

	NcursesDisplay();

	~NcursesDisplay();

	void draw();

	void drawBorder(int num);

	void drawTitle(int num, int x, Line * line);

	void drawLine(int num, int y, int x, Line * line);

	void getMaxYX(int &h, int &w);

	int getWindowNum(int h, int w, int y, int x);

private:

	int		windowCount;

	Windows windows;

	NcursesDisplay(NcursesDisplay const &copy);

	NcursesDisplay &operator=(NcursesDisplay const &assign);

};


#endif
