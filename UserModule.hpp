/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:05:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 22:03:16 by hshakula         ###   ########.fr       */
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

	enum info {Host = 2, User};

	UserModule();

	UserModule(UserModule const &copy);

	UserModule &operator=(UserModule const &assign);

};


#endif
