/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:59:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 21:59:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP


#include "AModule.hpp"

class NetworkModule : public AModule {

public:

	NetworkModule(int height, Monitor & monitor);

	~NetworkModule();

	void refresh();

private:

	enum info {In = 2, Out};

	NetworkModule();

	NetworkModule(NetworkModule const &copy);

	NetworkModule &operator=(NetworkModule const &assign);

};

#endif
