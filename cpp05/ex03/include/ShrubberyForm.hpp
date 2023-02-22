/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyForm.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:52:28 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 21:39:56 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
public:
	ShrubberyCreationForm(std::string);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

	void	action() const;
private:
};
