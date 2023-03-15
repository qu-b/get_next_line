/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:01:55 by fcullen           #+#    #+#             */
/*   Updated: 2023/03/15 10:29:38 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 42
// #endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*create_current_line(char *str);
char	*get_to_next(char	*str);

// Utilities
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);

#endif