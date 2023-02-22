/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyForm.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:49:06 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 22:44:47 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyForm.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &S) : AForm(S)
{
	this->_target = S._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &S)
{
	this->setName(S.getname());
	this->setSign(S.getsign());
	this->setGrade(S.getgrade());
	this->setExecute(S.getExecute());
	this->_target = S._target;
	return *this;
}

void	gospace(std::ofstream &o, int space)
{
	while (space-- > 0)
		o << " ";
	o << ">";
}

std::string	fixtext(const std::filesystem::path &p)
{
	std::string ret = p.string();
	return (ret.substr(ret.find_last_of("/") + 1));
}

void	listdir(std::ofstream &o, int spaces)
{
	for (const auto & entry : std::filesystem::directory_iterator(std::filesystem::current_path()))
	{
		gospace(o, spaces);
		o << fixtext(entry.path()) << std::endl;
		if (std::filesystem::is_directory(entry.path()))
		{
			std::filesystem::current_path(entry.path());
			listdir(o, spaces + 4);
		}
	}
}

void	ShrubberyCreationForm::action() const
{
	std::string	path = _target + "_shrubbery";
	std::ofstream	st(path);
	st << fixtext(std::filesystem::current_path()) << std::endl;
	listdir(st, 4);
	st.close();
}
