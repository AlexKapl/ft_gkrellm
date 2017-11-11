/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:25:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 16:25:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMODULE_HPP
# define AMODULE_HPP

# include "IMonitorModule.hpp"
# include "Monitor.hpp"
# include "Kernel.hpp"
# include "Line.hpp"

class AModule : public IMonitorModule{

public:

	AModule(const std::string & title);

	virtual ~AModule();

	void draw(IMonitorDisplay * display);

	int getWidth() const;

	int getHeight() const;

protected:

	int win;
	int width;
	int height;
	Line::Lines lines;

private:

	AModule();

	AModule(AModule const &copy);

	AModule &operator=(AModule const &assign);

};


#endif
