/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:05:26 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 16:44:32 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form{
public:
	Form(std::string name, int grade_toSign, int grade_toExecute);
	~Form();
	Form(Form const &);
	Form &operator=(Form const &);

	toohigh	GradeTooHighException;
	toolow	GradeTooLowException;

	std::string	getname() const				{ return _name; };
	bool		getsign() const				{ return _signed; };
	int			getgradetoSign() const		{ return _gradeToSign; };
	int			getgradetoExecute() const	{ return _gradeToExecute; };

	int	beSigned(Bureaucrat &);
private:
	std::string	_name;
	bool		_signed;
	int			_gradeToSign;
	int			_gradeToExecute;
};
