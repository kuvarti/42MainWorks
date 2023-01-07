#include <iostream>
#include <cmath>

using namespace std;

int	main()
{
	cout << "(1 << 8) : " << (1 << 8) << endl;
	cout << roundf(42.24f * (1 << 8)) << endl;
	cout << "42.24 * 256 : " << 42.24f * (1 << 8) << endl;
}

