/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:40:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/17 21:32:59 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &);
		Brain &operator=(const Brain &);

		std::string getIdea(int) const;
		void setIdea(int, std::string);
	private:
		std::string _ideas[100];
};
