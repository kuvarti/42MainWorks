#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

#define LINE "---------------------------------------------"

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void	addcontact();
		void	search();
	private:
		//* Add Utils
		std::string getstream(std::string prompt);
		int overwriteContact();

		//* Search utils
		void printthat(std::string stream);
		void printdetails(int index);

		int lastcontact;
		int totalid;
		_contact *contact_list;
};

#endif
