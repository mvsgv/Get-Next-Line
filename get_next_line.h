/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:09:51 by mavissar          #+#    #+#             */
/*   Updated: 2024/06/20 19:20:10 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

static char    ft_free_and_return(char **str, int to_free);
char    *next_line(char **line);

int     ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
char    ft_strchr(const char *string, int search);
char    *ft_substr(char *s, int start, int len);
char    *ft_strdup(char *str);

#endif