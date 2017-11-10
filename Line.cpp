/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:13:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 19:13:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Line.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

Line::Line() : name(), value() {}

Line::Line(const std::string &name, const std::string &value) :
		name(name), value(value) {}

Line::Line(Line const &copy) : name(copy.name), value(copy.value) {}

// * DESTRUCTORS ************************************************************ //

Line::~Line() {}

// * OPERATORS ************************************************************** //

Line &Line::operator=(Line const &assign) {
	if (this != &assign) {
		name = assign.name;
		value = assign.value;
	}
	return (*this);
}

// * GETTERS **************************************************************** //

const std::string &Line::getName() const {
	return name;
}

const std::string &Line::getValue() const {
	return value;
}

// * SETTERS **************************************************************** //

void Line::setName(const std::string &name) {
	this->name = name;
}

void Line::setValue(const std::string &value) {
	this->value = value;
}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
// * NESTED_CLASSES ********************************************************* //
