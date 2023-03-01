/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:49:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 03:29:21 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"
#include <type_traits>

Base * Base::generate(void)
{
	Base	*ret;
	srand(time(0));

	int generate = rand() % 3;
	switch (generate)
	{
	case 0:
		ret = new A;
		break;
	case 1:
		ret = new B;
		break;
	case 2:
		ret = new C;
		break;
	default:
		break;
	}
	return (ret);
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Its A*" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Its B*" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Its C*" << std::endl;
}

void	Base::identify(Base& p)
{
	try { dynamic_cast<A&>(p); std::cout << "Its A&" << std::endl; return ;}
	catch (std::exception &e) { }
	try { dynamic_cast<B&>(p); std::cout << "Its B&" << std::endl; return ;}
	catch (std::exception &e) { }
	try { dynamic_cast<C&>(p); std::cout << "Its C&" << std::endl; return ;}
	catch (std::exception &e) {  }
}
