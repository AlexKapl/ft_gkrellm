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

MyException::MyException(const std::string &msg) : msg(msg), type() {}

MyException::MyException(MyException::type_e type) : msg(), type(type) {
	switch (type) {
		case Width:
			msg = "Can't fit data in window. Please increase width";
			break;
		case Height:
			msg = "Can't fit data in window. Please increase height";
			break;
	}
}

MyException::MyException(MyException const &copy) {}

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

const std::string &MyException::getMsg() {
	if (msg.empty()) {
		return "Something goes wrong";
	}
	else {
		return msg;
	}
}

// * NESTED_CLASSES ********************************************************* //
