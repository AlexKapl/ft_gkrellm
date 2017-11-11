/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 17:01:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OSMODULE_HPP
# define OSMODULE_HPP

#include "AModule.hpp"

class OsModule : public AModule {

public:

	OsModule(int height, Monitor & monitor);

	~OsModule();

	void refresh();

private:

	enum info {Type = 2, Release};

	OsModule();

	OsModule(OsModule const &copy);

	OsModule &operator=(OsModule const &assign);

};


#endif
