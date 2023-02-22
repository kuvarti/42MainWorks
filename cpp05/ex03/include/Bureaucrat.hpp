/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 06:02:39 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 20:58:41 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

struct toohigh : public std::exception
{
	const char * what() const throw () { return "Grade too high";};
};

struct toolow : public std::exception
{
	const char * what() const throw () { return "Grade too low";};
};

class AForm;

class Bureaucrat{
public:
	Bureaucrat(std::string _name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &);
	Bureaucrat &operator=(Bureaucrat const &);

	void	incrementGrade(int);
	void	decrementGrade(int);

	toohigh	GradeTooHighException;
	toolow	GradeTooLowException;

	void	signForm(AForm &);
	void	executeForm(AForm const &);

	std::string	getName() const;
	int	getGrade() const;
	void	setGrade(int);
private:
	void		throwcontrol();
	std::string	_name;
	int			grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat &b);
