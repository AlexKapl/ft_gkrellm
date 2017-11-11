/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:05:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 19:05:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef USERMODULE_HPP
# define USERMODULE_HPP

#include "AModule.hpp"

class UserModule : public AModule {

public:

	UserModule(int height, Monitor & monitor);

	~UserModule();

	void refresh();

private:

	enum info {Title, Empty, Host, User};

	UserModule();

	UserModule(UserModule const &copy);

	UserModule &operator=(UserModule const &assign);

};


#endif
