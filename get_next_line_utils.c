/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:58:17 by mavissar          #+#    #+#             */
/*   Updated: 2024/06/20 19:52:12 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
char    *ft_strjoin(char *s1, char *s2)
{
    int     i;
    char    *res;

    i = 0;
    res = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return (NULL);
    while (s1 && s1[i++])
        res[i] = s1[i];
    while (s2 && s2[i++])
        res[i] = s2[i];
    res[i] = '\0';
    return (res);
}
char    ft_strchr(const char *string, int search)
{
    char    *s;

    s = (char *)string;
    while(*s && *s != search)
        s++;
    if (*s == search)
        return (s);
    else 
        return (NULL);
}

char    *ft_substr(char *s, int start, int len)
{
    int     i;
    char    *str;

    i = 0;
    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (malloc(1));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    str = malloc((len + 1) * sizeof(char));
    if (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = 0;
    return (str);
    
}
char    *ft_strdup(char *str)
{
    int     i;
    char    *dest;

    i = 0;
    if (!str)
        return (NULL);
    dest = malloc(sizeof(char) * i + 1);
    if (!dest)
        return (NULL);
    while (str[i++])
        dest[i] = str[i];
    dest[i] = '\0';
    return(dest);
}
