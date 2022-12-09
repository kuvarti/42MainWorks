#include "Contact.hpp"

_contact::_contact(int id, std::string firstname, std::string lastname, std::string nickname)
{
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
}

_contact::_contact()
{
	this->id = 0;
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
}

//* GETTERS
int _contact::getid()
{
	return this->id;
}

std::string _contact::getfirstname()
{
	return this->firstname;
}

std::string _contact::getlastname()
{
	return this->lastname;
}

std::string _contact::getnickname()
{
	return this->nickname;
}

std::string _contact::getphone()
{
	return this->phone;
}

std::string _contact::getdarkest_secret()
{
	return this->darkest_secret;
}

//* SETTERS
void _contact::setid(int id)
{
	this->id = id;
}

void _contact::setfirstname(std::string stream)
{
	this->firstname = stream;
}

void _contact::setlastname(std::string stream)
{
	this->lastname = stream;
}

void _contact::setnickname(std::string stream)
{
	this->nickname = stream;
}

void _contact::setphone(std::string stream)
{
	this->phone = stream;
}

void _contact::setdarkest_secret(std::string stream)
{
	this->darkest_secret = stream;
}
