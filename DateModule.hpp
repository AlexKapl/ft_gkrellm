/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:37:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 17:37:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATEMODULE_HPP
# define DATEMODULE_HPP

#include "AModule.hpp"

class DateModule : public AModule {

public:

	DateModule(int height, Monitor & monitor);

	~DateModule();

	void refresh();

private:

	DateModule();

	DateModule(DateModule const &copy);

	DateModule &operator=(DateModule const &assign);

};


#endif
