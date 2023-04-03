#include <iostream>
#include <string>

using namespace std;
int linelen = 1;
int	spacelen = 0;

int	spaces(int line, int max)
{
	int ret = 0;
	int	maxline = (max * 4) - 1;
	while (line < maxline)
	{
		if ((line + 1) % 4 == 3)
			ret += 3;
		else
			ret++;
		line++;
	}
	return ret;
}

int main(int argc,char **argv)
{
	if (argc != 2)
		return 0;
	int	size = 0;
	try { size = stoi(argv[1]); }
	catch ( exception const &e) { cout << "Error" << endl; return 0; }
	int wc = size;
	int line = 0;
	int pars = 3;
	while (size--)
	{
		for (int i = 0; i < pars; i++)
		{
			for (int sp = 0; sp < spaces(line, wc); sp++) cout << " ";
			cout << "/";
			for (int sp = 0; sp < linelen; sp++) cout << "*";
			cout << "\\" << endl;
			linelen += 2;
			line++;
		}
		pars++;
		linelen += 4;
	}
}
