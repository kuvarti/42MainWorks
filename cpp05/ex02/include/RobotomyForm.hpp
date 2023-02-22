/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyForm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:52:28 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 22:46:10 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
public:
	RobotomyRequestForm(std::string);
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &);

	void	action() const;
private:
};
