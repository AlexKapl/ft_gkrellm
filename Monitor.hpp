/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:53:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 14:23:17 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MONITOR_HPP
# define MONITOR_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"


class Monitor {

public:

	typedef std::vector<IMonitorModule *> Modules;
	typedef Modules::iterator iterator;

	Monitor();

	~Monitor();

	void draw();

	bool isOpen();

	void refreshAll();

	void addModule(IMonitorModule *module);

	void deleteModule(IMonitorModule *module);

	void swapModule(int n1, int n2);

	void getMaxYX(int & h, int & w);

	int getWidth() const;

	int getHeight() const;

	void setDisplay(IMonitorDisplay *display);

	IMonitorDisplay *getDisplay() const;

private:

	int width;
	int height;
	Modules modules;
	IMonitorDisplay *display;

	Monitor(Monitor const &copy);

	Monitor &operator=(Monitor const &assign);

};


#endif
