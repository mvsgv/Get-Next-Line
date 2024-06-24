/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:09:51 by mavissar          #+#    #+#             */
/*   Updated: 2024/06/24 17:48:14 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
// # endif

char	*next_line(char **string);
char	*read_line(int fd, char *to_save, char *buffer);
char	*get_next_line(int fd);

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *string);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *str);

#endif