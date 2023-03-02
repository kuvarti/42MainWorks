/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:18 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/02 19:34:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>


class Span{
public:
	Span(unsigned int);
	Span(Span const &);
	Span &operator=(Span const &);
	~Span();

	void	addNumber(int);
	void	addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
	class maxsizereached: public std::exception{
	public: const char * what() const throw(){
		return "Vector is full"; }
	};

	int	shortestSpan();
	int	longestSpan();
	class notfound: public std::exception{
	public: const char * what() const throw(){
		return "Element is not found"; }
	};

	int	maxnumber();
	int	minnumber();

private:
	std::vector<int>	_arr;
	long unsigned int	_size;
};
