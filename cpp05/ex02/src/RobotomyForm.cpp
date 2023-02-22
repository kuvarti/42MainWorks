/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyForm.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:49:06 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 22:54:02 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyForm.hpp"
#include <time.h>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
	srand(time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{ }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &S) : AForm(S)
{
	this->_target = S._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &S)
{
	this->setName(S.getname());
	this->setSign(S.getsign());
	this->setGrade(S.getgrade());
	this->setExecute(S.getExecute());
	this->_target = S._target;
	return *this;
}

void	RobotomyRequestForm::action() const
{
	std::cout << "drillling noise: vvvjjjjjuuuuuuu\ndrillling noise: çnnnçnnn" << std::endl;
	int	rnd = rand() % 100;
	if (rnd % 2 == 0)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << _target << " robotomize is failed." << std::endl;
}
