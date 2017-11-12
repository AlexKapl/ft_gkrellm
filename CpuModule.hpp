/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:02:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 19:02:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP


#include "AModule.hpp"

class CpuModule : public AModule {

public:

	CpuModule(int height, Monitor & monitor);

	~CpuModule();

	void refresh();

private:

	enum info {Brand = 2, Info, User, System};

	CpuModule();

	CpuModule(CpuModule const &copy);

	CpuModule &operator=(CpuModule const &assign);

};


#endif
