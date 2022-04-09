/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:18:35 by fcil              #+#    #+#             */
/*   Updated: 2022/03/24 16:43:46 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef STDLIB_H
#  include <stdlib.h>
# endif

# ifndef UNISTD_H
#  include <unistd.h>
# endif

# ifndef FCNTL_H
#  include <fcntl.h>
# endif

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
//UTILS
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(const char *s);
#endif
