/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:36:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 22:05:06 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include "ft_gkrellm.h"

class IMonitorDisplay;

class IMonitorModule {

public:

	IMonitorModule() {}

	virtual ~IMonitorModule() {}

	virtual void refresh() = 0;

	virtual void draw(IMonitorDisplay * display) = 0;

	virtual int getHeight() const = 0;

private:

	IMonitorModule(const IMonitorModule &) {};

	IMonitorModule &operator=(const IMonitorModule &rhs);

};


#endif
