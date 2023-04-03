/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:21:23 by aeryilma          #+#    #+#             */
/*   Updated: 2023/04/03 19:01:53 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <list>

void merge_sort(std::vector<int>& arr);
void merge_sort(std::list<int>& arr);

void	getinput(std::vector<int> *vc, std::list<int> *ls, std::string input)
{
	input += "  ";
	int fnd;
	int value = 0;
	while (input[0])
	{
		fnd = input.find(' ');
		try {
			value = stoi(std::string(input.begin(), input.begin() + fnd + 1));
		} catch (std::exception const &e) { }
		input = std::string(input.begin() + fnd + 1, input.end());
		if (value < 0)
		{
			while(!vc->empty())
				vc->pop_back();
			while(!ls->empty())
				ls->pop_front();
			return ;
		}
		vc->push_back(value);
		ls->push_front(value);
	}
}

int main(int argc, char **argv)
{
	std::cout << argv[1] << std::endl;
	if (argc != 2)
	{
		std::cerr << "Wrong Use! ./program \"positive numbers\"" << std::endl;
		return 1;
	}
	std::vector<int>	vec;
	std::list<int>		ls;
	getinput(&vec, &ls, argv[1]);
	if (vec.empty())
		std::cout << "its empty" << std::endl;
//*	PRINT CONTAINER
	std::cout << "Vector list : ";
	for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
//*	PRINT CONTAINER
	std::cout << "List list : ";
	for (std::list<int>::iterator it = ls.begin(); it != ls.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;

//*	GET TIME RESULTS
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	std::chrono::nanoseconds duration;

//*	VECTOR
	start = std::chrono::high_resolution_clock::now();
	merge_sort(vec);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::[vector] : " << duration.count() << " ns" << std::endl;

//*	LIST
	start = std::chrono::high_resolution_clock::now();
	merge_sort(ls);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::[list] : " << duration.count() << " ns" << std::endl;
}
