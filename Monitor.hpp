/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:53:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 21:59:18 by hshakula         ###   ########.fr       */
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

	void loop();

	bool isOpen();

	void refreshAll();

	void addModule(IMonitorModule *module);

	int getWidth() const;

	int getHeight() const;

	void setDisplay(IMonitorDisplay *display);

	IMonitorDisplay *getDisplay() const;

	static int swap;

private:
	int width;
	int height;
	Modules modules;
	IMonitorDisplay *display;

	Monitor(Monitor const &copy);

	Monitor &operator=(Monitor const &assign);

};


#endif
