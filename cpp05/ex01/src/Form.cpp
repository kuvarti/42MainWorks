/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:41:10 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 16:44:58 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int grade_toSign, int grade_toExecute)
{
	_name = name;
	_signed = 0;
	_gradeToSign = grade_toSign;
	_gradeToExecute = grade_toExecute;
}

Form::~Form() { }

Form::Form(Form const &f)
{
	_name = f._name;
	_signed = f._signed;
	_gradeToSign = f._gradeToSign;
	_gradeToExecute = f._gradeToExecute;
}

Form &Form::operator=(Form const &f)
{
	this->_name = f._name;
	this->_gradeToSign = f._gradeToSign;
	this->_gradeToExecute = f._gradeToExecute;
	return *this;
}

int	Form::beSigned(Bureaucrat &b)
{
	if (_signed == 1)
	{
		std::cout << _name << " is already signed." << std::endl;
		return 0;
	}
	else if(b.getGrade() > _gradeToSign)
	{
		std::cout << b.getName() << " couldn’t sign " << _name << "because grade isnt enough." << std::endl;
		throw(Form::GradeTooLowException);
	}
	else
	{
		_signed = 1;
		return 1;
	}
}
