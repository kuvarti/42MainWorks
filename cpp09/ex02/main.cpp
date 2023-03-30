/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:21:23 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/31 02:08:25 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <list>

void quicksort(std::vector<int>& arr, int left, int right) {
	if (left < right) {
		int pivot = arr[(left + right) / 2];
		int i = left - 1;
		int j = right + 1;
		while (true) {
			do {
				i++;
			} while (arr[i] < pivot);
			do {
				j--;
			} while (arr[j] > pivot);
			if (i >= j) {
				break;
			}
			std::swap(arr[i], arr[j]);
		}
		quicksort(arr, left, j);
		quicksort(arr, j + 1, right);
	}
}

void quicksort(std::list<int>& lst) {
	if (lst.size() < 2) {
		return;
	}

	std::list<int> smaller;
	std::list<int> equal;
	std::list<int> larger;
	int pivot = *lst.begin();

	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
		if (*it < pivot) {
			smaller.push_back(*it);
		} else if (*it == pivot) {
			equal.push_back(*it);
		} else {
			larger.push_back(*it);
		}
	}

	quicksort(smaller);
	quicksort(larger);

	lst.clear();
	lst.splice(lst.end(), smaller);
	lst.splice(lst.end(), equal);
	lst.splice(lst.end(), larger);
}

void	getinput(std::vector<int> *vc, std::list<int> *ls, std::string input)
{
	input += " ";
	int fnd;
	int value = 0;
	while (input[0])
	{
		fnd = input.find(' ');
		value = stoi(std::string(input.begin(), input.begin() + fnd + 1));
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
	quicksort(vec, 0, vec.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::[vector] : " << duration.count() << " ns" << std::endl;

//*	LIST
	start = std::chrono::high_resolution_clock::now();
	quicksort(ls);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::[list] : " << duration.count() << " ns" << std::endl;
}
