#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class _contact{
	public:
		_contact();
		_contact(int id, std::string firstname, std::string lastname, std::string nickname);

		//Getters
		int getid();
		std::string getfirstname();
		std::string getlastname();
		std::string getnickname();
		std::string getphone();
		std::string getdarkest_secret();

		//Setters
		void setid(int id);
		void setfirstname(std::string stream);
		void setlastname(std::string stream);
		void setnickname(std::string stream);
		void setphone(std::string stream);
		void setdarkest_secret(std::string stream);

	private:
		std::string setterutil(std::string stream);

		int id;
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone;
		std::string darkest_secret;
};

#endif
