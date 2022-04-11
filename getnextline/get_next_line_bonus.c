/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:41:40 by fcil              #+#    #+#             */
/*   Updated: 2022/03/04 13:00:09 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *kalan)
{
	int		i;
	char	*str;

	i = 0;
	if (!kalan[i])
		return (NULL);
	while (kalan[i] && kalan[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (kalan[i] && kalan[i] != '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	if (kalan[i] == '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *kalan)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (kalan[i] && kalan[i] != '\n')
		i++;
	if (!kalan[i])
	{
		free(kalan);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(kalan) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (kalan[i])
		str[j++] = kalan[i++];
	str[j] = '\0';
	free(kalan);
	return (str);
}

char	*ft_read_to_left_str(int fd, char *kalan)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(kalan, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		kalan = ft_strjoin(kalan, buff);
	}
	free(buff);
	return (kalan);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*kalan[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	kalan[fd] = ft_read_to_left_str(fd, kalan[fd]);
	if (!kalan[fd])
		return (NULL);
	str = ft_get_line(kalan[fd]);
	kalan[fd] = ft_new_left_str(kalan[fd]);
	return (str);
}
/*
int	main()
{
	int fd = open("test", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	int resfd = open("result", O_RDWR);
	char  *line;

	for (int i = 0; i < 10; i++) {
		if (i%2)
			line = get_next_line(fd2);
		else
			line = get_next_line(fd);
		write(resfd, line, ft_strlen(line));
	}
}
*/
