/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm{
public:
	AForm(std::string name, int grade_toSign, int grade_toExecute);
	AForm(AForm const &);
	AForm &operator=(AForm const &);

	virtual ~AForm();
	toohigh	GradeTooHighException;
	toolow	GradeTooLowException;

	std::string	getname() const				{ return _name; };
	bool		getsign() const				{ return _signed; };
	int			getgrade() const		{ return _gradeToSign; };
	int			getExecute() const	{ return _gradeToExecute; };

	void		setName(std::string const x) { _name = x; };
	void		setSign(bool const x) { _signed = x; };
	void		setGrade(int const x) { _gradeToSign = x; };
	void		setExecute(int const x) { _gradeToExecute = x; };

	int	beSigned(Bureaucrat &);
	int	execute(Bureaucrat const & executor) const;

protected:
	virtual void	action() const = 0;
	std::string	_target;
private:
	std::string	_name;
	bool		_signed;
	int			_gradeToSign;
	int			_gradeToExecute;
};
