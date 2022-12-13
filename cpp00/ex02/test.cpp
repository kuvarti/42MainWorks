//! This can be deleted
#include <iostream>
#include <vector>


class deneme{

public:
	typedef deneme d;
	deneme(int x);
private:
	int _amount;
	void	_displayTimestamp( void );

};

deneme::deneme(int x)
{
	this->_displayTimestamp();
	std::cout << x << " yazıldı\n";
	this->_amount = x;
}

void deneme::_displayTimestamp(void)
{
	time_t now	= time(0);
	tm *ltm		= localtime(&now);

	std::cout << "[";
	// Year - month - day
	std::cout << 1900 + ltm->tm_year;
	ltm->tm_mon < 10 ? std::cout << "0" << 1 + ltm->tm_mon : std::cout << 1 + ltm->tm_mon;
	ltm->tm_mday < 10 ? std::cout << "0" << ltm->tm_mday : std::cout <<  ltm->tm_mday;

	std::cout << "_";
	//hour - min - sec
	ltm->tm_hour < 10 ? std::cout << "0" << ltm->tm_hour : std::cout << ltm->tm_hour;
	ltm->tm_min < 10 ? std::cout << "0" << ltm->tm_min : std::cout <<  ltm->tm_min;
	ltm->tm_sec < 10 ? std::cout << "0" << ltm->tm_sec : std::cout <<  ltm->tm_sec;
	std::cout << "] ";
}


int main()
{
	typedef std::vector<deneme::d>	denemeler;

	int	const		amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };	//accounts sabit dizisi
	size_t const	amounts_size( sizeof(amounts) / sizeof(int) );				//account sayısı sabiti
	denemeler		qwe( amounts, amounts + amounts_size - 1 );				//

}
