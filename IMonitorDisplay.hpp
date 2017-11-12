/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:37:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 16:37:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include "ft_gkrellm.h"
# include "Line.hpp"
# include "AnimatedSprite.hpp"

class IMonitorDisplay {

public:

	IMonitorDisplay() {}

	virtual ~IMonitorDisplay() {}

	virtual void draw() = 0;

	virtual void drawBorder(int num) = 0;

	virtual void drawTitle(int num, int x, Line * line) = 0;

	virtual void drawLine(int num, int y, int x, Line * line) = 0;

	virtual void getMaxYX(int &h, int &w) = 0;

	virtual int getWindowNum(int h, int w, int y, int x) = 0;

	virtual void clear() = 0;

	virtual bool isOpen() = 0;

	virtual void processInput() = 0;

	virtual void drawPony(int, AnimatedSprite &) = 0;

private:

	IMonitorDisplay(const IMonitorDisplay &) {};

	IMonitorDisplay &operator=(const IMonitorDisplay &rhs);
};

#endif
