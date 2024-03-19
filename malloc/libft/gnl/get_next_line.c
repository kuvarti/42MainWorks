/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:18:27 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/19 15:45:20 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *remainingChars)
{
	int		i;
	char	*str;

	i = 0;
	if (!remainingChars[i])
		return (NULL);
	while (remainingChars[i] && remainingChars[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (remainingChars[i] && remainingChars[i] != '\n')
	{
		str[i] = remainingChars[i];
		i++;
	}
	if (remainingChars[i] == '\n')
	{
		str[i] = remainingChars[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *remainingChars)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainingChars[i] && remainingChars[i] != '\n')
		i++;
	if (!remainingChars[i])
	{
		free(remainingChars);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_gnl_strlen(remainingChars) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remainingChars[i])
		str[j++] = remainingChars[i++];
	str[j] = '\0';
	free(remainingChars);
	return (str);
}

char	*ft_read_to_left_str(int fd, char *remainingChars)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_gnl_strchr(remainingChars, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		remainingChars = ft_gnl_strjoin(remainingChars, buff);
	}
	free(buff);
	return (remainingChars);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*remainingChars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remainingChars = ft_read_to_left_str(fd, remainingChars);
	if (!remainingChars)
		return (NULL);
	str = ft_get_line(remainingChars);
	remainingChars = ft_new_left_str(remainingChars);
	return (str);
}
/*
#include "stdio.h"
int	main()
{
	int fd = open("test", O_RDONLY);
	int resfd = open("result", O_RDWR);
	char  *str;

	for (int i = 0; i < 3; i++)
	{
		printf("%s", get_next_line(fd));
	}
}
*/
