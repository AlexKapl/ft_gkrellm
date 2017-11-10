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

# include "IMonitorModule.hpp"
# include "Kernel.hpp"
# include "Line.hpp"


class UserModule : public IMonitorModule {

public:

	UserModule(int height);

	~UserModule();

	void	refresh();

private:

	enum info {Host, User};

	int width;
	int height;
	const std::string title;
	WINDOW *win;
	Line::Lines lines;

	UserModule();

	UserModule(UserModule const &copy);

	UserModule &operator=(UserModule const &assign);

};


#endif
