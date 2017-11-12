/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:53:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 17:17:00 by hshakula         ###   ########.fr       */
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

	void refreshAll();

	void addModule(IMonitorModule *module);

	void hideModule(IMonitorModule *module);

	int getWidth() const;

	int getHeight() const;

	void setDisplay(IMonitorDisplay *display);

	bool isOpen();

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
