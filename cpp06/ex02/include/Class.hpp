/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:50:10 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 03:09:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <time.h>
#include <iostream>

class Base{
public:
	virtual ~Base() { };
	static Base * generate(void);
	static void identify(Base* p);
	static void identify(Base& p);
};

class A : public Base { public: A() { } };
class B : public Base { public: B() { } };
class C : public Base { public: C() { } };
