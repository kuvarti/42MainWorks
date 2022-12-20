/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myStream.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:58:47 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/21 00:40:19 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myStream.hpp"
#include "iostream"

myStream::myStream(char *filename)
{
	std::ifstream inFile(filename);
	std::string ret = "";
	std::string tmp;

	while( getline(inFile, tmp) )
	{
		ret += tmp + "\n";
	}
	_text = ret;
	_filename = filename;
}

myStream::~myStream()
{
	_filename += ".replace";
	std::cout << _filename << " is created." << std::endl;
	std::ofstream outfile(_filename);
	outfile << _text;
	outfile.close();
}

std::string myStream::getText()
{
	return _text;
}

void myStream::replace(char *src, char *dest)
{
	std::string newString = "";
	const char *str = _text.c_str();
	int i = 0;

	int	j, k;
	while (str[i])
	{
		j = 0;
		k = 0;
		while(str[i + j] == src[k])
		{
			j++;
			k++;
			if (!src[k])
			{
				i += j;
				newString += dest;
			}
		}
		newString += str[i++];
	}
	_text = newString;
}
