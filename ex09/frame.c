#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= strlen(s))
		return (strdup(""));
	size = strlen(s + start);
	if (size < len)
		len = size;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	strlcpy(substr, (char *)s + start, len + 1);
	return (substr);
}

static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_p;
		}
	}
	*tab_p = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}

int getmaxchar(int argc, char **argv, char * token)
{
	char *tmp = token;
	int ret = 0;

	int i = 0;
	while (argv[++i])
	{
		if (strlen(argv[i]) > ret)
			ret = strlen(argv[i]);
	}
	return ret;
}

int main(int argc, char **argv)
{
	char *tmp;
	int aa = 1;
	if (argc == 1)
		return 1;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	int len = getmaxchar(argc, argv, tmp);
	for (int i = 0; i < len + 4; i++)
		printf("*");
	if (argc == 2)
		tmp = argv[0];
	else
		tmp = argv[1];
	if (argc == 2)
		aa--;
	while (1)
	{
		if (!argv[aa])
			break;
		printf("\n* %s", tmp);
		for (int i = strlen(tmp); i < len; i++)
			printf(" ");
		printf(" *");
		tmp = argv[++aa];
	}
	printf("\n");
	for (int i = 0; i < len + 4; i++)
		printf("*");
	printf("\n");
}
