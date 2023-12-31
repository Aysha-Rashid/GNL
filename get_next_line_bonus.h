/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:04:46 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/09/08 18:05:01 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char	*get_next_line(int fd);
char	*read_lines(int fd, char *store);
char	*new_line(char *line);
char	*remaining(char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char	*s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
#endif