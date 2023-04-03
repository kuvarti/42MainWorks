/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:33:31 by aeryilma          #+#    #+#             */
/*   Updated: 2023/04/03 15:51:23 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <deque>

std::deque<char>	getdeque(std::string input)
{
	std::deque<char> ret;
	int	i = -1;
	while (input[++i])
	{
		if (strchr("+-*/ 0123456789", input[i]))
		{
			if (input[i] == ' ')
				continue;
			ret.push_back(input[i]);
		}
		else
		{
			while(!(ret.empty()))
			{
				ret.pop_front();
			}
			break;
		}
	}
	return ret;
}

int	operation(int a, int b, char c)
{
	switch(c)
	{
		case '+':
			return a + b;
		break;
		case '-':
			return a - b;
		break;
		case '*':
			return a * b;
		break;
		case '/':
			return a / b;
		break;
		default:
			return 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong Use! ./program \"operations\"" << std::endl;
		return 1;
	}

	std::deque<char> mydeque = getdeque(argv[1]);
	if (mydeque.empty())
	{
		std::cerr << "Error" << std::endl;
		return 2;
	}

	int d1, d2;
	std::deque<int> tmp;
	while(!(mydeque.empty()))
	{
		if (isdigit(mydeque.front()))
			tmp.push_back(mydeque.front() - '0');
		else
		{
			d1 = tmp.front(); tmp.pop_front();
			d2 = tmp.front(); tmp.pop_front();
			tmp.push_front(operation(d1, d2, mydeque.front()));
		}
		mydeque.pop_front();
	}
	std::cout << "Result is : " << tmp.front() << std::endl;
}
