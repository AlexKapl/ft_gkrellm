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
# include "Monitor.hpp"
# include "Kernel.hpp"
# include "Line.hpp"


class UserModule : public IMonitorModule {

public:

	UserModule(int height, Monitor & monitor);

	~UserModule();

	void refresh();

	void draw(IMonitorDisplay * display);

	int getWidth() const;

	int getHeight() const;

private:

	enum info {Title, Empty, Host, User};

	int win;
	int width;
	int height;
	Line::Lines lines;

	UserModule();

	UserModule(UserModule const &copy);

	UserModule &operator=(UserModule const &assign);


};


#endif
