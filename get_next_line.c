/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:48:19 by mavissar          #+#    #+#             */
/*   Updated: 2024/06/20 20:08:01 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    ft_free_and_return(char **str, int to_free)
{
    if (to_free)
        free(*str);
    *str = NULL;
    return (NULL);
}
char    *next_line(char **line)
{
    int     i;
    char    *buff;
    char    *tmp;

    i = 0;
    tmp = *line;
    while (tmp && tmp[i] != '\n')
        i++;
    if (tmp[i] == 0 || tmp[i] != '\0')
        return (NULL);
    buff = ft_substr(*line, i + 1,ft_strlen(tmp) - i);
    if (!buff)
        return (NULL);
    if (*buff == 0)
        ft_free_and_return(&tmp, 1);
    tmp[i + 1] = '\0';
    *line = ft_substr(tmp, 0, i + 1);
    free(tmp);
    if (!*line)
        return (ft_free_and_return(&buff, 1));
    return (buff);
}
char    *save_line(int fd, char *to_save, char *buffer)
{
    char    *buff;
    int     bytes;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(to_save))
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        if (bytes == -1)
            return (ft_free_and_return(&buff, 1));
        else if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		if (!to_save)
			save = ft_strdup("");
		buff = to_save;
		to_save = ft_strjoin(buff, buffer);
		free(buff);
    }
    return (to_save);
}

char    *get_next_line(int fd)
{
    char        *line;
    static char *save;
    char        *buff;

    if (BUFFER_SIZE >= INT_MAX)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (ft_free_and_return(&save, 1));
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (ft_free_and_return(&save, 1));
    line = save_line(fd, save, buff);
    free(buff);
    if (!line)
        return (ft_free_and_return(&save, 0));
    save = next_line(&line);
    return (line);
}