/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:35:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 21:49:49 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_gkrellm.h"
# include "Monitor.hpp"
# include "UserModule.hpp"
# include "OsModule.hpp"
# include "NcursesDisplay.hpp"
# include "sfmlDisplay.hpp"

int main() {
	Monitor monitor;

	monitor.setDisplay(new sfmlDisplay());
	monitor.addModule(new UserModule(monitor.getHeight(), monitor));
	monitor.addModule(new OsModule(monitor.getHeight(), monitor));

	while (monitor.isOpen())
	{
		monitor.draw();
	}
	
	return (0);
}
