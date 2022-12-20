/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:18:16 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 18:07:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str =  "HI THIS IS BRAIN";
	std::string& stringREF = str;
	std::string *stringPTR = &str;


	std::cout << "STR   address     : " << &str << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;
	std::cout << "stringPTR address : " << &stringPTR << std::endl;
	std::cout << std::endl;
	std::cout << "STR   value     : " << str << std::endl;
	std::cout << "stringREF value : " << stringREF << std::endl;
	std::cout << "stringPTR value : " << *stringPTR << std::endl;
}
