/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:29:22 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/08 16:38:22 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string);
	FragTrap(const FragTrap &);
	~FragTrap(void);
	FragTrap & operator=(const FragTrap &);

	void	highFivesGuys(void);
private:
};

#endif
