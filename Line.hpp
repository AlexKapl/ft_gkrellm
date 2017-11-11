/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:13:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 20:26:55 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LINE_HPP
# define LINE_HPP

# include "ft_gkrellm.h"


class Line {

public:
	typedef	std::vector<Line *>	Lines;
	typedef	Lines::iterator		iterator;

	Line();

	Line(const std::string &name, const std::string &value);

	Line(Line const &copy);

	~Line();

	Line &operator=(Line const &assign);

	const std::string &getName() const;

	const std::string &getValue() const;

	void setName(const std::string &name);

	void setValue(const std::string &value);

private:

	int	len;
	int size;
	std::string	name;
	std::string	value;
};


#endif
