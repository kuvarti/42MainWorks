/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:57:22 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 03:26:17 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

int main()
{
	Base *ex;

	ex = Base::generate();
	Base &ex1 = *ex;

	Base::identify(ex);
	Base::identify(ex1);
}
