/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kernel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:31:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 20:31:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kernel.hpp"

// * STATICS **************************************************************** //

std::string Kernel::getKernelInfo(const std::string &name) {
	char info[1024];
	size_t size = sizeof(info);

	sysctlbyname(name.c_str(), &info, &size, NULL, 1024);
	std::string ret = info;
	return (ret);
}

std::string Kernel::getKernelInfoInt(const std::string &name) {
	std::stringstream ss;
	unsigned int ret;
	size_t size = sizeof(ret);

	sysctlbyname(name.c_str(), &ret, &size, NULL, 1024);
	ss << ret;
	return (ss.str());
}

std::string Kernel::getUserName() {
	struct passwd *pwuid;
	std::string name;

	pwuid = getpwuid(getuid());
	if (pwuid) {
		name = pwuid->pw_name;
	}
	return (name);
}

std::string Kernel::getTopInfo(const std::string &name) {
	char buffer[256];
	std::string cmd = "top -l 1 -n 0 | grep " + name , result;
	FILE *pipe = popen(cmd.c_str(), "r");

	if (pipe) {
		while (!feof(pipe)) {
			if (fgets(buffer, 256, pipe) != NULL)
				result += buffer;
		}
		pclose(pipe);
	}
	return result;
}

// * CONSTRUCTORS *********************************************************** //

Kernel::Kernel() {}

Kernel::Kernel(Kernel const &) {}

// * DESTRUCTORS ************************************************************ //

Kernel::~Kernel() {}

// * OPERATORS ************************************************************** //

Kernel &Kernel::operator=(Kernel const &assign) {
	if (this != &assign) {

	}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
// * NESTED_CLASSES ********************************************************* //
