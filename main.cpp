/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:35:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 16:35:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_gkrellm.h"
# include "Monitor.hpp"
# include "UserModule.hpp"
# include "NcursesDisplay.hpp"
# include "OsModule.hpp"

int main() {
	int	g;
	Monitor monitor;

	monitor.setDisplay(new NcursesDisplay());
	monitor.addModule(new UserModule(monitor.getHeight(), monitor));
	monitor.addModule(new OsModule(monitor.getHeight(), monitor));
	monitor.draw();
	do {
		g = getch();
	}
	while (g != 27);
	endwin();
	return (0);
}
