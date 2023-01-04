/* ************************************************************************** */
/*                                                                             */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:47:05 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/28 01:14:33 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class fixed{
public:
	fixed();
	fixed (const fixed &f);
	~fixed();
	fixed & operator = (const fixed &f);

	int		getRawBits( void );
	void	setRawBits( int const raw );

private:
	int					_rawbits;
	static const int	_dotPoint = 16;
};

#endif
