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

std::string	Kernel::getCoreInfo(int core) {
	std::stringstream ss;
	unsigned int core_count;
	unsigned long long used, total;
	processor_cpu_load_info_t cpuInfo;
	mach_msg_type_number_t cpu_msg_count;

	int rc =  host_processor_info(
			mach_host_self(),
			PROCESSOR_CPU_LOAD_INFO,
			&core_count,
			reinterpret_cast<processor_info_array_t *>(&cpuInfo),
			&cpu_msg_count
	);
	if (rc != 0)
		throw std::runtime_error("Error: failed to scan processor info");

	if (core < 0 || static_cast<int>(core_count) <= core)
		throw std::runtime_error("Error: invalid core number");
	used =  cpuInfo[core].cpu_ticks[CPU_STATE_USER];
	used += cpuInfo[core].cpu_ticks[CPU_STATE_NICE];
	used += cpuInfo[core].cpu_ticks[CPU_STATE_SYSTEM];
	total = used + cpuInfo[core].cpu_ticks[CPU_STATE_IDLE];
//	ss << std::setprecision(2) << std::setiosflags(std::ios_base::fixed);
	ss << (static_cast<double>(used) / static_cast<double >(total) * 100.0);
	return (ss.str());
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
