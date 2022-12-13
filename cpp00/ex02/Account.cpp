#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
}

static void Account::_displayTimestamp(void)
{
	time_t now	= time(0);
	tm *ltm		= localtime(&now);

	std::cout << "[";
	// Year - month - day
	std::cout << 1900 + ltm->tm_year;
	ltm->tm_mon < 10 ? std::cout << "0" << 1 + ltm->tm_mon : std::cout << 1 + ltm->tm_mon;
	ltm->tm_mday < 10 ? std::cout << "0" << ltm->tm_mday : std::cout <<  ltm->tm_mday;

	//hour - min - sec
	ltm->tm_hour < 10 ? std::cout << "0" << ltm->tm_hour : std::cout << ltm->tm_hour;
	ltm->tm_min < 10 ? std::cout << "0" << ltm->tm_min : std::cout <<  ltm->tm_min;
	ltm->tm_sec < 10 ? std::cout << "0" << ltm->tm_sec : std::cout <<  ltm->tm_sec;
	std::cout << "]";
}
