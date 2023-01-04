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

class Fixed{
public:
	Fixed();
	Fixed (const Fixed &f);
	~Fixed();
	Fixed & operator = (const Fixed &f);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_rawbits;
	static const int	_fractional_bits = 8;
};

#endif
