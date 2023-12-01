/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:41:20 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 18:19:42 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_check_symbol(char *str, int *f, int *flag)
{
	int	i;

	i = 0;
	if (str[i] == '-' && *f != 1)
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (str[i] == '\0' && *f == 0)
		{
			*flag = 1;
			return (1);
		}
		else
		{
			*f = 1;
			return (0);
		}
	}
	*f = 1;
	return (0);
}

int	ft_echo(char **ptr, int fd)
{
	int		flag;
	int		i;
	int		f;

	i = 0;
	flag = 0;
	f = 0;
	while (ptr[i])
	{
		if (ft_check_symbol(ptr[i], &f, &flag) == 0)
		{
			write(fd, ptr[i], ft_strlen(ptr[i]));
			if (ptr[i + 1] != '\0')
				write(fd, " ", 1);
		}
		i++;
	}
	if (flag == 0)
		write(fd, "\n", 1);
	return (0);
}
