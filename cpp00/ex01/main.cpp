#include <iostream>
#include "PhoneBook.hpp"

void	printmenu()
{
	std::cout << "Plase enter from above;" << std::endl;
	std::cout << "1 : ADD contact" << std::endl;
	std::cout << "2 : Search " << std::endl;
	std::cout << "3 : Exit the program" << std::endl;
	std::cout << "Enter The Choise: ";
}

int	isnumarray(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
	}
	return (1);
}

int	main()
{
	PhoneBook phonelist;

	std::string inp;
	while (1)
	{
		printmenu();
		std::cin >> inp;
		std::cout << LINE << std::endl;
		if (!isnumarray(inp))
		{
			std::cout << "Please enter a menu(numeric)" << std::endl << LINE << std::endl;
			continue;
		}
		switch (stoi(inp))
		{
		case 1:
			phonelist.addcontact();
			break;
		case 2:
			phonelist.search();
			break;
		case 3:
			std::cout << "bye bye" << std::endl << LINE << std::endl;
			return (0);
		default:
			std::cout << "Wrong input!! Plase enter the menu numbers" << std::endl;
			break;
		}
	}

}
