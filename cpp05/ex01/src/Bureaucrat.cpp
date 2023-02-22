/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 06:12:53 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 16:45:56 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

Bureaucrat::Bureaucrat(std::string name, int n) : _name(name){
	grade = n;
	throwcontrol();
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat::Bureaucrat(Bureaucrat const &b) : _name(b._name){
	grade = b.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b){
	grade = b.grade;
	return *this;
}

void	Bureaucrat::incrementGrade(int n){
	grade += n;
	throwcontrol();
}

void	Bureaucrat::decrementGrade(int n){
	grade -= n;
	throwcontrol();
}

std::string	Bureaucrat::getName() const{
	return _name;
}

int	Bureaucrat::getGrade() const{
	return grade;
}

void	Bureaucrat::setGrade(int n){
	grade = n;
	throwcontrol();
}

void	Bureaucrat::throwcontrol(){
	if (this->grade > 150)
		throw Bureaucrat::GradeTooHighException;
	else if (this->grade < 1)
		throw Bureaucrat::GradeTooLowException;
}

void	Bureaucrat::signForm(Form &a)
{
	if (a.beSigned(*this))
		std::cout << _name << " signed " << a.getname() << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &b){
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return o;
}
