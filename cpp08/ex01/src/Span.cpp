/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:22:51 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/02 19:39:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n) : _size(n) {
}

Span::Span(Span const &s) {
	_arr = s._arr;
	_size = s._size;
}

Span &Span::operator=(Span const &s){
	_arr = s._arr;
	_size = s._size;
	return *this;
}

Span::~Span()
{ }

void	Span::addNumber(int n){
	if (_arr.size() < _size)
		_arr.push_back(n);
	else
		throw maxsizereached();
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator finish)
{
	std::vector<int> tmp(start, finish);

	if (tmp.size() > (_size - _arr.size()))
		throw maxsizereached();
	std::copy(tmp.begin(), tmp.end(), std::back_inserter(_arr));
}

int	Span::longestSpan(){
	return (maxnumber() - minnumber());
}

int	Span::shortestSpan(){
	int ret = longestSpan();
	std::vector<int>::iterator	i = _arr.begin();
	for (; i < _arr.end(); i++)
	{
		std::vector<int>::iterator	j = _arr.begin();
		for (; j < _arr.end(); j++)
		{
			if (i == j)
				continue ;
			if (*i > *j && *i - *j < ret)
				ret = *i - *j;
			else if (*i < *j && *j - *i < ret)
				ret = *j - *i;
		}
	}
	return ret;
}

int	Span::maxnumber(){
	std::vector<int>::iterator i = _arr.begin();
	int	ret = *i;
	for (; i < _arr.end(); i++){
		if (ret < *i)
			ret = *i;
	}
	return ret;
}

int	Span::minnumber(){
	std::vector<int>::iterator i = _arr.begin();
	int	ret = *i;
	for (; i < _arr.end(); i++){
		if (ret > *i)
			ret = *i;
	}
	return ret;
}
