/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:00:46 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 04:11:15 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIDE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void setZombieName(std::string name);
	void announce( void );
private:
	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
