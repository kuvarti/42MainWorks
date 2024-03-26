/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:17:21 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 16:42:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	index;
	size_t	len;

	len = ft_strlen(s) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	index = 0;
	while (index < len)
	{
		ret[index] = s[index];
		index++;
	}
	return (ret);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src = "bunu dupla";
	printf("%s -> %s", src, ft_strdup(src));
}
*/
