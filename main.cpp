/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:35:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 20:10:27 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bitset>
#include "Monitor.hpp"
#include "UserModule.hpp"
// #include "NcursesDisplay.hpp"
#include "sfmlDisplay.hpp"
#include "OsModule.hpp"
#include "DateModule.hpp"
#include "CpuModule.hpp"
#include "PonyModule.hpp"

void parseFlags(Monitor &monitor, std::string flags) {

	int displayIsSet = 0;

	// if (flags.find('N') != std::string::npos) {
	// 	monitor.setDisplay(new NcursesDisplay());
	// 	displayIsSet = 1;
	// }
	if (!displayIsSet && flags.find('S') != std::string::npos) {
		monitor.setDisplay(new sfmlDisplay());
		displayIsSet = 2;
	}


	if (displayIsSet) {
		std::bitset<7> bitFlags;
		for (std::size_t i = 0; i < flags.size(); i++) {
			if (flags[i] == 'o' && bitFlags[0] == false) {
				bitFlags.set(0);
				monitor.addModule(new OsModule(monitor.getHeight(), monitor));
			}
			if (flags[i] == 'd' && bitFlags[1] == false) {
				bitFlags.set(1);
				monitor.addModule(new DateModule(monitor.getHeight(), monitor));
			}
			if (flags[i] == 'c' && bitFlags[2] == false) {
				bitFlags.set(2);
				monitor.addModule(new CpuModule(monitor.getHeight(), monitor));
			}
			if (flags[i] == 'u' && bitFlags[3] == false) {
				bitFlags.set(3);
				monitor.addModule(new UserModule(monitor.getHeight(), monitor));
			}
			// if (flags[i] == 'r' && bitFlags[4] == false) {
			// 	bitFlags.set(4);
			// 	monitor.addModule(new RamModule(monitor.getHeight(), monitor));
			// }
			// if (flags[i] == 'n' && bitFlags[5] == false) {
			// 	bitFlags.set(5);
			// 	monitor.addModule(new NetModule(monitor.getHeight(), monitor));
			// }
			if (flags[i] == 'p' && bitFlags[6] == false) {
				if (displayIsSet == 2) {
					bitFlags.set(6);
					monitor.addModule(new PonyModule(monitor.getHeight(), monitor));
				}
				else
					std::cout << "Warning: pony module available only in graphical mode" << std::endl;
			}
		}
		if (bitFlags.count() == 0) {
			std::cout << "Error: no modules" << std::endl;
			exit(-1);
		}
	}
	else {
		std::cout << "Error: missing display" << std::endl;
		exit(-2);
	}
}

void usage() {
	std::cout << "Usage: ./ft_gkrellm -[flags]" << std::endl;
	std::cout << "List of available flags: " << std::endl;
	std::cout << "N - ncurses mode" << std::endl;
	std::cout << "S - graphical mode" << std::endl;
	std::cout << "o - OS module" << std::endl;
	std::cout << "d - date module" << std::endl;
	std::cout << "u - user module" << std::endl;
	std::cout << "r - RAM module" << std::endl;
	std::cout << "n - NET module" << std::endl;
	std::cout << "p - Pony module" << std::endl;
	std::cout << "c - CPU module" << std::endl;
}

int main(int ac, char **av) {
	if (ac == 1) {
		usage();
	}
	else {
		std::string flags = "";
		for (int i = 1; i < ac; i++) {
			flags += std::string(av[i]);
		}
		Monitor monitor;
		parseFlags(monitor, flags);
		monitor.loop();
	}
	return (0);
}
