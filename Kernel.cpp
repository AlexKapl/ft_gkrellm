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

std::string Kernel::getKernelInfoByName(const std::string &name) {
	char info[1024];
	size_t size = sizeof(info);
//	char *str = new char[name.size() + 1];

//	std::strcpy(str, name.c_str());
	sysctlbyname(name.c_str(), &info, &size, NULL, 1024);
	std::string ret = info;

	return (ret);
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
