/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:48:00 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/23 00:15:12 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialForm.hpp"
#include "ShrubberyForm.hpp"
#include "RobotomyForm.hpp"

class Intern
{
public:
	Intern() { };
	~Intern() { };
	Intern(Intern const &) { };
	Intern &operator=(Intern const &) { return *this; };

	AForm	*makeForm(std::string, std::string);
};
