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

#include "Monitor.hpp"
#include "UserModule.hpp"
#include "NcursesDisplay.hpp"
#include "OsModule.hpp"
#include "DateModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"

int main() {
	Monitor monitor;

	monitor.setDisplay(new NcursesDisplay());
	monitor.addModule(new UserModule(monitor.getHeight(), monitor));
	monitor.addModule(new OsModule(monitor.getHeight(), monitor));
	monitor.addModule(new DateModule(monitor.getHeight(), monitor));
	monitor.addModule(new CpuModule(monitor.getHeight(), monitor));
	monitor.addModule(new RamModule(monitor.getHeight(), monitor));
	monitor.loop();
	return (0);
}
