#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->contact_list = new _contact[8];
	this->lastcontact = 0;
	this->totalid = 0;
}

PhoneBook::~PhoneBook()
{
	delete[] this->contact_list;
}

std::string PhoneBook::overwriteContact()
{
	std::cout << "You're overWriting to : ";
	std::cout << this->contact_list[this->lastcontact].getfirstname() << " ";
	std::cout << this->contact_list[this->lastcontact].getlastname() << std::endl;
	std::cout << "Are u sure?\n" << "Enter 0 :\"No i dont wanna overwrite\"" << std::endl;
	std::cout << "Enter Otherwise: \"Yes i wanna overwrite\"\nSelection: ";
	std::string	inp;
	std::cin >> inp;
	std::cout<< LINE << std::endl;
	return inp;
}

std::string PhoneBook::getstream(std::string prompt)
{
	std::string input;

	std::cout << prompt;	//Output the prompt
	std::cin >> input;

	while (input == "")
	{
		std::cout << "Field cant be empty, please try again." << std::endl;
		std::cout << prompt;
		std::cin >> input;
	}

	return input;
}

void PhoneBook::addcontact()
{
	if (this->contact_list[this->lastcontact].getfirstname() == "")
		std::cout << "You're adding new contact" << std::endl;
	else
	{
		if (overwriteContact() == "0")
			return ;
	}
	this->contact_list[this->lastcontact].setid(++(this->totalid));
	this->contact_list[this->lastcontact].setfirstname(getstream("First name: "));
	this->contact_list[this->lastcontact].setlastname(getstream("Last Name: "));
	this->contact_list[this->lastcontact].setnickname(getstream("Nickname: "));
	this->contact_list[this->lastcontact].setphone(getstream("Phone Number: "));
	this->contact_list[this->lastcontact].setdarkest_secret(getstream("Darkest Secret: "));

	std::cout << "New Contact was added. Returning the Menu" << std::endl;
	if (++(this->lastcontact) >= 8)
		this->lastcontact = 0;
	std::cout << LINE << std::endl;
}

void PhoneBook::printthat(std::string stream)
{
	if (stream.length() <= 10)
	{
		int space = 10 - stream.length();
		for (; space > 0; space--)
			std::cout << " ";
		std::cout << stream;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			std::cout << stream[i];
		}
		std::cout << ".";
	}
}

void PhoneBook::printdetails(int index)
{
	for(int i = 0; i < 8; i++)
	{
		if (contact_list[i].getid() == index)
		{
			std::cout << contact_list[i].getid() << "(index) is firstname: ";
			std::cout << contact_list[i].getfirstname() << ", lastname: ";
			std::cout << contact_list[i].getlastname() << ", Nickname: ";
			std::cout << contact_list[i].getnickname() << ", Phone Number: ";
			std::cout << contact_list[i].getphone() << ", darkest secret: ";
			std::cout << contact_list[i].getdarkest_secret() << std::endl;
		}
	}
}

void PhoneBook::search()
{
	std::string listindex;

	std::cout<<"|     index|first name| last name|  Nickname|" <<std::endl;
	for(int i = 0; i < 8; i++)
	{
		if (contact_list[i].getid() == 0)
			break;
		std::cout << "|";
		printthat(std::to_string(contact_list[i].getid()));
		std::cout << "|";
		printthat(contact_list[i].getfirstname());
		std::cout << "|";
		printthat(contact_list[i].getlastname());
		std::cout << "|";
		printthat(contact_list[i].getnickname());
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "Enter index for Details(if dont exist returns the Menu): ";
	std::cin >> listindex;
	if (!isnumarray(listindex))
		std::cout << "Please enter a index(numeric)" << std::endl;
	else
		printdetails(stoi(listindex));
	std::cout << "Returning the main menu"<< std::endl;
	std::cout << LINE << std::endl;
}
