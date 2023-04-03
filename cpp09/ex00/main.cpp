/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:22:33 by aeryilma          #+#    #+#             */
/*   Updated: 2023/04/03 15:22:14 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>

amount getamount(std::string text)
{
	amount ret;

	if (text[10] != ',')
	{
		ret.wrongdateformat(text);
		return ret;
	}
	int month = stoi(std::string(&text[5], &text[7]));
	int day = stoi(std::string(&text[8], &text[10]));
	if (month < 0 || month > 12 || day < 0 || day > 31)
	{
		ret.wrongdateformat(text);
		return ret;
	}
	std::string date = std::string(text.begin(), text.begin() + text.find(','));
	if (ret.getdate() == "")
		ret.setdate(date);
	float	value = stof(std::string(text.begin() + text.find(',') + 1, text.end()));
	if (value < 0 || value > 1000)
	{
		if (value > 1000)	ret.setdate("Error: too large a number.");
		else	ret.setdate("Error: not a positive number.");
		ret.setvalue(-1);
	}
	if (ret.getvalue() != -1)
		ret.setvalue(value);
	return ret;
}

std::queue<amount>	getqueue(std::string f)
{
	std::queue<amount>	ret;
	std::ifstream file(f);
	std::string line;

	if (file.is_open()) {
		std::getline(file, line);
		while (std::getline(file, line)) {
			ret.push(getamount(line));
		}
		file.close();
	} else {
		std::cerr << "Unable to open file" << std::endl;
	}
	return (ret);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong Use! ./program <input file>" << std::endl;
		return 1;
	}
	std::queue<amount> myQueue = getqueue(argv[1]);
	amount tmp;
	while (!myQueue.empty())
	{
		tmp = myQueue.front();
		if (tmp.getvalue() == -1)
			std::cout << tmp.getdate() << std::endl;
		else
			std::cout << tmp.getdate() << " => " << tmp.getvalue() << " = " << tmp.getvalue() * 18 << std::endl;
		myQueue.pop();
	}
}
