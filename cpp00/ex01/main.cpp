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

int	main()
{
	PhoneBook phonelist;

	std::string inp;
	while (1)
	{
		printmenu();
		std::cin >> inp;
		std::cout << LINE << std::endl;
		switch (stoi(inp))
		{
		case 1:
			phonelist.addcontact();
			break;
		case 2:
			phonelist.search();
			break;
		case 3:
			return (0);
		default:
			std::cout << "Wrong input!! Plase enter the menu numbers" << std::endl;
			break;
		}
	}

}
