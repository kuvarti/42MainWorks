/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialForm.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:49:06 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 22:57:19 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialForm.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{ }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &S) : AForm(S)
{
	this->_target = S._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &S)
{
	this->setName(S.getname());
	this->setSign(S.getsign());
	this->setGrade(S.getgrade());
	this->setExecute(S.getExecute());
	this->_target = S._target;
	return *this;
}

void	PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
