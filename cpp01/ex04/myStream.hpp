/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myStream.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:56:28 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/21 00:23:19 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTREAM_HPP
# define MYSTREAM_HPP

#include <string>
#include <fstream>

class myStream{
public:
	myStream(char *);
	~myStream();
	std::string getText();
	void replace(char *, char *);
private:
	std::string _text;
	std::string _filename;
};

#endif
