/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:37:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 16:37:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include "ft_gkrellm.h"

class IMonitorDisplay {

public:

	IMonitorDisplay() {}

	virtual ~IMonitorDisplay() {}

private:

	IMonitorDisplay(const IMonitorDisplay &) {};

	IMonitorDisplay &operator=(const IMonitorDisplay &rhs);
};


#endif
