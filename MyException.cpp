/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:56:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 19:56:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyException.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

MyException::MyException() : msg(), type() {}

MyException::MyException(const std::string &msg) :  msg(msg), type() {}

MyException::MyException(const char *msg) : msg(msg), type() {}

MyException::MyException(MyException::type_e type) throw() : msg(), type(type) {
	switch (this->type) {
		case Width:
			msg = "Can't fit data in window. Please increase width";
			break;
		case Height:
			msg = "Can't fit data in window. Please increase height";
			break;
	}
}

MyException::MyException(MyException const &copy) : std::exception(copy) {}

// * DESTRUCTORS ************************************************************ //

MyException::~MyException() throw() {}

// * OPERATORS ************************************************************** //

MyException &MyException::operator=(MyException const &assign) {
	if (this != &assign) {

	}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

const std::string &MyException::getMsg() throw() {
	return msg;
}

// * NESTED_CLASSES ********************************************************* //
