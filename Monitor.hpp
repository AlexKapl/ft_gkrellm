/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:53:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 18:53:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MONITOR_HPP
# define MONITOR_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"


class Monitor {

public:

	Monitor();

	Monitor(Monitor const &copy);

	~Monitor();

	Monitor &operator=(Monitor const &assign);

	void	refresh();

	void	addModule(IMonitorModule * module);

	void	deleteModule(IMonitorModule * module);

private:

	int width;
	int height;
	std::vector<IMonitorModule *> modules;

};


#endif
