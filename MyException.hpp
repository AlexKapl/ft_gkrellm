/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:56:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 19:56:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

# include <iostream>


class MyException : public std::exception {

public:

	enum type_e {Width = 1, Height};

	MyException();

	MyException(const std::string &msg);

	MyException(type_e type);

	virtual ~MyException() throw();

	const std::string & getMsg() throw();

private:

	std::string	msg;
	type_e	type;

	MyException(MyException const &copy);

	MyException &operator=(MyException const &assign);

};


#endif
