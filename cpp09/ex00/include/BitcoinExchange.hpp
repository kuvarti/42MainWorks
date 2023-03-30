/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:51:43 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/31 00:53:31 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <queue>
#include <string>

class amount{
public:
	amount() { _date = ""; _value = 0; }
	amount(std::string s, int v) { _date = s; _value = v; }
	amount &operator=(amount const &a) { _date = a.getdate(); _value = a.getvalue(); return *this;}

	void	wrongdateformat(std::string input)
	{
		_date = "Error: bad input -> " + std::string(input.begin(), input.begin() + input.find(','));
		_value = -1;
	}

	float getvalue() const { return _value; }
	std::string	getdate() const { return _date; }

	void	setdate(std::string d) { _date = d; }
	void	setvalue(float i) { _value = i; }
private:
	std::string _date;
	float	_value;
};
