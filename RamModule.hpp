/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:29:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/12 19:29:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include "AModule.hpp"

class RamModule : public AModule {

public:

	RamModule(int height, Monitor & monitor);

	~RamModule();

	void refresh();

private:

	enum info {Total = 2, Used, Wired, Free};

	RamModule();

	RamModule(RamModule const &copy);

	RamModule &operator=(RamModule const &assign);

};

#endif
