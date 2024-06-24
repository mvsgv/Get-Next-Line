/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:48:19 by mavissar          #+#    #+#             */
/*   Updated: 2024/06/24 17:47:40 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_and_return(char **str, int to_free)
{
	if (to_free)
		free(*str);
	*str = NULL;
	return (NULL);
}
char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*keep;

	buff = NULL;

	system("leaks a.out");
	if (BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (ft_free_and_return(&keep, 1));
	}
	
	// printf("buffer : %s\n", buff);
	// printf("stash :%s\n", keep);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free_and_return(&keep, 1));
	line = read_line(fd, keep, buff);
	if (!line)
		return (ft_free_and_return(&keep, 0));
	free(buff);
	keep = next_line(&line);
	
	return (line);
}
char	*next_line(char **string)
{
	int		i;
	char	*buffer;
	char	*tmp;

	i = 0;
	tmp = *string;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if(tmp[i] == 0 || tmp[1] == 0)
		return (NULL);
	buffer = ft_substr(*string, i + 1, ft_strlen(tmp) - i);
	if (!buffer)
		return (NULL);
	if (*buffer == 0)
		ft_free_and_return(&buffer, 1);
	tmp[i + 1] = 0;
	*string = ft_substr(tmp, 0, i + 1);
	free(tmp);
	
	if (!*string)
		return (ft_free_and_return(&buffer, 1));
	return (buffer);
	
}
char	*read_line(int fd, char *to_save, char *buffer)
{
	char	*m;
	int		bytes;

	while (!ft_strchr(to_save))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_free_and_return(&to_save, 1));
		else if (bytes == 0)
			break;
		buffer[bytes] = '\0';
		if (!to_save)
			to_save = ft_strdup("");
			m = to_save;
		if (ft_strchr(to_save))
			break ;
		to_save = ft_strjoin(m, buffer);
	}
	return (to_save);
}


// int   main(int ac, char **av)
// {
// 	char  *line;
// 	int   fd1;

// 	line = NULL;
// 	(void)ac;
// 	fd1 = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	free(line);
// 	line = NULL;
// 	printf("%s\n", line);
// 	line = get_next_line(fd1);
// 	printf("%s\n", line);
// //   get_next_line(fd1);
// //   printf("%s\n", line);
// }

int main(void)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	return (0);
}