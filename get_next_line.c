/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 08:29:24 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 12:42:09 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/includes/libft.h"
#include "get_next_line.h"

char	*get_line(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, 0, i);
			tmp = ft_strdup(str + i + 1);
			str = ft_strcpy(str, tmp);
			free(tmp);
			return (*line);
		}
		else
		{
			*line = ft_strsub(str, 0, i);
			str[0] = '\0';
			return (*line);
		}
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[256];
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	int			i;
	int			rd;

	i = 0;
	rd = 0;
	while ((rd = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (rd < 0)
			return (-1);
		buff[rd] = '\0';
		if (!(str[fd]))
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
	}
	*line = get_line(str[fd], line);
	if (*line == NULL)
		return (0);
	else
		return (1);
}
