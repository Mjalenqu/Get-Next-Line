/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 10:10:34 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 11:19:00 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *str, int fd)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(fd, &str[i], 1);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
