#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return printf("Wrong program use! ./program \"cards\"\n");
	int i = 0, acount = 0, total = 0;
	while (i < strlen(argv[1]))
	{
		if (isdigit(argv[1][i]))
			total += argv[1][i] - '0';
		else if (toupper(argv[1][i]) == 'A')
			acount++;
		else if (strchr("TJDK", toupper(argv[1][i])))
			total += 10;
		else
			return printf("undefinde characker : %c", argv[1][i]);
		i++;
	}
	while (acount--)
	{
		if (total + 11 == 21 & acount == 0)
			total = 21;
		else if (total + 11 < 21)
			total += 11;
		else
			total++;
	}
	if (total == 21)
		return printf("Blackjack!\n");
	else
		return printf("%d\n", total);
}
